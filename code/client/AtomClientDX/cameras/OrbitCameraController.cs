using Microsoft.Xna.Framework;

namespace AtomClient.cameras {
	public class OrbitCameraController : CameraController {
		float yaw_ = 0.0f;
		float pitch_ = 0.0f;
		float offset_ = 0.0f;
		float minOffset_ = 1.0f;
		float lerpStrength_ = 0.5f;
		float rotateStrength_ = 1.0f;
		float dollyStrength_ = 1.0f;
		float panStrength_ = 1.0f;
		Input input_;

		public OrbitCameraController( Camera cam, Input input ) : base(cam) {
			yaw_ = 0.7f;
			pitch_ = -0.5f;
			offset_ = 20.0f;
			rotateStrength_ = 1.0f;
			dollyStrength_ = 10.0f;
			panStrength_ = 1.0f;
			lerpStrength_ = 1.0f;

			input_ = input;
		}

		public override void onSet() {
			camera_.setUp(Vector3.Up);
			Matrix rotation = Matrix.CreateRotationX(pitch_) * Matrix.CreateRotationY(yaw_);
			Vector4 transformedForward = Vector4.Transform(new Vector4(0.0f, 0.0f, 1.0f, 0.0f), rotation);
			Vector3 forward = new Vector3(transformedForward.X, transformedForward.Y, transformedForward.Z);
			forward.Normalize();
			forward *= offset_;
			Vector3 desiredPosition = camera_.getTarget() + forward;
			camera_.setPosition(desiredPosition);

			base.onSet();
		}

		public override void update( float deltaTime, float elapsedTime ) {
			if( input_.isButtonDown(Input.MouseButton.Left) ) {
				float dx = (float)input_.deltaX();
				float dy = (float)input_.deltaY();
				rotateYaw(-dx * deltaTime);
				rotatePitch(-dy * deltaTime);
			}
			if( input_.isButtonDown(Input.MouseButton.Right) ) {
				float dy = (float)input_.deltaY();
				dolly(dy * deltaTime);
			}
			int scrollDelta = input_.deltaScroll();
			if( scrollDelta != 0 ) {
				float scrollValue = (float)scrollDelta * 0.1f;
				dolly(-scrollValue * deltaTime);
			}
			if( input_.isButtonDown(Input.MouseButton.Middle) ) {
				float dx = (float)input_.deltaX();
				float dy = (float)input_.deltaY();
				pan(dx * deltaTime, -dy * deltaTime);
			}

			Matrix rotation = Matrix.CreateRotationX(pitch_) * Matrix.CreateRotationY(yaw_);
			Vector4 transformedForward = Vector4.Transform(new Vector4(0.0f, 0.0f, 1.0f, 0.0f), rotation);
			Vector3 forward = new Vector3(transformedForward.X, transformedForward.Y, transformedForward.Z);
			forward.Normalize();
			forward *= offset_;
			Vector3 desiredPosition = camera_.getTarget() + forward;
			camera_.setPosition(Vector3.Lerp(camera_.getPosition(), desiredPosition, lerpStrength_));
			camera_.setViewDirty();

			base.update(deltaTime, elapsedTime);
		}

		void rotateYaw( float angle ) {
			yaw_ += angle * rotateStrength_;
			yaw_ = wrapAngle(yaw_, 0.0f, MathHelper.ToRadians(360.0f));
			camera_.setViewDirty();
		}

		void rotatePitch( float angle ) {
			pitch_ += angle * rotateStrength_;
			pitch_ = clamp(pitch_, MathHelper.ToRadians(-89.999f), MathHelper.ToRadians(89.999f));
			camera_.setViewDirty();
		}

		void dolly( float amount ) {
			offset_ += amount * dollyStrength_;
			offset_ = (offset_ < minOffset_) ? minOffset_ : offset_;
			camera_.setViewDirty();
		}

		void pan( float x, float y ) {
			Vector3 right = getLocalRight();
			camera_.setPosition(camera_.getPosition() + right * (x * panStrength_));
			camera_.setTarget(camera_.getTarget() + right * (x * panStrength_));

			Vector3  up = getLocalUp();
			camera_.setPosition(camera_.getPosition() + up * (y * panStrength_));
			camera_.setTarget(camera_.getTarget() + up * (y * panStrength_));
		}

		Vector3 getLocalRight() {
			Matrix rotation = Matrix.CreateRotationX(pitch_) * Matrix.CreateRotationY(yaw_);
			Vector4 transformed = Vector4.Transform(new Vector4(1.0f, 0.0f, 0.0f, 0.0f), rotation);
			Vector3 result = new Vector3(transformed.X, transformed.Y, transformed.Z);
			result.Normalize();
			return result;
		}

		Vector3 getLocalUp() {
			Matrix rotation = Matrix.CreateRotationX(pitch_) * Matrix.CreateRotationY(yaw_);
			Vector4 transformed = Vector4.Transform(new Vector4(0.0f, 1.0f, 0.0f, 0.0f), rotation);
			Vector3 result = new Vector3(transformed.X, transformed.Y, transformed.Z);
			result.Normalize();
			return result;
		}

		float wrapAngle( float angle, float min, float max ) {
			float angleMinusMin = angle - min;
			float maxMinusMin = max - min;
			return (((angleMinusMin % maxMinusMin) + maxMinusMin) % maxMinusMin) + min;
		}

		float clamp( float val, float min, float max ) {
			if( val < min )
			{
				return min;
			}
			if( val > max )
			{
				return max;
			}
			return val;
		}
	}
}
