// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: materials/TextureChanged.proto
#pragma warning disable 1591, 0612, 3021
#region Designer generated code

using pb = global::Google.Protobuf;
using pbc = global::Google.Protobuf.Collections;
using pbr = global::Google.Protobuf.Reflection;
using scg = global::System.Collections.Generic;
namespace Atom.Proto.Materials {

  /// <summary>Holder for reflection information generated from materials/TextureChanged.proto</summary>
  [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
  public static partial class TextureChangedReflection {

    #region Descriptor
    /// <summary>File descriptor for materials/TextureChanged.proto</summary>
    public static pbr::FileDescriptor Descriptor {
      get { return descriptor; }
    }
    private static pbr::FileDescriptor descriptor;

    static TextureChangedReflection() {
      byte[] descriptorData = global::System.Convert.FromBase64String(
          string.Concat(
            "Ch5tYXRlcmlhbHMvVGV4dHVyZUNoYW5nZWQucHJvdG8SFGF0b20ucHJvdG8u",
            "bWF0ZXJpYWxzGhttYXRlcmlhbHMvVGV4dHVyZURhdGEucHJvdG8aDVZlY3Rv",
            "cjIucHJvdG8i+AIKDlRleHR1cmVDaGFuZ2VkEhMKC1RleHR1cmVOYW1lGAEg",
            "ASgJEjEKBERhdGEYAiABKAsyIS5hdG9tLnByb3RvLm1hdGVyaWFscy5UZXh0",
            "dXJlRGF0YUgAEi0KDlRyYW5zbGF0ZUZyYW1lGAMgASgLMhMuYXRvbS5wcm90",
            "by5WZWN0b3IySAASFQoLUm90YXRlRnJhbWUYBCABKAJIABIRCgdNaXJyb3JV",
            "GAUgASgISAASEQoHTWlycm9yVhgGIAEoCEgAEg8KBVdyYXBVGAcgASgISAAS",
            "DwoFd3JhcFYYCCABKAhIABIlCgZSZXBlYXQYCSABKAsyEy5hdG9tLnByb3Rv",
            "LlZlY3RvcjJIABIlCgZPZmZzZXQYCiABKAsyEy5hdG9tLnByb3RvLlZlY3Rv",
            "cjJIABIQCgZSb3RhdGUYCyABKAJIABIkCgVOb2lzZRgMIAEoCzITLmF0b20u",
            "cHJvdG8uVmVjdG9yMkgAQgoKCFByb3BlcnR5YgZwcm90bzM="));
      descriptor = pbr::FileDescriptor.FromGeneratedCode(descriptorData,
          new pbr::FileDescriptor[] { global::Atom.Proto.Materials.TextureDataReflection.Descriptor, global::Atom.Proto.Vector2Reflection.Descriptor, },
          new pbr::GeneratedClrTypeInfo(null, new pbr::GeneratedClrTypeInfo[] {
            new pbr::GeneratedClrTypeInfo(typeof(global::Atom.Proto.Materials.TextureChanged), global::Atom.Proto.Materials.TextureChanged.Parser, new[]{ "TextureName", "Data", "TranslateFrame", "RotateFrame", "MirrorU", "MirrorV", "WrapU", "WrapV", "Repeat", "Offset", "Rotate", "Noise" }, new[]{ "Property" }, null, null)
          }));
    }
    #endregion

  }
  #region Messages
  [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
  public sealed partial class TextureChanged : pb::IMessage<TextureChanged> {
    private static readonly pb::MessageParser<TextureChanged> _parser = new pb::MessageParser<TextureChanged>(() => new TextureChanged());
    public static pb::MessageParser<TextureChanged> Parser { get { return _parser; } }

    public static pbr::MessageDescriptor Descriptor {
      get { return global::Atom.Proto.Materials.TextureChangedReflection.Descriptor.MessageTypes[0]; }
    }

    pbr::MessageDescriptor pb::IMessage.Descriptor {
      get { return Descriptor; }
    }

    public TextureChanged() {
      OnConstruction();
    }

    partial void OnConstruction();

    public TextureChanged(TextureChanged other) : this() {
      textureName_ = other.textureName_;
      switch (other.PropertyCase) {
        case PropertyOneofCase.Data:
          Data = other.Data.Clone();
          break;
        case PropertyOneofCase.TranslateFrame:
          TranslateFrame = other.TranslateFrame.Clone();
          break;
        case PropertyOneofCase.RotateFrame:
          RotateFrame = other.RotateFrame;
          break;
        case PropertyOneofCase.MirrorU:
          MirrorU = other.MirrorU;
          break;
        case PropertyOneofCase.MirrorV:
          MirrorV = other.MirrorV;
          break;
        case PropertyOneofCase.WrapU:
          WrapU = other.WrapU;
          break;
        case PropertyOneofCase.WrapV:
          WrapV = other.WrapV;
          break;
        case PropertyOneofCase.Repeat:
          Repeat = other.Repeat.Clone();
          break;
        case PropertyOneofCase.Offset:
          Offset = other.Offset.Clone();
          break;
        case PropertyOneofCase.Rotate:
          Rotate = other.Rotate;
          break;
        case PropertyOneofCase.Noise:
          Noise = other.Noise.Clone();
          break;
      }

    }

    public TextureChanged Clone() {
      return new TextureChanged(this);
    }

    /// <summary>Field number for the "TextureName" field.</summary>
    public const int TextureNameFieldNumber = 1;
    private string textureName_ = "";
    /// <summary>
    /// *&lt; Name of the texture that changed. 
    /// </summary>
    public string TextureName {
      get { return textureName_; }
      set {
        textureName_ = pb::ProtoPreconditions.CheckNotNull(value, "value");
      }
    }

    /// <summary>Field number for the "Data" field.</summary>
    public const int DataFieldNumber = 2;
    /// <summary>
    /// *&lt; Filename and raw data. 
    /// </summary>
    public global::Atom.Proto.Materials.TextureData Data {
      get { return propertyCase_ == PropertyOneofCase.Data ? (global::Atom.Proto.Materials.TextureData) property_ : null; }
      set {
        property_ = value;
        propertyCase_ = value == null ? PropertyOneofCase.None : PropertyOneofCase.Data;
      }
    }

    /// <summary>Field number for the "TranslateFrame" field.</summary>
    public const int TranslateFrameFieldNumber = 3;
    /// <summary>
    /// *&lt; TODO 
    /// </summary>
    public global::Atom.Proto.Vector2 TranslateFrame {
      get { return propertyCase_ == PropertyOneofCase.TranslateFrame ? (global::Atom.Proto.Vector2) property_ : null; }
      set {
        property_ = value;
        propertyCase_ = value == null ? PropertyOneofCase.None : PropertyOneofCase.TranslateFrame;
      }
    }

    /// <summary>Field number for the "RotateFrame" field.</summary>
    public const int RotateFrameFieldNumber = 4;
    /// <summary>
    /// *&lt; TODO 
    /// </summary>
    public float RotateFrame {
      get { return propertyCase_ == PropertyOneofCase.RotateFrame ? (float) property_ : 0F; }
      set {
        property_ = value;
        propertyCase_ = PropertyOneofCase.RotateFrame;
      }
    }

    /// <summary>Field number for the "MirrorU" field.</summary>
    public const int MirrorUFieldNumber = 5;
    /// <summary>
    /// *&lt; Mirror texcoords in U. 
    /// </summary>
    public bool MirrorU {
      get { return propertyCase_ == PropertyOneofCase.MirrorU ? (bool) property_ : false; }
      set {
        property_ = value;
        propertyCase_ = PropertyOneofCase.MirrorU;
      }
    }

    /// <summary>Field number for the "MirrorV" field.</summary>
    public const int MirrorVFieldNumber = 6;
    /// <summary>
    /// *&lt; Mirror texcoords in V. 
    /// </summary>
    public bool MirrorV {
      get { return propertyCase_ == PropertyOneofCase.MirrorV ? (bool) property_ : false; }
      set {
        property_ = value;
        propertyCase_ = PropertyOneofCase.MirrorV;
      }
    }

    /// <summary>Field number for the "WrapU" field.</summary>
    public const int WrapUFieldNumber = 7;
    /// <summary>
    /// *&lt; Wrap texcoords in U. 
    /// </summary>
    public bool WrapU {
      get { return propertyCase_ == PropertyOneofCase.WrapU ? (bool) property_ : false; }
      set {
        property_ = value;
        propertyCase_ = PropertyOneofCase.WrapU;
      }
    }

    /// <summary>Field number for the "wrapV" field.</summary>
    public const int WrapVFieldNumber = 8;
    /// <summary>
    /// *&lt; Wrap texcoords in V. 
    /// </summary>
    public bool WrapV {
      get { return propertyCase_ == PropertyOneofCase.WrapV ? (bool) property_ : false; }
      set {
        property_ = value;
        propertyCase_ = PropertyOneofCase.WrapV;
      }
    }

    /// <summary>Field number for the "Repeat" field.</summary>
    public const int RepeatFieldNumber = 9;
    /// <summary>
    /// *&lt; UV tiling. 
    /// </summary>
    public global::Atom.Proto.Vector2 Repeat {
      get { return propertyCase_ == PropertyOneofCase.Repeat ? (global::Atom.Proto.Vector2) property_ : null; }
      set {
        property_ = value;
        propertyCase_ = value == null ? PropertyOneofCase.None : PropertyOneofCase.Repeat;
      }
    }

    /// <summary>Field number for the "Offset" field.</summary>
    public const int OffsetFieldNumber = 10;
    /// <summary>
    /// *&lt; UV offset. 
    /// </summary>
    public global::Atom.Proto.Vector2 Offset {
      get { return propertyCase_ == PropertyOneofCase.Offset ? (global::Atom.Proto.Vector2) property_ : null; }
      set {
        property_ = value;
        propertyCase_ = value == null ? PropertyOneofCase.None : PropertyOneofCase.Offset;
      }
    }

    /// <summary>Field number for the "Rotate" field.</summary>
    public const int RotateFieldNumber = 11;
    /// <summary>
    /// *&lt; Rotation in degrees. 
    /// </summary>
    public float Rotate {
      get { return propertyCase_ == PropertyOneofCase.Rotate ? (float) property_ : 0F; }
      set {
        property_ = value;
        propertyCase_ = PropertyOneofCase.Rotate;
      }
    }

    /// <summary>Field number for the "Noise" field.</summary>
    public const int NoiseFieldNumber = 12;
    /// <summary>
    /// *&lt; Arbitrary noise. 
    /// </summary>
    public global::Atom.Proto.Vector2 Noise {
      get { return propertyCase_ == PropertyOneofCase.Noise ? (global::Atom.Proto.Vector2) property_ : null; }
      set {
        property_ = value;
        propertyCase_ = value == null ? PropertyOneofCase.None : PropertyOneofCase.Noise;
      }
    }

    private object property_;
    /// <summary>Enum of possible cases for the "Property" oneof.</summary>
    public enum PropertyOneofCase {
      None = 0,
      Data = 2,
      TranslateFrame = 3,
      RotateFrame = 4,
      MirrorU = 5,
      MirrorV = 6,
      WrapU = 7,
      WrapV = 8,
      Repeat = 9,
      Offset = 10,
      Rotate = 11,
      Noise = 12,
    }
    private PropertyOneofCase propertyCase_ = PropertyOneofCase.None;
    public PropertyOneofCase PropertyCase {
      get { return propertyCase_; }
    }

    public void ClearProperty() {
      propertyCase_ = PropertyOneofCase.None;
      property_ = null;
    }

    public override bool Equals(object other) {
      return Equals(other as TextureChanged);
    }

    public bool Equals(TextureChanged other) {
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
      if (PropertyCase != other.PropertyCase) return false;
      return true;
    }

    public override int GetHashCode() {
      int hash = 1;
      if (TextureName.Length != 0) hash ^= TextureName.GetHashCode();
      if (propertyCase_ == PropertyOneofCase.Data) hash ^= Data.GetHashCode();
      if (propertyCase_ == PropertyOneofCase.TranslateFrame) hash ^= TranslateFrame.GetHashCode();
      if (propertyCase_ == PropertyOneofCase.RotateFrame) hash ^= RotateFrame.GetHashCode();
      if (propertyCase_ == PropertyOneofCase.MirrorU) hash ^= MirrorU.GetHashCode();
      if (propertyCase_ == PropertyOneofCase.MirrorV) hash ^= MirrorV.GetHashCode();
      if (propertyCase_ == PropertyOneofCase.WrapU) hash ^= WrapU.GetHashCode();
      if (propertyCase_ == PropertyOneofCase.WrapV) hash ^= WrapV.GetHashCode();
      if (propertyCase_ == PropertyOneofCase.Repeat) hash ^= Repeat.GetHashCode();
      if (propertyCase_ == PropertyOneofCase.Offset) hash ^= Offset.GetHashCode();
      if (propertyCase_ == PropertyOneofCase.Rotate) hash ^= Rotate.GetHashCode();
      if (propertyCase_ == PropertyOneofCase.Noise) hash ^= Noise.GetHashCode();
      hash ^= (int) propertyCase_;
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
      if (propertyCase_ == PropertyOneofCase.Data) {
        output.WriteRawTag(18);
        output.WriteMessage(Data);
      }
      if (propertyCase_ == PropertyOneofCase.TranslateFrame) {
        output.WriteRawTag(26);
        output.WriteMessage(TranslateFrame);
      }
      if (propertyCase_ == PropertyOneofCase.RotateFrame) {
        output.WriteRawTag(37);
        output.WriteFloat(RotateFrame);
      }
      if (propertyCase_ == PropertyOneofCase.MirrorU) {
        output.WriteRawTag(40);
        output.WriteBool(MirrorU);
      }
      if (propertyCase_ == PropertyOneofCase.MirrorV) {
        output.WriteRawTag(48);
        output.WriteBool(MirrorV);
      }
      if (propertyCase_ == PropertyOneofCase.WrapU) {
        output.WriteRawTag(56);
        output.WriteBool(WrapU);
      }
      if (propertyCase_ == PropertyOneofCase.WrapV) {
        output.WriteRawTag(64);
        output.WriteBool(WrapV);
      }
      if (propertyCase_ == PropertyOneofCase.Repeat) {
        output.WriteRawTag(74);
        output.WriteMessage(Repeat);
      }
      if (propertyCase_ == PropertyOneofCase.Offset) {
        output.WriteRawTag(82);
        output.WriteMessage(Offset);
      }
      if (propertyCase_ == PropertyOneofCase.Rotate) {
        output.WriteRawTag(93);
        output.WriteFloat(Rotate);
      }
      if (propertyCase_ == PropertyOneofCase.Noise) {
        output.WriteRawTag(98);
        output.WriteMessage(Noise);
      }
    }

    public int CalculateSize() {
      int size = 0;
      if (TextureName.Length != 0) {
        size += 1 + pb::CodedOutputStream.ComputeStringSize(TextureName);
      }
      if (propertyCase_ == PropertyOneofCase.Data) {
        size += 1 + pb::CodedOutputStream.ComputeMessageSize(Data);
      }
      if (propertyCase_ == PropertyOneofCase.TranslateFrame) {
        size += 1 + pb::CodedOutputStream.ComputeMessageSize(TranslateFrame);
      }
      if (propertyCase_ == PropertyOneofCase.RotateFrame) {
        size += 1 + 4;
      }
      if (propertyCase_ == PropertyOneofCase.MirrorU) {
        size += 1 + 1;
      }
      if (propertyCase_ == PropertyOneofCase.MirrorV) {
        size += 1 + 1;
      }
      if (propertyCase_ == PropertyOneofCase.WrapU) {
        size += 1 + 1;
      }
      if (propertyCase_ == PropertyOneofCase.WrapV) {
        size += 1 + 1;
      }
      if (propertyCase_ == PropertyOneofCase.Repeat) {
        size += 1 + pb::CodedOutputStream.ComputeMessageSize(Repeat);
      }
      if (propertyCase_ == PropertyOneofCase.Offset) {
        size += 1 + pb::CodedOutputStream.ComputeMessageSize(Offset);
      }
      if (propertyCase_ == PropertyOneofCase.Rotate) {
        size += 1 + 4;
      }
      if (propertyCase_ == PropertyOneofCase.Noise) {
        size += 1 + pb::CodedOutputStream.ComputeMessageSize(Noise);
      }
      return size;
    }

    public void MergeFrom(TextureChanged other) {
      if (other == null) {
        return;
      }
      if (other.TextureName.Length != 0) {
        TextureName = other.TextureName;
      }
      switch (other.PropertyCase) {
        case PropertyOneofCase.Data:
          Data = other.Data;
          break;
        case PropertyOneofCase.TranslateFrame:
          TranslateFrame = other.TranslateFrame;
          break;
        case PropertyOneofCase.RotateFrame:
          RotateFrame = other.RotateFrame;
          break;
        case PropertyOneofCase.MirrorU:
          MirrorU = other.MirrorU;
          break;
        case PropertyOneofCase.MirrorV:
          MirrorV = other.MirrorV;
          break;
        case PropertyOneofCase.WrapU:
          WrapU = other.WrapU;
          break;
        case PropertyOneofCase.WrapV:
          WrapV = other.WrapV;
          break;
        case PropertyOneofCase.Repeat:
          Repeat = other.Repeat;
          break;
        case PropertyOneofCase.Offset:
          Offset = other.Offset;
          break;
        case PropertyOneofCase.Rotate:
          Rotate = other.Rotate;
          break;
        case PropertyOneofCase.Noise:
          Noise = other.Noise;
          break;
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
            global::Atom.Proto.Materials.TextureData subBuilder = new global::Atom.Proto.Materials.TextureData();
            if (propertyCase_ == PropertyOneofCase.Data) {
              subBuilder.MergeFrom(Data);
            }
            input.ReadMessage(subBuilder);
            Data = subBuilder;
            break;
          }
          case 26: {
            global::Atom.Proto.Vector2 subBuilder = new global::Atom.Proto.Vector2();
            if (propertyCase_ == PropertyOneofCase.TranslateFrame) {
              subBuilder.MergeFrom(TranslateFrame);
            }
            input.ReadMessage(subBuilder);
            TranslateFrame = subBuilder;
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
            global::Atom.Proto.Vector2 subBuilder = new global::Atom.Proto.Vector2();
            if (propertyCase_ == PropertyOneofCase.Repeat) {
              subBuilder.MergeFrom(Repeat);
            }
            input.ReadMessage(subBuilder);
            Repeat = subBuilder;
            break;
          }
          case 82: {
            global::Atom.Proto.Vector2 subBuilder = new global::Atom.Proto.Vector2();
            if (propertyCase_ == PropertyOneofCase.Offset) {
              subBuilder.MergeFrom(Offset);
            }
            input.ReadMessage(subBuilder);
            Offset = subBuilder;
            break;
          }
          case 93: {
            Rotate = input.ReadFloat();
            break;
          }
          case 98: {
            global::Atom.Proto.Vector2 subBuilder = new global::Atom.Proto.Vector2();
            if (propertyCase_ == PropertyOneofCase.Noise) {
              subBuilder.MergeFrom(Noise);
            }
            input.ReadMessage(subBuilder);
            Noise = subBuilder;
            break;
          }
        }
      }
    }

  }

  #endregion

}

#endregion Designer generated code
