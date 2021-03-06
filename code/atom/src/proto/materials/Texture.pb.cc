// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: materials/Texture.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "materials/Texture.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace atom {
namespace proto {
namespace materials {

namespace {

const ::google::protobuf::Descriptor* Texture_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Texture_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_materials_2fTexture_2eproto() {
  protobuf_AddDesc_materials_2fTexture_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "materials/Texture.proto");
  GOOGLE_CHECK(file != NULL);
  Texture_descriptor_ = file->message_type(0);
  static const int Texture_offsets_[12] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Texture, texturename_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Texture, data_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Texture, translateframe_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Texture, rotateframe_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Texture, mirroru_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Texture, mirrorv_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Texture, wrapu_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Texture, wrapv_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Texture, repeat_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Texture, offset_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Texture, rotate_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Texture, noise_),
  };
  Texture_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      Texture_descriptor_,
      Texture::default_instance_,
      Texture_offsets_,
      -1,
      -1,
      -1,
      sizeof(Texture),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Texture, _internal_metadata_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Texture, _is_default_instance_));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_materials_2fTexture_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      Texture_descriptor_, &Texture::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_materials_2fTexture_2eproto() {
  delete Texture::default_instance_;
  delete Texture_reflection_;
}

void protobuf_AddDesc_materials_2fTexture_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::atom::proto::materials::protobuf_AddDesc_materials_2fTextureData_2eproto();
  ::atom::proto::protobuf_AddDesc_Vector2_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\027materials/Texture.proto\022\024atom.proto.ma"
    "terials\032\033materials/TextureData.proto\032\rVe"
    "ctor2.proto\"\317\002\n\007Texture\022\023\n\013TextureName\030\001"
    " \001(\t\022/\n\004Data\030\002 \001(\0132!.atom.proto.material"
    "s.TextureData\022+\n\016TranslateFrame\030\003 \001(\0132\023."
    "atom.proto.Vector2\022\023\n\013RotateFrame\030\004 \001(\002\022"
    "\017\n\007MirrorU\030\005 \001(\010\022\017\n\007MirrorV\030\006 \001(\010\022\r\n\005Wra"
    "pU\030\007 \001(\010\022\r\n\005wrapV\030\010 \001(\010\022#\n\006Repeat\030\t \001(\0132"
    "\023.atom.proto.Vector2\022#\n\006Offset\030\n \001(\0132\023.a"
    "tom.proto.Vector2\022\016\n\006Rotate\030\013 \001(\002\022\"\n\005Noi"
    "se\030\014 \001(\0132\023.atom.proto.Vector2b\006proto3", 437);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "materials/Texture.proto", &protobuf_RegisterTypes);
  Texture::default_instance_ = new Texture();
  Texture::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_materials_2fTexture_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_materials_2fTexture_2eproto {
  StaticDescriptorInitializer_materials_2fTexture_2eproto() {
    protobuf_AddDesc_materials_2fTexture_2eproto();
  }
} static_descriptor_initializer_materials_2fTexture_2eproto_;

namespace {

static void MergeFromFail(int line) GOOGLE_ATTRIBUTE_COLD;
static void MergeFromFail(int line) {
  GOOGLE_CHECK(false) << __FILE__ << ":" << line;
}

}  // namespace


// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int Texture::kTextureNameFieldNumber;
const int Texture::kDataFieldNumber;
const int Texture::kTranslateFrameFieldNumber;
const int Texture::kRotateFrameFieldNumber;
const int Texture::kMirrorUFieldNumber;
const int Texture::kMirrorVFieldNumber;
const int Texture::kWrapUFieldNumber;
const int Texture::kWrapVFieldNumber;
const int Texture::kRepeatFieldNumber;
const int Texture::kOffsetFieldNumber;
const int Texture::kRotateFieldNumber;
const int Texture::kNoiseFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

Texture::Texture()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:atom.proto.materials.Texture)
}

void Texture::InitAsDefaultInstance() {
  _is_default_instance_ = true;
  data_ = const_cast< ::atom::proto::materials::TextureData*>(&::atom::proto::materials::TextureData::default_instance());
  translateframe_ = const_cast< ::atom::proto::Vector2*>(&::atom::proto::Vector2::default_instance());
  repeat_ = const_cast< ::atom::proto::Vector2*>(&::atom::proto::Vector2::default_instance());
  offset_ = const_cast< ::atom::proto::Vector2*>(&::atom::proto::Vector2::default_instance());
  noise_ = const_cast< ::atom::proto::Vector2*>(&::atom::proto::Vector2::default_instance());
}

