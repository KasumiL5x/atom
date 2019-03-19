using System;
using AtomClient.atom;
using Microsoft.Xna.Framework.Graphics;

namespace AtomClient.Handlers {
	public class MatrixChangedHandler : IHandler {
		public bool handle( GraphicsDevice device, Atom.Proto.AtomMessage msg, Client client, Scene.SceneManager scene ) {
			if( msg.MsgCase != Atom.Proto.AtomMessage.MsgOneofCase.MatrixChanged ) {
				return false;
			}

			if( scene.updateMatrix(msg.MatrixChanged.ObjectName, ProtoHelper.matrixFromProto(msg.MatrixChanged.Matrix)) ) {
				Log.write(string.Format("Updated {0}'s matrix", msg.MatrixChanged.ObjectName), OutputVerbosity.Info);
			} else {
				Log.write(string.Format("WARNING: Tried to set matrix but object didn't exist ({0})", msg.MatrixChanged.ObjectName), OutputVerbosity.Error);
			}

			return true;
		}
	}
}
