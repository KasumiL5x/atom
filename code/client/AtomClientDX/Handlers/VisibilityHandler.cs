using System;
using AtomClient.atom;
using Microsoft.Xna.Framework.Graphics;

namespace AtomClient.Handlers {
	public class VisibilityHandler : IHandler {
		public bool handle( GraphicsDevice device, Atom.Proto.AtomMessage msg, Client client, Scene.SceneManager scene ) {
			if( msg.MsgCase != Atom.Proto.AtomMessage.MsgOneofCase.VisibilityChanged ) {
				return false;
			}

			if( scene.updateVisibility(msg.VisibilityChanged.ObjectName, msg.VisibilityChanged.Visible) ) {
				Log.write(string.Format("{0} is now {1}", msg.VisibilityChanged.ObjectName, msg.VisibilityChanged.Visible ? "visible" : "invisible"), OutputVerbosity.Info);
			} else {
				Log.write(string.Format("Tried to set {0} to {1}, but it was not found.", msg.VisibilityChanged.ObjectName, msg.VisibilityChanged.Visible ? "visible" : "invisible"), OutputVerbosity.Error);
			}

			return true;
		}
	}
}