Texture::Texture(const Texture& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:atom.proto.materials.Texture)
}

void Texture::SharedCtor() {
    _is_default_instance_ = false;
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  texturename_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  data_ = NULL;
  translateframe_ = NULL;
  rotateframe_ = 0;
  mirroru_ = false;
  mirrorv_ = false;
  wrapu_ = false;
  wrapv_ = false;
  repeat_ = NULL;
  offset_ = NULL;
  rotate_ = 0;
  noise_ = NULL;
}

Texture::~Texture() {
  // @@protoc_insertion_point(destructor:atom.proto.materials.Texture)
  SharedDtor();
}

void Texture::SharedDtor() {
  texturename_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (this != default_instance_) {
    delete data_;
    delete translateframe_;
    delete repeat_;
    delete offset_;
    delete noise_;
  }
}

void Texture::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Texture::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Texture_descriptor_;
}

const Texture& Texture::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_materials_2fTexture_2eproto();
  return *default_instance_;
}

Texture* Texture::default_instance_ = NULL;

Texture* Texture::New(::google::protobuf::Arena* arena) const {
  Texture* n = new Texture;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void Texture::Clear() {
#define ZR_HELPER_(f) reinterpret_cast<char*>(\
  &reinterpret_cast<Texture*>(16)->f)

#define ZR_(first, last) do {\
  ::memset(&first, 0,\
           ZR_HELPER_(last) - ZR_HELPER_(first) + sizeof(last));\
} while (0)

  ZR_(rotateframe_, wrapv_);
  texturename_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (GetArenaNoVirtual() == NULL && data_ != NULL) delete data_;
  data_ = NULL;
  if (GetArenaNoVirtual() == NULL && translateframe_ != NULL) delete translateframe_;
  translateframe_ = NULL;
  if (GetArenaNoVirtual() == NULL && repeat_ != NULL) delete repeat_;
  repeat_ = NULL;
  if (GetArenaNoVirtual() == NULL && offset_ != NULL) delete offset_;
  offset_ = NULL;
  rotate_ = 0;
  if (GetArenaNoVirtual() == NULL && noise_ != NULL) delete noise_;
  noise_ = NULL;

#undef ZR_HELPER_
#undef ZR_

}

bool Texture::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:atom.proto.materials.Texture)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional string TextureName = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_texturename()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->texturename().data(), this->texturename().length(),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "atom.proto.materials.Texture.TextureName"));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_Data;
        break;
      }

      // optional .atom.proto.materials.TextureData Data = 2;
      case 2: {
        if (tag == 18) {
         parse_Data:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_data()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_TranslateFrame;
        break;
      }

      // optional .atom.proto.Vector2 TranslateFrame = 3;
      case 3: {
        if (tag == 26) {
         parse_TranslateFrame:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_translateframe()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(37)) goto parse_RotateFrame;
        break;
      }

      // optional float RotateFrame = 4;
      case 4: {
        if (tag == 37) {
         parse_RotateFrame:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &rotateframe_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(40)) goto parse_MirrorU;
        break;
      }

      // optional bool MirrorU = 5;
      case 5: {
        if (tag == 40) {
         parse_MirrorU:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &mirroru_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(48)) goto parse_MirrorV;
        break;
      }

      // optional bool MirrorV = 6;
      case 6: {
        if (tag == 48) {
         parse_MirrorV:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &mirrorv_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(56)) goto parse_WrapU;
        break;
      }

      // optional bool WrapU = 7;
      case 7: {
        if (tag == 56) {
         parse_WrapU:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &wrapu_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(64)) goto parse_wrapV;
        break;
      }

      // optional bool wrapV = 8;
      case 8: {
        if (tag == 64) {
         parse_wrapV:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &wrapv_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(74)) goto parse_Repeat;
        break;
      }

      // optional .atom.proto.Vector2 Repeat = 9;
      case 9: {
        if (tag == 74) {
         parse_Repeat:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_repeat()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(82)) goto parse_Offset;
        break;
      }

      // optional .atom.proto.Vector2 Offset = 10;
      case 10: {
        if (tag == 82) {
         parse_Offset:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_offset()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(93)) goto parse_Rotate;
        break;
      }

      // optional float Rotate = 11;
      case 11: {
        if (tag == 93) {
         parse_Rotate:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &rotate_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(98)) goto parse_Noise;
        break;
      }

      // optional .atom.proto.Vector2 Noise = 12;
      case 12: {
        if (tag == 98) {
         parse_Noise:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_noise()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:atom.proto.materials.Texture)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:atom.proto.materials.Texture)
  return false;
#undef DO_
}

