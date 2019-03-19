using Microsoft.Xna.Framework;

namespace AtomClient {
	public class Transform {
		Vector3 position_ = Vector3.Zero;
		Vector3 scale_ = Vector3.One;
		Quaternion orientation_ = Quaternion.Identity;
		Matrix world_ = Matrix.Identity;
		bool worldDirty_ = true;
		public bool Visible {get;set;} = true;

		public Transform() {
		}

		public Transform( Matrix world ) {
			World = world;
		}

		public Vector3 Position {
			get { return position_; }
			set { position_ = value; worldDirty_ = true; }
		}

		public Vector3 Scale {
			get { return scale_; }
			set { scale_ = value; worldDirty_ = true; }
		}

		public Quaternion Orientation {
			get { return orientation_; }
			set { orientation_ = value; worldDirty_ = true; }
		}

		public Matrix World {
			get {
				if( worldDirty_ ) {
					Matrix translation = Matrix.CreateTranslation(position_);
					Matrix rotation = Matrix.CreateFromQuaternion(orientation_);
					Matrix scale = Matrix.CreateScale(scale_);
					world_ = translation * rotation * scale;
					worldDirty_ = false;
				}
				return world_;
			}
			set {
				world_ = value;
				world_.Decompose(out scale_, out orientation_, out position_);
				worldDirty_ = false;
			}
		}

		public void identity() {
			position_ = Vector3.Zero;
			scale_ = Vector3.One;
			orientation_ = Quaternion.Identity;
			world_ = Matrix.Identity;
			worldDirty_ = false;
		}

		public void translate( Vector3 value ) {
			position_ += value;
			worldDirty_ = true;
		}

		public void translate( float x, float y, float z ) {
			position_ += new Vector3(x, y, z);
			worldDirty_ = true;
		}

		public void rotate( Quaternion value ) {
			orientation_ *= value;
			worldDirty_ = true;
		}

		public void scale( float multiplier ) {
			scale_ *= multiplier;
			worldDirty_ = true;
		}

		public void scale( float xMul, float yMul, float zMul ) {
			scale_ *= new Vector3(xMul, yMul, zMul);
			worldDirty_ = true;
		}
	}
}
