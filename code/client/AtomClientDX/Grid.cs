using System.Collections.Generic;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework;
using System;
using Microsoft.Xna.Framework.Content;

namespace AtomClient {
	public class Grid {
		private List<VertexPositionColor> vertices_ = new List<VertexPositionColor>();
		private VertexBuffer vertexBuffer_;
		private Effect effect_;
		public Color AxisColor { get; set; }
		public Color BorderColor { get; set; }
		public Color GridColor { get; set; }
		public Color MajorColor { get; set; }
		public float GridSpacing { get; set; }
		public int GridExtents { get; set; }
		public int MajorSpacing { get; set; }

		public Grid() {
		}

		public void create( GraphicsDevice device, ContentManager content ) {
			// create vertex list
			float ext = (float)GridExtents * GridSpacing;
			for( int i = -GridExtents; i <= GridExtents; ++i ) {
				float pos = (float)i * GridSpacing;

				// line 0
				VertexPositionColor v0 = new VertexPositionColor(new Vector3(pos, 0.0f, -ext), GridColor);
				VertexPositionColor v1 = new VertexPositionColor(new Vector3(pos, 0.0f,ext), GridColor);
				// line 1
				VertexPositionColor v2 = new VertexPositionColor(new Vector3(-ext, 0.0f, pos), GridColor);
				VertexPositionColor v3 = new VertexPositionColor(new Vector3(ext, 0.0f, pos), GridColor);

				// coloring
				if( 0 == i ) {
					v0.Color = v1.Color = v2.Color = v3.Color = AxisColor;
				} else if( -GridExtents == i || GridExtents == i ) {
					v0.Color = v1.Color = v2.Color = v3.Color = BorderColor;
				} else if( 0 == Math.Abs(i) % MajorSpacing ) {
					v0.Color = v1.Color = v2.Color = v3.Color = MajorColor;
				}

				vertices_.Add(v0);
				vertices_.Add(v1);
				vertices_.Add(v2);
				vertices_.Add(v3);
			}

			// create buffers
			vertexBuffer_ = new VertexBuffer(device, typeof(VertexPositionColor), vertices_.Count, BufferUsage.WriteOnly);
			vertexBuffer_.SetData<VertexPositionColor>(vertices_.ToArray());

			// create effect
			effect_ = content.Load<Effect>("shaders/Grid");
		}

		public void draw( GraphicsDevice device, Matrix view, Matrix proj ) {
			effect_.Parameters["Xform"].SetValue(view * proj * Matrix.Identity);

			device.SetVertexBuffer(vertexBuffer_);
			device.Indices = null;

			effect_.Techniques[0].Passes[0].Apply();
			device.DrawPrimitives(PrimitiveType.LineList, 0, vertices_.Count);
		}
	}
}
