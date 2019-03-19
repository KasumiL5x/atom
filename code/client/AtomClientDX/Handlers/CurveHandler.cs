using System;
using AtomClient.atom;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;

namespace AtomClient.Handlers {
	public class CurveHandler : IHandler {
		public bool handle( GraphicsDevice device, Atom.Proto.AtomMessage msg, Client client, Scene.SceneManager scene ) {
			if( msg.MsgCase != Atom.Proto.AtomMessage.MsgOneofCase.Curve ) {
				return false;
			}

			//var existing = scene.getCurve(msg.Curve.Name);
			//if( null == existing ) {
			//	var curve = new CurveShape(msg.Curve.Name);
			//	getPoints(curve, msg.Curve);
			//	scene.addCurve(curve);
			//	scene.setVisibility(msg.Curve.Name, msg.Curve.InitialVisibility);
			//	Console.WriteLine("Added new curve: {0}", curve.Name);
			//	debugPrintPoints(curve);
			//} else {
			//	existing.Name = msg.Curve.Name;
			//	getPoints(existing, msg.Curve);
			//	scene.setVisibility(msg.Curve.Name, msg.Curve.InitialVisibility);
			//	Console.WriteLine("Updated curve: {0}", existing.Name);
			//	debugPrintPoints(existing);
			//}

			return true;
		}

		//void getPoints( CurveShape curve, Atom.Proto.Curve protoCurve ) {
		//	curve.Points.Clear();
		//	foreach( var cv in protoCurve.CV ) {
		//		curve.Points.Add(new Vector3(cv.X, cv.Y, cv.Z));
		//	}
		//}

		//void debugPrintPoints( CurveShape curve ) {
		//	Console.WriteLine("Points ({0})", curve.Points.Count);
		//	foreach( var pnt in curve.Points ) {
		//		Console.WriteLine("\t{0}/{1}/{2}", pnt.X, pnt.Y, pnt.Z);
		//	}
		//}
	}
}
