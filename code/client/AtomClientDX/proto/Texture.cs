// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: materials/Texture.proto
#pragma warning disable 1591, 0612, 3021
#region Designer generated code

using pb = global::Google.Protobuf;
using pbc = global::Google.Protobuf.Collections;
using pbr = global::Google.Protobuf.Reflection;
using scg = global::System.Collections.Generic;
namespace Atom.Proto.Materials {

  /// <summary>Holder for reflection information generated from materials/Texture.proto</summary>
  [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
  public static partial class TextureReflection {

    #region Descriptor
    /// <summary>File descriptor for materials/Texture.proto</summary>
    public static pbr::FileDescriptor Descriptor {
      get { return descriptor; }
    }
    private static pbr::FileDescriptor descriptor;

    static TextureReflection() {
      byte[] descriptorData = global::System.Convert.FromBase64String(
          string.Concat(
            "ChdtYXRlcmlhbHMvVGV4dHVyZS5wcm90bxIUYXRvbS5wcm90by5tYXRlcmlh",
            "bHMaG21hdGVyaWFscy9UZXh0dXJlRGF0YS5wcm90bxoNVmVjdG9yMi5wcm90",
            "byLPAgoHVGV4dHVyZRITCgtUZXh0dXJlTmFtZRgBIAEoCRIvCgREYXRhGAIg",
            "ASgLMiEuYXRvbS5wcm90by5tYXRlcmlhbHMuVGV4dHVyZURhdGESKwoOVHJh",
            "bnNsYXRlRnJhbWUYAyABKAsyEy5hdG9tLnByb3RvLlZlY3RvcjISEwoLUm90",
            "YXRlRnJhbWUYBCABKAISDwoHTWlycm9yVRgFIAEoCBIPCgdNaXJyb3JWGAYg",
            "ASgIEg0KBVdyYXBVGAcgASgIEg0KBXdyYXBWGAggASgIEiMKBlJlcGVhdBgJ",
            "IAEoCzITLmF0b20ucHJvdG8uVmVjdG9yMhIjCgZPZmZzZXQYCiABKAsyEy5h",
            "dG9tLnByb3RvLlZlY3RvcjISDgoGUm90YXRlGAsgASgCEiIKBU5vaXNlGAwg",
            "ASgLMhMuYXRvbS5wcm90by5WZWN0b3IyYgZwcm90bzM="));
      descriptor = pbr::FileDescriptor.FromGeneratedCode(descriptorData,
          new pbr::FileDescriptor[] { global::Atom.Proto.Materials.TextureDataReflection.Descriptor, global::Atom.Proto.Vector2Reflection.Descriptor, },
          new pbr::GeneratedClrTypeInfo(null, new pbr::GeneratedClrTypeInfo[] {
            new pbr::GeneratedClrTypeInfo(typeof(global::Atom.Proto.Materials.Texture), global::Atom.Proto.Materials.Texture.Parser, new[]{ "TextureName", "Data", "TranslateFrame", "RotateFrame", "MirrorU", "MirrorV", "WrapU", "WrapV", "Repeat", "Offset", "Rotate", "Noise" }, null, null, null)
          }));
    }
    #endregion

  }
  #region Messages
  [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
  public sealed partial class Texture : pb::IMessage<Texture> {
    private static readonly pb::MessageParser<Texture> _parser = new pb::MessageParser<Texture>(() => new Texture());
    public static pb::MessageParser<Texture> Parser { get { return _parser; } }

    public static pbr::MessageDescriptor Descriptor {
      get { return global::Atom.Proto.Materials.TextureReflection.Descriptor.MessageTypes[0]; }
    }

    pbr::MessageDescriptor pb::IMessage.Descriptor {
      get { return Descriptor; }
    }

    public Texture() {
      OnConstruction();
    }

    partial void OnConstruction();

    public Texture(Texture other) : this() {
      textureName_ = other.textureName_;
      Data = other.data_ != null ? other.Data.Clone() : null;
      TranslateFrame = other.translateFrame_ != null ? other.TranslateFrame.Clone() : null;
      rotateFrame_ = other.rotateFrame_;
      mirrorU_ = other.mirrorU_;
      mirrorV_ = other.mirrorV_;
      wrapU_ = other.wrapU_;
      wrapV_ = other.wrapV_;
      Repeat = other.repeat_ != null ? other.Repeat.Clone() : null;
      Offset = other.offset_ != null ? other.Offset.Clone() : null;
      rotate_ = other.rotate_;
      Noise = other.noise_ != null ? other.Noise.Clone() : null;
    }

    public Texture Clone() {
      return new Texture(this);
    }

    /// <summary>Field number for the "TextureName" field.</summary>
    public const int TextureNameFieldNumber = 1;
    private string textureName_ = "";
    /// <summary>
    /// *&lt; Name of the texture node. 
    /// </summary>
    public string TextureName {
      get { return textureName_; }
      set {
        textureName_ = pb::ProtoPreconditions.CheckNotNull(value, "value");
      }
    }

    /// <summary>Field number for the "Data" field.</summary>
    public const int DataFieldNumber = 2;
    private global::Atom.Proto.Materials.TextureData data_;
    /// <summary>
    /// *&lt; Filename and raw data. 
    /// </summary>
    public global::Atom.Proto.Materials.TextureData Data {
      get { return data_; }
      set {
        data_ = value;
      }
    }

    /// <summary>Field number for the "TranslateFrame" field.</summary>
    public const int TranslateFrameFieldNumber = 3;
    private global::Atom.Proto.Vector2 translateFrame_;
    /// <summary>
    /// *&lt; TODO 
    /// </summary>
    public global::Atom.Proto.Vector2 TranslateFrame {
      get { return translateFrame_; }
      set {
        translateFrame_ = value;
      }
    }

    /// <summary>Field number for the "RotateFrame" field.</summary>
    public const int RotateFrameFieldNumber = 4;
    private float rotateFrame_;
    /// <summary>
    /// *&lt; TODO 
    /// </summary>
    public float RotateFrame {
      get { return rotateFrame_; }
      set {
        rotateFrame_ = value;
      }
    }

    /// <summary>Field number for the "MirrorU" field.</summary>
    public const int MirrorUFieldNumber = 5;
    private bool mirrorU_;
    /// <summary>
    /// *&lt; Mirror texcoords in U. 
    /// </summary>
    public bool MirrorU {
      get { return mirrorU_; }
      set {
        mirrorU_ = value;
      }
    }

    /// <summary>Field number for the "MirrorV" field.</summary>
    public const int MirrorVFieldNumber = 6;
    private bool mirrorV_;
    /// <summary>
    /// *&lt; Mirror texcoords in V. 
    /// </summary>
    public bool MirrorV {
      get { return mirrorV_; }
      set {
        mirrorV_ = value;
      }
    }

    /// <summary>Field number for the "WrapU" field.</summary>
    public const int WrapUFieldNumber = 7;
    private bool wrapU_;
    /// <summary>
    /// *&lt; Wrap texcoords in U. 
    /// </summary>
    public bool WrapU {
      get { return wrapU_; }
      set {
        wrapU_ = value;
      }
    }

    /// <summary>Field number for the "wrapV" field.</summary>
    public const int WrapVFieldNumber = 8;
    private bool wrapV_;
    /// <summary>
    /// *&lt; Wrap texcoords in V. 
    /// </summary>
    public bool WrapV {
      get { return wrapV_; }
      set {
        wrapV_ = value;
      }
    }

    /// <summary>Field number for the "Repeat" field.</summary>
    public const int RepeatFieldNumber = 9;
    private global::Atom.Proto.Vector2 repeat_;
    /// <summary>
    /// *&lt; UV tiling. 
    /// </summary>
    public global::Atom.Proto.Vector2 Repeat {
      get { return repeat_; }
      set {
        repeat_ = value;
      }
    }

    /// <summary>Field number for the "Offset" field.</summary>
    public const int OffsetFieldNumber = 10;
    private global::Atom.Proto.Vector2 offset_;
    /// <summary>
    /// *&lt; UV offset. 
    /// </summary>
    public global::Atom.Proto.Vector2 Offset {
      get { return offset_; }
      set {
        offset_ = value;
      }
    }

    /// <summary>Field number for the "Rotate" field.</summary>
    public const int RotateFieldNumber = 11;
    private float rotate_;
    /// <summary>
    /// *&lt; Rotation in degrees. 
    /// </summary>
    public float Rotate {
      get { return rotate_; }
      set {
        rotate_ = value;
      }
    }

    /// <summary>Field number for the "Noise" field.</summary>
    public const int NoiseFieldNumber = 12;
    private global::Atom.Proto.Vector2 noise_;
    /// <summary>
    /// *&lt; Arbitrary noise. 
    /// </summary>
    public global::Atom.Proto.Vector2 Noise {
      get { return noise_; }
      set {
        noise_ = value;
      }
    }

    public override bool Equals(object other) {
      return Equals(other as Texture);
    }

    public bool Equals(Texture other) {
      if (ReferenceEquals(other, null)) {
        return false;
      }
      if (ReferenceEquals(other, this)) {
        return true;
      }
      if (TextureName != other.TextureName) return false;
      if (!object.Equals(Data, other.Data)) return false;
      if (!object.Equals(TranslateFrame, other.TranslateFrame)) return false;
      if (RotateFrame != other.RotateFrame) return false;
      if (MirrorU != other.MirrorU) return false;
      if (MirrorV != other.MirrorV) return false;
      if (WrapU != other.WrapU) return false;
      if (WrapV != other.WrapV) return false;
      if (!object.Equals(Repeat, other.Repeat)) return false;
      if (!object.Equals(Offset, other.Offset)) return false;
      if (Rotate != other.Rotate) return false;
      if (!object.Equals(Noise, other.Noise)) return false;
      return true;
    }

    public override int GetHashCode() {
      int hash = 1;
      if (TextureName.Length != 0) hash ^= TextureName.GetHashCode();
      if (data_ != null) hash ^= Data.GetHashCode();
      if (translateFrame_ != null) hash ^= TranslateFrame.GetHashCode();
      if (RotateFrame != 0F) hash ^= RotateFrame.GetHashCode();
      if (MirrorU != false) hash ^= MirrorU.GetHashCode();
      if (MirrorV != false) hash ^= MirrorV.GetHashCode();
      if (WrapU != false) hash ^= WrapU.GetHashCode();
      if (WrapV != false) hash ^= WrapV.GetHashCode();
      if (repeat_ != null) hash ^= Repeat.GetHashCode();
      if (offset_ != null) hash ^= Offset.GetHashCode();
      if (Rotate != 0F) hash ^= Rotate.GetHashCode();
      if (noise_ != null) hash ^= Noise.GetHashCode();
      return hash;
    }

    public override string ToString() {
      return pb::JsonFormatter.ToDiagnosticString(this);
    }

    public void WriteTo(pb::CodedOutputStream output) {
      if (TextureName.Length != 0) {
        output.WriteRawTag(10);
        output.WriteString(TextureName);
      }
      if (data_ != null) {
        output.WriteRawTag(18);
        output.WriteMessage(Data);
      }
      if (translateFrame_ != null) {
        output.WriteRawTag(26);
        output.WriteMessage(TranslateFrame);
      }
      if (RotateFrame != 0F) {
        output.WriteRawTag(37);
        output.WriteFloat(RotateFrame);
      }
      if (MirrorU != false) {
        output.WriteRawTag(40);
        output.WriteBool(MirrorU);
      }
      if (MirrorV != false) {
        output.WriteRawTag(48);
        output.WriteBool(MirrorV);
      }
      if (WrapU != false) {
        output.WriteRawTag(56);
        output.WriteBool(WrapU);
      }
      if (WrapV != false) {
        output.WriteRawTag(64);
        output.WriteBool(WrapV);
      }
      if (repeat_ != null) {
        output.WriteRawTag(74);
        output.WriteMessage(Repeat);
      }
      if (offset_ != null) {
        output.WriteRawTag(82);
        output.WriteMessage(Offset);
      }
      if (Rotate != 0F) {
        output.WriteRawTag(93);
        output.WriteFloat(Rotate);
      }
      if (noise_ != null) {
        output.WriteRawTag(98);
        output.WriteMessage(Noise);
      }
    }

    public int CalculateSize() {
      int size = 0;
      if (TextureName.Length != 0) {
        size += 1 + pb::CodedOutputStream.ComputeStringSize(TextureName);
      }
      if (data_ != null) {
        size += 1 + pb::CodedOutputStream.ComputeMessageSize(Data);
      }
      if (translateFrame_ != null) {
        size += 1 + pb::CodedOutputStream.ComputeMessageSize(TranslateFrame);
      }
      if (RotateFrame != 0F) {
        size += 1 + 4;
      }
      if (MirrorU != false) {
        size += 1 + 1;
      }
      if (MirrorV != false) {
        size += 1 + 1;
      }
      if (WrapU != false) {
        size += 1 + 1;
      }
      if (WrapV != false) {
        size += 1 + 1;
      }
      if (repeat_ != null) {
        size += 1 + pb::CodedOutputStream.ComputeMessageSize(Repeat);
      }
      if (offset_ != null) {
        size += 1 + pb::CodedOutputStream.ComputeMessageSize(Offset);
      }
      if (Rotate != 0F) {
        size += 1 + 4;
      }
      if (noise_ != null) {
        size += 1 + pb::CodedOutputStream.ComputeMessageSize(Noise);
      }
      return size;
    }

    public void MergeFrom(Texture other) {
      if (other == null) {
        return;
      }
      if (other.TextureName.Length != 0) {
        TextureName = other.TextureName;
      }
      if (other.data_ != null) {
        if (data_ == null) {
          data_ = new global::Atom.Proto.Materials.TextureData();
        }
        Data.MergeFrom(other.Data);
      }
      if (other.translateFrame_ != null) {
        if (translateFrame_ == null) {
          translateFrame_ = new global::Atom.Proto.Vector2();
        }
        TranslateFrame.MergeFrom(other.TranslateFrame);
      }
      if (other.RotateFrame != 0F) {
        RotateFrame = other.RotateFrame;
      }
      if (other.MirrorU != false) {
        MirrorU = other.MirrorU;
      }
      if (other.MirrorV != false) {
        MirrorV = other.MirrorV;
      }
      if (other.WrapU != false) {
        WrapU = other.WrapU;
      }
      if (other.WrapV != false) {
        WrapV = other.WrapV;
      }
      if (other.repeat_ != null) {
        if (repeat_ == null) {
          repeat_ = new global::Atom.Proto.Vector2();
        }
        Repeat.MergeFrom(other.Repeat);
      }
      if (other.offset_ != null) {
        if (offset_ == null) {
          offset_ = new global::Atom.Proto.Vector2();
        }
        Offset.MergeFrom(other.Offset);
      }
      if (other.Rotate != 0F) {
        Rotate = other.Rotate;
      }
      if (other.noise_ != null) {
        if (noise_ == null) {
          noise_ = new global::Atom.Proto.Vector2();
        }
        Noise.MergeFrom(other.Noise);
      }
    }

    public void MergeFrom(pb::CodedInputStream input) {
      uint tag;
      while ((tag = input.ReadTag()) != 0) {
        switch(tag) {
          default:
            input.SkipLastField();
            break;
          case 10: {
            TextureName = input.ReadString();
            break;
          }
          case 18: {
            if (data_ == null) {
              data_ = new global::Atom.Proto.Materials.TextureData();
            }
            input.ReadMessage(data_);
            break;
          }
          case 26: {
            if (translateFrame_ == null) {
              translateFrame_ = new global::Atom.Proto.Vector2();
            }
            input.ReadMessage(translateFrame_);
            break;
          }
          case 37: {
            RotateFrame = input.ReadFloat();
            break;
          }
          case 40: {
            MirrorU = input.ReadBool();
            break;
          }
          case 48: {
            MirrorV = input.ReadBool();
            break;
          }
          case 56: {
            WrapU = input.ReadBool();
            break;
          }
          case 64: {
            WrapV = input.ReadBool();
            break;
          }
          case 74: {
            if (repeat_ == null) {
              repeat_ = new global::Atom.Proto.Vector2();
            }
            input.ReadMessage(repeat_);
            break;
          }
          case 82: {
            if (offset_ == null) {
              offset_ = new global::Atom.Proto.Vector2();
            }
            input.ReadMessage(offset_);
            break;
          }
          case 93: {
            Rotate = input.ReadFloat();
            break;
          }
          case 98: {
            if (noise_ == null) {
              noise_ = new global::Atom.Proto.Vector2();
            }
            input.ReadMessage(noise_);
            break;
          }
        }
      }
    }

  }

  #endregion

}

#endregion Designer generated code
