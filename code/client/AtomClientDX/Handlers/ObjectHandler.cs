using System;
using Microsoft.Xna.Framework.Graphics;

namespace AtomClient.Handlers {
	public class ObjectHandler : IHandler {
		public bool handle( GraphicsDevice device, Atom.Proto.AtomMessage msg, atom.Client client, Scene.SceneManager scene ) {
			if( msg.MsgCase != Atom.Proto.AtomMessage.MsgOneofCase.Transform ) {
				return false;
			}

			if( msg.Transform.Components.Count == 0 ) {
				return true; // ignore Objects with no components
			}

			var existing = scene.getXformByName(msg.Transform.Name);
			if( null == existing ) {
				var xform = new Scene.Xform(msg.Transform.Name);
				xform.Transform.World = ProtoHelper.matrixFromProto(msg.Transform.World);
				xform.Visible = msg.Transform.InitialVisibility;
				xform.ShapeName = msg.Transform.Components[0].Name;

				scene.addXform(xform);
				Log.write(string.Format("Added new transform: {0}=>{1}", msg.Transform.Name, msg.Transform.Components[0].Name), OutputVerbosity.Info);
			} else {
				existing.Transform.World = ProtoHelper.matrixFromProto(msg.Transform.World);
				existing.Visible = msg.Transform.InitialVisibility;
				Log.write(string.Format("Updated existing transform: {0}", existing.Name), OutputVerbosity.Info);
			}

			return true;
		}
	}
}
