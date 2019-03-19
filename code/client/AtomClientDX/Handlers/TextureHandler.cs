using System;
using Microsoft.Xna.Framework.Graphics;

namespace AtomClient.Handlers {
	public class TextureHandler : IHandler {
		public bool handle( GraphicsDevice device, Atom.Proto.AtomMessage msg, atom.Client client, Scene.SceneManager scene ) {
			if( msg.MsgCase != Atom.Proto.AtomMessage.MsgOneofCase.Texture && msg.MsgCase != Atom.Proto.AtomMessage.MsgOneofCase.TextureChanged ) {
				return false;
			}

			if( msg.MsgCase == Atom.Proto.AtomMessage.MsgOneofCase.Texture ) {
				var existing = scene.getTextureByName(msg.Texture.TextureName);
				if( null == existing ) {
					var tex = new Scene.Texture(msg.Texture.TextureName);
					if( null == msg.Texture.Data.Bytes || msg.Texture.Data.Bytes.IsEmpty ) {
						tex.loadFromFile(device, msg.Texture.Data.Filename);
					} else {
						tex.loadFromBytes(device, msg.Texture.Data.Bytes.ToByteArray());
					}
					scene.addTexture(tex);
					Log.write(string.Format("Added new texture ({0}): {1}", msg.Texture.Data.Extension, tex.Name), OutputVerbosity.Info);
				} else {
					Log.write(string.Format("Tried to add new texture but the name was already taken: {0}", existing.Name), OutputVerbosity.Error);
				}
			}

			if( msg.MsgCase == Atom.Proto.AtomMessage.MsgOneofCase.TextureChanged ) {
				var existing = scene.getTextureByName(msg.TextureChanged.TextureName);
				if( null == existing ) {
					Log.write(string.Format("Tried updating a texture but it didn't exist: {0}", msg.TextureChanged.TextureName), OutputVerbosity.Error);
				} else {
					switch( msg.TextureChanged.PropertyCase ) {
						case Atom.Proto.Materials.TextureChanged.PropertyOneofCase.None: {
								Log.write(string.Format("Received TextureChanged but no data was set."), OutputVerbosity.Info);
								break;
							}
						case Atom.Proto.Materials.TextureChanged.PropertyOneofCase.Data: {
								//existing.TheTexture.Dispose();
								if( null == msg.TextureChanged.Data.Bytes || msg.TextureChanged.Data.Bytes.IsEmpty ) {
									existing.loadFromFile(device, msg.TextureChanged.Data.Filename);
								} else {
									existing.loadFromBytes(device, msg.TextureChanged.Data.Bytes.ToByteArray());
								}
								break;
							}
						case Atom.Proto.Materials.TextureChanged.PropertyOneofCase.TranslateFrame: {
								Log.write(string.Format("Received TextureChanged TranslateFrame: ({0}, {1})", msg.TextureChanged.TranslateFrame.X, msg.TextureChanged.TranslateFrame.Y), OutputVerbosity.Info);
								//existing.TranslateFrameU = msg.TextureChanged.TranslateFrameU;
								break;
							}
						case Atom.Proto.Materials.TextureChanged.PropertyOneofCase.RotateFrame: {
								Log.write(string.Format("Received TextureChanged RotateFrame: {0}", msg.TextureChanged.RotateFrame), OutputVerbosity.Info);
								//existing.RotateFrame = msg.TextureChanged.RotateFrame;
								break;
							}
						case Atom.Proto.Materials.TextureChanged.PropertyOneofCase.MirrorU: {
								Log.write(string.Format("Received TextureChanged MirrorU: {0}", msg.TextureChanged.MirrorU), OutputVerbosity.Info);
								//existing.MirrorU = msg.TextureChanged.MirrorU;
								break;
							}
						case Atom.Proto.Materials.TextureChanged.PropertyOneofCase.MirrorV: {
								Log.write(string.Format("Received TextureChanged MirrorV: {0}", msg.TextureChanged.MirrorV), OutputVerbosity.Info);
								//existing.MirrorV = msg.TextureChanged.MirrorV;
								break;
							}
						case Atom.Proto.Materials.TextureChanged.PropertyOneofCase.WrapU: {
								Log.write(string.Format("Received TextureChanged WrapU: {0}", msg.TextureChanged.WrapU), OutputVerbosity.Info);
								//existing.WrapU = msg.TextureChanged.WrapU;
								break;
							}
						case Atom.Proto.Materials.TextureChanged.PropertyOneofCase.WrapV: {
								Log.write(string.Format("Received TextureChanged WrapV: {0}", msg.TextureChanged.WrapV), OutputVerbosity.Info);
								//existing.WrapV = msg.TextureChanged.WrapV;
								break;
							}
						case Atom.Proto.Materials.TextureChanged.PropertyOneofCase.Repeat: {
								Log.write(string.Format("Received TextureChanged Repeat: {0}", msg.TextureChanged.Repeat), OutputVerbosity.Info);
								//existing.RepeatU = msg.TextureChanged.RepeatU;
								break;
							}
						case Atom.Proto.Materials.TextureChanged.PropertyOneofCase.Offset: {
								Log.write(string.Format("Received TextureChanged Offset: ({0}, {1})", msg.TextureChanged.Offset.X, msg.TextureChanged.Offset.Y), OutputVerbosity.Info);
								//existing.OffsetU = msg.TextureChanged.OffsetU;
								break;
							}
						case Atom.Proto.Materials.TextureChanged.PropertyOneofCase.Rotate: {
								Log.write(string.Format("Received TextureChanged Rotate: {0}", msg.TextureChanged.Rotate), OutputVerbosity.Info);
								//existing.RotateUV = msg.TextureChanged.RotateUV;
								break;
							}
						case Atom.Proto.Materials.TextureChanged.PropertyOneofCase.Noise: {
								Log.write(string.Format("Received TextureChanged Noise: ({0}, {1})", msg.TextureChanged.Noise.X, msg.TextureChanged.Noise.Y), OutputVerbosity.Info);
								//existing.NoiseU = msg.TextureChanged.NoiseU;
								break;
							}
					}
				}
			}

			return true;
		}
	}
}
