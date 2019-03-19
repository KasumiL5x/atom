using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Input;
using System;
using System.Collections.Generic;

namespace AtomClient {
	public class Game1 : Game {
		GraphicsDeviceManager graphics;
		Input input = new Input();
		SpriteBatch spriteBatch = null;
		SpriteFont defaultFont = null;

		// camera controllers
		//cameras.OrbitCameraController userCameraController_;
		cameras.FPCameraController userCameraController_;

		// network things
		atom.Client client = new atom.Client();
		Handlers.ClientHandler clientHandler = null;

		// local scene stuff
		Grid grid = new Grid();
		Scene.SceneManager sceneManager = new Scene.SceneManager();

		// renderer stuff
		Renderer.HDRRenderer renderer_;
		int currentTechniqueIndex = 0;

		// backup lights
		List<Scene.Light> backupLights = new List<Scene.Light>();

		public Game1() {
			graphics = new GraphicsDeviceManager(this);
			Content.RootDirectory = "Content";

			this.IsMouseVisible = true;
			graphics.PreferredBackBufferWidth = 1280;
			graphics.PreferredBackBufferHeight = 720;

			// handle window resizing
			Window.AllowUserResizing = true;
			Window.ClientSizeChanged += (sender, e) => {
				Globals.DEFAULT_CAMERA.setAspect((float)Window.ClientBounds.Width / (float)Window.ClientBounds.Height);
			};
		}

		protected override void Initialize() {
			base.Initialize();

			// configure log
			Log.Verbosity = OutputVerbosity.Info;

			// configure renderer
			renderer_ = new Renderer.HDRRenderer(GraphicsDevice, Content);
			renderer_.initialize(Window.ClientBounds.Width, Window.ClientBounds.Height);

			// setup camera
			Globals.DEFAULT_CAMERA.setAspect((float)Window.ClientBounds.Width / (float)Window.ClientBounds.Height);
			Globals.DEFAULT_CAMERA.setPlanes(0.1f, 1000.0f);

			// create camera controllers
			userCameraController_ = new cameras.FPCameraController(Globals.DEFAULT_CAMERA, input);
			Globals.DEFAULT_CAMERA.setController(userCameraController_);

			// add client handler
			clientHandler = new Handlers.ClientHandler(GraphicsDevice, client, sceneManager);

			// configure client connected callback
			client.OutputMessageStats = false;
			client.Connected += delegate(string error) {
				Console.WriteLine(client.IsConnected ? "success!" : "failed (" + error + ")!");
			};
			// gather client input for host:port
			Console.Write("host: ");
			string inputHost = Console.ReadLine();
			Console.Write("port: ");
			int inputPort =0;
			int.TryParse(Console.ReadLine(), out inputPort);
			// connect to server with fallbacks for lack of entry
			Console.Write("Connecting to server...");
			const string FALLBACK_HOST = "127.0.0.1";
			const int FALLBACK_PORT = 1337;
			string host = String.IsNullOrWhiteSpace(inputHost) ? FALLBACK_HOST : inputHost;
			int port = (inputPort==0) ? FALLBACK_PORT : inputPort;
			client.connect(host, port);
		}

		protected override void LoadContent() {
			// load spritebatch and default font
			spriteBatch = new SpriteBatch(GraphicsDevice);
			defaultFont = Content.Load<SpriteFont>("fonts/DefaultFont");

			// init backup lights
			Scene.Light defaultDirLight = new Scene.Light("dirlight0", Scene.LightType.Directional);
			defaultDirLight.setDirection(new Vector3(-0.5265408f, -0.5735765f,-0.6275069f));
			defaultDirLight.setDiffuseColor(new Vector3(1.0f, 0.9607844f, 0.8078432f));
			defaultDirLight.setAmbientColor(new Vector3(0.05333332f, 0.09882354f, 0.1819608f));
			backupLights.Add(defaultDirLight);

			// load the grid
			grid.AxisColor = new Color(0.0f, 0.0f, 0.0f, 1.0f);
			grid.BorderColor = new Color(0.0f, 0.0f, 0.0f, 1.0f);
			grid.GridColor = new Color(0.6f, 0.6f, 0.6f, 1.0f);
			grid.MajorColor = new Color(0.8f, 0.8f, 0.8f, 1.0f);
			grid.MajorSpacing = 2;
			grid.GridExtents = 24;
			grid.GridSpacing = 0.5f;
			grid.create(GraphicsDevice, Content);
		}

		protected override void UnloadContent() {
			client.disconnect();
		}

