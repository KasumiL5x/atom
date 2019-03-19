using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;

namespace AtomClient.Renderer {
	public class FullscreenQuad {
		VertexBuffer vertexBuffer_;
		IndexBuffer indexBuffer_;

		public FullscreenQuad( GraphicsDevice device ) {
			// fill vertex buffer
			VertexPositionTexture[] verts = {
				new VertexPositionTexture(new Vector3(1, -1, 0), new Vector2(1, 1)),
				new VertexPositionTexture(new Vector3(-1, -1, 0), new Vector2(0, 1)),
				new VertexPositionTexture(new Vector3(-1, 1, 0), new Vector2(0, 0)),
				new VertexPositionTexture(new Vector3(1, 1, 0), new Vector2(1, 0))
			};
			vertexBuffer_ = new VertexBuffer(device, VertexPositionTexture.VertexDeclaration, verts.Length, BufferUsage.None);
			vertexBuffer_.SetData<VertexPositionTexture>(verts);

			// fill index buffer
			ushort[] inds = {0, 1, 2, 2, 3, 0 };
			indexBuffer_ = new IndexBuffer(device, IndexElementSize.SixteenBits, inds.Length, BufferUsage.None);
			indexBuffer_.SetData<ushort>(inds);
		}

		public void justSet( GraphicsDevice device ) {
			device.SetVertexBuffer(vertexBuffer_);
			device.Indices = indexBuffer_;
		}

		public void justDraw( GraphicsDevice device ) {
			device.DrawIndexedPrimitives(PrimitiveType.TriangleList, 0, 0, 4, 0, 2);
		}

		public void setAndDraw( GraphicsDevice device ) {
			device.SetVertexBuffer(vertexBuffer_);
			device.Indices = indexBuffer_;
			device.DrawIndexedPrimitives(PrimitiveType.TriangleList, 0, 0, 4, 0, 2);
		}
	}
}
