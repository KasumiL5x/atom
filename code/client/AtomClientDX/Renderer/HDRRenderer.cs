using System;
using System.Collections.Generic;
using AtomClient.cameras;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Content;
using Microsoft.Xna.Framework.Graphics;

namespace AtomClient.Renderer {
	public class HDRRenderer {
		GraphicsDevice device_ = null;
		ContentManager content_ = null;
		RenderTarget2D colorBuffer_ = null;
		RenderTarget2D bloomBuffer_ = null;
		RenderTargetBinding[] mrtBinding_ = null;
		RenderTarget2D[] pingPongBlurBuffers_ = null;
		FullscreenQuad quad_ = null;
		Effect depthEffect_ = null;
		Effect directionalEffect_ = null;
		Effect pointEffect_ = null;
		Effect spotEffect_ = null;
		Effect hdrEffect = null;
		Effect blurEffect_ = null;
		float luminanceSaturation_ = 1.0f;
		public float LuminanceSaturation {
			get { return luminanceSaturation_; }
			set { luminanceSaturation_ = MathHelper.Clamp(value, 0.0f, 4.0f); }
		}
		float whiteLevel_ = 5.0f;
		public float WhiteLevel {
			get { return whiteLevel_; }
			set { whiteLevel_ = MathHelper.Clamp(value, 0.0f, 25.0f); }
		}
		float exposure_ = 1.0f;
		public float Exposure {
			get { return exposure_; }
			set { exposure_ = MathHelper.Clamp(value, 0.0f, float.MaxValue); }
		}
		Color clearColor_ = Color.Black;
		public RenderTarget2D ColorTarget {
			get { return colorBuffer_; }
		}
		public RenderTarget2D BloomTarget {
			get { return bloomBuffer_; }
		}
		public RenderTarget2D BlurredBloomTarget {
			get { return pingPongBlurBuffers_[0]; }
		}
		int blurAmount_ = 10;
		public int BlurAmount {
			get { return blurAmount_; }
			set {
				blurAmount_ = value < 0 ? 0 : value;
			}
		}
		public bool UseBloom { get; set; } = true;
		//
		float middleGrey_ = 0.6f;
		public float MiddleGrey {
			get { return middleGrey_; }
			set { middleGrey_ = MathHelper.Clamp(value, 0.0f, 1.0f); }
		}

		float bias_ = 1.0f;
		public float Bias {
			get { return bias_; }
			set { bias_ = MathHelper.Clamp(value, 0.0f, 1.0f); }
		}

		//
		RenderTarget2D currentFrameLuminance_;
		RenderTarget2D currentFrameAdaptedLuminance_;
		RenderTarget2D lastFrameAdaptedLuminance_;
		RenderTarget2D[] luminanceChain_;
		Effect luminanceEffect_;
		Effect scalingEffect_;
		Effect luminanceAdaptEffect_;
		float adaptRate_ = 1.25f;
		public float AdaptRate {
			get { return adaptRate_; }
			set { adaptRate_ = MathHelper.Clamp(value, 0.0f, 40.0f); }
		}
		public RenderTarget2D FinalLuminancePreview {
			get; private set;
		}
		public RenderTarget2D LuminanceTexture {
			get { return currentFrameAdaptedLuminance_; }
		}

		//
		float bloomAmount_ = 2.0f;
		public float BloomAmount {
			get { return bloomAmount_; }
			set { bloomAmount_ = MathHelper.Clamp(value, 0.0f, 10.0f); }
		}

		//
		TextureCube skyboxTexture_;
		Effect skyboxEffect_;
		public bool RenderSkybox { get;set; } = true;

		int tonemapTechnique_ = 2;
		public int TonemapTechnique {
			get { return tonemapTechnique_; }
			set { tonemapTechnique_ = MathHelper.Clamp(value, 0, 3); }
		}


		public HDRRenderer( GraphicsDevice device, ContentManager content ) {
			device_ = device;
			content_ = content;
		}

