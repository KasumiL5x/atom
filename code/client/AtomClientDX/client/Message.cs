using System;
using System.IO;

namespace AtomClient.atom {
	public class Message {
		public const int HEADER_SIZE = sizeof(Int32);
		public bool HasReadHeader { get;set; }
		public const int BUFFER_SIZE = 1024;
		public byte[] ReadBuffer { get; } = new byte[BUFFER_SIZE];
		public int ReadDataSize { get; set; }
		public MemoryStream Data { get; } = new MemoryStream();

		public int BytesSent { get; set; }
		public Int32 Size { get; }
		public Int32 TotalSize { get { return Size + HEADER_SIZE; } }

		public TimeSpan StartTime;

		public Message() {
		}

		public Message( byte[] userData, Int32 userDataSize ) {
			Data = new MemoryStream();
			Size = userDataSize;

			// encode header and copy user data
			byte[] header = BitConverter.GetBytes(userDataSize);
			Data.Write(header, 0, HEADER_SIZE);
			Data.Write(userData, 0, userDataSize);
		}
	}
}
