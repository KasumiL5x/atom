using System;
using Microsoft.Xna.Framework.Graphics;

namespace AtomClient.Handlers {
	public class NameHandler : IHandler {
		public bool handle( GraphicsDevice device, Atom.Proto.AtomMessage msg, atom.Client client, Scene.SceneManager scene ) {
			if( msg.MsgCase != Atom.Proto.AtomMessage.MsgOneofCase.NameChanged ) {
				return false;
			}

			if( scene.rename(msg.NameChanged.OldName, msg.NameChanged.NewName) ) {
				Log.write(string.Format("Renamed object: {0}=>{1}", msg.NameChanged.OldName, msg.NameChanged.NewName), OutputVerbosity.Info);
			} else {
				Log.write(string.Format("Tried to rename but couldn't find object: {0}=>{1}", msg.NameChanged.OldName, msg.NameChanged.NewName), OutputVerbosity.Error);
			}

			return true;
		}
	}
}
