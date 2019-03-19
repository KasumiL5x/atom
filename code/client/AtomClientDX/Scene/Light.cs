using System;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;

namespace AtomClient.Scene {
	public enum LightType {
		Invalid,
		Directional,
		Spot,
		Point
	}

	public class Light : Shape {
		// colors
		Vector3 _diffuseColor = new Vector3(1.0f, 1.0f, 1.0f);
		float _diffuseIntensity = 1.0f;
		Vector3 _specularColor = new Vector3(1.0f, 1.0f, 1.0f);
		float _specularIntensity = 1.0f;
		Vector3 _ambientColor = new Vector3(0.0f, 0.0f, 0.0f);
		// general properties
		LightType _type = LightType.Invalid;
		Vector3 _position = new Vector3(0.0f, 0.0f, 0.0f);
		Vector3 _direction = new Vector3(0.0f, -1.0f, 0.0f);
		float _range = 100.0f;
		float _coneAngle = 10.0f; // modify
		float _penumbra = 1.0f; // modify
		float _coneInnerAngle = 0.0f; // calc
		float _coneOuterAngle = 0.0f; // calc
		// shadow stuff
		RenderTarget2D _shadowRenderTarget = null;
		bool _castShadows = false;
		Matrix _view = Matrix.Identity;
		bool _viewDirty = true;
		Matrix _proj = Matrix.Identity;
		bool _projDirty = true;
		float _shadowBias = 0.01f;


		public Light( string name, LightType lightType ) : base(name, ShapeType.Light) {
			_type = lightType;
		}


		public Vector3 diffuseColor() {
			return _diffuseColor;
		}

		public float diffuseIntensity() {
			return _diffuseIntensity;
		}

		public Vector3 specularColor() {
			return _specularColor;
		}

		public float specularIntensity() {
			return _specularIntensity;
		}

		public Vector3 ambientColor() {
			return _ambientColor;
		}

		public LightType type() {
			return _type;
		}

		public Vector3 position() {
			return _position;
		}

		public Vector3 direction() {
			return _direction;
		}

		public float range() {
			return _range;
		}

		public float coneInnerAngle() {
			return _coneInnerAngle;
		}

		public float coneOuterAngle() {
			return _coneOuterAngle;
		}

		public float cosInnerAngle( bool radians ) {
			return (float)Math.Cos(radians ? MathHelper.ToRadians(_coneInnerAngle) : _coneInnerAngle);
		}

		public float cosOuterAngle( bool radians ) {
			return (float)Math.Cos(radians ? MathHelper.ToRadians(_coneOuterAngle) : _coneOuterAngle);
		}

		public bool castShadows() {
			return _castShadows;
		}

		public float shadowBias() {
			return _shadowBias;
		}

		public void setDiffuseColor( Vector3 value ) {
			_diffuseColor.X = Math.Abs(value.X);
			_diffuseColor.Y = Math.Abs(value.Y);
			_diffuseColor.Z = Math.Abs(value.Z);
		}

		public void setDiffuseIntensity( float value ) {
			_diffuseIntensity = Math.Abs(value);
		}

		public void setSpecularColor( Vector3 value ) {
			_specularColor.X = Math.Abs(value.X);
			_specularColor.Y = Math.Abs(value.Y);
			_specularColor.Z = Math.Abs(value.Z);
		}

		public void setSpecularIntensity( float value ) {
			_specularIntensity = Math.Abs(value);
		}

		public void setAmbientColor( Vector3 value ) {
			_ambientColor = value;
		}

		public void setType( LightType value ) {
			_type = value;
			_viewDirty = _projDirty = true;
		}

		public void setPosition( Vector3 value ) {
			_position = value;
			_viewDirty = true;
		}

		public void setDirection( Vector3 value ) {
			_direction = value + new Vector3(1e-5f, 1e-5f, 1e-5f); // fudge to avoid exactly zero
			_direction.Normalize();
			_viewDirty = true;
		}

		public void setRange( float value ) {
			_range = value;
			_projDirty = true;
		}

		public void setConeAngle( float value ) {
			_coneAngle = value;
			updateConeAngles();
			_projDirty = true;
		}

		public void setPenumbra( float value ) {
			_penumbra = value;
			updateConeAngles();
			_projDirty = true;
		}

		public void setCastShadows( bool value ) {
			_castShadows = value;
		}
		public void setShadowBias( float value ) {
			_shadowBias = value;
		}

		private void updateConeAngles() {
			float first = _coneAngle;
			float second = _coneAngle + _penumbra;

			first = first < 0.0f ? 0.0f : first;
			second = second < 0.0f ? 0.0f : second;

			_coneInnerAngle = Math.Min(first, second);
			_coneOuterAngle = Math.Max(first, second);
		}

		public void createShadowTargets( GraphicsDevice device, int size ) {
			if( size <= 0 ) {
				return;
			}
			_shadowRenderTarget = new RenderTarget2D(device, size, size, false, SurfaceFormat.Single, DepthFormat.Depth24);
		}

		public RenderTarget2D shadowRenderTarget() {
			return _shadowRenderTarget;
		}

		public Matrix getView() {
			if( _viewDirty ) {
				_viewDirty = false;
				_view = Matrix.CreateLookAt(_position, _position + _direction, Vector3.Up);
			}
			return _view;
		}

		public Matrix getProj() {
			if( _projDirty ) {
				_projDirty = false;
				//_proj = Matrix.CreatePerspectiveFieldOfView(MathHelper.PiOver2, 1.0f, 0.1f, _range);
				//_proj = Matrix.CreatePerspectiveFieldOfView(_coneOuterAngle * 2.0f, 1.0f, 0.1f, _range);
				_proj = Matrix.CreatePerspectiveFieldOfView(MathHelper.ToRadians(_coneOuterAngle * 2.0f), 1.0f, 1.0f, _range);
			}
			return _proj;
		}
	}
}
