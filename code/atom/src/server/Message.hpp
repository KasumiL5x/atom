#ifndef __atom_Message__
#define __atom_Message__

#include <memory>
#include <array>
#include "../Utils.hpp"

namespace atom {

class Message {
private:
	enum class MessageType {
		Outgoing,
		Incoming
	};

public:
	const static int32_t HEADER_SIZE = sizeof(int32_t); /**< Size of data-prefixed header. */
	const static int32_t BUFFER_SIZE = 1024; /**< Size of incoming buffer in bytes. */

private:
	Message();
	Message( const Message& )=delete;
	const Message& operator=( const Message& )=delete;
public:
	~Message();

	static std::shared_ptr<Message> createOutgoing( const void* userData, const int32_t sizeInBytes );
	static std::shared_ptr<Message> createIncoming();

	/* [OUT]: Data to send (header+data).  [IN]: Data received (data w/o header). */
	const std::unique_ptr<unsigned char[]>& data() const;
	/* [OUT]: Gets the size of the data to send.  [IN]: Gets the size of the data to receive. */
	int32_t dataSize() const;
	/* [OUT/IN]: Gets the size of the data to send/receive including the header. */
	int32_t totalSize() const;
	/* [OUT]: Unused.  [IN]: Gets the temporary read buffer of size BUFFER_SIZE. */
	std::array<unsigned char, Message::BUFFER_SIZE>& readBuffer();
	/* [OUT]: Unused.  [IN]: Gets if the header has been read yet. */
	bool hasReadHeader() const;
	/* [OUT]: DON'T call it.  [IN]: Sets the data size and allocates the data accordingly. */
	void setDataSize( int32_t val );
	/* [OUT]: Gets how many bytes have been written.  [IN]: Gets how many bytes have been read. */
	int32_t bytesProcessed() const;
	/* [OUT]: Sets the amount of bytes that have been written.  [IN]: Sets the amount of bytes that have been read. */
	void setBytesProcessed( int32_t amount );
	
private:
	std::unique_ptr<unsigned char[]> data_;
	int32_t dataSize_;
	std::array<unsigned char, Message::BUFFER_SIZE> readBuffer_;
	bool hasReadHeader_;
	int32_t bytesProcessed_;
	MessageType type_;
};

}

#endif
