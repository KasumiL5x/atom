#ifndef __atom_Connection__
#define __atom_Connection__

#include <memory>
#include <mutex>
#include <deque>
#include <functional>
#define ASIO_STANDALONE
#include <asio.hpp>
using asio::ip::tcp;
#include "Message.hpp"

namespace atom {

class Connection : public std::enable_shared_from_this<Connection> {
	typedef std::function<void(std::shared_ptr<Message>)> OnReceived;
	typedef std::function<void()> OnDisconnect;

public:
	Connection( tcp::socket connectionSocket );
	~Connection();

	tcp::socket& socket();

	void disconnect();
	void beginRead();
	void write( std::shared_ptr<Message> msg );
	void setOnReceived( OnReceived func );
	void setOnDisconnect( OnDisconnect func );

	std::string getClientName() const;

	bool isActive() const;

private:
	void readInternal();
	void readCallback( const std::error_code& ec, std::size_t bytesTransferred );
	void writeInternal();
	void writeCallback( const asio::error_code& ec, std::size_t bytesTransferred );

private:
	tcp::socket socket_;
	bool active_;
	std::shared_ptr<Message> readMsg_;
	OnReceived onReceived_;
	OnDisconnect onDisconnect_;
	std::deque<std::shared_ptr<Message>> writeLog_;
	std::recursive_mutex writeLogMutex_;
	std::shared_ptr<Message> writeMsg_;
};

}

#endif