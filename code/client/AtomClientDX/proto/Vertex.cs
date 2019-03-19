// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Vertex.proto
#pragma warning disable 1591, 0612, 3021
#region Designer generated code

using pb = global::Google.Protobuf;
using pbc = global::Google.Protobuf.Collections;
using pbr = global::Google.Protobuf.Reflection;
using scg = global::System.Collections.Generic;
namespace Atom.Proto {

  /// <summary>Holder for reflection information generated from Vertex.proto</summary>
  [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
  public static partial class VertexReflection {

    #region Descriptor
    /// <summary>File descriptor for Vertex.proto</summary>
    public static pbr::FileDescriptor Descriptor {
      get { return descriptor; }
    }
    private static pbr::FileDescriptor descriptor;

    static VertexReflection() {
      byte[] descriptorData = global::System.Convert.FromBase64String(
          string.Concat(
            "CgxWZXJ0ZXgucHJvdG8SCmF0b20ucHJvdG8aDVZlY3RvcjIucHJvdG8aDVZl",
            "Y3RvcjMucHJvdG8aC0NvbG9yLnByb3RvIvkBCgZWZXJ0ZXgSDQoFSW5kZXgY",
            "ASABKAUSJQoIUG9zaXRpb24YAiABKAsyEy5hdG9tLnByb3RvLlZlY3RvcjMS",
            "IwoGTm9ybWFsGAMgASgLMhMuYXRvbS5wcm90by5WZWN0b3IzEiUKCFRleGNv",
            "b3JkGAQgAygLMhMuYXRvbS5wcm90by5WZWN0b3IyEiQKB1RhbmdlbnQYBSAD",
            "KAsyEy5hdG9tLnByb3RvLlZlY3RvcjMSJQoIQmlub3JtYWwYBiADKAsyEy5h",
            "dG9tLnByb3RvLlZlY3RvcjMSIAoFQ29sb3IYByADKAsyES5hdG9tLnByb3Rv",
            "LkNvbG9yYgZwcm90bzM="));
      descriptor = pbr::FileDescriptor.FromGeneratedCode(descriptorData,
          new pbr::FileDescriptor[] { global::Atom.Proto.Vector2Reflection.Descriptor, global::Atom.Proto.Vector3Reflection.Descriptor, global::Atom.Proto.ColorReflection.Descriptor, },
          new pbr::GeneratedClrTypeInfo(null, new pbr::GeneratedClrTypeInfo[] {
            new pbr::GeneratedClrTypeInfo(typeof(global::Atom.Proto.Vertex), global::Atom.Proto.Vertex.Parser, new[]{ "Index", "Position", "Normal", "Texcoord", "Tangent", "Binormal", "Color" }, null, null, null)
          }));
    }
    #endregion

  }
  #region Messages
  [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
  public sealed partial class Vertex : pb::IMessage<Vertex> {
    private static readonly pb::MessageParser<Vertex> _parser = new pb::MessageParser<Vertex>(() => new Vertex());
    public static pb::MessageParser<Vertex> Parser { get { return _parser; } }

    public static pbr::MessageDescriptor Descriptor {
      get { return global::Atom.Proto.VertexReflection.Descriptor.MessageTypes[0]; }
    }

    pbr::MessageDescriptor pb::IMessage.Descriptor {
      get { return Descriptor; }
    }

    public Vertex() {
      OnConstruction();
    }

    partial void OnConstruction();

    public Vertex(Vertex other) : this() {
      index_ = other.index_;
      Position = other.position_ != null ? other.Position.Clone() : null;
      Normal = other.normal_ != null ? other.Normal.Clone() : null;
      texcoord_ = other.texcoord_.Clone();
      tangent_ = other.tangent_.Clone();
      binormal_ = other.binormal_.Clone();
      color_ = other.color_.Clone();
    }

    public Vertex Clone() {
      return new Vertex(this);
    }

    /// <summary>Field number for the "Index" field.</summary>
    public const int IndexFieldNumber = 1;
    private int index_;
    public int Index {
      get { return index_; }
      set {
        index_ = value;
      }
    }

    /// <summary>Field number for the "Position" field.</summary>
    public const int PositionFieldNumber = 2;
    private global::Atom.Proto.Vector3 position_;
    public global::Atom.Proto.Vector3 Position {
      get { return position_; }
      set {
        position_ = value;
      }
    }

    /// <summary>Field number for the "Normal" field.</summary>
    public const int NormalFieldNumber = 3;
    private global::Atom.Proto.Vector3 normal_;
    public global::Atom.Proto.Vector3 Normal {
      get { return normal_; }
      set {
        normal_ = value;
      }
    }

    /// <summary>Field number for the "Texcoord" field.</summary>
    public const int TexcoordFieldNumber = 4;
    private static readonly pb::FieldCodec<global::Atom.Proto.Vector2> _repeated_texcoord_codec
        = pb::FieldCodec.ForMessage(34, global::Atom.Proto.Vector2.Parser);
    private readonly pbc::RepeatedField<global::Atom.Proto.Vector2> texcoord_ = new pbc::RepeatedField<global::Atom.Proto.Vector2>();
    public pbc::RepeatedField<global::Atom.Proto.Vector2> Texcoord {
      get { return texcoord_; }
    }

    /// <summary>Field number for the "Tangent" field.</summary>
    public const int TangentFieldNumber = 5;
    private static readonly pb::FieldCodec<global::Atom.Proto.Vector3> _repeated_tangent_codec
        = pb::FieldCodec.ForMessage(42, global::Atom.Proto.Vector3.Parser);
    private readonly pbc::RepeatedField<global::Atom.Proto.Vector3> tangent_ = new pbc::RepeatedField<global::Atom.Proto.Vector3>();
    public pbc::RepeatedField<global::Atom.Proto.Vector3> Tangent {
      get { return tangent_; }
    }

    /// <summary>Field number for the "Binormal" field.</summary>
    public const int BinormalFieldNumber = 6;
    private static readonly pb::FieldCodec<global::Atom.Proto.Vector3> _repeated_binormal_codec
        = pb::FieldCodec.ForMessage(50, global::Atom.Proto.Vector3.Parser);
    private readonly pbc::RepeatedField<global::Atom.Proto.Vector3> binormal_ = new pbc::RepeatedField<global::Atom.Proto.Vector3>();
    public pbc::RepeatedField<global::Atom.Proto.Vector3> Binormal {
      get { return binormal_; }
    }

    /// <summary>Field number for the "Color" field.</summary>
    public const int ColorFieldNumber = 7;
    private static readonly pb::FieldCodec<global::Atom.Proto.Color> _repeated_color_codec
        = pb::FieldCodec.ForMessage(58, global::Atom.Proto.Color.Parser);
    private readonly pbc::RepeatedField<global::Atom.Proto.Color> color_ = new pbc::RepeatedField<global::Atom.Proto.Color>();
    public pbc::RepeatedField<global::Atom.Proto.Color> Color {
      get { return color_; }
    }

    public override bool Equals(object other) {
      return Equals(other as Vertex);
    }

    public bool Equals(Vertex other) {
      if (ReferenceEquals(other, null)) {
        return false;
      }
      if (ReferenceEquals(other, this)) {
        return true;
      }
      if (Index != other.Index) return false;
      if (!object.Equals(Position, other.Position)) return false;
      if (!object.Equals(Normal, other.Normal)) return false;
      if(!texcoord_.Equals(other.texcoord_)) return false;
      if(!tangent_.Equals(other.tangent_)) return false;
      if(!binormal_.Equals(other.binormal_)) return false;
      if(!color_.Equals(other.color_)) return false;
      return true;
    }

    public override int GetHashCode() {
      int hash = 1;
      if (Index != 0) hash ^= Index.GetHashCode();
      if (position_ != null) hash ^= Position.GetHashCode();
      if (normal_ != null) hash ^= Normal.GetHashCode();
      hash ^= texcoord_.GetHashCode();
      hash ^= tangent_.GetHashCode();
      hash ^= binormal_.GetHashCode();
      hash ^= color_.GetHashCode();
      return hash;
    }

    public override string ToString() {
      return pb::JsonFormatter.ToDiagnosticString(this);
    }

    public void WriteTo(pb::CodedOutputStream output) {
      if (Index != 0) {
        output.WriteRawTag(8);
        output.WriteInt32(Index);
      }
      if (position_ != null) {
        output.WriteRawTag(18);
        output.WriteMessage(Position);
      }
      if (normal_ != null) {
        output.WriteRawTag(26);
        output.WriteMessage(Normal);
      }
      texcoord_.WriteTo(output, _repeated_texcoord_codec);
      tangent_.WriteTo(output, _repeated_tangent_codec);
      binormal_.WriteTo(output, _repeated_binormal_codec);
      color_.WriteTo(output, _repeated_color_codec);
    }

    public int CalculateSize() {
      int size = 0;
      if (Index != 0) {
        size += 1 + pb::CodedOutputStream.ComputeInt32Size(Index);
      }
      if (position_ != null) {
        size += 1 + pb::CodedOutputStream.ComputeMessageSize(Position);
      }
      if (normal_ != null) {
        size += 1 + pb::CodedOutputStream.ComputeMessageSize(Normal);
      }
      size += texcoord_.CalculateSize(_repeated_texcoord_codec);
      size += tangent_.CalculateSize(_repeated_tangent_codec);
      size += binormal_.CalculateSize(_repeated_binormal_codec);
      size += color_.CalculateSize(_repeated_color_codec);
      return size;
    }

    public void MergeFrom(Vertex other) {
      if (other == null) {
        return;
      }
      if (other.Index != 0) {
        Index = other.Index;
      }
      if (other.position_ != null) {
        if (position_ == null) {
          position_ = new global::Atom.Proto.Vector3();
        }
        Position.MergeFrom(other.Position);
      }
      if (other.normal_ != null) {
        if (normal_ == null) {
          normal_ = new global::Atom.Proto.Vector3();
        }
        Normal.MergeFrom(other.Normal);
      }
      texcoord_.Add(other.texcoord_);
      tangent_.Add(other.tangent_);
      binormal_.Add(other.binormal_);
      color_.Add(other.color_);
    }

    public void MergeFrom(pb::CodedInputStream input) {
      uint tag;
      while ((tag = input.ReadTag()) != 0) {
        switch(tag) {
          default:
            input.SkipLastField();
            break;
          case 8: {
            Index = input.ReadInt32();
            break;
          }
          case 18: {
            if (position_ == null) {
              position_ = new global::Atom.Proto.Vector3();
            }
            input.ReadMessage(position_);
            break;
          }
          case 26: {
            if (normal_ == null) {
              normal_ = new global::Atom.Proto.Vector3();
            }
            input.ReadMessage(normal_);
            break;
          }
          case 34: {
            texcoord_.AddEntriesFrom(input, _repeated_texcoord_codec);
            break;
          }
          case 42: {
            tangent_.AddEntriesFrom(input, _repeated_tangent_codec);
            break;
          }
          case 50: {
            binormal_.AddEntriesFrom(input, _repeated_binormal_codec);
            break;
          }
          case 58: {
            color_.AddEntriesFrom(input, _repeated_color_codec);
            break;
          }
        }
      }
    }

  }

  #endregion

}

#endregion Designer generated code