		public bool initialize( int width, int height ) {
			colorBuffer_ = new RenderTarget2D(device_, width, height, false, SurfaceFormat.Vector4, DepthFormat.Depth24Stencil8);
			bloomBuffer_ = new RenderTarget2D(device_, width, height ,false, SurfaceFormat.Vector4, DepthFormat.Depth24Stencil8);
			mrtBinding_ = new RenderTargetBinding[2] {
				colorBuffer_,
				bloomBuffer_
			};
			pingPongBlurBuffers_ = new RenderTarget2D[] {
				new RenderTarget2D(device_, width, height, false, SurfaceFormat.Vector4, DepthFormat.None, 0, RenderTargetUsage.PreserveContents),
				new RenderTarget2D(device_, width, height, false, SurfaceFormat.Vector4, DepthFormat.None, 0, RenderTargetUsage.PreserveContents)
			};
			quad_ = new FullscreenQuad(device_);

			depthEffect_ = content_.Load<Effect>("shaders/Depth");
			directionalEffect_ = content_.Load<Effect>("shaders/DirectionalLight");
			pointEffect_ = content_.Load<Effect>("shaders/PointLight");
			spotEffect_ = content_.Load<Effect>("shaders/SpotLight");
			hdrEffect = content_.Load<Effect>("shaders/HDR");
			blurEffect_ = content_.Load<Effect>("shaders/GaussianBlur");

			//
			currentFrameLuminance_ = new RenderTarget2D(device_, 1, 1, false, SurfaceFormat.Single, DepthFormat.None,0, RenderTargetUsage.DiscardContents);
			currentFrameAdaptedLuminance_ = new RenderTarget2D(device_, 1, 1, false, SurfaceFormat.Single, DepthFormat.None, 0, RenderTargetUsage.DiscardContents);
			lastFrameAdaptedLuminance_ = new RenderTarget2D(device_, 1, 1, false, SurfaceFormat.Single, DepthFormat.None, 0, RenderTargetUsage.DiscardContents);
			device_.SetRenderTarget(lastFrameAdaptedLuminance_);
			device_.Clear(Color.White);
			device_.SetRenderTarget(null);
			//
			int chainLength = 1;
			int startSize = (int)MathHelper.Min(width, height);
			int size = 16;
			for( size = 16; size < startSize; size *= 4 ) {
				chainLength++;
			}
			luminanceChain_ = new RenderTarget2D[chainLength];
			size /= 4;
			for( int i = 0; i < chainLength; ++i ) {
				luminanceChain_[i] = new RenderTarget2D(device_, size, size, false, SurfaceFormat.Single, DepthFormat.None, 0, RenderTargetUsage.DiscardContents);
				size /= 4;
			}
			//
			luminanceEffect_ = content_.Load<Effect>("shaders/Luminance");
			scalingEffect_ = content_.Load<Effect>("shaders/Scaling");
			luminanceAdaptEffect_ = content_.Load<Effect>("shaders/AdaptLuminance");
			FinalLuminancePreview = new RenderTarget2D(device_, 256, 256, false, SurfaceFormat.Single, DepthFormat.None, 0, RenderTargetUsage.DiscardContents);

			//
			Texture2D skyboxTop = content_.Load<Texture2D>("textures/AboveTheSeaTop");
			Texture2D skyboxBottom = content_.Load<Texture2D>("textures/AboveTheSeaBottom");
			Texture2D skyboxLeft = content_.Load<Texture2D>("textures/AboveTheSeaLeft");
			Texture2D skyboxRight = content_.Load<Texture2D>("textures/AboveTheSeaRight");
			Texture2D skyboxBack = content_.Load<Texture2D>("textures/AboveTheSeaBack");
			Texture2D skyboxFront = content_.Load<Texture2D>("textures/AboveTheSeaFront");
			skyboxTexture_ = new TextureCube(device_, skyboxTop.Width, false, SurfaceFormat.Color);
			Color[] skyboxBuffer = new Color[skyboxTop.Width * skyboxTop.Height];
			//Color[] skyboxSOLID = new Color[skyboxTop.Width * skyboxTop.Height]; for( int i = 0; i < skyboxTop.Width * skyboxTop.Height; ++i ) { skyboxSOLID[i] = Color.Red; }
			skyboxTop.GetData<Color>(skyboxBuffer); skyboxTexture_.SetData<Color>(CubeMapFace.PositiveY, skyboxBuffer);
			skyboxBottom.GetData<Color>(skyboxBuffer); skyboxTexture_.SetData<Color>(CubeMapFace.NegativeY, skyboxBuffer);
			skyboxLeft.GetData<Color>(skyboxBuffer); skyboxTexture_.SetData<Color>(CubeMapFace.PositiveX, skyboxBuffer);
			skyboxRight.GetData<Color>(skyboxBuffer); skyboxTexture_.SetData<Color>(CubeMapFace.NegativeX, skyboxBuffer);
			skyboxBack.GetData<Color>(skyboxBuffer); skyboxTexture_.SetData<Color>(CubeMapFace.PositiveZ, skyboxBuffer);
			skyboxFront.GetData<Color>(skyboxBuffer); skyboxTexture_.SetData<Color>(CubeMapFace.NegativeZ, skyboxBuffer);
			skyboxEffect_ = content_.Load<Effect>("shaders/Skybox");

			return true;
		}

