// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Curve.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "Curve.pb.h"

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

const ::google::protobuf::Descriptor* Curve_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Curve_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_Curve_2eproto() {
  protobuf_AddDesc_Curve_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "Curve.proto");
  GOOGLE_CHECK(file != NULL);
  Curve_descriptor_ = file->message_type(0);
  static const int Curve_offsets_[4] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Curve, name_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Curve, cv_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Curve, world_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Curve, initialvisibility_),
  };
  Curve_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      Curve_descriptor_,
      Curve::default_instance_,
      Curve_offsets_,
      -1,
      -1,
      -1,
      sizeof(Curve),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Curve, _internal_metadata_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Curve, _is_default_instance_));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_Curve_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      Curve_descriptor_, &Curve::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_Curve_2eproto() {
  delete Curve::default_instance_;
  delete Curve_reflection_;
}

void protobuf_AddDesc_Curve_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::atom::proto::protobuf_AddDesc_Vector3_2eproto();
  ::atom::proto::protobuf_AddDesc_Matrix_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\013Curve.proto\022\natom.proto\032\rVector3.proto"
    "\032\014Matrix.proto\"t\n\005Curve\022\014\n\004Name\030\001 \001(\t\022\037\n"
    "\002CV\030\002 \003(\0132\023.atom.proto.Vector3\022!\n\005World\030"
    "\003 \001(\0132\022.atom.proto.Matrix\022\031\n\021InitialVisi"
    "bility\030\004 \001(\010b\006proto3", 180);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "Curve.proto", &protobuf_RegisterTypes);
  Curve::default_instance_ = new Curve();
  Curve::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_Curve_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_Curve_2eproto {
  StaticDescriptorInitializer_Curve_2eproto() {
    protobuf_AddDesc_Curve_2eproto();
  }
} static_descriptor_initializer_Curve_2eproto_;

namespace {

static void MergeFromFail(int line) GOOGLE_ATTRIBUTE_COLD;
static void MergeFromFail(int line) {
  GOOGLE_CHECK(false) << __FILE__ << ":" << line;
}

}  // namespace


// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int Curve::kNameFieldNumber;
const int Curve::kCVFieldNumber;
const int Curve::kWorldFieldNumber;
const int Curve::kInitialVisibilityFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

Curve::Curve()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:atom.proto.Curve)
}

void Curve::InitAsDefaultInstance() {
  _is_default_instance_ = true;
  world_ = const_cast< ::atom::proto::Matrix*>(&::atom::proto::Matrix::default_instance());
}

Curve::Curve(const Curve& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:atom.proto.Curve)
}

void Curve::SharedCtor() {
    _is_default_instance_ = false;
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  name_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  world_ = NULL;
  initialvisibility_ = false;
}

Curve::~Curve() {
  // @@protoc_insertion_point(destructor:atom.proto.Curve)
  SharedDtor();
}

void Curve::SharedDtor() {
  name_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (this != default_instance_) {
    delete world_;
  }
}

void Curve::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Curve::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Curve_descriptor_;
}

const Curve& Curve::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_Curve_2eproto();
  return *default_instance_;
}

Curve* Curve::default_instance_ = NULL;

Curve* Curve::New(::google::protobuf::Arena* arena) const {
  Curve* n = new Curve;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void Curve::Clear() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (GetArenaNoVirtual() == NULL && world_ != NULL) delete world_;
  world_ = NULL;
  initialvisibility_ = false;
  cv_.Clear();
}

bool Curve::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:atom.proto.Curve)
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
            "atom.proto.Curve.Name"));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_CV;
        break;
      }

      // repeated .atom.proto.Vector3 CV = 2;
      case 2: {
        if (tag == 18) {
         parse_CV:
          DO_(input->IncrementRecursionDepth());
         parse_loop_CV:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtualNoRecursionDepth(
                input, add_cv()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_loop_CV;
        input->UnsafeDecrementRecursionDepth();
        if (input->ExpectTag(26)) goto parse_World;
        break;
      }

      // optional .atom.proto.Matrix World = 3;
      case 3: {
        if (tag == 26) {
         parse_World:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_world()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(32)) goto parse_InitialVisibility;
        break;
      }

      // optional bool InitialVisibility = 4;
      case 4: {
        if (tag == 32) {
         parse_InitialVisibility:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &initialvisibility_)));

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
  // @@protoc_insertion_point(parse_success:atom.proto.Curve)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:atom.proto.Curve)
  return false;
#undef DO_
}

void Curve::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:atom.proto.Curve)
  // optional string Name = 1;
  if (this->name().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->name().data(), this->name().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "atom.proto.Curve.Name");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->name(), output);
  }

  // repeated .atom.proto.Vector3 CV = 2;
  for (unsigned int i = 0, n = this->cv_size(); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->cv(i), output);
  }

  // optional .atom.proto.Matrix World = 3;
  if (this->has_world()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      3, *this->world_, output);
  }

  // optional bool InitialVisibility = 4;
  if (this->initialvisibility() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(4, this->initialvisibility(), output);
  }

  // @@protoc_insertion_point(serialize_end:atom.proto.Curve)
}

::google::protobuf::uint8* Curve::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:atom.proto.Curve)
  // optional string Name = 1;
  if (this->name().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->name().data(), this->name().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "atom.proto.Curve.Name");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->name(), target);
  }

  // repeated .atom.proto.Vector3 CV = 2;
  for (unsigned int i = 0, n = this->cv_size(); i < n; i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->cv(i), target);
  }

  // optional .atom.proto.Matrix World = 3;
  if (this->has_world()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        3, *this->world_, target);
  }

  // optional bool InitialVisibility = 4;
  if (this->initialvisibility() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(4, this->initialvisibility(), target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:atom.proto.Curve)
  return target;
}

