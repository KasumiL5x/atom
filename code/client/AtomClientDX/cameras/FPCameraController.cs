using System;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Input;

namespace AtomClient.cameras {
	public class FPCameraController : CameraController {
		enum Direction {
			Forward,
			Backward,
			Left,
			Right
		}

		float yaw_ = 0.0f;
		float pitch_ = 0.0f;
		float moveSpeed_ = 100.0f;
		float sensitivity_ = 50.0f;
		Vector3 front_ = new Vector3();
		Vector3 right_ = new Vector3();

		Input input_;

		public FPCameraController( Camera cam, Input input ) : base(cam) {
			input_ = input;
			OverrideView = true;
			OverrideForward = true;
			updateVectors();
		}

		public override void onSet() {

			camera_.setPosition(new Vector3(-135.0f, 170.0f, 145.0f));
			yaw_ = 305.0f;
			pitch_ = -36.9f;

			updateVectors();
			base.onSet();
		}

		public override void update( float deltaTime, float elapsedTime ) {
			if( input_.isKeyDown(Keys.W) ) {
				move(Direction.Forward, deltaTime);
			}
			if( input_.isKeyDown(Keys.S) ) {
				move(Direction.Backward, deltaTime);
			}
			if( input_.isKeyDown(Keys.A) ) {
				move(Direction.Left, deltaTime);
			}
			if( input_.isKeyDown(Keys.D) ) {
				move(Direction.Right, deltaTime);
			}

			if( input_.isButtonDown(Input.MouseButton.Right) ) {
				float dx = (float)input_.deltaX();
				float dy = (float)input_.deltaY();
				rotateYaw(dx * deltaTime);
				rotatePitch(dy * deltaTime);
			}

			base.update(deltaTime, elapsedTime);
		}

		public override Matrix rebuildView() {
			return Matrix.CreateLookAt(camera_.getPosition(), camera_.getPosition() + front_, camera_.getUp());
		}

		public override Vector3 getForward() {
			return front_;
		}

		float wrapAngle( float angle, float min, float max ) {
			float maxMinusMin = max - min;
			return ((((angle - min) % maxMinusMin) + maxMinusMin) % maxMinusMin) + min;
		}

		void move( Direction dir, float deltaTime ) {
			float velocity = moveSpeed_ * deltaTime;
			Vector3 movement = Vector3.Zero;

			switch( dir ) {
				case Direction.Forward: {
					movement = front_ * velocity;
					break;
				}
				case Direction.Backward: {
					movement = -front_ * velocity;
					break;
				}
				case Direction.Left: {
					movement = -right_ * velocity;
					break;
				}
				case Direction.Right: {
					movement = right_ * velocity;
					break;
				}
			}

			camera_.setPosition(camera_.getPosition() + movement);
			camera_.setViewDirty();
		}

		void rotateYaw( float val ) {
			yaw_ += val * sensitivity_;
			yaw_ = wrapAngle(yaw_, 0.0f, 360.0f);
			camera_.setViewDirty();
			updateVectors();
		}

		void rotatePitch( float val ) {
			pitch_ += val * sensitivity_;
			pitch_ = MathHelper.Clamp(pitch_, -89.9f, 89.9f);
			camera_.setViewDirty();
			updateVectors();
		}

		void updateVectors() {
			front_.X = (float)Math.Cos(MathHelper.ToRadians(yaw_)) * (float)Math.Cos(MathHelper.ToRadians(pitch_));
			front_.Y = (float)Math.Sin(MathHelper.ToRadians(pitch_));
			front_.Z = (float)Math.Sin(MathHelper.ToRadians(yaw_)) * (float)Math.Cos(MathHelper.ToRadians(pitch_));
			front_.Normalize();

			right_ = Vector3.Cross(front_, Vector3.Up);
			right_.Normalize();

			// todo: camera's camera.up vector
			Vector3 newUp = (Vector3.Cross(right_, front_));
			newUp.Normalize();
			camera_.setUp(newUp);
		}
	}
}
