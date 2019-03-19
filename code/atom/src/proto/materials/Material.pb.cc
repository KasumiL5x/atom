// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: materials/Material.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "materials/Material.pb.h"

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

const ::google::protobuf::Descriptor* Material_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Material_reflection_ = NULL;
struct MaterialOneofInstance {
  const ::atom::proto::materials::Lambert* lambert_;
  const ::atom::proto::materials::Phong* phong_;
  const ::atom::proto::materials::PhongE* phonge_;
  const ::atom::proto::materials::Blinn* blinn_;
  const ::atom::proto::materials::Anisotropic* anisotropic_;
}* Material_default_oneof_instance_ = NULL;

}  // namespace


void protobuf_AssignDesc_materials_2fMaterial_2eproto() {
  protobuf_AddDesc_materials_2fMaterial_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "materials/Material.proto");
  GOOGLE_CHECK(file != NULL);
  Material_descriptor_ = file->message_type(0);
  static const int Material_offsets_[8] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Material, name_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Material, type_),
    PROTO2_GENERATED_DEFAULT_ONEOF_FIELD_OFFSET(Material_default_oneof_instance_, lambert_),
    PROTO2_GENERATED_DEFAULT_ONEOF_FIELD_OFFSET(Material_default_oneof_instance_, phong_),
    PROTO2_GENERATED_DEFAULT_ONEOF_FIELD_OFFSET(Material_default_oneof_instance_, phonge_),
    PROTO2_GENERATED_DEFAULT_ONEOF_FIELD_OFFSET(Material_default_oneof_instance_, blinn_),
    PROTO2_GENERATED_DEFAULT_ONEOF_FIELD_OFFSET(Material_default_oneof_instance_, anisotropic_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Material, Data_),
  };
  Material_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      Material_descriptor_,
      Material::default_instance_,
      Material_offsets_,
      -1,
      -1,
      -1,
      Material_default_oneof_instance_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Material, _oneof_case_[0]),
      sizeof(Material),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Material, _internal_metadata_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Material, _is_default_instance_));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_materials_2fMaterial_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      Material_descriptor_, &Material::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_materials_2fMaterial_2eproto() {
  delete Material::default_instance_;
  delete Material_default_oneof_instance_;
  delete Material_reflection_;
}

void protobuf_AddDesc_materials_2fMaterial_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::atom::proto::materials::protobuf_AddDesc_materials_2fMaterialType_2eproto();
  ::atom::proto::materials::protobuf_AddDesc_materials_2fLambert_2eproto();
  ::atom::proto::materials::protobuf_AddDesc_materials_2fPhong_2eproto();
  ::atom::proto::materials::protobuf_AddDesc_materials_2fPhongE_2eproto();
  ::atom::proto::materials::protobuf_AddDesc_materials_2fBlinn_2eproto();
  ::atom::proto::materials::protobuf_AddDesc_materials_2fAnisotropic_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\030materials/Material.proto\022\024atom.proto.m"
    "aterials\032\034materials/MaterialType.proto\032\027"
    "materials/Lambert.proto\032\025materials/Phong"
    ".proto\032\026materials/PhongE.proto\032\025material"
    "s/Blinn.proto\032\033materials/Anisotropic.pro"
    "to\"\312\002\n\010Material\022\014\n\004Name\030\001 \001(\t\0220\n\004Type\030\002 "
    "\001(\0162\".atom.proto.materials.MaterialType\022"
    "0\n\007Lambert\030\003 \001(\0132\035.atom.proto.materials."
    "LambertH\000\022,\n\005Phong\030\004 \001(\0132\033.atom.proto.ma"
    "terials.PhongH\000\022.\n\006Phonge\030\005 \001(\0132\034.atom.p"
    "roto.materials.PhongEH\000\022,\n\005Blinn\030\006 \001(\0132\033"
    ".atom.proto.materials.BlinnH\000\0228\n\013Anisotr"
    "opic\030\007 \001(\0132!.atom.proto.materials.Anisot"
    "ropicH\000B\006\n\004Datab\006proto3", 543);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "materials/Material.proto", &protobuf_RegisterTypes);
  Material::default_instance_ = new Material();
  Material_default_oneof_instance_ = new MaterialOneofInstance();
  Material::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_materials_2fMaterial_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_materials_2fMaterial_2eproto {
  StaticDescriptorInitializer_materials_2fMaterial_2eproto() {
    protobuf_AddDesc_materials_2fMaterial_2eproto();
  }
} static_descriptor_initializer_materials_2fMaterial_2eproto_;

