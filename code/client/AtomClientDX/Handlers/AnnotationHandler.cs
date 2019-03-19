using System;
using AtomClient.atom;
using Microsoft.Xna.Framework.Graphics;

namespace AtomClient.Handlers {
	public class AnnotationHandler : IHandler {
		public bool handle( GraphicsDevice device, Atom.Proto.AtomMessage msg, Client client, Scene.SceneManager scene ) {
			if( msg.MsgCase != Atom.Proto.AtomMessage.MsgOneofCase.Annotation ) {
				return false;
			}
			
			var existing = scene.getShapeByName(msg.Annotation.Name);
			if( null == existing ) {
				var annotation = new Scene.Annotation(msg.Annotation.Name);
				annotation.Text = msg.Annotation.Text;
				annotation.Visible = msg.Annotation.InitialVisibility;
				scene.addShape(annotation);
				Log.write(string.Format("Added new annotation: {0}", annotation.Name), OutputVerbosity.Info);
			} else {
				(existing as Scene.Annotation).Text = msg.Annotation.Text;
				Log.write(string.Format("Updated annotation: {0}", existing.Name), OutputVerbosity.Info);
			}

			return true;
		}
	}
}
