using Microsoft.Xna.Framework;

namespace AtomClient.cameras {
	public class MayaCameraController : CameraController {
		public MayaCameraController( Camera cam ) : base(cam) {
		}

		public override void onSet() {
			base.onSet();
		}

		public override void update( float deltaTime, float elapsedTime ) {
			base.update(deltaTime, elapsedTime);
		}

		public void setPosition( Vector3 value ) {
			camera_.setPosition(value);
			camera_.setViewDirty();
		}

		public void setTarget( Vector3 value ) {
			camera_.setTarget(value);
			camera_.setViewDirty();
		}

		public void setUp( Vector3 value ) {
			camera_.setUp(value);
			camera_.setViewDirty();
		}

		public void setFov( float value ) {
			camera_.setFov(value);
			camera_.setProjDirty();
		}

		public void setPlanes( float near, float far ) {
			camera_.setPlanes(near, far);
			camera_.setProjDirty();
		}
	}
}
