using System.IO;
using Microsoft.Xna.Framework.Graphics;

namespace AtomClient.Scene {
	public class Texture : Named {
		public Texture2D Tex {get; private set;}

		public Texture( string name ) : base(name) {
		}

		public void loadFromBytes( GraphicsDevice device, byte[] data ) {
			try {
				Tex = null;
				Tex = Texture2D.FromStream(device, new MemoryStream(data));
			} catch {
			}
		}

		public void loadFromFile( GraphicsDevice device, string file ) {
			try { 
			using( var fs = new FileStream(file, FileMode.Open) ) {				
				Tex = null;
				Tex = Texture2D.FromStream(device, fs);
			}
			} catch {
			}
		}
	}
}
