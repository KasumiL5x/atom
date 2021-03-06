// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Component.proto
#pragma warning disable 1591, 0612, 3021
#region Designer generated code

using pb = global::Google.Protobuf;
using pbc = global::Google.Protobuf.Collections;
using pbr = global::Google.Protobuf.Reflection;
using scg = global::System.Collections.Generic;
namespace Atom.Proto {

  /// <summary>Holder for reflection information generated from Component.proto</summary>
  [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
  public static partial class ComponentReflection {

    #region Descriptor
    /// <summary>File descriptor for Component.proto</summary>
    public static pbr::FileDescriptor Descriptor {
      get { return descriptor; }
    }
    private static pbr::FileDescriptor descriptor;

    static ComponentReflection() {
      byte[] descriptorData = global::System.Convert.FromBase64String(
          string.Concat(
            "Cg9Db21wb25lbnQucHJvdG8SCmF0b20ucHJvdG8ingEKCUNvbXBvbmVudBIx",
            "CgRUeXBlGAEgASgOMiMuYXRvbS5wcm90by5Db21wb25lbnQuQ29tcG9uZW50",
            "VHlwZRIMCgROYW1lGAIgASgJIlAKDUNvbXBvbmVudFR5cGUSCQoFa01lc2gQ",
            "ABIKCgZrTGlnaHQQAhILCgdrQ2FtZXJhEAMSDwoLa0Fubm90YXRpb24QBBIK",
            "CgZrQ3VydmUQBWIGcHJvdG8z"));
      descriptor = pbr::FileDescriptor.FromGeneratedCode(descriptorData,
          new pbr::FileDescriptor[] { },
          new pbr::GeneratedClrTypeInfo(null, new pbr::GeneratedClrTypeInfo[] {
            new pbr::GeneratedClrTypeInfo(typeof(global::Atom.Proto.Component), global::Atom.Proto.Component.Parser, new[]{ "Type", "Name" }, null, new[]{ typeof(global::Atom.Proto.Component.Types.ComponentType) }, null)
          }));
    }
    #endregion

  }
  #region Messages
  [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
  public sealed partial class Component : pb::IMessage<Component> {
    private static readonly pb::MessageParser<Component> _parser = new pb::MessageParser<Component>(() => new Component());
    public static pb::MessageParser<Component> Parser { get { return _parser; } }

    public static pbr::MessageDescriptor Descriptor {
      get { return global::Atom.Proto.ComponentReflection.Descriptor.MessageTypes[0]; }
    }

    pbr::MessageDescriptor pb::IMessage.Descriptor {
      get { return Descriptor; }
    }

    public Component() {
      OnConstruction();
    }

    partial void OnConstruction();

    public Component(Component other) : this() {
      type_ = other.type_;
      name_ = other.name_;
    }

    public Component Clone() {
      return new Component(this);
    }

    /// <summary>Field number for the "Type" field.</summary>
    public const int TypeFieldNumber = 1;
    private global::Atom.Proto.Component.Types.ComponentType type_ = global::Atom.Proto.Component.Types.ComponentType.kMesh;
    public global::Atom.Proto.Component.Types.ComponentType Type {
      get { return type_; }
      set {
        type_ = value;
      }
    }

    /// <summary>Field number for the "Name" field.</summary>
    public const int NameFieldNumber = 2;
    private string name_ = "";
    public string Name {
      get { return name_; }
      set {
        name_ = pb::ProtoPreconditions.CheckNotNull(value, "value");
      }
    }

    public override bool Equals(object other) {
      return Equals(other as Component);
    }

    public bool Equals(Component other) {
      if (ReferenceEquals(other, null)) {
        return false;
      }
      if (ReferenceEquals(other, this)) {
        return true;
      }
      if (Type != other.Type) return false;
      if (Name != other.Name) return false;
      return true;
    }

    public override int GetHashCode() {
      int hash = 1;
      if (Type != global::Atom.Proto.Component.Types.ComponentType.kMesh) hash ^= Type.GetHashCode();
      if (Name.Length != 0) hash ^= Name.GetHashCode();
      return hash;
    }

    public override string ToString() {
      return pb::JsonFormatter.ToDiagnosticString(this);
    }

    public void WriteTo(pb::CodedOutputStream output) {
      if (Type != global::Atom.Proto.Component.Types.ComponentType.kMesh) {
        output.WriteRawTag(8);
        output.WriteEnum((int) Type);
      }
      if (Name.Length != 0) {
        output.WriteRawTag(18);
        output.WriteString(Name);
      }
    }

    public int CalculateSize() {
      int size = 0;
      if (Type != global::Atom.Proto.Component.Types.ComponentType.kMesh) {
        size += 1 + pb::CodedOutputStream.ComputeEnumSize((int) Type);
      }
      if (Name.Length != 0) {
        size += 1 + pb::CodedOutputStream.ComputeStringSize(Name);
      }
      return size;
    }

    public void MergeFrom(Component other) {
      if (other == null) {
        return;
      }
      if (other.Type != global::Atom.Proto.Component.Types.ComponentType.kMesh) {
        Type = other.Type;
      }
      if (other.Name.Length != 0) {
        Name = other.Name;
      }
    }

    public void MergeFrom(pb::CodedInputStream input) {
      uint tag;
      while ((tag = input.ReadTag()) != 0) {
        switch(tag) {
          default:
            input.SkipLastField();
            break;
          case 8: {
            type_ = (global::Atom.Proto.Component.Types.ComponentType) input.ReadEnum();
            break;
          }
          case 18: {
            Name = input.ReadString();
            break;
          }
        }
      }
    }

    #region Nested types
    /// <summary>Container for nested types declared in the Component message type.</summary>
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
    public static partial class Types {
      public enum ComponentType {
        kMesh = 0,
        kLight = 2,
        kCamera = 3,
        kAnnotation = 4,
        kCurve = 5,
      }

    }
    #endregion

  }

  #endregion

}

#endregion Designer generated code
