using System;
using System.Text;
using Microsoft.Xna.Framework.Graphics;

namespace AtomClient.Handlers {
	public class SceneHandler : IHandler {
		public bool handle( GraphicsDevice device, Atom.Proto.AtomMessage msg, atom.Client client, Scene.SceneManager scene ) {
			if( msg.MsgCase != Atom.Proto.AtomMessage.MsgOneofCase.Scene ) {
				return false;
			}

			switch( msg.Scene.TransferReason ) {
				case Atom.Proto.Scene.Types.Reason.kRebuildOnConnected: {
						processFullScene(msg.Scene, client);
						break;
					}
				case Atom.Proto.Scene.Types.Reason.kRebuildOnNew: {
						scene.reset();
						break;
					}
				case Atom.Proto.Scene.Types.Reason.kRebuildOnOpen: {
						scene.reset();
						processFullScene(msg.Scene, client);
						break;
					}
				case Atom.Proto.Scene.Types.Reason.kAdded: {
						processFullScene(msg.Scene, client);
						break;
					}
				case Atom.Proto.Scene.Types.Reason.kRemoved: {
						foreach( var obj in msg.Scene.Transforms ) {
							scene.removeXform(obj.Name);
							Log.write(string.Format("Removed Object: {0}", obj.Name), OutputVerbosity.Info);
						}
						foreach( var mesh in msg.Scene.Meshes ) {
							scene.removeShape(mesh.Name);
							Log.write(string.Format("Removed Mesh: {0}", mesh.Name), OutputVerbosity.Info);
						}
						foreach( var light in msg.Scene.Lights ) {
							scene.removeShape(light.Name);
							Log.write(string.Format("Removed Light: {0}", light.Name), OutputVerbosity.Info);
						}
						foreach( var mat in msg.Scene.Materials ) {
							scene.removeMaterial(mat.Name);
							Log.write(string.Format("Removed Material: {0}", mat.Name), OutputVerbosity.Info);
						}
						foreach( var tex in msg.Scene.Textures ) {
							scene.removeTexture(tex.Name);
							Log.write(string.Format("Removed Texture: {0}", tex.Name), OutputVerbosity.Info);
						}
						foreach( var ann in msg.Scene.Annotations ) {
							scene.removeShape(ann.Name);
							Log.write(string.Format("Removed Annotation: {0}", ann.Name), OutputVerbosity.Info);
						}
						break;
					}
			}

			return true;
		}

		void processFullScene( Atom.Proto.Scene scene, atom.Client client ) {
			// watch all objects
			foreach( var obj in scene.Transforms ) {
				var bytes = Encoding.ASCII.GetBytes("watch " + obj.Name + ";");
				client.write(new atom.Message(bytes, bytes.Length));
			}

			// watch all meshes
			foreach( var mesh in scene.Meshes ) {
				var bytes = Encoding.ASCII.GetBytes("watch " + mesh.Name + ";");
				client.write(new atom.Message(bytes, bytes.Length));
			}

			// watch all lights
			foreach( var light in scene.Lights ) {
				var bytes = Encoding.ASCII.GetBytes("watch " + light.Name + ";");
				client.write(new atom.Message(bytes, bytes.Length));
			}

			// watch the first camera
			if( scene.Cameras.Count > 0 ) {
				var bytes = Encoding.ASCII.GetBytes("watch " + scene.Cameras[0].Name + ";");
				client.write(new atom.Message(bytes, bytes.Length));
			}

			// watch all materials
			foreach( var mat in scene.Materials ) {
				var bytes = Encoding.ASCII.GetBytes("watch " + mat.Name + ";");
				client.write(new atom.Message(bytes, bytes.Length));
			}

			// watch all textures
			foreach( var tex in scene.Textures ) {
				var bytes = Encoding.ASCII.GetBytes("watch " + tex.Name + ";");
				client.write(new atom.Message(bytes, bytes.Length));
			}

			// watch all annotations
			foreach( var annot in scene.Annotations ) {
				var bytes = Encoding.ASCII.GetBytes("watch " + annot.Name + ";");
				client.write(new atom.Message(bytes, bytes.Length));
			}

			// watch all curves
			foreach( var curve in scene.Curves ) {
				var bytes = Encoding.ASCII.GetBytes("watch " + curve.Name + ";");
				client.write(new atom.Message(bytes, bytes.Length));
			}
		}
	}
}
