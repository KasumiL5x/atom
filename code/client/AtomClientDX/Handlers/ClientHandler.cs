using System;
using System.Collections.Generic;
using Microsoft.Xna.Framework.Graphics;

namespace AtomClient {
	namespace Handlers {
		public class ClientHandler {
			atom.Client client_ = null;
			List<IHandler> handlers_ = new List<IHandler>();
			GraphicsDevice device_ = null;
			Scene.SceneManager scene_ = null;

			public ClientHandler( GraphicsDevice device, atom.Client client, Scene.SceneManager scene ) {
				device_ = device;
				client_ = client;
				scene_ = scene;

				handlers_.Add(new UnknownHandler());
				handlers_.Add(new DbgMsgHandler());
				handlers_.Add(new SceneHandler());
				handlers_.Add(new MeshHandler());
				handlers_.Add(new CameraHandler());
				handlers_.Add(new LightHandler());
				handlers_.Add(new MaterialHandler());
				handlers_.Add(new TextureHandler());
				handlers_.Add(new NameHandler());
				handlers_.Add(new ObjectHandler());
				handlers_.Add(new AnnotationHandler());
				handlers_.Add(new CurveHandler());
				handlers_.Add(new MatrixChangedHandler());
				handlers_.Add(new VisibilityHandler());

				client_.Received += ReceiveHandler;
			}

			private void ReceiveHandler( int bytesTransferred, int totalBytes, atom.TransferStatus status, byte[] data ) {
				//double percent = Math.Round(((double)bytesTransferred/(double)totalBytes)*100.0, 2);
				//Console.WriteLine("Transferring: {0}%", percent);

				if( status == atom.TransferStatus.Complete) {
					lock( Globals.LOCK_OBJ ) {
						Atom.Proto.AtomMessage msg = Atom.Proto.AtomMessage.Parser.ParseFrom(data);
						bool handled = false;
						foreach( var handler in handlers_ ) {
							if( handler.handle(device_, msg, client_, scene_) ) {
								handled = true;
								break;
							}
						}
						if( !handled ) {
							Console.WriteLine("Failed to handle message.");
						}
					}
				}
			}
		}
	}
}
