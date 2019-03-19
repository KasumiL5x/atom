using Microsoft.Xna.Framework;

namespace AtomClient.cameras {
	public class CameraController {
		protected Camera camera_ = null;
		public bool OverrideView {get;set;} = false;
		public bool OverrideForward {get;set;} = false;

		public CameraController( Camera cam ) {
			camera_ = cam;
		}

		public virtual void onSet() {
		}

		public virtual void update( float deltaTime, float elapsedTime ) {
		}

		public virtual Matrix rebuildView() {
			return Matrix.Identity;
		}

		public virtual Vector3 getForward() {
			return Vector3.Forward;
		}
	}
}