namespace {

static void MergeFromFail(int line) GOOGLE_ATTRIBUTE_COLD;
static void MergeFromFail(int line) {
  GOOGLE_CHECK(false) << __FILE__ << ":" << line;
}

}  // namespace


// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int Material::kNameFieldNumber;
const int Material::kTypeFieldNumber;
const int Material::kLambertFieldNumber;
const int Material::kPhongFieldNumber;
const int Material::kPhongeFieldNumber;
const int Material::kBlinnFieldNumber;
const int Material::kAnisotropicFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

Material::Material()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:atom.proto.materials.Material)
}

void Material::InitAsDefaultInstance() {
  _is_default_instance_ = true;
  Material_default_oneof_instance_->lambert_ = const_cast< ::atom::proto::materials::Lambert*>(&::atom::proto::materials::Lambert::default_instance());
  Material_default_oneof_instance_->phong_ = const_cast< ::atom::proto::materials::Phong*>(&::atom::proto::materials::Phong::default_instance());
  Material_default_oneof_instance_->phonge_ = const_cast< ::atom::proto::materials::PhongE*>(&::atom::proto::materials::PhongE::default_instance());
  Material_default_oneof_instance_->blinn_ = const_cast< ::atom::proto::materials::Blinn*>(&::atom::proto::materials::Blinn::default_instance());
  Material_default_oneof_instance_->anisotropic_ = const_cast< ::atom::proto::materials::Anisotropic*>(&::atom::proto::materials::Anisotropic::default_instance());
}

Material::Material(const Material& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:atom.proto.materials.Material)
}

void Material::SharedCtor() {
    _is_default_instance_ = false;
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  name_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  type_ = 0;
  clear_has_Data();
}

Material::~Material() {
  // @@protoc_insertion_point(destructor:atom.proto.materials.Material)
  SharedDtor();
}

void Material::SharedDtor() {
  name_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (has_Data()) {
    clear_Data();
  }
  if (this != default_instance_) {
  }
}

void Material::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Material::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Material_descriptor_;
}

const Material& Material::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_materials_2fMaterial_2eproto();
  return *default_instance_;
}

Material* Material::default_instance_ = NULL;

Material* Material::New(::google::protobuf::Arena* arena) const {
  Material* n = new Material;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void Material::clear_Data() {
  switch(Data_case()) {
    case kLambert: {
      delete Data_.lambert_;
      break;
    }
    case kPhong: {
      delete Data_.phong_;
      break;
    }
    case kPhonge: {
      delete Data_.phonge_;
      break;
    }
    case kBlinn: {
      delete Data_.blinn_;
      break;
    }
    case kAnisotropic: {
      delete Data_.anisotropic_;
      break;
    }
    case DATA_NOT_SET: {
      break;
    }
  }
  _oneof_case_[0] = DATA_NOT_SET;
}


void Material::Clear() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  type_ = 0;
  clear_Data();
}

