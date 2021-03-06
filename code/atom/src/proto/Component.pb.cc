// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Component.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "Component.pb.h"

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

namespace {

const ::google::protobuf::Descriptor* Component_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Component_reflection_ = NULL;
const ::google::protobuf::EnumDescriptor* Component_ComponentType_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_Component_2eproto() {
  protobuf_AddDesc_Component_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "Component.proto");
  GOOGLE_CHECK(file != NULL);
  Component_descriptor_ = file->message_type(0);
  static const int Component_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Component, type_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Component, name_),
  };
  Component_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      Component_descriptor_,
      Component::default_instance_,
      Component_offsets_,
      -1,
      -1,
      -1,
      sizeof(Component),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Component, _internal_metadata_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Component, _is_default_instance_));
  Component_ComponentType_descriptor_ = Component_descriptor_->enum_type(0);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_Component_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      Component_descriptor_, &Component::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_Component_2eproto() {
  delete Component::default_instance_;
  delete Component_reflection_;
}

void protobuf_AddDesc_Component_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\017Component.proto\022\natom.proto\"\236\001\n\tCompon"
    "ent\0221\n\004Type\030\001 \001(\0162#.atom.proto.Component"
    ".ComponentType\022\014\n\004Name\030\002 \001(\t\"P\n\rComponen"
    "tType\022\t\n\005kMesh\020\000\022\n\n\006kLight\020\002\022\013\n\007kCamera\020"
    "\003\022\017\n\013kAnnotation\020\004\022\n\n\006kCurve\020\005b\006proto3", 198);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "Component.proto", &protobuf_RegisterTypes);
  Component::default_instance_ = new Component();
  Component::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_Component_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_Component_2eproto {
  StaticDescriptorInitializer_Component_2eproto() {
    protobuf_AddDesc_Component_2eproto();
  }
} static_descriptor_initializer_Component_2eproto_;

namespace {

static void MergeFromFail(int line) GOOGLE_ATTRIBUTE_COLD;
static void MergeFromFail(int line) {
  GOOGLE_CHECK(false) << __FILE__ << ":" << line;
}

}  // namespace


// ===================================================================

const ::google::protobuf::EnumDescriptor* Component_ComponentType_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Component_ComponentType_descriptor_;
}
bool Component_ComponentType_IsValid(int value) {
  switch(value) {
    case 0:
    case 2:
    case 3:
    case 4:
    case 5:
      return true;
    default:
      return false;
  }
}

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const Component_ComponentType Component::kMesh;
const Component_ComponentType Component::kLight;
const Component_ComponentType Component::kCamera;
const Component_ComponentType Component::kAnnotation;
const Component_ComponentType Component::kCurve;
const Component_ComponentType Component::ComponentType_MIN;
const Component_ComponentType Component::ComponentType_MAX;
const int Component::ComponentType_ARRAYSIZE;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int Component::kTypeFieldNumber;
const int Component::kNameFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

Component::Component()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:atom.proto.Component)
}

void Component::InitAsDefaultInstance() {
  _is_default_instance_ = true;
}

Component::Component(const Component& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:atom.proto.Component)
}

void Component::SharedCtor() {
    _is_default_instance_ = false;
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  type_ = 0;
  name_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

Component::~Component() {
  // @@protoc_insertion_point(destructor:atom.proto.Component)
  SharedDtor();
}

void Component::SharedDtor() {
  name_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (this != default_instance_) {
  }
}

void Component::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Component::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Component_descriptor_;
}

const Component& Component::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_Component_2eproto();
  return *default_instance_;
}

Component* Component::default_instance_ = NULL;

Component* Component::New(::google::protobuf::Arena* arena) const {
  Component* n = new Component;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void Component::Clear() {
  type_ = 0;
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

bool Component::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:atom.proto.Component)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .atom.proto.Component.ComponentType Type = 1;
      case 1: {
        if (tag == 8) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          set_type(static_cast< ::atom::proto::Component_ComponentType >(value));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_Name;
        break;
      }

      // optional string Name = 2;
      case 2: {
        if (tag == 18) {
         parse_Name:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_name()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->name().data(), this->name().length(),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "atom.proto.Component.Name"));
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
  // @@protoc_insertion_point(parse_success:atom.proto.Component)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:atom.proto.Component)
  return false;
#undef DO_
}

void Component::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:atom.proto.Component)
  // optional .atom.proto.Component.ComponentType Type = 1;
  if (this->type() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      1, this->type(), output);
  }

  // optional string Name = 2;
  if (this->name().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->name().data(), this->name().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "atom.proto.Component.Name");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->name(), output);
  }

  // @@protoc_insertion_point(serialize_end:atom.proto.Component)
}

::google::protobuf::uint8* Component::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:atom.proto.Component)
  // optional .atom.proto.Component.ComponentType Type = 1;
  if (this->type() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      1, this->type(), target);
  }

  // optional string Name = 2;
  if (this->name().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->name().data(), this->name().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "atom.proto.Component.Name");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->name(), target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:atom.proto.Component)
  return target;
}

int Component::ByteSize() const {
  int total_size = 0;

  // optional .atom.proto.Component.ComponentType Type = 1;
  if (this->type() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::EnumSize(this->type());
  }

  // optional string Name = 2;
  if (this->name().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->name());
  }

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Component::MergeFrom(const ::google::protobuf::Message& from) {
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  const Component* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const Component>(
          &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Component::MergeFrom(const Component& from) {
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  if (from.type() != 0) {
    set_type(from.type());
  }
  if (from.name().size() > 0) {

    name_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.name_);
  }
}

void Component::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Component::CopyFrom(const Component& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Component::IsInitialized() const {

  return true;
}

void Component::Swap(Component* other) {
  if (other == this) return;
  InternalSwap(other);
}
void Component::InternalSwap(Component* other) {
  std::swap(type_, other->type_);
  name_.Swap(&other->name_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata Component::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Component_descriptor_;
  metadata.reflection = Component_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// Component

// optional .atom.proto.Component.ComponentType Type = 1;
void Component::clear_type() {
  type_ = 0;
}
 ::atom::proto::Component_ComponentType Component::type() const {
  // @@protoc_insertion_point(field_get:atom.proto.Component.Type)
  return static_cast< ::atom::proto::Component_ComponentType >(type_);
}
 void Component::set_type(::atom::proto::Component_ComponentType value) {
  
  type_ = value;
  // @@protoc_insertion_point(field_set:atom.proto.Component.Type)
}

// optional string Name = 2;
void Component::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 const ::std::string& Component::name() const {
  // @@protoc_insertion_point(field_get:atom.proto.Component.Name)
  return name_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void Component::set_name(const ::std::string& value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:atom.proto.Component.Name)
}
 void Component::set_name(const char* value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:atom.proto.Component.Name)
}
 void Component::set_name(const char* value, size_t size) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:atom.proto.Component.Name)
}
 ::std::string* Component::mutable_name() {
  
  // @@protoc_insertion_point(field_mutable:atom.proto.Component.Name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 ::std::string* Component::release_name() {
  
  return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void Component::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    
  } else {
    
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:atom.proto.Component.Name)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace proto
}  // namespace atom

// @@protoc_insertion_point(global_scope)
