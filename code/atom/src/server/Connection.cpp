#include "Connection.hpp"
#include <functional>

using namespace atom;

Connection::Connection( tcp::socket connectionSocket )
	: socket_(std::move(connectionSocket)), active_(false), readMsg_(nullptr), writeMsg_(nullptr) {
}

Connection::~Connection() {
}

tcp::socket& Connection::socket() {
	return socket_;
}

void Connection::disconnect() {
	if( !active_ ) {
		return;
	}

	if( onDisconnect_ ) {
		onDisconnect_();
	}

	active_ = false;
	socket_.shutdown(tcp::socket::shutdown_both);
	socket_.close();
}

void Connection::beginRead() {
	active_ = true;
	readInternal();
}

void Connection::write( std::shared_ptr<Message> msg ) {
	std::lock_guard<std::recursive_mutex> lock(writeLogMutex_);
	const bool writeInProgress = !writeLog_.empty();
	writeLog_.push_back(msg);
	if( !writeInProgress ) {
		writeInternal();
	}
}

void Connection::setOnReceived( OnReceived func ) {
	onReceived_ = func;
}

void Connection::setOnDisconnect( OnDisconnect func ) {
	onDisconnect_ = func;
}

std::string Connection::getClientName() const {
	return active_ ? socket_.remote_endpoint().address().to_string() + ":" + std::to_string(socket_.remote_endpoint().port()) : "ERROR";
}

bool Connection::isActive() const {
	return active_;
}

void Connection::readInternal() {
	readMsg_ = Message::createIncoming();
	socket_.async_read_some(asio::buffer(readMsg_->readBuffer().data(), Message::HEADER_SIZE), std::bind(&Connection::readCallback, shared_from_this(), std::placeholders::_1, std::placeholders::_2));
}

void Connection::readCallback( const std::error_code& ec, std::size_t bytesTransferred ) {
	if( ec ) {
		disconnect();
		return;
	}

	const int dataRead = static_cast<int>(bytesTransferred);

	if( dataRead <= 0 ) {
		disconnect();
		return;
	}

	// read size header
	if( !readMsg_->hasReadHeader() ) {
		// decode header size
		std::array<unsigned char, 4> headerArray;
		std::memcpy(headerArray.data(), readMsg_->readBuffer().data(), Message::HEADER_SIZE);
		readMsg_->setDataSize(utils::decodeHeader(headerArray));
		// start to read remaining data
		const int sizeToRead = std::min<int>((int)Message::BUFFER_SIZE, readMsg_->dataSize());
		socket_.async_read_some(asio::buffer(readMsg_->readBuffer().data(), sizeToRead), std::bind(&Connection::readCallback, shared_from_this(), std::placeholders::_1, std::placeholders::_2));
		return;
	}

	// append write buffer and continue reading if necessary
	if( (readMsg_->bytesProcessed() + dataRead) == readMsg_->dataSize() ) {
		std::memcpy(readMsg_->data().get() + readMsg_->bytesProcessed(), readMsg_->readBuffer().data(), dataRead);
		readMsg_->setBytesProcessed(readMsg_->bytesProcessed() + dataRead);
		if( onReceived_ ) {
			onReceived_(readMsg_);
		}
		readInternal();
		return;
	} else {
		std::memcpy(readMsg_->data().get() + readMsg_->bytesProcessed(), readMsg_->readBuffer().data(), dataRead);
		readMsg_->setBytesProcessed(readMsg_->bytesProcessed() + dataRead);
		const int sizeToRead = std::min<int>((int)Message::BUFFER_SIZE, readMsg_->dataSize() - readMsg_->bytesProcessed());
		socket_.async_read_some(asio::buffer(readMsg_->readBuffer().data(), sizeToRead), std::bind(&Connection::readCallback, shared_from_this(), std::placeholders::_1, std::placeholders::_2));
	}
}

void Connection::writeInternal() {
	{
		std::lock_guard<std::recursive_mutex> lock(writeLogMutex_);
		writeMsg_ = writeLog_.front();
	}
	socket_.async_write_some(asio::buffer(writeMsg_->data().get(), writeMsg_->totalSize()), std::bind(&Connection::writeCallback, shared_from_this(), std::placeholders::_1, std::placeholders::_2));
}

void Connection::writeCallback( const asio::error_code& ec, std::size_t bytesTransferred ) {
	if( ec ) {
		disconnect();
		return;
	}

	const int dataSent = static_cast<int>(bytesTransferred);
	writeMsg_->setBytesProcessed(writeMsg_->bytesProcessed() + dataSent);
	if( writeMsg_->bytesProcessed() != writeMsg_->totalSize() ) {
		socket_.async_write_some(asio::buffer(writeMsg_->data().get() + writeMsg_->bytesProcessed(), writeMsg_->totalSize() - writeMsg_->bytesProcessed()), std::bind(&Connection::writeCallback, shared_from_this(), std::placeholders::_1, std::placeholders::_2));
	} else {
		std::lock_guard<std::recursive_mutex> lock(writeLogMutex_);
		writeLog_.pop_front();
		if( !writeLog_.empty() ) {
			writeInternal();
		}
	}
}