		public void draw( List<Scene.Xform> meshXforms, List<Scene.Light> lights, Camera camera, Grid grid, int technique, float deltaTime ) {
			// camera shit
			Matrix cameraView = camera.getView();
			Matrix cameraProj = camera.getProj();
			Matrix cameraViewProj = cameraView * cameraProj;
			Vector3 cameraPos = camera.getPosition();

			// reset states
			device_.BlendState = BlendState.Opaque;
			device_.DepthStencilState = DepthStencilState.Default;
			device_.RasterizerState = RasterizerState.CullNone;

			/*
			 * Render all shadow maps
			 */
			foreach( var light in lights ) {
				if( !light.castShadows() || light.shadowRenderTarget() == null ) { // ignore lights that don't cast shadows or have no valid target
					continue;
				}
				switch( light.type() ) {
					case Scene.LightType.Directional: {
							break; // no support yet
						}
					case Scene.LightType.Spot: {
							device_.SetRenderTarget(light.shadowRenderTarget());
							device_.Clear(ClearOptions.Target | ClearOptions.DepthBuffer, Color.Black, 1.0f, 0);
							drawSceneDepth(light.getView() * light.getProj(), light.position(), light.range(), meshXforms);
							break;
						}
					case Scene.LightType.Point: {
							break; // no support yet
						}
				}
			}

			/*
			 * draw scene into hdr target
			 */
			device_.SetRenderTargets(mrtBinding_);
			device_.Clear(ClearOptions.Target | ClearOptions.DepthBuffer | ClearOptions.Stencil, clearColor_, 1.0f, 0);

			// skybox
			if( RenderSkybox ) {
				device_.DepthStencilState = DepthStencilState.None;
				skyboxEffect_.Parameters["ViewMatrix"].SetValue(cameraView);
				skyboxEffect_.Parameters["InverseProjMatrix"].SetValue(Matrix.Transpose(Matrix.Invert(cameraProj)));
				skyboxEffect_.Parameters["SkyboxTexture"].SetValue(skyboxTexture_);
				skyboxEffect_.Techniques[0].Passes[0].Apply();
				quad_.setAndDraw(device_);
				device_.DepthStencilState = DepthStencilState.Default; // reset state
			}

			grid.draw(device_, cameraView, cameraProj);
			bool firstLight = true;
			foreach( var light in lights ) {
				switch( light.type() ) {
					case Scene.LightType.Directional: {
							directionalEffect_.Parameters["CameraPosition"].SetValue(cameraPos);
							directionalEffect_.Parameters["LightDirection"].SetValue(light.direction());
							directionalEffect_.Parameters["LightColor"].SetValue(light.diffuseColor());
							directionalEffect_.Parameters["LightIntensity"].SetValue(light.diffuseIntensity());
							directionalEffect_.Parameters["LightAmbientColor"].SetValue(light.ambientColor());
							foreach( var xform in meshXforms ) {
								var mesh = xform.Shape as Scene.Mesh;
								device_.SetVertexBuffer(mesh.VertexBuffer);
								device_.Indices = mesh.IndexBuffer;

								Scene.Material mat = mesh.Material;
								Texture2D xnaDiffuseTex = mat?.DiffuseTexture?.Tex;
								directionalEffect_.Parameters["UseDiffuseTexture"].SetValue(xnaDiffuseTex != null);
								if( xnaDiffuseTex != null ) { directionalEffect_.Parameters["DiffuseTexture"].SetValue(xnaDiffuseTex); }

								Texture2D xnaNrm = mat?.BumpTexture?.Tex;
								directionalEffect_.Parameters["UseNormalTexture"].SetValue(xnaNrm != null);
								if( xnaNrm != null ) { directionalEffect_.Parameters["NormalTexture"].SetValue(xnaNrm); }

								directionalEffect_.Parameters["SpecularPower"].SetValue(null == mat ? 64.0f : mat.SpecularPower);
								directionalEffect_.Parameters["SurfaceColor"].SetValue(null == mat || xnaDiffuseTex != null ? new Vector3(1.0f, 1.0f, 1.0f) : mat.DiffuseColor);

								directionalEffect_.Parameters["World"].SetValue(xform.Transform.World);
								directionalEffect_.Parameters["Xform"].SetValue(xform.Transform.World * cameraViewProj);

								directionalEffect_.Techniques[technique].Passes[0].Apply();
								device_.DrawIndexedPrimitives(PrimitiveType.TriangleList, 0, 0, mesh.IndexBuffer.IndexCount / 3);
							}
							break;
						}

					case Scene.LightType.Point: {
							pointEffect_.Parameters["CameraPosition"].SetValue(cameraPos);
							pointEffect_.Parameters["LightPosition"].SetValue(light.position());
							pointEffect_.Parameters["LightColor"].SetValue(light.diffuseColor());
							pointEffect_.Parameters["LightIntensity"].SetValue(light.diffuseIntensity());
							pointEffect_.Parameters["LightAmbientColor"].SetValue(light.ambientColor());
							pointEffect_.Parameters["LightRange"].SetValue(light.range());
							foreach( var xform in meshXforms ) {
								var mesh = xform.Shape as Scene.Mesh;
								device_.SetVertexBuffer(mesh.VertexBuffer);
								device_.Indices = mesh.IndexBuffer;

								Scene.Material mat = mesh.Material;

								Texture2D xnaDiffuseTex = mat?.DiffuseTexture?.Tex;
								pointEffect_.Parameters["UseDiffuseTexture"].SetValue(xnaDiffuseTex != null);
								if( xnaDiffuseTex != null ) { pointEffect_.Parameters["DiffuseTexture"].SetValue(xnaDiffuseTex); }

								Texture2D xnaNrm = mat?.BumpTexture?.Tex;
								pointEffect_.Parameters["UseNormalTexture"].SetValue(xnaNrm != null);
								if( xnaNrm != null ) { pointEffect_.Parameters["NormalTexture"].SetValue(xnaNrm); }

								pointEffect_.Parameters["SpecularPower"].SetValue(null == mat ? 64.0f : mat.SpecularPower);
								pointEffect_.Parameters["SurfaceColor"].SetValue(null == mat || xnaDiffuseTex != null ? new Vector3(1.0f, 1.0f, 1.0f) : mat.DiffuseColor);

								pointEffect_.Parameters["World"].SetValue(xform.Transform.World);
								pointEffect_.Parameters["Xform"].SetValue(xform.Transform.World * cameraViewProj);

								pointEffect_.Techniques[technique].Passes[0].Apply();
								device_.DrawIndexedPrimitives(PrimitiveType.TriangleList, 0, 0, mesh.IndexBuffer.IndexCount / 3);
							}
							break;
						}

					case Scene.LightType.Spot: {
							spotEffect_.Parameters["CameraPosition"].SetValue(cameraPos);
							spotEffect_.Parameters["LightPosition"].SetValue(light.position());
							spotEffect_.Parameters["LightDirection"].SetValue(light.direction());
							spotEffect_.Parameters["LightColor"].SetValue(light.diffuseColor());
							spotEffect_.Parameters["LightIntensity"].SetValue(light.diffuseIntensity());
							spotEffect_.Parameters["LightAmbientColor"].SetValue(light.ambientColor());
							spotEffect_.Parameters["LightRange"].SetValue(light.range());
							spotEffect_.Parameters["LightCosInner"].SetValue(light.cosInnerAngle(true));
							spotEffect_.Parameters["LightCosOuter"].SetValue(light.cosOuterAngle(true));
							spotEffect_.Parameters["DepthTexture"].SetValue(light.shadowRenderTarget());
							spotEffect_.Parameters["CastShadows"].SetValue(light.castShadows());
							spotEffect_.Parameters["LightViewProj"].SetValue(light.getView() * light.getProj());
							spotEffect_.Parameters["LightShadowBias"].SetValue(light.shadowBias());
							foreach( var xform in meshXforms ) {
								var mesh = xform.Shape as Scene.Mesh;
								device_.SetVertexBuffer(mesh.VertexBuffer);
								device_.Indices = mesh.IndexBuffer;

								Scene.Material mat = mesh.Material;

								Texture2D xnaDiffuseTex = mat?.DiffuseTexture?.Tex;
								spotEffect_.Parameters["UseDiffuseTexture"].SetValue(xnaDiffuseTex != null);
								if( xnaDiffuseTex != null ) { spotEffect_.Parameters["DiffuseTexture"].SetValue(xnaDiffuseTex); }

								Texture2D xnaNrm = mat?.BumpTexture?.Tex;
								spotEffect_.Parameters["UseNormalTexture"].SetValue(xnaNrm != null);
								if( xnaNrm != null ) { spotEffect_.Parameters["NormalTexture"].SetValue(xnaNrm); }

								spotEffect_.Parameters["SpecularPower"].SetValue(null == mat ? 64.0f : mat.SpecularPower);
								spotEffect_.Parameters["SurfaceColor"].SetValue(null == mat || xnaDiffuseTex != null ? new Vector3(1.0f, 1.0f, 1.0f) : mat.DiffuseColor);

								spotEffect_.Parameters["World"].SetValue(xform.Transform.World);
								spotEffect_.Parameters["Xform"].SetValue(xform.Transform.World * cameraViewProj);

								spotEffect_.Techniques[technique].Passes[0].Apply();
								device_.DrawIndexedPrimitives(PrimitiveType.TriangleList, 0, 0, mesh.IndexBuffer.IndexCount / 3);
							}
							break;
						}
				}

				if( firstLight ) {
					firstLight = false;
					device_.BlendState = BlendState.Additive;
				}
			}

			// reset blend state
			device_.BlendState = BlendState.Opaque;

			/*
			 * Luminance computation and adaptation.
			 */
			// calculate initial luminance
			luminanceEffect_.Parameters["InputTexture"].SetValue(colorBuffer_);
			device_.SetRenderTarget(luminanceChain_[0]);
			luminanceEffect_.Techniques[0].Passes[0].Apply();
			quad_.setAndDraw(device_);
			// repeatedly downscale luminance through chain
			for( int i = 1; i < luminanceChain_.Length; ++i ) {
				var src = luminanceChain_[i-1];
				var dst = luminanceChain_[i];
				scalingEffect_.Parameters["InputTexture"].SetValue(src);
				scalingEffect_.Parameters["SourceDimensions"].SetValue(new Vector2((float)src.Width, (float)src.Height));
				scalingEffect_.Parameters["Luminance"].SetValue(false);
				device_.SetRenderTarget(dst);
				scalingEffect_.Techniques[0].Passes[0].Apply();
				quad_.setAndDraw(device_);
			}
			// final downscale
			scalingEffect_.Parameters["Luminance"].SetValue(true);
			scalingEffect_.Parameters["InputTexture"].SetValue(luminanceChain_[luminanceChain_.Length - 1]);
			scalingEffect_.Parameters["SourceDimensions"].SetValue(new Vector2((float)luminanceChain_[luminanceChain_.Length - 1].Width, (float)luminanceChain_[luminanceChain_.Length - 1].Height));
			device_.SetRenderTarget(currentFrameLuminance_);
			scalingEffect_.Techniques[0].Passes[0].Apply();
			quad_.setAndDraw(device_);
			// adapt luminance value
			luminanceAdaptEffect_.Parameters["InputTexture1"].SetValue(currentFrameLuminance_);
			luminanceAdaptEffect_.Parameters["InputTexture2"].SetValue(lastFrameAdaptedLuminance_);
			luminanceAdaptEffect_.Parameters["TimeDelta"].SetValue(deltaTime);
			luminanceAdaptEffect_.Parameters["Tau"].SetValue(adaptRate_);
			device_.SetRenderTarget(currentFrameAdaptedLuminance_);
			luminanceAdaptEffect_.Techniques[0].Passes[0].Apply();
			quad_.setAndDraw(device_);
			// copy for preview
			float[] tmpBuf = { 0.0f };
			currentFrameAdaptedLuminance_.GetData<float>(tmpBuf);
			float[] newBuf = new float[FinalLuminancePreview.Width*FinalLuminancePreview.Height];
			for( int i = 0; i < FinalLuminancePreview.Width*FinalLuminancePreview.Height; ++i ) {
				newBuf[i] = tmpBuf[0];
			}
			FinalLuminancePreview.SetData<float>(newBuf);

			// blur the bloom texture
			bool horizontal = true;
			bool firstBlur = true;
			for( int i = 0; i < blurAmount_; ++i ) {
				// set horizontal flag
				blurEffect_.Parameters["Horizontal"].SetValue(horizontal);

				// bind current buffer
				int firstIndex = horizontal ? 1 : 0;
				device_.SetRenderTarget(pingPongBlurBuffers_[firstIndex]);

				// set texture size parameter
				float textureWidth = (float)pingPongBlurBuffers_[firstIndex].Width;
				float textureHeight = (float)pingPongBlurBuffers_[firstIndex].Height;
				blurEffect_.Parameters["TextureSize"].SetValue(new Vector2(1.0f / textureWidth, 1.0f / textureHeight));

				// set other buffer as texture; first iteration is scene bloom, onwards is pingpong blurs
				int secondIndex = horizontal ? 0 : 1;
				blurEffect_.Parameters["InputTexture"].SetValue(firstBlur ? bloomBuffer_ : pingPongBlurBuffers_[secondIndex]);

				// draw quad
				blurEffect_.Techniques[0].Passes[0].Apply();
				quad_.setAndDraw(device_);

				// flip horizontal flag
				horizontal = !horizontal;

				// update first iteration flag
				if( firstBlur ) {
					firstBlur = false;
				}
			}

			// render floating point texture to 2d quad and draw that to screen w/ tonemapping
			device_.SetRenderTarget(null);
			device_.Clear(ClearOptions.Target | ClearOptions.DepthBuffer | ClearOptions.Stencil, clearColor_, 1.0f, 0);
			hdrEffect.Parameters["LuminanceSaturation"].SetValue(luminanceSaturation_);
			hdrEffect.Parameters["WhiteLevel"].SetValue(whiteLevel_);
			hdrEffect.Parameters["Exposure"].SetValue(exposure_);
			hdrEffect.Parameters["HdrTexture"].SetValue(colorBuffer_);
			hdrEffect.Parameters["LuminanceTexture"].SetValue(currentFrameAdaptedLuminance_);
			hdrEffect.Parameters["BloomTexture"].SetValue(pingPongBlurBuffers_[0]);
			hdrEffect.Parameters["Bloom"].SetValue(UseBloom);
			hdrEffect.Parameters["MiddleGrey"].SetValue(middleGrey_);
			hdrEffect.Parameters["Bias"].SetValue(bias_);
			hdrEffect.Parameters["BloomAmount"].SetValue(bloomAmount_);
			hdrEffect.Parameters["TonemapTechnique"].SetValue(tonemapTechnique_);
			hdrEffect.Techniques[0].Passes[0].Apply();
			quad_.setAndDraw(device_);

			// flip adapted luminance targets
			RenderTarget2D tmpRT = currentFrameAdaptedLuminance_;
			currentFrameAdaptedLuminance_ = lastFrameAdaptedLuminance_;
			lastFrameAdaptedLuminance_ = tmpRT;
		}

		void drawSceneDepth( Matrix viewProj, Vector3 lightPos, float farPlane, List<Scene.Xform> meshXforms ) {
			depthEffect_.Parameters["LightPosition"].SetValue(lightPos);
			depthEffect_.Parameters["FarPlane"].SetValue(farPlane);

			foreach( var xform in meshXforms ) {
				var mesh = xform.Shape as Scene.Mesh;
				device_.SetVertexBuffer(mesh.VertexBuffer);
				device_.Indices = mesh.IndexBuffer;
				depthEffect_.Parameters["Xform"].SetValue(xform.Transform.World * viewProj);
				depthEffect_.Parameters["World"].SetValue(xform.Transform.World);
				depthEffect_.CurrentTechnique.Passes[0].Apply();
				device_.DrawIndexedPrimitives(PrimitiveType.TriangleList, 0, 0, mesh.IndexBuffer.IndexCount / 3);
			}
		}
	}
}
