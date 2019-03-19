using System;
using AtomClient.atom;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;

namespace AtomClient.Handlers {
	public class CameraHandler : IHandler {
		private AtomClient.cameras.MayaCameraController controller = null;

		public bool handle( GraphicsDevice device, Atom.Proto.AtomMessage msg, atom.Client client, Scene.SceneManager scene ) {
			if( msg.MsgCase != Atom.Proto.AtomMessage.MsgOneofCase.Camera ) {
				return false;
			}

			if( null == controller ) {
				controller = new cameras.MayaCameraController(Globals.DEFAULT_CAMERA);
			}

			if( Globals.CAMERA_FOLLOWS_MAYA ) {
				Globals.DEFAULT_CAMERA.setController(controller);
				Vector3 position = new Vector3(msg.Camera.Position.X, msg.Camera.Position.Y, msg.Camera.Position.Z);
				Vector3 target = new Vector3(msg.Camera.Target.X, msg.Camera.Target.Y, msg.Camera.Target.Z);
				Vector3 up = new Vector3(msg.Camera.Up.X, msg.Camera.Up.Y, msg.Camera.Up.Z);
				controller.setPosition(position);
				controller.setTarget(target);
				controller.setUp(up);
				controller.setFov(msg.Camera.FieldOfView);
				controller.setPlanes(msg.Camera.NearPlane, msg.Camera.FarPlane);
			}

			return true;
		}
	}
}
