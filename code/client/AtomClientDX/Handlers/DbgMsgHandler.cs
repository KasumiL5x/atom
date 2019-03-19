using System;
using Microsoft.Xna.Framework.Graphics;

namespace AtomClient.Handlers {
	public class DbgMsgHandler : IHandler {
		public bool handle( GraphicsDevice device, Atom.Proto.AtomMessage msg, atom.Client client, Scene.SceneManager scene ) {
			if( msg.MsgCase != Atom.Proto.AtomMessage.MsgOneofCase.DebugMessage ) {
				return false;
			}

			Console.WriteLine("Debug message: {0}", msg.DebugMessage);
			return true;
		}
	}
}
