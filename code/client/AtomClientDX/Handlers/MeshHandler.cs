using System;
using System.Collections.Generic;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;

using pbc = global::Google.Protobuf.Collections;

namespace AtomClient.Handlers {
	public class MeshHandler : IHandler {
		public bool handle( GraphicsDevice device, Atom.Proto.AtomMessage msg, atom.Client client, Scene.SceneManager scene ) {
			if( msg.MsgCase != Atom.Proto.AtomMessage.MsgOneofCase.Mesh && msg.MsgCase != Atom.Proto.AtomMessage.MsgOneofCase.MeshPointsChanged && msg.MsgCase != Atom.Proto.AtomMessage.MsgOneofCase.MeshGeometryChanged && msg.MsgCase != Atom.Proto.AtomMessage.MsgOneofCase.MeshMaterialChanged ) {
				return false;
			}

			if( msg.MsgCase == Atom.Proto.AtomMessage.MsgOneofCase.Mesh ) {
				var existing = scene.getShapeByName(msg.Mesh.Name);
				if( null == existing ) {
					var mesh = new Scene.Mesh(msg.Mesh.Name);
					mesh.MaterialName = msg.Mesh.MaterialName;
					mesh.Visible = msg.Mesh.InitialVisibility;

					var verts = new List<CustomVertexFormat>();
					var inds = new List<int>();
					convertGeometry(msg.Mesh.Vertices, msg.Mesh.Indices, ref verts, ref inds);
					mesh.Vertices = verts;
					mesh.Indices = inds;
					mesh.build(device);

					scene.addShape(mesh);
					Log.write(string.Format("Added new mesh: {0}", mesh.Name), OutputVerbosity.Info);
				} else {
					Log.write(string.Format("Tried to add new mesh but the name was already taken: {0}", existing.Name), OutputVerbosity.Error);
				}
			}

			if( msg.MsgCase == Atom.Proto.AtomMessage.MsgOneofCase.MeshPointsChanged ) {
				var existing = scene.getShapeByName(msg.MeshPointsChanged.MeshName);
				if( null == existing ) {
					Log.write(string.Format("Tried updating a mesh but it didn't exist: {0}", msg.MeshPointsChanged.MeshName), OutputVerbosity.Error);
				} else {
					int lastIndex = msg.MeshPointsChanged.Vertices.Count - 1;
					for( int i = 0; i < msg.MeshPointsChanged.Vertices.Count; ++i ) {
						var atomVtx = msg.MeshPointsChanged.Vertices[i];
						var vtx = new CustomVertexFormat();
						if( atomVtx.Position != null ) { vtx.Position = new Vector3(atomVtx.Position.X, atomVtx.Position.Y, atomVtx.Position.Z); }
						if( atomVtx.Normal != null ) { vtx.Normal = new Vector3(atomVtx.Normal.X, atomVtx.Normal.Y, atomVtx.Normal.Z); }
						if( atomVtx.Tangent.Count > 0 ) { vtx.Tangent = new Vector4(atomVtx.Tangent[0].X, atomVtx.Tangent[0].Y, atomVtx.Tangent[0].Z, 1.0f); }
						if( atomVtx.Texcoord.Count > 0 ) { vtx.Texcoord = new Vector2(atomVtx.Texcoord[0].X, -atomVtx.Texcoord[0].Y); }
						(existing as Scene.Mesh).updateVertex(atomVtx.Index, vtx, i == lastIndex);
					}
					Log.write(string.Format("Updated {0} mesh vertices: {1}", msg.MeshPointsChanged.Vertices.Count, existing.Name), OutputVerbosity.Info);
				}
			}

			if( msg.MsgCase == Atom.Proto.AtomMessage.MsgOneofCase.MeshGeometryChanged ) {
				var existing = scene.getShapeByName(msg.MeshGeometryChanged.MeshName);
				if( null == existing ) {
					Log.write(string.Format("Tried to replace mesh but it didn't exist: {0}", msg.MeshGeometryChanged.MeshName), OutputVerbosity.Error);
				} else {
					var newVerts = new List<CustomVertexFormat>();
					var newInds = new List<int>();
					convertGeometry(msg.MeshGeometryChanged.Vertices, msg.MeshGeometryChanged.Indices, ref newVerts, ref newInds);
					(existing as Scene.Mesh).update(device, newVerts, newInds);
					Log.write(string.Format("Replaced mesh: {0}", existing.Name), OutputVerbosity.Info);
				}
			}

			if( msg.MsgCase == Atom.Proto.AtomMessage.MsgOneofCase.MeshMaterialChanged ) {
				var existing = scene.getShapeByName(msg.MeshMaterialChanged.MeshName);
				if( null == existing ) {
					Log.write(string.Format("Tried changing a mesh material but it didn't exist: {0}", msg.MeshMaterialChanged.MeshName), OutputVerbosity.Error);
				} else {
					(existing as Scene.Mesh).MaterialName = msg.MeshMaterialChanged.MaterialName;
					scene.linkMeshMaterials((existing as Scene.Mesh));
					Log.write(string.Format("Updated mesh material: {0}=>{1}", existing.Name, msg.MeshMaterialChanged.MaterialName), OutputVerbosity.Info);
				}
			}

			return true;
		}

		private void convertGeometry( pbc::RepeatedField<Atom.Proto.Vertex> inVerts, pbc::RepeatedField<int> inInds,  ref List<CustomVertexFormat> outVerts, ref List<int> outInds ) {
			foreach( var atomVtx in inVerts ) {
				var vtx = new CustomVertexFormat();
				if( atomVtx.Position != null ) {
					vtx.Position = new Vector3(atomVtx.Position.X, atomVtx.Position.Y, atomVtx.Position.Z);
				}
				if( atomVtx.Normal != null ) {
					vtx.Normal = new Vector3(atomVtx.Normal.X, atomVtx.Normal.Y, atomVtx.Normal.Z);
				}
				if( atomVtx.Tangent.Count > 0 ) {
					vtx.Tangent = new Vector4(atomVtx.Tangent[0].X, atomVtx.Tangent[0].Y, atomVtx.Tangent[0].Z, 1.0f);
				}
				if( atomVtx.Texcoord.Count > 0 ) {
					vtx.Texcoord = new Vector2(atomVtx.Texcoord[0].X, -atomVtx.Texcoord[0].Y);
				}
				//Console.WriteLine("Color sets: {0}", atomVtx.Color.Count);
				//foreach( var atomColor in atomVtx.Color ) {
				//	Console.WriteLine("\tr({0}); g({1}); b({2}); a({3})", atomColor.R, atomColor.G, atomColor.B, atomColor.A);
				//}
				outVerts.Add(vtx);
			}
			foreach( var i in inInds ) {
				outInds.Add(i);
			}
		}
	}
}
