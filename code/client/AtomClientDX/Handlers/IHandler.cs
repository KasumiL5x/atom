using Microsoft.Xna.Framework.Graphics;

namespace AtomClient.Handlers {
	interface IHandler {
		bool handle( GraphicsDevice device, Atom.Proto.AtomMessage msg, atom.Client client, Scene.SceneManager scene );
	}
}