void Texture::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:atom.proto.materials.Texture)
  // optional string TextureName = 1;
  if (this->texturename().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->texturename().data(), this->texturename().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "atom.proto.materials.Texture.TextureName");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->texturename(), output);
  }

  // optional .atom.proto.materials.TextureData Data = 2;
  if (this->has_data()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, *this->data_, output);
  }

  // optional .atom.proto.Vector2 TranslateFrame = 3;
  if (this->has_translateframe()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      3, *this->translateframe_, output);
  }

  // optional float RotateFrame = 4;
  if (this->rotateframe() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(4, this->rotateframe(), output);
  }

  // optional bool MirrorU = 5;
  if (this->mirroru() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(5, this->mirroru(), output);
  }

  // optional bool MirrorV = 6;
  if (this->mirrorv() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(6, this->mirrorv(), output);
  }

  // optional bool WrapU = 7;
  if (this->wrapu() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(7, this->wrapu(), output);
  }

  // optional bool wrapV = 8;
  if (this->wrapv() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(8, this->wrapv(), output);
  }

  // optional .atom.proto.Vector2 Repeat = 9;
  if (this->has_repeat()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      9, *this->repeat_, output);
  }

  // optional .atom.proto.Vector2 Offset = 10;
  if (this->has_offset()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      10, *this->offset_, output);
  }

  // optional float Rotate = 11;
  if (this->rotate() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(11, this->rotate(), output);
  }

  // optional .atom.proto.Vector2 Noise = 12;
  if (this->has_noise()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      12, *this->noise_, output);
  }

  // @@protoc_insertion_point(serialize_end:atom.proto.materials.Texture)
}

::google::protobuf::uint8* Texture::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:atom.proto.materials.Texture)
  // optional string TextureName = 1;
  if (this->texturename().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->texturename().data(), this->texturename().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "atom.proto.materials.Texture.TextureName");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->texturename(), target);
  }

  // optional .atom.proto.materials.TextureData Data = 2;
  if (this->has_data()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, *this->data_, target);
  }

  // optional .atom.proto.Vector2 TranslateFrame = 3;
  if (this->has_translateframe()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        3, *this->translateframe_, target);
  }

  // optional float RotateFrame = 4;
  if (this->rotateframe() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFloatToArray(4, this->rotateframe(), target);
  }

  // optional bool MirrorU = 5;
  if (this->mirroru() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(5, this->mirroru(), target);
  }

  // optional bool MirrorV = 6;
  if (this->mirrorv() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(6, this->mirrorv(), target);
  }

  // optional bool WrapU = 7;
  if (this->wrapu() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(7, this->wrapu(), target);
  }

  // optional bool wrapV = 8;
  if (this->wrapv() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(8, this->wrapv(), target);
  }

  // optional .atom.proto.Vector2 Repeat = 9;
  if (this->has_repeat()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        9, *this->repeat_, target);
  }

  // optional .atom.proto.Vector2 Offset = 10;
  if (this->has_offset()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        10, *this->offset_, target);
  }

  // optional float Rotate = 11;
  if (this->rotate() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFloatToArray(11, this->rotate(), target);
  }

  // optional .atom.proto.Vector2 Noise = 12;
  if (this->has_noise()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        12, *this->noise_, target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:atom.proto.materials.Texture)
  return target;
}