bool Material::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:atom.proto.materials.Material)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional string Name = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_name()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->name().data(), this->name().length(),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "atom.proto.materials.Material.Name"));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_Type;
        break;
      }

      // optional .atom.proto.materials.MaterialType Type = 2;
      case 2: {
        if (tag == 16) {
         parse_Type:
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          set_type(static_cast< ::atom::proto::materials::MaterialType >(value));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_Lambert;
        break;
      }

      // optional .atom.proto.materials.Lambert Lambert = 3;
      case 3: {
        if (tag == 26) {
         parse_Lambert:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_lambert()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(34)) goto parse_Phong;
        break;
      }

      // optional .atom.proto.materials.Phong Phong = 4;
      case 4: {
        if (tag == 34) {
         parse_Phong:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_phong()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(42)) goto parse_Phonge;
        break;
      }

      // optional .atom.proto.materials.PhongE Phonge = 5;
      case 5: {
        if (tag == 42) {
         parse_Phonge:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_phonge()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(50)) goto parse_Blinn;
        break;
      }

      // optional .atom.proto.materials.Blinn Blinn = 6;
      case 6: {
        if (tag == 50) {
         parse_Blinn:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_blinn()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(58)) goto parse_Anisotropic;
        break;
      }

      // optional .atom.proto.materials.Anisotropic Anisotropic = 7;
      case 7: {
        if (tag == 58) {
         parse_Anisotropic:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_anisotropic()));
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
  // @@protoc_insertion_point(parse_success:atom.proto.materials.Material)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:atom.proto.materials.Material)
  return false;
#undef DO_
}

void Material::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:atom.proto.materials.Material)
  // optional string Name = 1;
  if (this->name().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->name().data(), this->name().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "atom.proto.materials.Material.Name");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->name(), output);
  }

  // optional .atom.proto.materials.MaterialType Type = 2;
  if (this->type() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      2, this->type(), output);
  }

  // optional .atom.proto.materials.Lambert Lambert = 3;
  if (has_lambert()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      3, *Data_.lambert_, output);
  }

  // optional .atom.proto.materials.Phong Phong = 4;
  if (has_phong()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      4, *Data_.phong_, output);
  }

  // optional .atom.proto.materials.PhongE Phonge = 5;
  if (has_phonge()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      5, *Data_.phonge_, output);
  }

  // optional .atom.proto.materials.Blinn Blinn = 6;
  if (has_blinn()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      6, *Data_.blinn_, output);
  }

  // optional .atom.proto.materials.Anisotropic Anisotropic = 7;
  if (has_anisotropic()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      7, *Data_.anisotropic_, output);
  }

  // @@protoc_insertion_point(serialize_end:atom.proto.materials.Material)
}

::google::protobuf::uint8* Material::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:atom.proto.materials.Material)
  // optional string Name = 1;
  if (this->name().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->name().data(), this->name().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "atom.proto.materials.Material.Name");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->name(), target);
  }

  // optional .atom.proto.materials.MaterialType Type = 2;
  if (this->type() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      2, this->type(), target);
  }

  // optional .atom.proto.materials.Lambert Lambert = 3;
  if (has_lambert()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        3, *Data_.lambert_, target);
  }

  // optional .atom.proto.materials.Phong Phong = 4;
  if (has_phong()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        4, *Data_.phong_, target);
  }

  // optional .atom.proto.materials.PhongE Phonge = 5;
  if (has_phonge()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        5, *Data_.phonge_, target);
  }

  // optional .atom.proto.materials.Blinn Blinn = 6;
  if (has_blinn()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        6, *Data_.blinn_, target);
  }

  // optional .atom.proto.materials.Anisotropic Anisotropic = 7;
  if (has_anisotropic()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        7, *Data_.anisotropic_, target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:atom.proto.materials.Material)
  return target;
}

