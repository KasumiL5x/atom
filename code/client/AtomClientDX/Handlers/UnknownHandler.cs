using System;
using Microsoft.Xna.Framework.Graphics;

namespace AtomClient.Handlers {
	public class UnknownHandler : IHandler {
		public bool handle( GraphicsDevice device, Atom.Proto.AtomMessage msg, atom.Client client, Scene.SceneManager scene ) {
			if( msg.MsgCase != Atom.Proto.AtomMessage.MsgOneofCase.None ) {
				return false;
			}

			Console.WriteLine("Unknown message received.");
			return true;
		}
	}
}
