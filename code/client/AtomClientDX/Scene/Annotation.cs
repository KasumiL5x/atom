namespace AtomClient.Scene {
	public class Annotation : Shape {
		public string Text {get;set;}

		public Annotation( string name ) : base(name, ShapeType.Annotation) {
		}
	}
}