int Material::ByteSize() const {
  int total_size = 0;

  // optional string Name = 1;
  if (this->name().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->name());
  }

  // optional .atom.proto.materials.MaterialType Type = 2;
  if (this->type() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::EnumSize(this->type());
  }

  switch (Data_case()) {
    // optional .atom.proto.materials.Lambert Lambert = 3;
    case kLambert: {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          *Data_.lambert_);
      break;
    }
    // optional .atom.proto.materials.Phong Phong = 4;
    case kPhong: {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          *Data_.phong_);
      break;
    }
    // optional .atom.proto.materials.PhongE Phonge = 5;
    case kPhonge: {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          *Data_.phonge_);
      break;
    }
    // optional .atom.proto.materials.Blinn Blinn = 6;
    case kBlinn: {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          *Data_.blinn_);
      break;
    }
    // optional .atom.proto.materials.Anisotropic Anisotropic = 7;
    case kAnisotropic: {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          *Data_.anisotropic_);
      break;
    }
    case DATA_NOT_SET: {
      break;
    }
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Material::MergeFrom(const ::google::protobuf::Message& from) {
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  const Material* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const Material>(
          &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Material::MergeFrom(const Material& from) {
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  switch (from.Data_case()) {
    case kLambert: {
      mutable_lambert()->::atom::proto::materials::Lambert::MergeFrom(from.lambert());
      break;
    }
    case kPhong: {
      mutable_phong()->::atom::proto::materials::Phong::MergeFrom(from.phong());
      break;
    }
    case kPhonge: {
      mutable_phonge()->::atom::proto::materials::PhongE::MergeFrom(from.phonge());
      break;
    }
    case kBlinn: {
      mutable_blinn()->::atom::proto::materials::Blinn::MergeFrom(from.blinn());
      break;
    }
    case kAnisotropic: {
      mutable_anisotropic()->::atom::proto::materials::Anisotropic::MergeFrom(from.anisotropic());
      break;
    }
    case DATA_NOT_SET: {
      break;
    }
  }
  if (from.name().size() > 0) {

    name_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.name_);
  }
  if (from.type() != 0) {
    set_type(from.type());
  }
}

void Material::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Material::CopyFrom(const Material& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Material::IsInitialized() const {

  return true;
}

void Material::Swap(Material* other) {
  if (other == this) return;
  InternalSwap(other);
}
void Material::InternalSwap(Material* other) {
  name_.Swap(&other->name_);
  std::swap(type_, other->type_);
  std::swap(Data_, other->Data_);
  std::swap(_oneof_case_[0], other->_oneof_case_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata Material::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Material_descriptor_;
  metadata.reflection = Material_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// Material

// optional string Name = 1;
void Material::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 const ::std::string& Material::name() const {
  // @@protoc_insertion_point(field_get:atom.proto.materials.Material.Name)
  return name_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void Material::set_name(const ::std::string& value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:atom.proto.materials.Material.Name)
}
 void Material::set_name(const char* value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:atom.proto.materials.Material.Name)
}
 void Material::set_name(const char* value, size_t size) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:atom.proto.materials.Material.Name)
}
 ::std::string* Material::mutable_name() {
  
  // @@protoc_insertion_point(field_mutable:atom.proto.materials.Material.Name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 ::std::string* Material::release_name() {
  
  return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void Material::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    
  } else {
    
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:atom.proto.materials.Material.Name)
}

// optional .atom.proto.materials.MaterialType Type = 2;
void Material::clear_type() {
  type_ = 0;
}
 ::atom::proto::materials::MaterialType Material::type() const {
  // @@protoc_insertion_point(field_get:atom.proto.materials.Material.Type)
  return static_cast< ::atom::proto::materials::MaterialType >(type_);
}
 void Material::set_type(::atom::proto::materials::MaterialType value) {
  
  type_ = value;
  // @@protoc_insertion_point(field_set:atom.proto.materials.Material.Type)
}

