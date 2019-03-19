// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: VisibilityChanged.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "VisibilityChanged.pb.h"

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

const ::google::protobuf::Descriptor* VisibilityChanged_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  VisibilityChanged_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_VisibilityChanged_2eproto() {
  protobuf_AddDesc_VisibilityChanged_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "VisibilityChanged.proto");
  GOOGLE_CHECK(file != NULL);
  VisibilityChanged_descriptor_ = file->message_type(0);
  static const int VisibilityChanged_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(VisibilityChanged, objectname_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(VisibilityChanged, visible_),
  };
  VisibilityChanged_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      VisibilityChanged_descriptor_,
      VisibilityChanged::default_instance_,
      VisibilityChanged_offsets_,
      -1,
      -1,
      -1,
      sizeof(VisibilityChanged),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(VisibilityChanged, _internal_metadata_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(VisibilityChanged, _is_default_instance_));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_VisibilityChanged_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      VisibilityChanged_descriptor_, &VisibilityChanged::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_VisibilityChanged_2eproto() {
  delete VisibilityChanged::default_instance_;
  delete VisibilityChanged_reflection_;
}

void protobuf_AddDesc_VisibilityChanged_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\027VisibilityChanged.proto\022\natom.proto\"8\n"
    "\021VisibilityChanged\022\022\n\nObjectName\030\001 \001(\t\022\017"
    "\n\007Visible\030\002 \001(\010b\006proto3", 103);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "VisibilityChanged.proto", &protobuf_RegisterTypes);
  VisibilityChanged::default_instance_ = new VisibilityChanged();
  VisibilityChanged::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_VisibilityChanged_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_VisibilityChanged_2eproto {
  StaticDescriptorInitializer_VisibilityChanged_2eproto() {
    protobuf_AddDesc_VisibilityChanged_2eproto();
  }
} static_descriptor_initializer_VisibilityChanged_2eproto_;

namespace {

static void MergeFromFail(int line) GOOGLE_ATTRIBUTE_COLD;
static void MergeFromFail(int line) {
  GOOGLE_CHECK(false) << __FILE__ << ":" << line;
}

}  // namespace


// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int VisibilityChanged::kObjectNameFieldNumber;
const int VisibilityChanged::kVisibleFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

VisibilityChanged::VisibilityChanged()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:atom.proto.VisibilityChanged)
}

void VisibilityChanged::InitAsDefaultInstance() {
  _is_default_instance_ = true;
}

VisibilityChanged::VisibilityChanged(const VisibilityChanged& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:atom.proto.VisibilityChanged)
}

void VisibilityChanged::SharedCtor() {
    _is_default_instance_ = false;
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  objectname_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  visible_ = false;
}

VisibilityChanged::~VisibilityChanged() {
  // @@protoc_insertion_point(destructor:atom.proto.VisibilityChanged)
  SharedDtor();
}

void VisibilityChanged::SharedDtor() {
  objectname_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (this != default_instance_) {
  }
}

void VisibilityChanged::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* VisibilityChanged::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return VisibilityChanged_descriptor_;
}

const VisibilityChanged& VisibilityChanged::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_VisibilityChanged_2eproto();
  return *default_instance_;
}

VisibilityChanged* VisibilityChanged::default_instance_ = NULL;

VisibilityChanged* VisibilityChanged::New(::google::protobuf::Arena* arena) const {
  VisibilityChanged* n = new VisibilityChanged;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void VisibilityChanged::Clear() {
  objectname_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  visible_ = false;
}

bool VisibilityChanged::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:atom.proto.VisibilityChanged)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional string ObjectName = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_objectname()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->objectname().data(), this->objectname().length(),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "atom.proto.VisibilityChanged.ObjectName"));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_Visible;
        break;
      }

      // optional bool Visible = 2;
      case 2: {
        if (tag == 16) {
         parse_Visible:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &visible_)));

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
  // @@protoc_insertion_point(parse_success:atom.proto.VisibilityChanged)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:atom.proto.VisibilityChanged)
  return false;