int Curve::ByteSize() const {
  int total_size = 0;

  // optional string Name = 1;
  if (this->name().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->name());
  }

  // optional .atom.proto.Matrix World = 3;
  if (this->has_world()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        *this->world_);
  }

  // optional bool InitialVisibility = 4;
  if (this->initialvisibility() != 0) {
    total_size += 1 + 1;
  }

  // repeated .atom.proto.Vector3 CV = 2;
  total_size += 1 * this->cv_size();
  for (int i = 0; i < this->cv_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->cv(i));
  }

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Curve::MergeFrom(const ::google::protobuf::Message& from) {
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  const Curve* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const Curve>(
          &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Curve::MergeFrom(const Curve& from) {
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  cv_.MergeFrom(from.cv_);
  if (from.name().size() > 0) {

    name_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.name_);
  }
  if (from.has_world()) {
    mutable_world()->::atom::proto::Matrix::MergeFrom(from.world());
  }
  if (from.initialvisibility() != 0) {
    set_initialvisibility(from.initialvisibility());
  }
}

void Curve::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Curve::CopyFrom(const Curve& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Curve::IsInitialized() const {

  return true;
}

void Curve::Swap(Curve* other) {
  if (other == this) return;
  InternalSwap(other);
}
void Curve::InternalSwap(Curve* other) {
  name_.Swap(&other->name_);
  cv_.UnsafeArenaSwap(&other->cv_);
  std::swap(world_, other->world_);
  std::swap(initialvisibility_, other->initialvisibility_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata Curve::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Curve_descriptor_;
  metadata.reflection = Curve_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// Curve

// optional string Name = 1;
void Curve::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 const ::std::string& Curve::name() const {
  // @@protoc_insertion_point(field_get:atom.proto.Curve.Name)
  return name_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void Curve::set_name(const ::std::string& value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:atom.proto.Curve.Name)
}
 void Curve::set_name(const char* value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:atom.proto.Curve.Name)
}
 void Curve::set_name(const char* value, size_t size) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:atom.proto.Curve.Name)
}
 ::std::string* Curve::mutable_name() {
  
  // @@protoc_insertion_point(field_mutable:atom.proto.Curve.Name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 ::std::string* Curve::release_name() {
  
  return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void Curve::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    
  } else {
    
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:atom.proto.Curve.Name)
}

// repeated .atom.proto.Vector3 CV = 2;
int Curve::cv_size() const {
  return cv_.size();
}
void Curve::clear_cv() {
  cv_.Clear();
}
const ::atom::proto::Vector3& Curve::cv(int index) const {
  // @@protoc_insertion_point(field_get:atom.proto.Curve.CV)
  return cv_.Get(index);
}
::atom::proto::Vector3* Curve::mutable_cv(int index) {
  // @@protoc_insertion_point(field_mutable:atom.proto.Curve.CV)
  return cv_.Mutable(index);
}
::atom::proto::Vector3* Curve::add_cv() {
  // @@protoc_insertion_point(field_add:atom.proto.Curve.CV)
  return cv_.Add();
}
::google::protobuf::RepeatedPtrField< ::atom::proto::Vector3 >*
Curve::mutable_cv() {
  // @@protoc_insertion_point(field_mutable_list:atom.proto.Curve.CV)
  return &cv_;
}
const ::google::protobuf::RepeatedPtrField< ::atom::proto::Vector3 >&
Curve::cv() const {
  // @@protoc_insertion_point(field_list:atom.proto.Curve.CV)
  return cv_;
}

// optional .atom.proto.Matrix World = 3;
bool Curve::has_world() const {
  return !_is_default_instance_ && world_ != NULL;
}
void Curve::clear_world() {
  if (GetArenaNoVirtual() == NULL && world_ != NULL) delete world_;
  world_ = NULL;
}
const ::atom::proto::Matrix& Curve::world() const {
  // @@protoc_insertion_point(field_get:atom.proto.Curve.World)
  return world_ != NULL ? *world_ : *default_instance_->world_;
}
::atom::proto::Matrix* Curve::mutable_world() {
  
  if (world_ == NULL) {
    world_ = new ::atom::proto::Matrix;
  }
  // @@protoc_insertion_point(field_mutable:atom.proto.Curve.World)
  return world_;
}
::atom::proto::Matrix* Curve::release_world() {
  
  ::atom::proto::Matrix* temp = world_;
  world_ = NULL;
  return temp;
}
void Curve::set_allocated_world(::atom::proto::Matrix* world) {
  delete world_;
  world_ = world;
  if (world) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:atom.proto.Curve.World)
}

// optional bool InitialVisibility = 4;
void Curve::clear_initialvisibility() {
  initialvisibility_ = false;
}
 bool Curve::initialvisibility() const {
  // @@protoc_insertion_point(field_get:atom.proto.Curve.InitialVisibility)
  return initialvisibility_;
}
 void Curve::set_initialvisibility(bool value) {
  
  initialvisibility_ = value;
  // @@protoc_insertion_point(field_set:atom.proto.Curve.InitialVisibility)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace proto
}  // namespace atom

// @@protoc_insertion_point(global_scope)