		protected override void Update( GameTime gameTime ) {
			input.preUpdate();

			if( input.isKeyDown(Keys.Escape) ) {
				Exit();
			}

			if( input.keyTapped(Keys.P) ) {
				//var bytes = Encoding.ASCII.GetBytes("unwatch " + scene.getMeshes()[0].Name + ";");
				//client.write(new atom.Message(bytes, bytes.Length));
			}

			float deltaTime = (float)gameTime.ElapsedGameTime.TotalSeconds;
			float elapsedTime = (float)gameTime.TotalGameTime.TotalSeconds;

			if( this.IsActive ) {
				if( input.keyTapped(Keys.Space) ) {
					Globals.CAMERA_FOLLOWS_MAYA = !Globals.CAMERA_FOLLOWS_MAYA;
					if( !Globals.CAMERA_FOLLOWS_MAYA ) {
						Globals.DEFAULT_CAMERA.setController(userCameraController_);
					}
				}

				Globals.DEFAULT_CAMERA.update(deltaTime, elapsedTime);

				if( input.keyTapped(Keys.N) ) {
					currentTechniqueIndex += 1;
					currentTechniqueIndex = (currentTechniqueIndex==4) ? 0 : currentTechniqueIndex;
				}

				if( input.isKeyDown(Keys.OemPlus) ) {
					renderer_.Exposure += 1.0f * deltaTime;
				}
				if( input.isKeyDown(Keys.OemMinus) ) {
					renderer_.Exposure -= 1.0f * deltaTime;
				}

				if( input.keyTapped(Keys.OemCloseBrackets) ) {
					renderer_.BlurAmount += 1;
				}
				if( input.keyTapped(Keys.OemOpenBrackets) ) {
					renderer_.BlurAmount -= 1;
				}

				if( input.isKeyDown(Keys.OemQuotes) ) {
					renderer_.LuminanceSaturation += 1.0f * deltaTime;
				}
				if( input.isKeyDown(Keys.OemSemicolon) ) {
					renderer_.LuminanceSaturation -= 1.0f * deltaTime;
				}

				if( input.isKeyDown(Keys.OemPeriod) ) {
					renderer_.WhiteLevel += 1.0f * deltaTime;
				}
				if( input.isKeyDown(Keys.OemComma) ) {
					renderer_.WhiteLevel -= 1.0f * deltaTime;
				}

				if( input.isKeyDown(Keys.End) ) {
					renderer_.MiddleGrey -= 1.0f * deltaTime;
				}
				if( input.isKeyDown(Keys.Home) ) {
					renderer_.MiddleGrey += 1.0f * deltaTime;
				}

				if( input.isKeyDown(Keys.Delete) ) {
					renderer_.Bias -= 1.0f * deltaTime;
				}
				if( input.isKeyDown(Keys.Insert) ) {
					renderer_.Bias += 1.0f * deltaTime;
				}

				if( input.isKeyDown(Keys.PageUp) ) {
					renderer_.AdaptRate += 5.0f * deltaTime;
				}
				if( input.isKeyDown(Keys.PageDown) ) {
					renderer_.AdaptRate -= 5.0f * deltaTime;
				}

				if( input.isKeyDown(Keys.L) ) {
					renderer_.BloomAmount += 1.0f * deltaTime;
				}
				if( input.isKeyDown(Keys.K) ) {
					renderer_.BloomAmount -= 1.0f * deltaTime;
				}

				if( input.keyTapped(Keys.Right) ) {
					renderer_.TonemapTechnique += 1;
				}
				if( input.keyTapped(Keys.Left) ) {
					renderer_.TonemapTechnique -= 1;
				}

				if( input.keyTapped(Keys.P) ) {
					renderer_.RenderSkybox = !renderer_.RenderSkybox;
				}

				if( input.keyTapped(Keys.B) ) {
					renderer_.UseBloom = !renderer_.UseBloom;
				}

				// bunch of debug output
				if( input.keyTapped(Keys.F9) ) {
					Console.WriteLine("--DEBUG OUTPUT--");
					Console.WriteLine("Total bytes received: {0} ({1}KB)", client.TotalBytesReceived, client.TotalBytesReceived/1024);
					Console.WriteLine("Total messages received: {0}", client.TotalMessagesReceived);
					Console.WriteLine("Total receive time: {0}ms", client.TotalReceiveTime);
					lock( Globals.LOCK_OBJ ) {
						Console.WriteLine("Xforms: {0}", sceneManager.AllXforms.Count);
						Console.WriteLine("Shapes: {0}", sceneManager.AllShapes.Count);
						Console.WriteLine("Textures: {0}", sceneManager.AllTextures.Count);
						Console.WriteLine("Materials: {0}", sceneManager.AllMaterials.Count);
						Console.WriteLine("Light Shapes: {0}", sceneManager.getLights().Count);
						Console.WriteLine("Mesh Shapes: {0}", sceneManager.getMeshes().Count);
						Console.WriteLine("Annotation Shapes: {0}", sceneManager.getAnnotations().Count);
					}
				}
			}

			input.postUpdate();
			base.Update(gameTime);
		}