int Texture::ByteSize() const {
  int total_size = 0;

  // optional string TextureName = 1;
  if (this->texturename().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->texturename());
  }

  // optional .atom.proto.materials.TextureData Data = 2;
  if (this->has_data()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        *this->data_);
  }

  // optional .atom.proto.Vector2 TranslateFrame = 3;
  if (this->has_translateframe()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        *this->translateframe_);
  }

  // optional float RotateFrame = 4;
  if (this->rotateframe() != 0) {
    total_size += 1 + 4;
  }

  // optional bool MirrorU = 5;
  if (this->mirroru() != 0) {
    total_size += 1 + 1;
  }

  // optional bool MirrorV = 6;
  if (this->mirrorv() != 0) {
    total_size += 1 + 1;
  }

  // optional bool WrapU = 7;
  if (this->wrapu() != 0) {
    total_size += 1 + 1;
  }

  // optional bool wrapV = 8;
  if (this->wrapv() != 0) {
    total_size += 1 + 1;
  }

  // optional .atom.proto.Vector2 Repeat = 9;
  if (this->has_repeat()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        *this->repeat_);
  }

  // optional .atom.proto.Vector2 Offset = 10;
  if (this->has_offset()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        *this->offset_);
  }

  // optional float Rotate = 11;
  if (this->rotate() != 0) {
    total_size += 1 + 4;
  }

  // optional .atom.proto.Vector2 Noise = 12;
  if (this->has_noise()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        *this->noise_);
  }

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Texture::MergeFrom(const ::google::protobuf::Message& from) {
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  const Texture* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const Texture>(
          &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Texture::MergeFrom(const Texture& from) {
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  if (from.texturename().size() > 0) {

    texturename_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.texturename_);
  }
  if (from.has_data()) {
    mutable_data()->::atom::proto::materials::TextureData::MergeFrom(from.data());
  }
  if (from.has_translateframe()) {
    mutable_translateframe()->::atom::proto::Vector2::MergeFrom(from.translateframe());
  }
  if (from.rotateframe() != 0) {
    set_rotateframe(from.rotateframe());
  }
  if (from.mirroru() != 0) {
    set_mirroru(from.mirroru());
  }
  if (from.mirrorv() != 0) {
    set_mirrorv(from.mirrorv());
  }
  if (from.wrapu() != 0) {
    set_wrapu(from.wrapu());
  }
  if (from.wrapv() != 0) {
    set_wrapv(from.wrapv());
  }
  if (from.has_repeat()) {
    mutable_repeat()->::atom::proto::Vector2::MergeFrom(from.repeat());
  }
  if (from.has_offset()) {
    mutable_offset()->::atom::proto::Vector2::MergeFrom(from.offset());
  }
  if (from.rotate() != 0) {
    set_rotate(from.rotate());
  }
  if (from.has_noise()) {
    mutable_noise()->::atom::proto::Vector2::MergeFrom(from.noise());
  }
}

void Texture::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Texture::CopyFrom(const Texture& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Texture::IsInitialized() const {

  return true;
}

void Texture::Swap(Texture* other) {
  if (other == this) return;
  InternalSwap(other);
}
void Texture::InternalSwap(Texture* other) {
  texturename_.Swap(&other->texturename_);
  std::swap(data_, other->data_);
  std::swap(translateframe_, other->translateframe_);
  std::swap(rotateframe_, other->rotateframe_);
  std::swap(mirroru_, other->mirroru_);
  std::swap(mirrorv_, other->mirrorv_);
  std::swap(wrapu_, other->wrapu_);
  std::swap(wrapv_, other->wrapv_);
  std::swap(repeat_, other->repeat_);
  std::swap(offset_, other->offset_);
  std::swap(rotate_, other->rotate_);
  std::swap(noise_, other->noise_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata Texture::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Texture_descriptor_;
  metadata.reflection = Texture_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// Texture

// optional string TextureName = 1;
void Texture::clear_texturename() {
  texturename_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 const ::std::string& Texture::texturename() const {
  // @@protoc_insertion_point(field_get:atom.proto.materials.Texture.TextureName)
  return texturename_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void Texture::set_texturename(const ::std::string& value) {
  
  texturename_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:atom.proto.materials.Texture.TextureName)
}
 void Texture::set_texturename(const char* value) {
  
  texturename_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:atom.proto.materials.Texture.TextureName)
}
 void Texture::set_texturename(const char* value, size_t size) {
  
  texturename_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:atom.proto.materials.Texture.TextureName)
}
 ::std::string* Texture::mutable_texturename() {
  
  // @@protoc_insertion_point(field_mutable:atom.proto.materials.Texture.TextureName)
  return texturename_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 ::std::string* Texture::release_texturename() {
  
  return texturename_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void Texture::set_allocated_texturename(::std::string* texturename) {
  if (texturename != NULL) {
    
  } else {
    
  }
  texturename_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), texturename);
  // @@protoc_insertion_point(field_set_allocated:atom.proto.materials.Texture.TextureName)
}

// optional .atom.proto.materials.TextureData Data = 2;
bool Texture::has_data() const {
  return !_is_default_instance_ && data_ != NULL;
}
void Texture::clear_data() {
  if (GetArenaNoVirtual() == NULL && data_ != NULL) delete data_;
  data_ = NULL;
}
const ::atom::proto::materials::TextureData& Texture::data() const {
  // @@protoc_insertion_point(field_get:atom.proto.materials.Texture.Data)
  return data_ != NULL ? *data_ : *default_instance_->data_;
}
::atom::proto::materials::TextureData* Texture::mutable_data() {
  
  if (data_ == NULL) {
    data_ = new ::atom::proto::materials::TextureData;
  }
  // @@protoc_insertion_point(field_mutable:atom.proto.materials.Texture.Data)
  return data_;
}
::atom::proto::materials::TextureData* Texture::release_data() {
  
  ::atom::proto::materials::TextureData* temp = data_;
  data_ = NULL;
  return temp;
}
void Texture::set_allocated_data(::atom::proto::materials::TextureData* data) {
  delete data_;
  data_ = data;
  if (data) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:atom.proto.materials.Texture.Data)
}

// optional .atom.proto.Vector2 TranslateFrame = 3;
bool Texture::has_translateframe() const {
  return !_is_default_instance_ && translateframe_ != NULL;
}
void Texture::clear_translateframe() {
  if (GetArenaNoVirtual() == NULL && translateframe_ != NULL) delete translateframe_;
  translateframe_ = NULL;
}
const ::atom::proto::Vector2& Texture::translateframe() const {
  // @@protoc_insertion_point(field_get:atom.proto.materials.Texture.TranslateFrame)
  return translateframe_ != NULL ? *translateframe_ : *default_instance_->translateframe_;
}
::atom::proto::Vector2* Texture::mutable_translateframe() {
  
  if (translateframe_ == NULL) {
    translateframe_ = new ::atom::proto::Vector2;
  }
  // @@protoc_insertion_point(field_mutable:atom.proto.materials.Texture.TranslateFrame)
  return translateframe_;
}
::atom::proto::Vector2* Texture::release_translateframe() {
  
  ::atom::proto::Vector2* temp = translateframe_;
  translateframe_ = NULL;
  return temp;
}
void Texture::set_allocated_translateframe(::atom::proto::Vector2* translateframe) {
  delete translateframe_;
  translateframe_ = translateframe;
  if (translateframe) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:atom.proto.materials.Texture.TranslateFrame)
}

// optional float RotateFrame = 4;
void Texture::clear_rotateframe() {
  rotateframe_ = 0;
}
 float Texture::rotateframe() const {
  // @@protoc_insertion_point(field_get:atom.proto.materials.Texture.RotateFrame)
  return rotateframe_;
}
 void Texture::set_rotateframe(float value) {
  
  rotateframe_ = value;
  // @@protoc_insertion_point(field_set:atom.proto.materials.Texture.RotateFrame)
}

// optional bool MirrorU = 5;
void Texture::clear_mirroru() {
  mirroru_ = false;
}
 bool Texture::mirroru() const {
  // @@protoc_insertion_point(field_get:atom.proto.materials.Texture.MirrorU)
  return mirroru_;
}
 void Texture::set_mirroru(bool value) {
  
  mirroru_ = value;
  // @@protoc_insertion_point(field_set:atom.proto.materials.Texture.MirrorU)
}

// optional bool MirrorV = 6;
void Texture::clear_mirrorv() {
  mirrorv_ = false;
}
 bool Texture::mirrorv() const {
  // @@protoc_insertion_point(field_get:atom.proto.materials.Texture.MirrorV)
  return mirrorv_;
}
 void Texture::set_mirrorv(bool value) {
  
  mirrorv_ = value;
  // @@protoc_insertion_point(field_set:atom.proto.materials.Texture.MirrorV)
}

// optional bool WrapU = 7;
void Texture::clear_wrapu() {
  wrapu_ = false;
}
 bool Texture::wrapu() const {
  // @@protoc_insertion_point(field_get:atom.proto.materials.Texture.WrapU)
  return wrapu_;
}
 void Texture::set_wrapu(bool value) {
  
  wrapu_ = value;
  // @@protoc_insertion_point(field_set:atom.proto.materials.Texture.WrapU)
}

// optional bool wrapV = 8;
void Texture::clear_wrapv() {
  wrapv_ = false;
}
 bool Texture::wrapv() const {
  // @@protoc_insertion_point(field_get:atom.proto.materials.Texture.wrapV)
  return wrapv_;
}
 void Texture::set_wrapv(bool value) {
  
  wrapv_ = value;
  // @@protoc_insertion_point(field_set:atom.proto.materials.Texture.wrapV)
}

// optional .atom.proto.Vector2 Repeat = 9;
bool Texture::has_repeat() const {
  return !_is_default_instance_ && repeat_ != NULL;
}
void Texture::clear_repeat() {
  if (GetArenaNoVirtual() == NULL && repeat_ != NULL) delete repeat_;
  repeat_ = NULL;
}
const ::atom::proto::Vector2& Texture::repeat() const {
  // @@protoc_insertion_point(field_get:atom.proto.materials.Texture.Repeat)
  return repeat_ != NULL ? *repeat_ : *default_instance_->repeat_;
}
::atom::proto::Vector2* Texture::mutable_repeat() {
  
  if (repeat_ == NULL) {
    repeat_ = new ::atom::proto::Vector2;
  }
  // @@protoc_insertion_point(field_mutable:atom.proto.materials.Texture.Repeat)
  return repeat_;
}
::atom::proto::Vector2* Texture::release_repeat() {
  
  ::atom::proto::Vector2* temp = repeat_;
  repeat_ = NULL;
  return temp;
}
void Texture::set_allocated_repeat(::atom::proto::Vector2* repeat) {
  delete repeat_;
  repeat_ = repeat;
  if (repeat) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:atom.proto.materials.Texture.Repeat)
}