// optional .atom.proto.materials.Lambert Lambert = 3;
bool Material::has_lambert() const {
  return Data_case() == kLambert;
}
void Material::set_has_lambert() {
  _oneof_case_[0] = kLambert;
}
void Material::clear_lambert() {
  if (has_lambert()) {
    delete Data_.lambert_;
    clear_has_Data();
  }
}
 const ::atom::proto::materials::Lambert& Material::lambert() const {
  // @@protoc_insertion_point(field_get:atom.proto.materials.Material.Lambert)
  return has_lambert()
      ? *Data_.lambert_
      : ::atom::proto::materials::Lambert::default_instance();
}
::atom::proto::materials::Lambert* Material::mutable_lambert() {
  if (!has_lambert()) {
    clear_Data();
    set_has_lambert();
    Data_.lambert_ = new ::atom::proto::materials::Lambert;
  }
  // @@protoc_insertion_point(field_mutable:atom.proto.materials.Material.Lambert)
  return Data_.lambert_;
}
::atom::proto::materials::Lambert* Material::release_lambert() {
  if (has_lambert()) {
    clear_has_Data();
    ::atom::proto::materials::Lambert* temp = Data_.lambert_;
    Data_.lambert_ = NULL;
    return temp;
  } else {
    return NULL;
  }
}
void Material::set_allocated_lambert(::atom::proto::materials::Lambert* lambert) {
  clear_Data();
  if (lambert) {
    set_has_lambert();
    Data_.lambert_ = lambert;
  }
  // @@protoc_insertion_point(field_set_allocated:atom.proto.materials.Material.Lambert)
}

// optional .atom.proto.materials.Phong Phong = 4;
bool Material::has_phong() const {
  return Data_case() == kPhong;
}
void Material::set_has_phong() {
  _oneof_case_[0] = kPhong;
}
void Material::clear_phong() {
  if (has_phong()) {
    delete Data_.phong_;
    clear_has_Data();
  }
}
 const ::atom::proto::materials::Phong& Material::phong() const {
  // @@protoc_insertion_point(field_get:atom.proto.materials.Material.Phong)
  return has_phong()
      ? *Data_.phong_
      : ::atom::proto::materials::Phong::default_instance();
}
::atom::proto::materials::Phong* Material::mutable_phong() {
  if (!has_phong()) {
    clear_Data();
    set_has_phong();
    Data_.phong_ = new ::atom::proto::materials::Phong;
  }
  // @@protoc_insertion_point(field_mutable:atom.proto.materials.Material.Phong)
  return Data_.phong_;
}
::atom::proto::materials::Phong* Material::release_phong() {
  if (has_phong()) {
    clear_has_Data();
    ::atom::proto::materials::Phong* temp = Data_.phong_;
    Data_.phong_ = NULL;
    return temp;
  } else {
    return NULL;
  }
}
void Material::set_allocated_phong(::atom::proto::materials::Phong* phong) {
  clear_Data();
  if (phong) {
    set_has_phong();
    Data_.phong_ = phong;
  }
  // @@protoc_insertion_point(field_set_allocated:atom.proto.materials.Material.Phong)
}

// optional .atom.proto.materials.PhongE Phonge = 5;
bool Material::has_phonge() const {
  return Data_case() == kPhonge;
}
void Material::set_has_phonge() {
  _oneof_case_[0] = kPhonge;
}
void Material::clear_phonge() {
  if (has_phonge()) {
    delete Data_.phonge_;
    clear_has_Data();
  }
}
 const ::atom::proto::materials::PhongE& Material::phonge() const {
  // @@protoc_insertion_point(field_get:atom.proto.materials.Material.Phonge)
  return has_phonge()
      ? *Data_.phonge_
      : ::atom::proto::materials::PhongE::default_instance();
}
::atom::proto::materials::PhongE* Material::mutable_phonge() {
  if (!has_phonge()) {
    clear_Data();
    set_has_phonge();
    Data_.phonge_ = new ::atom::proto::materials::PhongE;
  }
  // @@protoc_insertion_point(field_mutable:atom.proto.materials.Material.Phonge)
  return Data_.phonge_;
}
::atom::proto::materials::PhongE* Material::release_phonge() {
  if (has_phonge()) {
    clear_has_Data();
    ::atom::proto::materials::PhongE* temp = Data_.phonge_;
    Data_.phonge_ = NULL;
    return temp;
  } else {
    return NULL;
  }
}
void Material::set_allocated_phonge(::atom::proto::materials::PhongE* phonge) {
  clear_Data();
  if (phonge) {
    set_has_phonge();
    Data_.phonge_ = phonge;
  }
  // @@protoc_insertion_point(field_set_allocated:atom.proto.materials.Material.Phonge)
}