		protected override void Draw( GameTime gameTime ) {
			lock( Globals.LOCK_OBJ ) {
				// build list of lights to draw
				List<Scene.Light> lightsToDraw = new List<Scene.Light>();
				foreach( var light in sceneManager.getLights() ) {
					if( !light.Visible ) {
						continue;
					}
					lightsToDraw.Add(light as Scene.Light);
				}
				if( lightsToDraw.Count == 0 ) {
					lightsToDraw = backupLights;
				}

				// build list of meshes to draw
				List<Scene.Xform> meshesToDraw = new List<Scene.Xform>();
				foreach( var xform in sceneManager.getValidMeshXforms() ) {
					if( !xform.Visible ) {
						continue;
					}

					var mesh = xform.Shape as Scene.Mesh;
					if( !mesh.Visible ) {
						continue;
					}

					meshesToDraw.Add(xform);
				}

				// render all
				renderer_.draw(meshesToDraw, lightsToDraw, Globals.DEFAULT_CAMERA, grid, currentTechniqueIndex, (float)gameTime.ElapsedGameTime.TotalSeconds);

				// render annotations
				spriteBatch.Begin();
				foreach( var obj in sceneManager.getValidAnnotationXforms() ) {
					Vector3 screenPos = GraphicsDevice.Viewport.Project(obj.Transform.Position, Globals.DEFAULT_CAMERA.getProj(), Globals.DEFAULT_CAMERA.getView(), Matrix.Identity);
					if( screenPos.Z < 1.0f ) {
						var annotation = obj.Shape as Scene.Annotation;
						Vector2 stringSize = defaultFont.MeasureString(annotation.Text);
						Vector2 textPos = new Vector2(screenPos.X - (stringSize.X * 0.5f), screenPos.Y - (stringSize.Y * 0.5f));
						spriteBatch.DrawString(defaultFont, annotation.Text, textPos, Color.Red);
					}
				}
				spriteBatch.End();

				spriteBatch.Begin();
				spriteBatch.DrawString(defaultFont, "Exposure: " + renderer_.Exposure.ToString(), new Vector2(10.0f, 10.0f), Color.Red);
				spriteBatch.DrawString(defaultFont, "Blur Samples: " + renderer_.BlurAmount.ToString(), new Vector2(10.0f, 30.0f), Color.Red);
				spriteBatch.DrawString(defaultFont, "Luminance Saturation: " + renderer_.LuminanceSaturation.ToString(), new Vector2(10.0f, 50.0f), Color.Blue);
				spriteBatch.DrawString(defaultFont, "WhiteLevel: " + renderer_.WhiteLevel.ToString(), new Vector2(10.0f, 70.0f), Color.Blue);
				spriteBatch.DrawString(defaultFont, "Middle Grey: " + renderer_.MiddleGrey.ToString(), new Vector2(10.0f, 90.0f), Color.Green);
				string techniqueName = "INVALID";
				if( currentTechniqueIndex == 0 ) { techniqueName = "Lambert"; }
				if( currentTechniqueIndex == 1 ) { techniqueName = "Phong"; }
				if( currentTechniqueIndex == 2 ) { techniqueName = "Blinn"; }
				if( currentTechniqueIndex == 3 ) { techniqueName = "WardIso"; }
				spriteBatch.DrawString(defaultFont, "Rendering with: " + techniqueName, new Vector2(10.0f, 110.0f), Color.Green);
				spriteBatch.DrawString(defaultFont, "Bias: " + renderer_.Bias.ToString(), new Vector2(10.0f, 130.0f), Color.Pink);
				spriteBatch.DrawString(defaultFont, "Adapt Rate: " + renderer_.AdaptRate.ToString(), new Vector2(10.0f, 150.0f), Color.Red);
				spriteBatch.DrawString(defaultFont, "Bloom Amount: " + renderer_.BloomAmount.ToString(), new Vector2(10.0f, 170.0f), Color.Red);
				string tonemap = "NONE";
				if( renderer_.TonemapTechnique == 0 ) { tonemap = "Reinhard Modified"; }
				if( renderer_.TonemapTechnique == 1 ) { tonemap = "Logarithmic"; }
				if( renderer_.TonemapTechnique == 2 ) { tonemap = "Drago's Logarithmic"; }
				if( renderer_.TonemapTechnique == 3 ) { tonemap = "Exponential"; }
				spriteBatch.DrawString(defaultFont, "Tonemap Technique: " + tonemap, new Vector2(10.0f, 190.0f), Color.Red);
				spriteBatch.Draw(renderer_.FinalLuminancePreview, new Vector2(20.0f, 300.0f), null, Color.White, 0.0f, Vector2.Zero, 0.25f, SpriteEffects.None, 0);
				spriteBatch.End();
			}
			base.Draw(gameTime);
		}
	}
}
