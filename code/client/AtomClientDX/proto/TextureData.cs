// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: materials/TextureData.proto
#pragma warning disable 1591, 0612, 3021
#region Designer generated code

using pb = global::Google.Protobuf;
using pbc = global::Google.Protobuf.Collections;
using pbr = global::Google.Protobuf.Reflection;
using scg = global::System.Collections.Generic;
namespace Atom.Proto.Materials {

  /// <summary>Holder for reflection information generated from materials/TextureData.proto</summary>
  [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
  public static partial class TextureDataReflection {

    #region Descriptor
    /// <summary>File descriptor for materials/TextureData.proto</summary>
    public static pbr::FileDescriptor Descriptor {
      get { return descriptor; }
    }
    private static pbr::FileDescriptor descriptor;

    static TextureDataReflection() {
      byte[] descriptorData = global::System.Convert.FromBase64String(
          string.Concat(
            "ChttYXRlcmlhbHMvVGV4dHVyZURhdGEucHJvdG8SFGF0b20ucHJvdG8ubWF0",
            "ZXJpYWxzIkEKC1RleHR1cmVEYXRhEhAKCEZpbGVuYW1lGAEgASgJEhEKCUV4",
            "dGVuc2lvbhgCIAEoCRINCgVCeXRlcxgDIAEoDGIGcHJvdG8z"));
      descriptor = pbr::FileDescriptor.FromGeneratedCode(descriptorData,
          new pbr::FileDescriptor[] { },
          new pbr::GeneratedClrTypeInfo(null, new pbr::GeneratedClrTypeInfo[] {
            new pbr::GeneratedClrTypeInfo(typeof(global::Atom.Proto.Materials.TextureData), global::Atom.Proto.Materials.TextureData.Parser, new[]{ "Filename", "Extension", "Bytes" }, null, null, null)
          }));
    }
    #endregion

  }
  #region Messages
  [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
  public sealed partial class TextureData : pb::IMessage<TextureData> {
    private static readonly pb::MessageParser<TextureData> _parser = new pb::MessageParser<TextureData>(() => new TextureData());
    public static pb::MessageParser<TextureData> Parser { get { return _parser; } }

    public static pbr::MessageDescriptor Descriptor {
      get { return global::Atom.Proto.Materials.TextureDataReflection.Descriptor.MessageTypes[0]; }
    }

    pbr::MessageDescriptor pb::IMessage.Descriptor {
      get { return Descriptor; }
    }

    public TextureData() {
      OnConstruction();
    }

    partial void OnConstruction();

    public TextureData(TextureData other) : this() {
      filename_ = other.filename_;
      extension_ = other.extension_;
      bytes_ = other.bytes_;
    }

    public TextureData Clone() {
      return new TextureData(this);
    }

    /// <summary>Field number for the "Filename" field.</summary>
    public const int FilenameFieldNumber = 1;
    private string filename_ = "";
    /// <summary>
    /// *&lt; Local filename of the texture. 
    /// </summary>
    public string Filename {
      get { return filename_; }
      set {
        filename_ = pb::ProtoPreconditions.CheckNotNull(value, "value");
      }
    }

    /// <summary>Field number for the "Extension" field.</summary>
    public const int ExtensionFieldNumber = 2;
    private string extension_ = "";
    /// <summary>
    /// *&lt; Extension of the file. 
    /// </summary>
    public string Extension {
      get { return extension_; }
      set {
        extension_ = pb::ProtoPreconditions.CheckNotNull(value, "value");
      }
    }

    /// <summary>Field number for the "Bytes" field.</summary>
    public const int BytesFieldNumber = 3;
    private pb::ByteString bytes_ = pb::ByteString.Empty;
    /// <summary>
    /// *&lt; Raw bytes of the texture. 
    /// </summary>
    public pb::ByteString Bytes {
      get { return bytes_; }
      set {
        bytes_ = pb::ProtoPreconditions.CheckNotNull(value, "value");
      }
    }

    public override bool Equals(object other) {
      return Equals(other as TextureData);
    }

    public bool Equals(TextureData other) {
      if (ReferenceEquals(other, null)) {
        return false;
      }
      if (ReferenceEquals(other, this)) {
        return true;
      }
      if (Filename != other.Filename) return false;
      if (Extension != other.Extension) return false;
      if (Bytes != other.Bytes) return false;
      return true;
    }

    public override int GetHashCode() {
      int hash = 1;
      if (Filename.Length != 0) hash ^= Filename.GetHashCode();
      if (Extension.Length != 0) hash ^= Extension.GetHashCode();
      if (Bytes.Length != 0) hash ^= Bytes.GetHashCode();
      return hash;
    }

    public override string ToString() {
      return pb::JsonFormatter.ToDiagnosticString(this);
    }

    public void WriteTo(pb::CodedOutputStream output) {
      if (Filename.Length != 0) {
        output.WriteRawTag(10);
        output.WriteString(Filename);
      }
      if (Extension.Length != 0) {
        output.WriteRawTag(18);
        output.WriteString(Extension);
      }
      if (Bytes.Length != 0) {
        output.WriteRawTag(26);
        output.WriteBytes(Bytes);
      }
    }

    public int CalculateSize() {
      int size = 0;
      if (Filename.Length != 0) {
        size += 1 + pb::CodedOutputStream.ComputeStringSize(Filename);
      }
      if (Extension.Length != 0) {
        size += 1 + pb::CodedOutputStream.ComputeStringSize(Extension);
      }
      if (Bytes.Length != 0) {
        size += 1 + pb::CodedOutputStream.ComputeBytesSize(Bytes);
      }
      return size;
    }

    public void MergeFrom(TextureData other) {
      if (other == null) {
        return;
      }
      if (other.Filename.Length != 0) {
        Filename = other.Filename;
      }
      if (other.Extension.Length != 0) {
        Extension = other.Extension;
      }
      if (other.Bytes.Length != 0) {
        Bytes = other.Bytes;
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
            Filename = input.ReadString();
            break;
          }
          case 18: {
            Extension = input.ReadString();
            break;
          }
          case 26: {
            Bytes = input.ReadBytes();
            break;
          }
        }
      }
    }

  }

  #endregion

}

#endregion Designer generated code
