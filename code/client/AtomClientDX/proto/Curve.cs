// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Curve.proto
#pragma warning disable 1591, 0612, 3021
#region Designer generated code

using pb = global::Google.Protobuf;
using pbc = global::Google.Protobuf.Collections;
using pbr = global::Google.Protobuf.Reflection;
using scg = global::System.Collections.Generic;
namespace Atom.Proto {

  /// <summary>Holder for reflection information generated from Curve.proto</summary>
  [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
  public static partial class CurveReflection {

    #region Descriptor
    /// <summary>File descriptor for Curve.proto</summary>
    public static pbr::FileDescriptor Descriptor {
      get { return descriptor; }
    }
    private static pbr::FileDescriptor descriptor;

    static CurveReflection() {
      byte[] descriptorData = global::System.Convert.FromBase64String(
          string.Concat(
            "CgtDdXJ2ZS5wcm90bxIKYXRvbS5wcm90bxoNVmVjdG9yMy5wcm90bxoMTWF0",
            "cml4LnByb3RvInQKBUN1cnZlEgwKBE5hbWUYASABKAkSHwoCQ1YYAiADKAsy",
            "Ey5hdG9tLnByb3RvLlZlY3RvcjMSIQoFV29ybGQYAyABKAsyEi5hdG9tLnBy",
            "b3RvLk1hdHJpeBIZChFJbml0aWFsVmlzaWJpbGl0eRgEIAEoCGIGcHJvdG8z"));
      descriptor = pbr::FileDescriptor.FromGeneratedCode(descriptorData,
          new pbr::FileDescriptor[] { global::Atom.Proto.Vector3Reflection.Descriptor, global::Atom.Proto.MatrixReflection.Descriptor, },
          new pbr::GeneratedClrTypeInfo(null, new pbr::GeneratedClrTypeInfo[] {
            new pbr::GeneratedClrTypeInfo(typeof(global::Atom.Proto.Curve), global::Atom.Proto.Curve.Parser, new[]{ "Name", "CV", "World", "InitialVisibility" }, null, null, null)
          }));
    }
    #endregion

  }
  #region Messages
  [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
  public sealed partial class Curve : pb::IMessage<Curve> {
    private static readonly pb::MessageParser<Curve> _parser = new pb::MessageParser<Curve>(() => new Curve());
    public static pb::MessageParser<Curve> Parser { get { return _parser; } }

    public static pbr::MessageDescriptor Descriptor {
      get { return global::Atom.Proto.CurveReflection.Descriptor.MessageTypes[0]; }
    }

    pbr::MessageDescriptor pb::IMessage.Descriptor {
      get { return Descriptor; }
    }

    public Curve() {
      OnConstruction();
    }

    partial void OnConstruction();

    public Curve(Curve other) : this() {
      name_ = other.name_;
      cV_ = other.cV_.Clone();
      World = other.world_ != null ? other.World.Clone() : null;
      initialVisibility_ = other.initialVisibility_;
    }

    public Curve Clone() {
      return new Curve(this);
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

    /// <summary>Field number for the "CV" field.</summary>
    public const int CVFieldNumber = 2;
    private static readonly pb::FieldCodec<global::Atom.Proto.Vector3> _repeated_cV_codec
        = pb::FieldCodec.ForMessage(18, global::Atom.Proto.Vector3.Parser);
    private readonly pbc::RepeatedField<global::Atom.Proto.Vector3> cV_ = new pbc::RepeatedField<global::Atom.Proto.Vector3>();
    public pbc::RepeatedField<global::Atom.Proto.Vector3> CV {
      get { return cV_; }
    }

    /// <summary>Field number for the "World" field.</summary>
    public const int WorldFieldNumber = 3;
    private global::Atom.Proto.Matrix world_;
    public global::Atom.Proto.Matrix World {
      get { return world_; }
      set {
        world_ = value;
      }
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
      return Equals(other as Curve);
    }

    public bool Equals(Curve other) {
      if (ReferenceEquals(other, null)) {
        return false;
      }
      if (ReferenceEquals(other, this)) {
        return true;
      }
      if (Name != other.Name) return false;
      if(!cV_.Equals(other.cV_)) return false;
      if (!object.Equals(World, other.World)) return false;
      if (InitialVisibility != other.InitialVisibility) return false;
      return true;
    }

    public override int GetHashCode() {
      int hash = 1;
      if (Name.Length != 0) hash ^= Name.GetHashCode();
      hash ^= cV_.GetHashCode();
      if (world_ != null) hash ^= World.GetHashCode();
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
      cV_.WriteTo(output, _repeated_cV_codec);
      if (world_ != null) {
        output.WriteRawTag(26);
        output.WriteMessage(World);
      }
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
      size += cV_.CalculateSize(_repeated_cV_codec);
      if (world_ != null) {
        size += 1 + pb::CodedOutputStream.ComputeMessageSize(World);
      }
      if (InitialVisibility != false) {
        size += 1 + 1;
      }
      return size;
    }

    public void MergeFrom(Curve other) {
      if (other == null) {
        return;
      }
      if (other.Name.Length != 0) {
        Name = other.Name;
      }
      cV_.Add(other.cV_);
      if (other.world_ != null) {
        if (world_ == null) {
          world_ = new global::Atom.Proto.Matrix();
        }
        World.MergeFrom(other.World);
      }
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
            cV_.AddEntriesFrom(input, _repeated_cV_codec);
            break;
          }
          case 26: {
            if (world_ == null) {
              world_ = new global::Atom.Proto.Matrix();
            }
            input.ReadMessage(world_);
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
