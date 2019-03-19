using Microsoft.Xna.Framework;

namespace AtomClient.cameras {
	public class Camera {
		protected Matrix view_ = Matrix.Identity;
		protected bool viewDirty_ = true;
		protected Vector3 position_ = Vector3.Zero;
		protected Vector3 target_ = Vector3.Zero;
		protected Vector3 up_ = Vector3.Up;
		//
		protected Matrix proj_ = Matrix.Identity;
		protected bool projDirty_ = true;
		protected float fov_ = 0.872664626f; // 50 degrees in radians
		protected float aspect_ = 1.0f;
		protected float nearPlane_ = 0.1f;
		protected float farPlane_ = 1000.0f;
		//
		private CameraController controller_ = null;

		public Camera() {
		}

		public void update( float deltaTime, float elapsedTime ) {
			controller_?.update(deltaTime, elapsedTime);
		}

		public void setController( CameraController controller ) {
			controller_ = controller;
			controller_.onSet();
		}

		public Matrix getView() {
			if( viewDirty_ ) {
				if( controller_ != null && controller_.OverrideView ) {
					view_ = controller_.rebuildView();
				} else {
					rebuildView();
				}
				viewDirty_ = false;
			}
			return view_;
		}

		public Vector3 getPosition() {
			return position_;
		}

		public Vector3 getTarget() {
			return target_;
		}

		public Vector3 getUp() {
			return up_;
		}

		public void setPosition( Vector3 val ) {
			position_ = val;
			viewDirty_ = true;
		}

		public void setTarget( Vector3 val ) {
			target_ = val;
			viewDirty_ = true;
		}

		public void setUp( Vector3 val ) {
			up_ = val;
			viewDirty_ = true;
		}

		public Matrix getProj() {
			if( projDirty_ ) {
				rebuildProj();
				projDirty_ = false;
			}
			return proj_;
		}

		public float getFov() {
			return fov_;
		}

		public float getAspect() {
			return aspect_;
		}

		public float getNearPlane() {
			return nearPlane_;
		}

		public float getFarPlane() {
			return farPlane_;
		}

		public void setFov( float val ) {
			fov_ = val;
			projDirty_ = true;
		}

		public void setAspect( float val ) {
			aspect_ = val;
			projDirty_ = true;
		}
		
		public void setPlanes( float near, float far ) {
			nearPlane_ = near;
			farPlane_ = far;
			projDirty_ = true;
		}

		public Vector3 getForward() {
			if( controller_ != null && controller_.OverrideForward ) {
				return controller_.getForward();
			} else {
				Vector3 forward = target_ - position_;
				forward.Normalize();
				return forward;
			}
		}

		protected void rebuildView() {
			view_ = Matrix.CreateLookAt(position_, target_, up_);
		}

		protected void rebuildProj() {
			proj_ = Matrix.CreatePerspectiveFieldOfView(fov_, aspect_, nearPlane_, farPlane_);
		}

		public void setViewDirty() {
			viewDirty_ = true;
		}

		public void setProjDirty() {
			projDirty_ = true;
		}
	}
}
