using System;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;

namespace AtomClient.Handlers {
	public class MaterialHandler : IHandler {
		public bool handle( GraphicsDevice device, Atom.Proto.AtomMessage msg, atom.Client client, Scene.SceneManager scene ) {
			if( msg.MsgCase != Atom.Proto.AtomMessage.MsgOneofCase.Material && msg.MsgCase != Atom.Proto.AtomMessage.MsgOneofCase.MaterialChanged ) {
				return false;
			}

			if( msg.MsgCase == Atom.Proto.AtomMessage.MsgOneofCase.Material ) {
				var existing = scene.getMaterialByName(msg.Material.Name);
				if( null == existing ) {
					var mat = new Scene.Material(msg.Material.Name);
					copyMaterialData(msg.Material, mat);
					scene.addMaterial(mat);
					Log.write(string.Format("Added new material: {0}", mat.Name), OutputVerbosity.Info);
				} else {
					copyMaterialData(msg.Material, existing as Scene.Material);
					Log.write(string.Format("Fully updated material: {0}", existing.Name), OutputVerbosity.Info);
				}
			}

			if( msg.MsgCase == Atom.Proto.AtomMessage.MsgOneofCase.MaterialChanged ) {
				var existing = scene.getMaterialByName(msg.MaterialChanged.MaterialName);
				if( null == existing ) {
					Log.write(string.Format("Tried updating a material but it didn't exist: {0}", msg.MaterialChanged.MaterialName), OutputVerbosity.Error);
				} else {
					var mat = existing as Scene.Material;
					Atom.Proto.Materials.MaterialChanged from = msg.MaterialChanged;
					switch( from.PropertyCase ) {
						case Atom.Proto.Materials.MaterialChanged.PropertyOneofCase.None: {
								Log.write(string.Format("Received MaterialChanged but no data was set."), OutputVerbosity.Info);
								break;
							}
						case Atom.Proto.Materials.MaterialChanged.PropertyOneofCase.Color: {
								mat.DiffuseColor = new Vector3(from.Color.AsColor.R, from.Color.AsColor.G, from.Color.AsColor.B);
								mat.DiffuseTextureName = from.Color.Texture;
								scene.linkMaterialTextures(mat);
								Log.write(string.Format("Received MaterialChanged Color: ({0}/{1})", from.Color.AsColor, from.Color.Texture), OutputVerbosity.Info);
								break;
							}
						case Atom.Proto.Materials.MaterialChanged.PropertyOneofCase.Transparency: {
								Log.write(string.Format("Received MaterialChanged Transparency: ({0}/{1})", from.Transparency.AsColor, from.Transparency.Texture), OutputVerbosity.Info);
								break;
							}
						case Atom.Proto.Materials.MaterialChanged.PropertyOneofCase.AmbientColor: {
								mat.AmbientColor = new Vector3(from.AmbientColor.AsColor.R, from.AmbientColor.AsColor.G, from.AmbientColor.AsColor.B);
								Log.write(string.Format("Received MaterialChanged AmbientColor: ({0}/{1})", from.AmbientColor.AsColor, from.AmbientColor.Texture), OutputVerbosity.Info);
								break;
							}
						case Atom.Proto.Materials.MaterialChanged.PropertyOneofCase.Incandescence: {
								Log.write(string.Format("Received MaterialChanged Incandescence: ({0}/{1})", from.Incandescence.AsColor, from.Incandescence.Texture), OutputVerbosity.Info);
								break;
							}
						case Atom.Proto.Materials.MaterialChanged.PropertyOneofCase.BumpMap: {
								mat.BumpTextureName = from.BumpMap;
								scene.linkMaterialTextures(mat);
								Log.write(string.Format("Received MaterialChanged BumpMap: {0}", from.BumpMap), OutputVerbosity.Info);
								break;
							}
						case Atom.Proto.Materials.MaterialChanged.PropertyOneofCase.DiffuseAmount: {
								mat.DiffuseAmount = from.DiffuseAmount.AsFloat;
								Log.write(string.Format("Received MaterialChanged DiffuseAmount: ({0}/{1})", from.DiffuseAmount.AsFloat, from.DiffuseAmount.Texture), OutputVerbosity.Info);
								break;
							}
						case Atom.Proto.Materials.MaterialChanged.PropertyOneofCase.Translucence: {
								Log.write(string.Format("Received MaterialChanged Translucence: ({0}/{1})", from.Translucence.AsFloat, from.Translucence.Texture), OutputVerbosity.Info);
								break;
							}
						case Atom.Proto.Materials.MaterialChanged.PropertyOneofCase.TranslucenceDepth: {
								Log.write(string.Format("Received MaterialChanged TranslucenceDepth: ({0}/{1})", from.TranslucenceDepth.AsFloat, from.TranslucenceDepth.Texture), OutputVerbosity.Info);
								break;
							}
						case Atom.Proto.Materials.MaterialChanged.PropertyOneofCase.TranslucenceFocus: {
								Log.write(string.Format("Received MaterialChanged TranslucenceFocus: ({0}/{1})", from.TranslucenceFocus.AsFloat, from.TranslucenceFocus.Texture), OutputVerbosity.Info);
								break;
							}
						case Atom.Proto.Materials.MaterialChanged.PropertyOneofCase.GlowIntensity: {
								Log.write(string.Format("Received MaterialChanged GlowIntensity: ({0}/{1})", from.GlowIntensity.AsFloat, from.GlowIntensity.Texture), OutputVerbosity.Info);
								break;
							}
						case Atom.Proto.Materials.MaterialChanged.PropertyOneofCase.SpecularColor: {
								mat.SpecularColor = new Vector3(from.SpecularColor.AsColor.R, from.SpecularColor.AsColor.G, from.SpecularColor.AsColor.B);
								Log.write(string.Format("Received MaterialChanged SpecularColor: ({0}/{1})", from.SpecularColor.AsColor, from.SpecularColor.Texture), OutputVerbosity.Info);
								break;
							}
						case Atom.Proto.Materials.MaterialChanged.PropertyOneofCase.Reflectivity: {
								mat.SpecularPower = from.Reflectivity.AsFloat; // tmp
								Log.write(string.Format("Received MaterialChanged Reflectivity: ({0}/{1})", from.Reflectivity.AsFloat, from.Reflectivity.Texture), OutputVerbosity.Info);
								break;
							}
						case Atom.Proto.Materials.MaterialChanged.PropertyOneofCase.ReflectedColor: {
								Log.write(string.Format("Received MaterialChanged ReflectedColor: ({0}/{1})", from.ReflectedColor.AsColor, from.ReflectedColor.Texture), OutputVerbosity.Info);
								break;
							}
						case Atom.Proto.Materials.MaterialChanged.PropertyOneofCase.Roughness: {
								mat.SpecularPower = from.Roughness.AsFloat; // tmp
								Log.write(string.Format("Received MaterialChanged Roughness: ({0}/{1})", from.Roughness.AsFloat, from.Roughness.Texture), OutputVerbosity.Info);
								break;
							}
						case Atom.Proto.Materials.MaterialChanged.PropertyOneofCase.CosinePower: {
								mat.SpecularPower = from.CosinePower.AsFloat;
								Log.write(string.Format("Received MaterialChanged CosinePower: ({0}/{1})", from.CosinePower.AsFloat, from.CosinePower.Texture), OutputVerbosity.Info);
								break;
							}
						case Atom.Proto.Materials.MaterialChanged.PropertyOneofCase.HighlightSize: {
								Log.write(string.Format("Received MaterialChanged HighlightSize: ({0}/{1})", from.HighlightSize.AsFloat, from.HighlightSize.Texture), OutputVerbosity.Info);
								break;
							}
						case Atom.Proto.Materials.MaterialChanged.PropertyOneofCase.Whiteness: {
								Log.write(string.Format("Received MaterialChanged Whiteness: ({0}/{1})", from.Whiteness.AsColor, from.Whiteness.Texture), OutputVerbosity.Info);
								break;
							}
						case Atom.Proto.Materials.MaterialChanged.PropertyOneofCase.Eccentricity: {
								Log.write(string.Format("Received MaterialChanged Eccentricity: ({0}/{1})", from.Eccentricity.AsFloat, from.Eccentricity.Texture), OutputVerbosity.Info);
								break;
							}
						case Atom.Proto.Materials.MaterialChanged.PropertyOneofCase.SpecularRollOff: {
								mat.SpecularPower = from.SpecularRollOff.AsFloat; // tmp
								Log.write(string.Format("Received MaterialChanged SpecularRollOff: ({0}/{1})", from.SpecularRollOff.AsFloat, from.SpecularRollOff.Texture), OutputVerbosity.Info);
								break;
							}
						case Atom.Proto.Materials.MaterialChanged.PropertyOneofCase.Angle: {
								Log.write(string.Format("Received MaterialChanged Angle: ({0}/{1})", from.Angle.AsFloat, from.Angle.Texture), OutputVerbosity.Info);
								break;
							}
						case Atom.Proto.Materials.MaterialChanged.PropertyOneofCase.SpreadX: {
								Log.write(string.Format("Received MaterialChanged SpreadX: ({0}/{1})", from.SpreadX.AsFloat, from.SpreadX.Texture), OutputVerbosity.Info);
								break;
							}
						case Atom.Proto.Materials.MaterialChanged.PropertyOneofCase.SpreadY: {
								Log.write(string.Format("Received MaterialChanged SpreadY: ({0}/{1})", from.SpreadY.AsFloat, from.SpreadY.Texture), OutputVerbosity.Info);
								break;
							}
						case Atom.Proto.Materials.MaterialChanged.PropertyOneofCase.FresnelIndex: {
								Log.write(string.Format("Received MaterialChanged FresnelIndex: ({0}/{1})", from.FresnelIndex.AsFloat, from.FresnelIndex.Texture), OutputVerbosity.Info);
								break;
							}
					}

				}
			}

			return true;
		}

