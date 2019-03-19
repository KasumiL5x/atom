using System;
using System.Runtime.InteropServices;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;

namespace AtomClient {
  [StructLayout(LayoutKind.Sequential, Pack = 1)]
	public struct CustomVertexFormat : IVertexType {
		public Vector3 Position;
		public Vector3 Normal;
		public Vector4 Tangent;
		public Vector2 Texcoord;

		public CustomVertexFormat( Vector3 pos, Vector3 nrm, Vector2 tex ) {
			Position = pos;
			Normal = nrm;
			Tangent = Vector4.Zero;
			Texcoord = tex;
		}

		public CustomVertexFormat( Vector3 pos, Vector3 nrm, Vector4 tan, Vector2 tex ) {
			Position = pos;
			Normal = nrm;
			Tangent = tan;
			Texcoord = tex;
		}

		public readonly static VertexDeclaration VertexDeclaration = new VertexDeclaration(
			new VertexElement(0, VertexElementFormat.Vector3, VertexElementUsage.Position, 0),
			new VertexElement(12, VertexElementFormat.Vector3, VertexElementUsage.Normal, 0),
			new VertexElement(24, VertexElementFormat.Vector4, VertexElementUsage.Tangent, 0),
			new VertexElement(40, VertexElementFormat.Vector2, VertexElementUsage.TextureCoordinate, 0)
		);

		VertexDeclaration IVertexType.VertexDeclaration {
			get { return VertexDeclaration; }
		}
	}
}
