#include "Message.hpp"

using namespace atom;

Message::Message()
	: data_(nullptr), dataSize_(0), hasReadHeader_(false), bytesProcessed_(0) {
}

Message::~Message() {
}

std::shared_ptr<Message> Message::createOutgoing( const void* userData, const int32_t sizeInBytes ) {
	if( nullptr == userData || sizeInBytes <= 0 ) {
		return nullptr;
	}

	auto msg = std::shared_ptr<Message>(new Message);
	msg->type_ = MessageType::Outgoing;
	// store
	msg->dataSize_ = sizeInBytes;
	// allocate data buffer
	msg->data_ = std::make_unique<unsigned char[]>(sizeInBytes + Message::HEADER_SIZE);
	// encode header
	const auto header = utils::encodeHeader(sizeInBytes);
	// copy header and data into buffer
	std::memcpy(msg->data_.get(), header.data(), Message::HEADER_SIZE);
	std::memcpy(msg->data_.get() + Message::HEADER_SIZE, userData, sizeInBytes);
	return msg;
}


std::shared_ptr<Message> Message::createIncoming() {
	auto msg = std::shared_ptr<Message>(new Message);
	msg->type_ = MessageType::Incoming;
	return msg;
}

const std::unique_ptr<unsigned char[]>& Message::data() const {
	return data_;
}

int32_t Message::dataSize() const {
	return dataSize_;
}

int32_t Message::totalSize() const {
	return dataSize_ + HEADER_SIZE;
}

std::array<unsigned char, Message::BUFFER_SIZE>& Message::readBuffer() {
	return readBuffer_;
}

bool Message::hasReadHeader() const {
	return hasReadHeader_;
}

void Message::setDataSize( int32_t val ) {
	if( MessageType::Outgoing == type_ ) {
		return;
	}

	if( val <= 0 ) {
		return;
	}

	hasReadHeader_ = true;
	dataSize_ = val;
	data_ = std::make_unique<unsigned char[]>(val);
}

int32_t Message::bytesProcessed() const {
	return bytesProcessed_;
}

void Message::setBytesProcessed( int32_t amount ) {
	bytesProcessed_ = amount;
}