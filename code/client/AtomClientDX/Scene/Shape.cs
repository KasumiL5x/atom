namespace AtomClient.Scene {
	public class Shape : Named {
		public bool Visible {get;set;}=true;
		public ShapeType Type {get;set;}
		public Transform Transform {get;set;} = new Transform();

		public Shape( string name, ShapeType type ) : base(name) {
			Type = type;
		}
	}
}
