using System;
using System.Collections.Generic;
using System.Net.Sockets;

namespace AtomClient.atom {
	public enum TransferStatus {
		Transferring,
		Complete
	}

	public class Client {
		public delegate void OnConnected( string error );
		public event OnConnected Connected;

		public delegate void OnReceived( int bytesTransferred, int totalBytes, TransferStatus status, byte[] data );
		public event OnReceived Received;

		private Socket socket_;
		private bool connected_ = false;
		public bool IsConnected { get { return connected_; } }

		private Queue<Message> writeLog = new Queue<Message>();
		private object WriteLogLock = new object();

		public int TotalMessagesReceived { get; private set; } = 0;
		public bool OutputMessageStats {get;set;} = false;
		public int TotalReceiveTime {get; private set; }=0;
		public int TotalBytesReceived {get;private set;}=0;

		public Client() {
			socket_ = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
		}

		public void connect( string host, int port ) {
			try {
				socket_.BeginConnect(host, port, new AsyncCallback(ConnectCallback), socket_);
			} catch( Exception ex ) {
				Connected?.Invoke(ex.Message); // invoke because it failed and they need to know why
			}
		}

		private void ConnectCallback( IAsyncResult ar ) {
			try { 
				Socket socket = (Socket)ar.AsyncState;
				socket.EndConnect(ar);
				socket.SetSocketOption(SocketOptionLevel.Socket, SocketOptionName.KeepAlive, true);
				connected_ = true;
				Connected?.Invoke("success");
				ReadInternal();
			} catch( Exception ex ) {
				Connected?.Invoke(ex.Message); // still invoke for users to check status
			}
		}

		public void disconnect() {
			if( !connected_) {
				return;
			}

			connected_ = false;
			socket_.Shutdown(SocketShutdown.Both);
			socket_.Close();
		}

		private void ReadInternal() {
			Message msg = new Message();
			socket_.BeginReceive(msg.ReadBuffer, 0, Message.HEADER_SIZE, SocketFlags.None, new AsyncCallback(ReadCallback), msg);
		}

		private void ReadCallback( IAsyncResult ar ) {
			try { 
				Message msg = (Message)ar.AsyncState;
				SocketError error;

				int dataRead = socket_.EndReceive(ar, out error);
				if( error != SocketError.Success ) {
					disconnect();
					return;
				}

				if( dataRead <= 0 ) {
					disconnect();
					return;
				}

				// read size header
				if( !msg.HasReadHeader ) {
					if( Message.HEADER_SIZE == dataRead ) {
						msg.ReadDataSize = BitConverter.ToInt32(msg.ReadBuffer, 0);
						msg.HasReadHeader = true;
						int sizeToRead = Math.Min(Message.BUFFER_SIZE, msg.ReadDataSize);
						msg.StartTime = DateTime.Now.TimeOfDay;
						if( OutputMessageStats ) {
							Console.WriteLine("Started reading Message ({0} bytes)", msg.ReadDataSize);
						}
						socket_.BeginReceive(msg.ReadBuffer, 0, sizeToRead, SocketFlags.None, new AsyncCallback(ReadCallback), msg);
						return;
					} else {
						throw new Exception("Header was not fully received for some reason.");
					}
				}

				// append write buffer and continue reading if necessary
				if( (msg.Data.Length + dataRead) == msg.ReadDataSize ) {
					msg.Data.Write(msg.ReadBuffer, 0, dataRead);
					byte[] copiedData = msg.Data.ToArray();

					TotalMessagesReceived += 1;
					TotalBytesReceived += (msg.ReadDataSize + Message.HEADER_SIZE);
					var deltaTime = DateTime.Now.TimeOfDay - msg.StartTime;
					TotalReceiveTime += deltaTime.Milliseconds;
					if( OutputMessageStats ) {
						Console.WriteLine("Message read in {0} ms ({1} total)", deltaTime.Milliseconds, TotalMessagesReceived);
					}
					Received?.Invoke(copiedData.Length, copiedData.Length, TransferStatus.Complete, copiedData);
					ReadInternal();
				} else {
					Received?.Invoke((int)msg.Data.Length, msg.ReadDataSize, TransferStatus.Transferring, null);
					msg.Data.Write(msg.ReadBuffer, 0, dataRead);
					int sizeToRead = Math.Min(Message.BUFFER_SIZE, msg.ReadDataSize - (int)msg.Data.Length);
					socket_.BeginReceive(msg.ReadBuffer, 0, sizeToRead, SocketFlags.None, new AsyncCallback(ReadCallback), msg);
				}
			} catch( Exception ex ) {
				Console.WriteLine(ex.Message);
				disconnect();
			}
		}

		public void write( Message msg ) {
			lock(WriteLogLock) {
				bool writeInProgress = writeLog.Count != 0;
				writeLog.Enqueue(msg);
				if( !writeInProgress ) {
					WriteInternal();
				}
			}
		}

		private void WriteInternal() {
			Message msg = null;
			lock(WriteLogLock) {
				msg = writeLog.Peek();
			}
			byte[] data = msg.Data.ToArray();
			socket_.BeginSend(data, 0, data.Length, SocketFlags.None, new AsyncCallback(WriteCallback), msg);
		}

		private void WriteCallback( IAsyncResult ar ) {
			Message msg = (Message)ar.AsyncState;
			int sentData = socket_.EndSend(ar);
			msg.BytesSent += sentData;
			if( msg.BytesSent != msg.TotalSize ) {
				socket_.BeginSend(msg.Data.ToArray(), msg.BytesSent, msg.TotalSize - msg.BytesSent, SocketFlags.None, new AsyncCallback(WriteCallback), msg);
			} else {
				lock(WriteLogLock) {
					writeLog.Dequeue();
					if( writeLog.Count != 0 ) {
						WriteInternal();
					}
				}
			}
		}
	}
}
