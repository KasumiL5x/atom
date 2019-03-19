using System;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;

namespace AtomClient.Handlers {
	public class LightHandler : IHandler {
		public bool handle( GraphicsDevice device, Atom.Proto.AtomMessage msg, atom.Client client, Scene.SceneManager scene ) {
			if( msg.MsgCase != Atom.Proto.AtomMessage.MsgOneofCase.Light && msg.MsgCase != Atom.Proto.AtomMessage.MsgOneofCase.LightChanged ) {
				return false;
			}

			if( msg.MsgCase == Atom.Proto.AtomMessage.MsgOneofCase.Light ) {
				var existing = scene.getShapeByName(msg.Light.Name);
				if( null == existing ) {
					var light = new Scene.Light(msg.Light.Name, convertLightType(msg.Light.Type));
					populateLight(msg.Light, ref light, device);
					light.Visible = msg.Light.InitialVisibility;
					scene.addShape(light);
					Log.write(string.Format("Added new light: {0}", light.Name), OutputVerbosity.Info);
				} else {
					Log.write(string.Format("Tried to add a new light but the name was already taken: {0}", existing.Name), OutputVerbosity.Error);
				}
			}

			if( msg.MsgCase == Atom.Proto.AtomMessage.MsgOneofCase.LightChanged ) {
				var existing = scene.getShapeByName(msg.LightChanged.LightName);
				if( null == existing ) {
					Log.write(string.Format("Tried updating a light but it didn't exist: {0}", msg.LightChanged.LightName), OutputVerbosity.Error);
				} else {
					var light = existing as Scene.Light;
					switch( msg.LightChanged.PropertyCase ) {
						case Atom.Proto.Lights.LightChanged.PropertyOneofCase.None: {
								Log.write("Received LightChanged but no data was set.", OutputVerbosity.Info);
								break;
							}
						case Atom.Proto.Lights.LightChanged.PropertyOneofCase.Type: {
								Log.write(string.Format("Received LightChanged Type: {0}", msg.LightChanged.Type), OutputVerbosity.Info);
								light.setType(convertLightType(msg.LightChanged.Type));
								break;
							}
						case Atom.Proto.Lights.LightChanged.PropertyOneofCase.Position: {
								Log.write(string.Format("Received LightChanged Position: {0}", msg.LightChanged.Position), OutputVerbosity.Info);
								light.setPosition(new Vector3(msg.LightChanged.Position.X, msg.LightChanged.Position.Y, msg.LightChanged.Position.Z));
								break;
							}
						case Atom.Proto.Lights.LightChanged.PropertyOneofCase.Direction: {
								Log.write(string.Format("Received LightChanged Direction: {0}", msg.LightChanged.Direction), OutputVerbosity.Info);
								light.setDirection(new Vector3(msg.LightChanged.Direction.X, msg.LightChanged.Direction.Y, msg.LightChanged.Direction.Z));
								break;
							}
						case Atom.Proto.Lights.LightChanged.PropertyOneofCase.Range: {
								Log.write(string.Format("Received LightChanged Range: {0}", msg.LightChanged.Range), OutputVerbosity.Info);
								light.setRange(msg.LightChanged.Range);
								break;
							}
						case Atom.Proto.Lights.LightChanged.PropertyOneofCase.Color: {
								Log.write(string.Format("Received LightChanged Color: {0}", msg.LightChanged.Color), OutputVerbosity.Info);
								light.setDiffuseColor(new Vector3(msg.LightChanged.Color.R, msg.LightChanged.Color.G, msg.LightChanged.Color.B));
								break;
							}
						case Atom.Proto.Lights.LightChanged.PropertyOneofCase.Intensity: {
								Log.write(string.Format("Received LightChanged Intensity: {0}", msg.LightChanged.Intensity), OutputVerbosity.Info);
								light.setDiffuseIntensity(msg.LightChanged.Intensity);
								break;
							}
						case Atom.Proto.Lights.LightChanged.PropertyOneofCase.ConeAngle: {
								Log.write(string.Format("Received LightChanged ConeAngle: {0}", msg.LightChanged.ConeAngle), OutputVerbosity.Info);
								light.setConeAngle(msg.LightChanged.ConeAngle);
								break;
							}
						case Atom.Proto.Lights.LightChanged.PropertyOneofCase.PenumbraAngle: {
								Log.write(string.Format("Received LightChanged PenumbraAngle: {0}", msg.LightChanged.PenumbraAngle), OutputVerbosity.Info);
								light.setPenumbra(msg.LightChanged.PenumbraAngle);
								break;
							}
						case Atom.Proto.Lights.LightChanged.PropertyOneofCase.Dropoff: {
								Log.write(string.Format("Received LightChanged Dropoff: {0}", msg.LightChanged.Dropoff), OutputVerbosity.Info);
								break;
							}
						case Atom.Proto.Lights.LightChanged.PropertyOneofCase.Shadows: {
								Log.write(string.Format("Received LightChanged Shadows: {0}", msg.LightChanged.Shadows), OutputVerbosity.Info);
								light.setCastShadows(msg.LightChanged.Shadows);
								break;
							}
						case Atom.Proto.Lights.LightChanged.PropertyOneofCase.ShadowResolution: {
								Log.write(string.Format("Received LightChanged ShadowResolution: {0}", msg.LightChanged.ShadowResolution), OutputVerbosity.Info);
								light.createShadowTargets(device, msg.LightChanged.ShadowResolution);
								break;
							}
						case Atom.Proto.Lights.LightChanged.PropertyOneofCase.ShadowBias: {
								Log.write(string.Format("Received LightChanged ShadowBias: {0}", msg.LightChanged.ShadowBias), OutputVerbosity.Info);
								light.setShadowBias(msg.LightChanged.ShadowBias);
								break;
							}
						case Atom.Proto.Lights.LightChanged.PropertyOneofCase.ShadowColor: {
								Log.write(string.Format("Received LightChanged ShadowColor: {0}", msg.LightChanged.ShadowColor), OutputVerbosity.Info);
								break;
							}
					}
				}
			}

			return true;
		}