// optional .atom.proto.Vector2 Offset = 10;
bool Texture::has_offset() const {
  return !_is_default_instance_ && offset_ != NULL;
}
void Texture::clear_offset() {
  if (GetArenaNoVirtual() == NULL && offset_ != NULL) delete offset_;
  offset_ = NULL;
}
const ::atom::proto::Vector2& Texture::offset() const {
  // @@protoc_insertion_point(field_get:atom.proto.materials.Texture.Offset)
  return offset_ != NULL ? *offset_ : *default_instance_->offset_;
}
::atom::proto::Vector2* Texture::mutable_offset() {
  
  if (offset_ == NULL) {
    offset_ = new ::atom::proto::Vector2;
  }
  // @@protoc_insertion_point(field_mutable:atom.proto.materials.Texture.Offset)
  return offset_;
}
::atom::proto::Vector2* Texture::release_offset() {
  
  ::atom::proto::Vector2* temp = offset_;
  offset_ = NULL;
  return temp;
}
void Texture::set_allocated_offset(::atom::proto::Vector2* offset) {
  delete offset_;
  offset_ = offset;
  if (offset) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:atom.proto.materials.Texture.Offset)
}

// optional float Rotate = 11;
void Texture::clear_rotate() {
  rotate_ = 0;
}
 float Texture::rotate() const {
  // @@protoc_insertion_point(field_get:atom.proto.materials.Texture.Rotate)
  return rotate_;
}
 void Texture::set_rotate(float value) {
  
  rotate_ = value;
  // @@protoc_insertion_point(field_set:atom.proto.materials.Texture.Rotate)
}

// optional .atom.proto.Vector2 Noise = 12;
bool Texture::has_noise() const {
  return !_is_default_instance_ && noise_ != NULL;
}
void Texture::clear_noise() {
  if (GetArenaNoVirtual() == NULL && noise_ != NULL) delete noise_;
  noise_ = NULL;
}
const ::atom::proto::Vector2& Texture::noise() const {
  // @@protoc_insertion_point(field_get:atom.proto.materials.Texture.Noise)
  return noise_ != NULL ? *noise_ : *default_instance_->noise_;
}
::atom::proto::Vector2* Texture::mutable_noise() {
  
  if (noise_ == NULL) {
    noise_ = new ::atom::proto::Vector2;
  }
  // @@protoc_insertion_point(field_mutable:atom.proto.materials.Texture.Noise)
  return noise_;
}
::atom::proto::Vector2* Texture::release_noise() {
  
  ::atom::proto::Vector2* temp = noise_;
  noise_ = NULL;
  return temp;
}
void Texture::set_allocated_noise(::atom::proto::Vector2* noise) {
  delete noise_;
  noise_ = noise;
  if (noise) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:atom.proto.materials.Texture.Noise)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace materials
}  // namespace proto
}  // namespace atom

// @@protoc_insertion_point(global_scope)
