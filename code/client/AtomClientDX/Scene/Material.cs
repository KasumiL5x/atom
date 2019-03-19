using Microsoft.Xna.Framework;

namespace AtomClient.Scene {
	public class Material : Named {
		public Vector3 DiffuseColor { get; set; }
		public Texture DiffuseTexture {get;set;}
		public string DiffuseTextureName {get;set;}
		public float DiffuseAmount { get; set; }
		public Vector3 AmbientColor { get; set; }
		public Texture BumpTexture {get;set;}
		public string BumpTextureName {get;set;}
		public Vector3 SpecularColor { get; set; }
		public float SpecularPower { get; set; }

		public Material( string name ) : base(name) {
		}
	}
}
