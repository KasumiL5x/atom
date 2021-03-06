// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Transform.proto
#pragma warning disable 1591, 0612, 3021
#region Designer generated code

using pb = global::Google.Protobuf;
using pbc = global::Google.Protobuf.Collections;
using pbr = global::Google.Protobuf.Reflection;
using scg = global::System.Collections.Generic;
namespace Atom.Proto {

  /// <summary>Holder for reflection information generated from Transform.proto</summary>
  [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
  public static partial class TransformReflection {

    #region Descriptor
    /// <summary>File descriptor for Transform.proto</summary>
    public static pbr::FileDescriptor Descriptor {
      get { return descriptor; }
    }
    private static pbr::FileDescriptor descriptor;

    static TransformReflection() {
      byte[] descriptorData = global::System.Convert.FromBase64String(
          string.Concat(
            "Cg9UcmFuc2Zvcm0ucHJvdG8SCmF0b20ucHJvdG8aD0NvbXBvbmVudC5wcm90",
            "bxoMTWF0cml4LnByb3RvIoIBCglUcmFuc2Zvcm0SDAoETmFtZRgBIAEoCRIh",
            "CgVXb3JsZBgCIAEoCzISLmF0b20ucHJvdG8uTWF0cml4EikKCkNvbXBvbmVu",
            "dHMYAyADKAsyFS5hdG9tLnByb3RvLkNvbXBvbmVudBIZChFJbml0aWFsVmlz",
            "aWJpbGl0eRgEIAEoCGIGcHJvdG8z"));
      descriptor = pbr::FileDescriptor.FromGeneratedCode(descriptorData,
          new pbr::FileDescriptor[] { global::Atom.Proto.ComponentReflection.Descriptor, global::Atom.Proto.MatrixReflection.Descriptor, },
          new pbr::GeneratedClrTypeInfo(null, new pbr::GeneratedClrTypeInfo[] {
            new pbr::GeneratedClrTypeInfo(typeof(global::Atom.Proto.Transform), global::Atom.Proto.Transform.Parser, new[]{ "Name", "World", "Components", "InitialVisibility" }, null, null, null)
          }));
    }
    #endregion

  }
  #region Messages
  [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
  public sealed partial class Transform : pb::IMessage<Transform> {
    private static readonly pb::MessageParser<Transform> _parser = new pb::MessageParser<Transform>(() => new Transform());
    public static pb::MessageParser<Transform> Parser { get { return _parser; } }

    public static pbr::MessageDescriptor Descriptor {
      get { return global::Atom.Proto.TransformReflection.Descriptor.MessageTypes[0]; }
    }

    pbr::MessageDescriptor pb::IMessage.Descriptor {
      get { return Descriptor; }
    }

    public Transform() {
      OnConstruction();
    }

    partial void OnConstruction();

    public Transform(Transform other) : this() {
      name_ = other.name_;
      World = other.world_ != null ? other.World.Clone() : null;
      components_ = other.components_.Clone();
      initialVisibility_ = other.initialVisibility_;
    }

    public Transform Clone() {
      return new Transform(this);
    }

    /// <summary>Field number for the "Name" field.</summary>
    public const int NameFieldNumber = 1;
    private string name_ = "";
    public string Name {
      get { return name_; }
      set {
        name_ = pb::ProtoPreconditions.CheckNotNull(value, "value");
      }
    }

    /// <summary>Field number for the "World" field.</summary>
    public const int WorldFieldNumber = 2;
    private global::Atom.Proto.Matrix world_;
    public global::Atom.Proto.Matrix World {
      get { return world_; }
      set {
        world_ = value;
      }
    }

    /// <summary>Field number for the "Components" field.</summary>
    public const int ComponentsFieldNumber = 3;
    private static readonly pb::FieldCodec<global::Atom.Proto.Component> _repeated_components_codec
        = pb::FieldCodec.ForMessage(26, global::Atom.Proto.Component.Parser);
    private readonly pbc::RepeatedField<global::Atom.Proto.Component> components_ = new pbc::RepeatedField<global::Atom.Proto.Component>();
    public pbc::RepeatedField<global::Atom.Proto.Component> Components {
      get { return components_; }
    }

    /// <summary>Field number for the "InitialVisibility" field.</summary>
    public const int InitialVisibilityFieldNumber = 4;
    private bool initialVisibility_;
    /// <summary>
    /// *&lt; Visibility upon creation. 
    /// </summary>
    public bool InitialVisibility {
      get { return initialVisibility_; }
      set {
        initialVisibility_ = value;
      }
    }

    public override bool Equals(object other) {
      return Equals(other as Transform);
    }

    public bool Equals(Transform other) {
      if (ReferenceEquals(other, null)) {
        return false;
      }
      if (ReferenceEquals(other, this)) {
        return true;
      }
      if (Name != other.Name) return false;
      if (!object.Equals(World, other.World)) return false;
      if(!components_.Equals(other.components_)) return false;
      if (InitialVisibility != other.InitialVisibility) return false;
      return true;
    }

    public override int GetHashCode() {
      int hash = 1;
      if (Name.Length != 0) hash ^= Name.GetHashCode();
      if (world_ != null) hash ^= World.GetHashCode();
      hash ^= components_.GetHashCode();
      if (InitialVisibility != false) hash ^= InitialVisibility.GetHashCode();
      return hash;
    }

    public override string ToString() {
      return pb::JsonFormatter.ToDiagnosticString(this);
    }

    public void WriteTo(pb::CodedOutputStream output) {
      if (Name.Length != 0) {
        output.WriteRawTag(10);
        output.WriteString(Name);
      }
      if (world_ != null) {
        output.WriteRawTag(18);
        output.WriteMessage(World);
      }
      components_.WriteTo(output, _repeated_components_codec);
      if (InitialVisibility != false) {
        output.WriteRawTag(32);
        output.WriteBool(InitialVisibility);
      }
    }

    public int CalculateSize() {
      int size = 0;
      if (Name.Length != 0) {
        size += 1 + pb::CodedOutputStream.ComputeStringSize(Name);
      }
      if (world_ != null) {
        size += 1 + pb::CodedOutputStream.ComputeMessageSize(World);
      }
      size += components_.CalculateSize(_repeated_components_codec);
      if (InitialVisibility != false) {
        size += 1 + 1;
      }
      return size;
    }

    public void MergeFrom(Transform other) {
      if (other == null) {
        return;
      }
      if (other.Name.Length != 0) {
        Name = other.Name;
      }
      if (other.world_ != null) {
        if (world_ == null) {
          world_ = new global::Atom.Proto.Matrix();
        }
        World.MergeFrom(other.World);
      }
      components_.Add(other.components_);
      if (other.InitialVisibility != false) {
        InitialVisibility = other.InitialVisibility;
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
            Name = input.ReadString();
            break;
          }
          case 18: {
            if (world_ == null) {
              world_ = new global::Atom.Proto.Matrix();
            }
            input.ReadMessage(world_);
            break;
          }
          case 26: {
            components_.AddEntriesFrom(input, _repeated_components_codec);
            break;
          }
          case 32: {
            InitialVisibility = input.ReadBool();
            break;
          }
        }
      }
    }

  }

  #endregion

}

#endregion Designer generated code
