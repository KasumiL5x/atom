#ifndef __ResetEvent__
#define __ResetEvent__

#include <mutex>
#include <atomic>
#include <condition_variable>

namespace atom {

class ManualResetEvent {
public:
	ManualResetEvent()
		: signaled_(false) {
	}
	ManualResetEvent( const ManualResetEvent& rhs )=delete;

	void waitOne() {
		std::unique_lock<std::mutex> lock(sync_);
		while( !signaled_ ) {
			cv_.wait(lock);
		}
	}

	void set() {
		std::unique_lock<std::mutex> lock(sync_);
		signaled_ = true;
		cv_.notify_all();
	}

	void reset() {
		std::unique_lock<std::mutex> lock(sync_);
		signaled_ = false;
	}

private:
	std::condition_variable cv_;
	std::mutex sync_;
	std::atomic<bool> signaled_;
};

}

#endif