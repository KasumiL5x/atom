using System;
using System.Collections.Generic;
using Microsoft.Xna.Framework.Graphics;

namespace AtomClient.Scene {
	public class Mesh : Shape  {
		private List<CustomVertexFormat> vertices_ = new List<CustomVertexFormat>();
		private List<int> indices_ = new List<int>();
		public Material Material {get; set;}
		public string MaterialName {get; set;}

		public List<CustomVertexFormat> Vertices {
			get { return vertices_; }
			set { vertices_ = value; }
		}
		public List<int> Indices {
			get { return indices_; }
			set { indices_ = value; }
		}

		public VertexBuffer VertexBuffer {get; private set; }
		public IndexBuffer IndexBuffer {get; private set; }

		public Mesh( string name ) : base(name, ShapeType.Mesh) {
		}

		public void addVertex( CustomVertexFormat vtx ) {
			vertices_.Add(vtx);
		}

		public void addIndex( int idx ) {
			indices_.Add(idx);
		}

		public void updateVertex( int index, CustomVertexFormat vtx, bool updateBuffer ) {
			if( index < 0 || index >= vertices_.Count ) {
				return;
			}
			vertices_[index] = vtx;
			if( updateBuffer ) {
				VertexBuffer.SetData<CustomVertexFormat>(vertices_.ToArray());
			}
		}

		public void updateIndex( int index, int idx, bool updateBuffer ) {
			if( index < 0 || index >= indices_.Count ) {
				return;
			}
			indices_[index] = idx;
			if( updateBuffer ) {
				IndexBuffer.SetData<int>(indices_.ToArray());
			}
		}

		public void clear() {
			vertices_ = new List<CustomVertexFormat>();
			indices_ = new List<int>();
			VertexBuffer = null;
			IndexBuffer = null;
		}

		public void build( GraphicsDevice device ) {
			VertexBuffer = new VertexBuffer(device, typeof(CustomVertexFormat), vertices_.Count, BufferUsage.WriteOnly);
			VertexBuffer.SetData<CustomVertexFormat>(vertices_.ToArray());

			IndexBuffer = new IndexBuffer(device, typeof(int), indices_.Count, BufferUsage.WriteOnly);
			IndexBuffer.SetData<int>(indices_.ToArray());
		}

		public void update( GraphicsDevice device, List<CustomVertexFormat> newVertices, List<int> newIndices ) {
			if( 0==newVertices.Count || 0==newIndices.Count ) {
				throw new Exception("newVertices or newIndices was wrong.");
			}

			if( newVertices.Count != vertices_.Count ) {
				VertexBuffer = new VertexBuffer(device, typeof(CustomVertexFormat), newVertices.Count, BufferUsage.WriteOnly);
			}
			vertices_ = newVertices;
			VertexBuffer.SetData<CustomVertexFormat>(vertices_.ToArray());

			if( newIndices.Count != indices_.Count ) {
				IndexBuffer = new IndexBuffer(device, typeof(int), newIndices.Count, BufferUsage.WriteOnly);
			}
			indices_ = newIndices;
			IndexBuffer.SetData<int>(indices_.ToArray());
		}
	}
}
