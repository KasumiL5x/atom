// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Scene.proto
#pragma warning disable 1591, 0612, 3021
#region Designer generated code

using pb = global::Google.Protobuf;
using pbc = global::Google.Protobuf.Collections;
using pbr = global::Google.Protobuf.Reflection;
using scg = global::System.Collections.Generic;
namespace Atom.Proto {

  /// <summary>Holder for reflection information generated from Scene.proto</summary>
  [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
  public static partial class SceneReflection {

    #region Descriptor
    /// <summary>File descriptor for Scene.proto</summary>
    public static pbr::FileDescriptor Descriptor {
      get { return descriptor; }
    }
    private static pbr::FileDescriptor descriptor;

    static SceneReflection() {
      byte[] descriptorData = global::System.Convert.FromBase64String(
          string.Concat(
            "CgtTY2VuZS5wcm90bxIKYXRvbS5wcm90bxoRU2NlbmVPYmplY3QucHJvdG8i",
            "9AMKBVNjZW5lEjAKDlRyYW5zZmVyUmVhc29uGAEgASgOMhguYXRvbS5wcm90",
            "by5TY2VuZS5SZWFzb24SJwoGTWVzaGVzGAIgAygLMhcuYXRvbS5wcm90by5T",
            "Y2VuZU9iamVjdBInCgZMaWdodHMYAyADKAsyFy5hdG9tLnByb3RvLlNjZW5l",
            "T2JqZWN0EigKB0NhbWVyYXMYBCADKAsyFy5hdG9tLnByb3RvLlNjZW5lT2Jq",
            "ZWN0EioKCU1hdGVyaWFscxgFIAMoCzIXLmF0b20ucHJvdG8uU2NlbmVPYmpl",
            "Y3QSKQoIVGV4dHVyZXMYBiADKAsyFy5hdG9tLnByb3RvLlNjZW5lT2JqZWN0",
            "EisKClRyYW5zZm9ybXMYByADKAsyFy5hdG9tLnByb3RvLlNjZW5lT2JqZWN0",
            "EiwKC0Fubm90YXRpb25zGAggAygLMhcuYXRvbS5wcm90by5TY2VuZU9iamVj",
            "dBInCgZDdXJ2ZXMYCSADKAsyFy5hdG9tLnByb3RvLlNjZW5lT2JqZWN0ImIK",
            "BlJlYXNvbhIXChNrUmVidWlsZE9uQ29ubmVjdGVkEAASEQoNa1JlYnVpbGRP",
            "bk5ldxABEhIKDmtSZWJ1aWxkT25PcGVuEAISCgoGa0FkZGVkEAMSDAoIa1Jl",
            "bW92ZWQQBGIGcHJvdG8z"));
      descriptor = pbr::FileDescriptor.FromGeneratedCode(descriptorData,
          new pbr::FileDescriptor[] { global::Atom.Proto.SceneObjectReflection.Descriptor, },
          new pbr::GeneratedClrTypeInfo(null, new pbr::GeneratedClrTypeInfo[] {
            new pbr::GeneratedClrTypeInfo(typeof(global::Atom.Proto.Scene), global::Atom.Proto.Scene.Parser, new[]{ "TransferReason", "Meshes", "Lights", "Cameras", "Materials", "Textures", "Transforms", "Annotations", "Curves" }, null, new[]{ typeof(global::Atom.Proto.Scene.Types.Reason) }, null)
          }));
    }
    #endregion

  }
  #region Messages
  [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
  public sealed partial class Scene : pb::IMessage<Scene> {
    private static readonly pb::MessageParser<Scene> _parser = new pb::MessageParser<Scene>(() => new Scene());
    public static pb::MessageParser<Scene> Parser { get { return _parser; } }

    public static pbr::MessageDescriptor Descriptor {
      get { return global::Atom.Proto.SceneReflection.Descriptor.MessageTypes[0]; }
    }

    pbr::MessageDescriptor pb::IMessage.Descriptor {
      get { return Descriptor; }
    }

    public Scene() {
      OnConstruction();
    }

    partial void OnConstruction();

    public Scene(Scene other) : this() {
      transferReason_ = other.transferReason_;
      meshes_ = other.meshes_.Clone();
      lights_ = other.lights_.Clone();
      cameras_ = other.cameras_.Clone();
      materials_ = other.materials_.Clone();
      textures_ = other.textures_.Clone();
      transforms_ = other.transforms_.Clone();
      annotations_ = other.annotations_.Clone();
      curves_ = other.curves_.Clone();
    }

    public Scene Clone() {
      return new Scene(this);
    }

    /// <summary>Field number for the "TransferReason" field.</summary>
    public const int TransferReasonFieldNumber = 1;
    private global::Atom.Proto.Scene.Types.Reason transferReason_ = global::Atom.Proto.Scene.Types.Reason.kRebuildOnConnected;
    public global::Atom.Proto.Scene.Types.Reason TransferReason {
      get { return transferReason_; }
      set {
        transferReason_ = value;
      }
    }

    /// <summary>Field number for the "Meshes" field.</summary>
    public const int MeshesFieldNumber = 2;
    private static readonly pb::FieldCodec<global::Atom.Proto.SceneObject> _repeated_meshes_codec
        = pb::FieldCodec.ForMessage(18, global::Atom.Proto.SceneObject.Parser);
    private readonly pbc::RepeatedField<global::Atom.Proto.SceneObject> meshes_ = new pbc::RepeatedField<global::Atom.Proto.SceneObject>();
    public pbc::RepeatedField<global::Atom.Proto.SceneObject> Meshes {
      get { return meshes_; }
    }

    /// <summary>Field number for the "Lights" field.</summary>
    public const int LightsFieldNumber = 3;
    private static readonly pb::FieldCodec<global::Atom.Proto.SceneObject> _repeated_lights_codec
        = pb::FieldCodec.ForMessage(26, global::Atom.Proto.SceneObject.Parser);
    private readonly pbc::RepeatedField<global::Atom.Proto.SceneObject> lights_ = new pbc::RepeatedField<global::Atom.Proto.SceneObject>();
    public pbc::RepeatedField<global::Atom.Proto.SceneObject> Lights {
      get { return lights_; }
    }

    /// <summary>Field number for the "Cameras" field.</summary>
    public const int CamerasFieldNumber = 4;
    private static readonly pb::FieldCodec<global::Atom.Proto.SceneObject> _repeated_cameras_codec
        = pb::FieldCodec.ForMessage(34, global::Atom.Proto.SceneObject.Parser);
    private readonly pbc::RepeatedField<global::Atom.Proto.SceneObject> cameras_ = new pbc::RepeatedField<global::Atom.Proto.SceneObject>();
    public pbc::RepeatedField<global::Atom.Proto.SceneObject> Cameras {
      get { return cameras_; }
    }

    /// <summary>Field number for the "Materials" field.</summary>
    public const int MaterialsFieldNumber = 5;
    private static readonly pb::FieldCodec<global::Atom.Proto.SceneObject> _repeated_materials_codec
        = pb::FieldCodec.ForMessage(42, global::Atom.Proto.SceneObject.Parser);
    private readonly pbc::RepeatedField<global::Atom.Proto.SceneObject> materials_ = new pbc::RepeatedField<global::Atom.Proto.SceneObject>();
    public pbc::RepeatedField<global::Atom.Proto.SceneObject> Materials {
      get { return materials_; }
    }

    /// <summary>Field number for the "Textures" field.</summary>
    public const int TexturesFieldNumber = 6;
    private static readonly pb::FieldCodec<global::Atom.Proto.SceneObject> _repeated_textures_codec
        = pb::FieldCodec.ForMessage(50, global::Atom.Proto.SceneObject.Parser);
    private readonly pbc::RepeatedField<global::Atom.Proto.SceneObject> textures_ = new pbc::RepeatedField<global::Atom.Proto.SceneObject>();
    public pbc::RepeatedField<global::Atom.Proto.SceneObject> Textures {
      get { return textures_; }
    }

    /// <summary>Field number for the "Transforms" field.</summary>
    public const int TransformsFieldNumber = 7;
    private static readonly pb::FieldCodec<global::Atom.Proto.SceneObject> _repeated_transforms_codec
        = pb::FieldCodec.ForMessage(58, global::Atom.Proto.SceneObject.Parser);
    private readonly pbc::RepeatedField<global::Atom.Proto.SceneObject> transforms_ = new pbc::RepeatedField<global::Atom.Proto.SceneObject>();
    public pbc::RepeatedField<global::Atom.Proto.SceneObject> Transforms {
      get { return transforms_; }
    }

    /// <summary>Field number for the "Annotations" field.</summary>
    public const int AnnotationsFieldNumber = 8;
    private static readonly pb::FieldCodec<global::Atom.Proto.SceneObject> _repeated_annotations_codec
        = pb::FieldCodec.ForMessage(66, global::Atom.Proto.SceneObject.Parser);
    private readonly pbc::RepeatedField<global::Atom.Proto.SceneObject> annotations_ = new pbc::RepeatedField<global::Atom.Proto.SceneObject>();
    public pbc::RepeatedField<global::Atom.Proto.SceneObject> Annotations {
      get { return annotations_; }
    }

    /// <summary>Field number for the "Curves" field.</summary>
    public const int CurvesFieldNumber = 9;
    private static readonly pb::FieldCodec<global::Atom.Proto.SceneObject> _repeated_curves_codec
        = pb::FieldCodec.ForMessage(74, global::Atom.Proto.SceneObject.Parser);
    private readonly pbc::RepeatedField<global::Atom.Proto.SceneObject> curves_ = new pbc::RepeatedField<global::Atom.Proto.SceneObject>();
    public pbc::RepeatedField<global::Atom.Proto.SceneObject> Curves {
      get { return curves_; }
    }

    public override bool Equals(object other) {
      return Equals(other as Scene);
    }

    public bool Equals(Scene other) {
      if (ReferenceEquals(other, null)) {
        return false;
      }
      if (ReferenceEquals(other, this)) {
        return true;
      }
      if (TransferReason != other.TransferReason) return false;
      if(!meshes_.Equals(other.meshes_)) return false;
      if(!lights_.Equals(other.lights_)) return false;
      if(!cameras_.Equals(other.cameras_)) return false;
      if(!materials_.Equals(other.materials_)) return false;
      if(!textures_.Equals(other.textures_)) return false;
      if(!transforms_.Equals(other.transforms_)) return false;
      if(!annotations_.Equals(other.annotations_)) return false;
      if(!curves_.Equals(other.curves_)) return false;
      return true;
    }

    public override int GetHashCode() {
      int hash = 1;
      if (TransferReason != global::Atom.Proto.Scene.Types.Reason.kRebuildOnConnected) hash ^= TransferReason.GetHashCode();
      hash ^= meshes_.GetHashCode();
      hash ^= lights_.GetHashCode();
      hash ^= cameras_.GetHashCode();
      hash ^= materials_.GetHashCode();
      hash ^= textures_.GetHashCode();
      hash ^= transforms_.GetHashCode();
      hash ^= annotations_.GetHashCode();
      hash ^= curves_.GetHashCode();
      return hash;
    }

    public override string ToString() {
      return pb::JsonFormatter.ToDiagnosticString(this);
    }

    public void WriteTo(pb::CodedOutputStream output) {
      if (TransferReason != global::Atom.Proto.Scene.Types.Reason.kRebuildOnConnected) {
        output.WriteRawTag(8);
        output.WriteEnum((int) TransferReason);
      }
      meshes_.WriteTo(output, _repeated_meshes_codec);
      lights_.WriteTo(output, _repeated_lights_codec);
      cameras_.WriteTo(output, _repeated_cameras_codec);
      materials_.WriteTo(output, _repeated_materials_codec);
      textures_.WriteTo(output, _repeated_textures_codec);
      transforms_.WriteTo(output, _repeated_transforms_codec);
      annotations_.WriteTo(output, _repeated_annotations_codec);
      curves_.WriteTo(output, _repeated_curves_codec);
    }

    public int CalculateSize() {
      int size = 0;
      if (TransferReason != global::Atom.Proto.Scene.Types.Reason.kRebuildOnConnected) {
        size += 1 + pb::CodedOutputStream.ComputeEnumSize((int) TransferReason);
      }
      size += meshes_.CalculateSize(_repeated_meshes_codec);
      size += lights_.CalculateSize(_repeated_lights_codec);
      size += cameras_.CalculateSize(_repeated_cameras_codec);
      size += materials_.CalculateSize(_repeated_materials_codec);
      size += textures_.CalculateSize(_repeated_textures_codec);
      size += transforms_.CalculateSize(_repeated_transforms_codec);
      size += annotations_.CalculateSize(_repeated_annotations_codec);
      size += curves_.CalculateSize(_repeated_curves_codec);
      return size;
    }

    public void MergeFrom(Scene other) {
      if (other == null) {
        return;
      }
      if (other.TransferReason != global::Atom.Proto.Scene.Types.Reason.kRebuildOnConnected) {
        TransferReason = other.TransferReason;
      }
      meshes_.Add(other.meshes_);
      lights_.Add(other.lights_);
      cameras_.Add(other.cameras_);
      materials_.Add(other.materials_);
      textures_.Add(other.textures_);
      transforms_.Add(other.transforms_);
      annotations_.Add(other.annotations_);
      curves_.Add(other.curves_);
    }

    public void MergeFrom(pb::CodedInputStream input) {
      uint tag;
      while ((tag = input.ReadTag()) != 0) {
        switch(tag) {
          default:
            input.SkipLastField();
            break;
          case 8: {
            transferReason_ = (global::Atom.Proto.Scene.Types.Reason) input.ReadEnum();
            break;
          }
          case 18: {
            meshes_.AddEntriesFrom(input, _repeated_meshes_codec);
            break;
          }
          case 26: {
            lights_.AddEntriesFrom(input, _repeated_lights_codec);
            break;
          }
          case 34: {
            cameras_.AddEntriesFrom(input, _repeated_cameras_codec);
            break;
          }
          case 42: {
            materials_.AddEntriesFrom(input, _repeated_materials_codec);
            break;
          }
          case 50: {
            textures_.AddEntriesFrom(input, _repeated_textures_codec);
            break;
          }
          case 58: {
            transforms_.AddEntriesFrom(input, _repeated_transforms_codec);
            break;
          }
          case 66: {
            annotations_.AddEntriesFrom(input, _repeated_annotations_codec);
            break;
          }
          case 74: {
            curves_.AddEntriesFrom(input, _repeated_curves_codec);
            break;
          }
        }
      }
    }

    #region Nested types
    /// <summary>Container for nested types declared in the Scene message type.</summary>
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
    public static partial class Types {
      public enum Reason {
        /// <summary>
        /// *&lt; When a connection is made, the scene is sent. 
        /// </summary>
        kRebuildOnConnected = 0,
        /// <summary>
        /// *&lt; A new scene was created.  This can be treat as empty. 
        /// </summary>
        kRebuildOnNew = 1,
        /// <summary>
        /// *&lt; A new scene was opened.  This can be treat as a full scene. 
        /// </summary>
        kRebuildOnOpen = 2,
        /// <summary>
        /// *&lt; Nodes listed have been added to the scene. 
        /// </summary>
        kAdded = 3,
        /// <summary>
        /// *&lt; Nodes listed have been removed from the scene. 
        /// </summary>
        kRemoved = 4,
      }

    }
    #endregion

  }

  #endregion

}

#endregion Designer generated code
