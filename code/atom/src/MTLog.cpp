#include "MTLog.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <maya/MGlobal.h>

MTLog::MTLog() {
	_thread = std::thread{&MTLog::processEntries, this};
	_thread.detach(); // not sure; stops debug error upon exit
}

MTLog* MTLog::instance() {
	static MTLog inst;
	return &inst;
}

void MTLog::log( const std::string& entry, bool timePrefix, Destination destination ) {
	std::unique_lock<std::mutex> lock(_mutex);
	_queue.push(Message(timePrefix ? getTimeString() + entry : entry, destination));
	_condVar.notify_all();
}

void MTLog::processEntries() {
	std::unique_lock<std::mutex> lock(_mutex);
	while( true ) {
		_condVar.wait(lock); // waits for non-empty queue due to break below
		lock.unlock();
		while( true ) {
			lock.lock();
			if( _queue.empty() ) {
				break; // finished with queue, break to wait for data in queue with cond var
			} else {
				// output
				const Message& msg = _queue.front();
				switch( msg.destination ) {
					case Destination::Maya: {
						MGlobal::displayInfo(msg.message.c_str());
						break;
					}
					case Destination::Std: {
						fprintf(stdout, msg.message.c_str());
						fflush(stdout);
						break;
					}
				}
				_queue.pop();
			}
			lock.unlock();
		}
	}
}

std::string MTLog::getTimeString() const {
	const auto t = std::time(nullptr);
	const auto tm = *std::localtime(&t);
	std::ostringstream oss;
	oss << std::put_time(&tm, "[%H:%M:%S]: ");
	return oss.str();
}