#ifndef __atom_Server__
#define __atom_Server__

#include <memory>
#include <set>
#include <thread>
#include <mutex>
#include <functional>
#define ASIO_STANDALONE
#include <asio.hpp>
using asio::ip::tcp;
#include "../ManualResetEvent.hpp"
#include "Connection.hpp"

namespace atom {

class Server : public std::enable_shared_from_this<Server> {
	typedef std::function<void(std::shared_ptr<Connection>)> OnConnectionMade;
	typedef std::function<void(std::shared_ptr<Connection>)> OnDisconnected;

public:
	Server();
	~Server();

	bool start( int port );
	void stop();

	bool isRunning() const;

	void setOnConnectionMade( OnConnectionMade func );
	void setOnDisconnected( OnDisconnected func );

	void sendToAll( std::shared_ptr<Message> msg );

	unsigned int numberOfClients();

private:
	void ListenThread();

private:
	asio::io_service ioService_;
	std::thread ioServiceThread_;
	tcp::acceptor acceptor_;
	tcp::socket acceptorSocket_;
	bool running_;
	ManualResetEvent connectionMadeEvent;
	std::set<std::shared_ptr<Connection>> connections_;
	std::mutex connectionsMutex_;
	std::thread listenThread_;
	OnConnectionMade onConnectionMade_;
	OnDisconnected onDisconnected_;
};

}

#endif