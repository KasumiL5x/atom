namespace AtomClient.Scene {
	public class Xform : Named {
		public Shape Shape {get;set;}
		public string ShapeName {get;set;}
		public Transform Transform {get;set;} = new Transform();
		public bool Visible {get;set;}=true;

		public Xform( string name ) : base(name) {
		}
	}
}
