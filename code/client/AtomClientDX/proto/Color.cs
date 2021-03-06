// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Color.proto
#pragma warning disable 1591, 0612, 3021
#region Designer generated code

using pb = global::Google.Protobuf;
using pbc = global::Google.Protobuf.Collections;
using pbr = global::Google.Protobuf.Reflection;
using scg = global::System.Collections.Generic;
namespace Atom.Proto {

  /// <summary>Holder for reflection information generated from Color.proto</summary>
  [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
  public static partial class ColorReflection {

    #region Descriptor
    /// <summary>File descriptor for Color.proto</summary>
    public static pbr::FileDescriptor Descriptor {
      get { return descriptor; }
    }
    private static pbr::FileDescriptor descriptor;

    static ColorReflection() {
      byte[] descriptorData = global::System.Convert.FromBase64String(
          string.Concat(
            "CgtDb2xvci5wcm90bxIKYXRvbS5wcm90byIzCgVDb2xvchIJCgFyGAEgASgC",
            "EgkKAWcYAiABKAISCQoBYhgDIAEoAhIJCgFhGAQgASgCYgZwcm90bzM="));
      descriptor = pbr::FileDescriptor.FromGeneratedCode(descriptorData,
          new pbr::FileDescriptor[] { },
          new pbr::GeneratedClrTypeInfo(null, new pbr::GeneratedClrTypeInfo[] {
            new pbr::GeneratedClrTypeInfo(typeof(global::Atom.Proto.Color), global::Atom.Proto.Color.Parser, new[]{ "R", "G", "B", "A" }, null, null, null)
          }));
    }
    #endregion

  }
  #region Messages
  [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
  public sealed partial class Color : pb::IMessage<Color> {
    private static readonly pb::MessageParser<Color> _parser = new pb::MessageParser<Color>(() => new Color());
    public static pb::MessageParser<Color> Parser { get { return _parser; } }

    public static pbr::MessageDescriptor Descriptor {
      get { return global::Atom.Proto.ColorReflection.Descriptor.MessageTypes[0]; }
    }

    pbr::MessageDescriptor pb::IMessage.Descriptor {
      get { return Descriptor; }
    }

    public Color() {
      OnConstruction();
    }

    partial void OnConstruction();

    public Color(Color other) : this() {
      r_ = other.r_;
      g_ = other.g_;
      b_ = other.b_;
      a_ = other.a_;
    }

    public Color Clone() {
      return new Color(this);
    }

    /// <summary>Field number for the "r" field.</summary>
    public const int RFieldNumber = 1;
    private float r_;
    public float R {
      get { return r_; }
      set {
        r_ = value;
      }
    }

    /// <summary>Field number for the "g" field.</summary>
    public const int GFieldNumber = 2;
    private float g_;
    public float G {
      get { return g_; }
      set {
        g_ = value;
      }
    }

    /// <summary>Field number for the "b" field.</summary>
    public const int BFieldNumber = 3;
    private float b_;
    public float B {
      get { return b_; }
      set {
        b_ = value;
      }
    }

    /// <summary>Field number for the "a" field.</summary>
    public const int AFieldNumber = 4;
    private float a_;
    public float A {
      get { return a_; }
      set {
        a_ = value;
      }
    }

    public override bool Equals(object other) {
      return Equals(other as Color);
    }

    public bool Equals(Color other) {
      if (ReferenceEquals(other, null)) {
        return false;
      }
      if (ReferenceEquals(other, this)) {
        return true;
      }
      if (R != other.R) return false;
      if (G != other.G) return false;
      if (B != other.B) return false;
      if (A != other.A) return false;
      return true;
    }

    public override int GetHashCode() {
      int hash = 1;
      if (R != 0F) hash ^= R.GetHashCode();
      if (G != 0F) hash ^= G.GetHashCode();
      if (B != 0F) hash ^= B.GetHashCode();
      if (A != 0F) hash ^= A.GetHashCode();
      return hash;
    }

    public override string ToString() {
      return pb::JsonFormatter.ToDiagnosticString(this);
    }

    public void WriteTo(pb::CodedOutputStream output) {
      if (R != 0F) {
        output.WriteRawTag(13);
        output.WriteFloat(R);
      }
      if (G != 0F) {
        output.WriteRawTag(21);
        output.WriteFloat(G);
      }
      if (B != 0F) {
        output.WriteRawTag(29);
        output.WriteFloat(B);
      }
      if (A != 0F) {
        output.WriteRawTag(37);
        output.WriteFloat(A);
      }
    }

    public int CalculateSize() {
      int size = 0;
      if (R != 0F) {
        size += 1 + 4;
      }
      if (G != 0F) {
        size += 1 + 4;
      }
      if (B != 0F) {
        size += 1 + 4;
      }
      if (A != 0F) {
        size += 1 + 4;
      }
      return size;
    }

    public void MergeFrom(Color other) {
      if (other == null) {
        return;
      }
      if (other.R != 0F) {
        R = other.R;
      }
      if (other.G != 0F) {
        G = other.G;
      }
      if (other.B != 0F) {
        B = other.B;
      }
      if (other.A != 0F) {
        A = other.A;
      }
    }

    public void MergeFrom(pb::CodedInputStream input) {
      uint tag;
      while ((tag = input.ReadTag()) != 0) {
        switch(tag) {
          default:
            input.SkipLastField();
            break;
          case 13: {
            R = input.ReadFloat();
            break;
          }
          case 21: {
            G = input.ReadFloat();
            break;
          }
          case 29: {
            B = input.ReadFloat();
            break;
          }
          case 37: {
            A = input.ReadFloat();
            break;
          }
        }
      }
    }

  }

  #endregion

}

#endregion Designer generated code
