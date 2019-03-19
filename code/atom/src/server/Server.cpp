#include "Server.hpp"

using namespace atom;

Server::Server()
	: acceptor_(ioService_), acceptorSocket_(ioService_), running_(false) {
}

Server::~Server() {
	stop();
}

bool Server::start( int port ) {
	if( running_ ) {
		return false;
	}

	auto ep = tcp::endpoint(tcp::v4(), port);
	acceptor_.open(ep.protocol());
	acceptor_.set_option(tcp::acceptor::keep_alive(true));
	std::error_code ec;
	acceptor_.bind(ep, ec);
	if( ec ) {
		return false;
	}
	acceptor_.listen(tcp::acceptor::max_connections, ec);
	if( ec ) {
		return false;
	}

	running_ = true;

	// start listen thread
	listenThread_ = std::thread(&Server::ListenThread, this);

	ioServiceThread_ = std::thread([this]{
		ioService_.run();
	});

	return true;
}

void Server::stop() {
	if( !running_ ) {
		return;
	}

	// copy the connections as calling their disconnect() removes them from
	// the connections_ set.  removing during a loop of that set will crash.
	std::set<std::shared_ptr<Connection>> copyOfConnections = connections_;
	for( auto& conn : copyOfConnections ) {
		conn->disconnect();
	}
	copyOfConnections.clear();
	connections_.clear();

	running_ = false;
	acceptor_.close();
	listenThread_.join();
	ioServiceThread_.join();
}

bool Server::isRunning() const {
	return running_;
}

void Server::setOnConnectionMade( OnConnectionMade func ) {
	onConnectionMade_ = func;
}

void Server::setOnDisconnected( OnDisconnected func ) {
	onDisconnected_ = func;
}

void Server::sendToAll( std::shared_ptr<Message> msg ) {
	std::unique_lock<std::mutex> lock(connectionsMutex_);
	for( auto& conn : connections_ ) {
		conn->write(msg);
	}
}

unsigned int Server::numberOfClients() {
	std::unique_lock<std::mutex> lock(connectionsMutex_);
	return static_cast<unsigned int>(connections_.size());
}

void Server::ListenThread() {
	while( running_ ) {
		connectionMadeEvent.reset();
		acceptor_.async_accept(acceptorSocket_, [&, this](const std::error_code& ec) {
			if( ec ) {
				connectionMadeEvent.set();
				return; // failed to accept client
			}

			auto connection = std::make_shared<Connection>(std::move(acceptorSocket_));
			connection->beginRead();
			
			{
			std::unique_lock<std::mutex> lock(connectionsMutex_);
			connections_.insert(connection);
			}

			if( onConnectionMade_ ) {
				onConnectionMade_(connection);
			}

			// configure disconnect callback
			connection->setOnDisconnect([this, connection](){
				if( onDisconnected_ ) {
					onDisconnected_(connection);
				}
				connections_.erase(connection);
			});

			connectionMadeEvent.set();
		});
		connectionMadeEvent.waitOne();
	}
}