// optional .atom.proto.materials.Blinn Blinn = 6;
bool Material::has_blinn() const {
  return Data_case() == kBlinn;
}
void Material::set_has_blinn() {
  _oneof_case_[0] = kBlinn;
}
void Material::clear_blinn() {
  if (has_blinn()) {
    delete Data_.blinn_;
    clear_has_Data();
  }
}
 const ::atom::proto::materials::Blinn& Material::blinn() const {
  // @@protoc_insertion_point(field_get:atom.proto.materials.Material.Blinn)
  return has_blinn()
      ? *Data_.blinn_
      : ::atom::proto::materials::Blinn::default_instance();
}
::atom::proto::materials::Blinn* Material::mutable_blinn() {
  if (!has_blinn()) {
    clear_Data();
    set_has_blinn();
    Data_.blinn_ = new ::atom::proto::materials::Blinn;
  }
  // @@protoc_insertion_point(field_mutable:atom.proto.materials.Material.Blinn)
  return Data_.blinn_;
}
::atom::proto::materials::Blinn* Material::release_blinn() {
  if (has_blinn()) {
    clear_has_Data();
    ::atom::proto::materials::Blinn* temp = Data_.blinn_;
    Data_.blinn_ = NULL;
    return temp;
  } else {
    return NULL;
  }
}
void Material::set_allocated_blinn(::atom::proto::materials::Blinn* blinn) {
  clear_Data();
  if (blinn) {
    set_has_blinn();
    Data_.blinn_ = blinn;
  }
  // @@protoc_insertion_point(field_set_allocated:atom.proto.materials.Material.Blinn)
}

// optional .atom.proto.materials.Anisotropic Anisotropic = 7;
bool Material::has_anisotropic() const {
  return Data_case() == kAnisotropic;
}
void Material::set_has_anisotropic() {
  _oneof_case_[0] = kAnisotropic;
}
void Material::clear_anisotropic() {
  if (has_anisotropic()) {
    delete Data_.anisotropic_;
    clear_has_Data();
  }
}
 const ::atom::proto::materials::Anisotropic& Material::anisotropic() const {
  // @@protoc_insertion_point(field_get:atom.proto.materials.Material.Anisotropic)
  return has_anisotropic()
      ? *Data_.anisotropic_
      : ::atom::proto::materials::Anisotropic::default_instance();
}
::atom::proto::materials::Anisotropic* Material::mutable_anisotropic() {
  if (!has_anisotropic()) {
    clear_Data();
    set_has_anisotropic();
    Data_.anisotropic_ = new ::atom::proto::materials::Anisotropic;
  }
  // @@protoc_insertion_point(field_mutable:atom.proto.materials.Material.Anisotropic)
  return Data_.anisotropic_;
}
::atom::proto::materials::Anisotropic* Material::release_anisotropic() {
  if (has_anisotropic()) {
    clear_has_Data();
    ::atom::proto::materials::Anisotropic* temp = Data_.anisotropic_;
    Data_.anisotropic_ = NULL;
    return temp;
  } else {
    return NULL;
  }
}
void Material::set_allocated_anisotropic(::atom::proto::materials::Anisotropic* anisotropic) {
  clear_Data();
  if (anisotropic) {
    set_has_anisotropic();
    Data_.anisotropic_ = anisotropic;
  }
  // @@protoc_insertion_point(field_set_allocated:atom.proto.materials.Material.Anisotropic)
}

bool Material::has_Data() const {
  return Data_case() != DATA_NOT_SET;
}
void Material::clear_has_Data() {
  _oneof_case_[0] = DATA_NOT_SET;
}
Material::DataCase Material::Data_case() const {
  return Material::DataCase(_oneof_case_[0]);
}
#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace materials
}  // namespace proto
}  // namespace atom

// @@protoc_insertion_point(global_scope)