		private void copyMaterialData( Atom.Proto.Materials.Material from, Scene.Material to ) {
			switch( from.Type ) {
				case Atom.Proto.Materials.MaterialType.kMaterialTypeLambert: {
					var mat = from.Lambert;
					to.DiffuseTextureName = mat.Color.Texture;
					to.DiffuseColor = new Vector3(mat.Color.AsColor.R, mat.Color.AsColor.G, mat.Color.AsColor.B);
					to.DiffuseAmount = mat.DiffuseAmount.AsFloat;
					to.AmbientColor = new Vector3(mat.AmbientColor.AsColor.R, mat.AmbientColor.AsColor.G, mat.AmbientColor.AsColor.B);
					to.BumpTextureName = mat.BumpMap;
					break;
				}
				case Atom.Proto.Materials.MaterialType.kMaterialTypePhong: {
					var mat = from.Phong;
					to.DiffuseTextureName = mat.Color.Texture;
					to.DiffuseColor = new Vector3(mat.Color.AsColor.R, mat.Color.AsColor.G, mat.Color.AsColor.B);
					to.DiffuseAmount = mat.DiffuseAmount.AsFloat;
					to.AmbientColor = new Vector3(mat.AmbientColor.AsColor.R, mat.AmbientColor.AsColor.G, mat.AmbientColor.AsColor.B);
					to.BumpTextureName = mat.BumpMap;
					to.SpecularColor = new Vector3(mat.SpecularColor.AsColor.R, mat.SpecularColor.AsColor.G, mat.SpecularColor.AsColor.B);
					to.SpecularPower = mat.Reflectivity.AsFloat;//mat.CosinePower.AsFloat;
					break;
				}
				case Atom.Proto.Materials.MaterialType.kMaterialTypePhongE: {
					var mat = from.Phonge;
					to.DiffuseTextureName = mat.Color.Texture;
					to.DiffuseColor = new Vector3(mat.Color.AsColor.R, mat.Color.AsColor.G, mat.Color.AsColor.B);
					to.DiffuseAmount = mat.DiffuseAmount.AsFloat;
					to.AmbientColor = new Vector3(mat.AmbientColor.AsColor.R, mat.AmbientColor.AsColor.G, mat.AmbientColor.AsColor.B);
					to.BumpTextureName = mat.BumpMap;
					to.SpecularColor = new Vector3(mat.SpecularColor.AsColor.R, mat.SpecularColor.AsColor.G, mat.SpecularColor.AsColor.B);
					to.SpecularPower = mat.Roughness.AsFloat;
					break;
				}
				case Atom.Proto.Materials.MaterialType.kMaterialTypeBlinn: {
					var mat = from.Blinn;
					to.DiffuseTextureName = mat.Color.Texture;
					to.DiffuseColor = new Vector3(mat.Color.AsColor.R, mat.Color.AsColor.G, mat.Color.AsColor.B);
					to.DiffuseAmount = mat.DiffuseAmount.AsFloat;
					to.AmbientColor = new Vector3(mat.AmbientColor.AsColor.R, mat.AmbientColor.AsColor.G, mat.AmbientColor.AsColor.B);
					to.BumpTextureName = mat.BumpMap;
					to.SpecularColor = new Vector3(mat.SpecularColor.AsColor.R, mat.SpecularColor.AsColor.G, mat.SpecularColor.AsColor.B);
					to.SpecularPower = mat.SpecularRollOff.AsFloat;
					break;
				}
				case Atom.Proto.Materials.MaterialType.kMaterialTypeAnisotropic: {
					var mat = from.Anisotropic;
					to.DiffuseTextureName = mat.Color.Texture;
					to.DiffuseColor = new Vector3(mat.Color.AsColor.R, mat.Color.AsColor.G, mat.Color.AsColor.B);
					to.DiffuseAmount = mat.DiffuseAmount.AsFloat;
					to.AmbientColor = new Vector3(mat.AmbientColor.AsColor.R, mat.AmbientColor.AsColor.G, mat.AmbientColor.AsColor.B);
					to.BumpTextureName = mat.BumpMap;
					to.SpecularColor = new Vector3(mat.SpecularColor.AsColor.R, mat.SpecularColor.AsColor.G, mat.SpecularColor.AsColor.B);
					to.SpecularPower = mat.Roughness.AsFloat;
					break;
				}
			}
		}
	}
}