		private void populateLight( Atom.Proto.Lights.Light atomLight, ref Scene.Light light, GraphicsDevice device ) {
			light.setDiffuseColor(new Vector3(atomLight.Color.R, atomLight.Color.G, atomLight.Color.B));
			light.setDiffuseIntensity(atomLight.Intensity);
			light.setSpecularColor(new Vector3(1.0f, 1.0f, 1.0f)); // todo
			light.setSpecularIntensity(atomLight.Intensity);
			light.setPosition(new Vector3(atomLight.Position.X, atomLight.Position.Y, atomLight.Position.Z));
			light.setDirection(new Vector3(atomLight.Direction.X, atomLight.Direction.Y, atomLight.Direction.Z));
			light.setRange(atomLight.Range);
			light.setConeAngle(atomLight.ConeAngle);
			light.setPenumbra(atomLight.PenumbraAngle);
			light.setCastShadows(atomLight.Shadows);
			if( atomLight.ShadowResolution > 0 ) {
				light.createShadowTargets(device, atomLight.ShadowResolution);
			}
			light.setShadowBias(atomLight.ShadowBias);
		}

		private Scene.LightType convertLightType( Atom.Proto.Lights.LightType atomType ) {
			switch( atomType ) {
				// todo: support ambient lights
				case Atom.Proto.Lights.LightType.kLightTypeDirectional: { return Scene.LightType.Directional; }
				case Atom.Proto.Lights.LightType.kLightTypePoint: { return Scene.LightType.Point; }
				case Atom.Proto.Lights.LightType.kLightTypeSpot: { return Scene.LightType.Spot; }
			}
			return Scene.LightType.Invalid;
		}

	}
}