#undef DO_
}

void VisibilityChanged::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:atom.proto.VisibilityChanged)
  // optional string ObjectName = 1;
  if (this->objectname().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->objectname().data(), this->objectname().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "atom.proto.VisibilityChanged.ObjectName");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->objectname(), output);
  }

  // optional bool Visible = 2;
  if (this->visible() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(2, this->visible(), output);
  }

  // @@protoc_insertion_point(serialize_end:atom.proto.VisibilityChanged)
}

::google::protobuf::uint8* VisibilityChanged::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:atom.proto.VisibilityChanged)
  // optional string ObjectName = 1;
  if (this->objectname().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->objectname().data(), this->objectname().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "atom.proto.VisibilityChanged.ObjectName");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->objectname(), target);
  }

  // optional bool Visible = 2;
  if (this->visible() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(2, this->visible(), target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:atom.proto.VisibilityChanged)
  return target;
}

int VisibilityChanged::ByteSize() const {
  int total_size = 0;

  // optional string ObjectName = 1;
  if (this->objectname().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->objectname());
  }

  // optional bool Visible = 2;
  if (this->visible() != 0) {
    total_size += 1 + 1;
  }

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void VisibilityChanged::MergeFrom(const ::google::protobuf::Message& from) {
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  const VisibilityChanged* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const VisibilityChanged>(
          &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void VisibilityChanged::MergeFrom(const VisibilityChanged& from) {
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  if (from.objectname().size() > 0) {

    objectname_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.objectname_);
  }
  if (from.visible() != 0) {
    set_visible(from.visible());
  }
}

void VisibilityChanged::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void VisibilityChanged::CopyFrom(const VisibilityChanged& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool VisibilityChanged::IsInitialized() const {

  return true;
}

void VisibilityChanged::Swap(VisibilityChanged* other) {
  if (other == this) return;
  InternalSwap(other);
}
void VisibilityChanged::InternalSwap(VisibilityChanged* other) {
  objectname_.Swap(&other->objectname_);
  std::swap(visible_, other->visible_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata VisibilityChanged::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = VisibilityChanged_descriptor_;
  metadata.reflection = VisibilityChanged_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// VisibilityChanged

// optional string ObjectName = 1;
void VisibilityChanged::clear_objectname() {
  objectname_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 const ::std::string& VisibilityChanged::objectname() const {
  // @@protoc_insertion_point(field_get:atom.proto.VisibilityChanged.ObjectName)
  return objectname_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void VisibilityChanged::set_objectname(const ::std::string& value) {
  
  objectname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:atom.proto.VisibilityChanged.ObjectName)
}
 void VisibilityChanged::set_objectname(const char* value) {
  
  objectname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:atom.proto.VisibilityChanged.ObjectName)
}
 void VisibilityChanged::set_objectname(const char* value, size_t size) {
  
  objectname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:atom.proto.VisibilityChanged.ObjectName)
}
 ::std::string* VisibilityChanged::mutable_objectname() {
  
  // @@protoc_insertion_point(field_mutable:atom.proto.VisibilityChanged.ObjectName)
  return objectname_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 ::std::string* VisibilityChanged::release_objectname() {
  
  return objectname_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void VisibilityChanged::set_allocated_objectname(::std::string* objectname) {
  if (objectname != NULL) {
    
  } else {
    
  }
  objectname_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), objectname);
  // @@protoc_insertion_point(field_set_allocated:atom.proto.VisibilityChanged.ObjectName)
}

// optional bool Visible = 2;
void VisibilityChanged::clear_visible() {
  visible_ = false;
}
 bool VisibilityChanged::visible() const {
  // @@protoc_insertion_point(field_get:atom.proto.VisibilityChanged.Visible)
  return visible_;
}
 void VisibilityChanged::set_visible(bool value) {
  
  visible_ = value;
  // @@protoc_insertion_point(field_set:atom.proto.VisibilityChanged.Visible)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace proto
}  // namespace atom

// @@protoc_insertion_point(global_scope)