// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: meshes/MeshPointsChanged.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "meshes/MeshPointsChanged.pb.h"

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
namespace meshes {

namespace {

const ::google::protobuf::Descriptor* MeshPointsChanged_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  MeshPointsChanged_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_meshes_2fMeshPointsChanged_2eproto() {
  protobuf_AddDesc_meshes_2fMeshPointsChanged_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "meshes/MeshPointsChanged.proto");
  GOOGLE_CHECK(file != NULL);
  MeshPointsChanged_descriptor_ = file->message_type(0);
  static const int MeshPointsChanged_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MeshPointsChanged, meshname_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MeshPointsChanged, vertices_),
  };
  MeshPointsChanged_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      MeshPointsChanged_descriptor_,
      MeshPointsChanged::default_instance_,
      MeshPointsChanged_offsets_,
      -1,
      -1,
      -1,
      sizeof(MeshPointsChanged),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MeshPointsChanged, _internal_metadata_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MeshPointsChanged, _is_default_instance_));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_meshes_2fMeshPointsChanged_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      MeshPointsChanged_descriptor_, &MeshPointsChanged::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_meshes_2fMeshPointsChanged_2eproto() {
  delete MeshPointsChanged::default_instance_;
  delete MeshPointsChanged_reflection_;
}

void protobuf_AddDesc_meshes_2fMeshPointsChanged_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::atom::proto::protobuf_AddDesc_Vertex_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\036meshes/MeshPointsChanged.proto\022\021atom.p"
    "roto.meshes\032\014Vertex.proto\"K\n\021MeshPointsC"
    "hanged\022\020\n\010MeshName\030\001 \001(\t\022$\n\010Vertices\030\002 \003"
    "(\0132\022.atom.proto.Vertexb\006proto3", 150);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "meshes/MeshPointsChanged.proto", &protobuf_RegisterTypes);
  MeshPointsChanged::default_instance_ = new MeshPointsChanged();
  MeshPointsChanged::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_meshes_2fMeshPointsChanged_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_meshes_2fMeshPointsChanged_2eproto {
  StaticDescriptorInitializer_meshes_2fMeshPointsChanged_2eproto() {
    protobuf_AddDesc_meshes_2fMeshPointsChanged_2eproto();
  }
} static_descriptor_initializer_meshes_2fMeshPointsChanged_2eproto_;

namespace {

static void MergeFromFail(int line) GOOGLE_ATTRIBUTE_COLD;
static void MergeFromFail(int line) {
  GOOGLE_CHECK(false) << __FILE__ << ":" << line;
}

}  // namespace


// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int MeshPointsChanged::kMeshNameFieldNumber;
const int MeshPointsChanged::kVerticesFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

MeshPointsChanged::MeshPointsChanged()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:atom.proto.meshes.MeshPointsChanged)
}

void MeshPointsChanged::InitAsDefaultInstance() {
  _is_default_instance_ = true;
}

MeshPointsChanged::MeshPointsChanged(const MeshPointsChanged& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:atom.proto.meshes.MeshPointsChanged)
}

void MeshPointsChanged::SharedCtor() {
    _is_default_instance_ = false;
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  meshname_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

MeshPointsChanged::~MeshPointsChanged() {
  // @@protoc_insertion_point(destructor:atom.proto.meshes.MeshPointsChanged)
  SharedDtor();
}

void MeshPointsChanged::SharedDtor() {
  meshname_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (this != default_instance_) {
  }
}

void MeshPointsChanged::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* MeshPointsChanged::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return MeshPointsChanged_descriptor_;
}

const MeshPointsChanged& MeshPointsChanged::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_meshes_2fMeshPointsChanged_2eproto();
  return *default_instance_;
}

MeshPointsChanged* MeshPointsChanged::default_instance_ = NULL;

MeshPointsChanged* MeshPointsChanged::New(::google::protobuf::Arena* arena) const {
  MeshPointsChanged* n = new MeshPointsChanged;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void MeshPointsChanged::Clear() {
  meshname_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  vertices_.Clear();
}

bool MeshPointsChanged::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:atom.proto.meshes.MeshPointsChanged)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional string MeshName = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_meshname()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->meshname().data(), this->meshname().length(),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "atom.proto.meshes.MeshPointsChanged.MeshName"));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_Vertices;
        break;
      }

      // repeated .atom.proto.Vertex Vertices = 2;
      case 2: {
        if (tag == 18) {
         parse_Vertices:
          DO_(input->IncrementRecursionDepth());
         parse_loop_Vertices:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtualNoRecursionDepth(
                input, add_vertices()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_loop_Vertices;
        input->UnsafeDecrementRecursionDepth();
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
  // @@protoc_insertion_point(parse_success:atom.proto.meshes.MeshPointsChanged)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:atom.proto.meshes.MeshPointsChanged)
  return false;
#undef DO_
}

void MeshPointsChanged::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:atom.proto.meshes.MeshPointsChanged)
  // optional string MeshName = 1;
  if (this->meshname().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->meshname().data(), this->meshname().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "atom.proto.meshes.MeshPointsChanged.MeshName");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->meshname(), output);
  }

  // repeated .atom.proto.Vertex Vertices = 2;
  for (unsigned int i = 0, n = this->vertices_size(); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->vertices(i), output);
  }

  // @@protoc_insertion_point(serialize_end:atom.proto.meshes.MeshPointsChanged)
}

::google::protobuf::uint8* MeshPointsChanged::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:atom.proto.meshes.MeshPointsChanged)
  // optional string MeshName = 1;
  if (this->meshname().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->meshname().data(), this->meshname().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "atom.proto.meshes.MeshPointsChanged.MeshName");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->meshname(), target);
  }

  // repeated .atom.proto.Vertex Vertices = 2;
  for (unsigned int i = 0, n = this->vertices_size(); i < n; i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->vertices(i), target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:atom.proto.meshes.MeshPointsChanged)
  return target;
}

int MeshPointsChanged::ByteSize() const {
  int total_size = 0;

  // optional string MeshName = 1;
  if (this->meshname().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->meshname());
  }

  // repeated .atom.proto.Vertex Vertices = 2;
  total_size += 1 * this->vertices_size();
  for (int i = 0; i < this->vertices_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->vertices(i));
  }

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void MeshPointsChanged::MergeFrom(const ::google::protobuf::Message& from) {
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  const MeshPointsChanged* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const MeshPointsChanged>(
          &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void MeshPointsChanged::MergeFrom(const MeshPointsChanged& from) {
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  vertices_.MergeFrom(from.vertices_);
  if (from.meshname().size() > 0) {

    meshname_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.meshname_);
  }
}

void MeshPointsChanged::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void MeshPointsChanged::CopyFrom(const MeshPointsChanged& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MeshPointsChanged::IsInitialized() const {

  return true;
}

void MeshPointsChanged::Swap(MeshPointsChanged* other) {
  if (other == this) return;
  InternalSwap(other);
}
void MeshPointsChanged::InternalSwap(MeshPointsChanged* other) {
  meshname_.Swap(&other->meshname_);
  vertices_.UnsafeArenaSwap(&other->vertices_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata MeshPointsChanged::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = MeshPointsChanged_descriptor_;
  metadata.reflection = MeshPointsChanged_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// MeshPointsChanged

// optional string MeshName = 1;
void MeshPointsChanged::clear_meshname() {
  meshname_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 const ::std::string& MeshPointsChanged::meshname() const {
  // @@protoc_insertion_point(field_get:atom.proto.meshes.MeshPointsChanged.MeshName)
  return meshname_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void MeshPointsChanged::set_meshname(const ::std::string& value) {
  
  meshname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:atom.proto.meshes.MeshPointsChanged.MeshName)
}
 void MeshPointsChanged::set_meshname(const char* value) {
  
  meshname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:atom.proto.meshes.MeshPointsChanged.MeshName)
}
 void MeshPointsChanged::set_meshname(const char* value, size_t size) {
  
  meshname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:atom.proto.meshes.MeshPointsChanged.MeshName)
}
 ::std::string* MeshPointsChanged::mutable_meshname() {
  
  // @@protoc_insertion_point(field_mutable:atom.proto.meshes.MeshPointsChanged.MeshName)
  return meshname_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 ::std::string* MeshPointsChanged::release_meshname() {
  
  return meshname_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void MeshPointsChanged::set_allocated_meshname(::std::string* meshname) {
  if (meshname != NULL) {
    
  } else {
    
  }
  meshname_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), meshname);
  // @@protoc_insertion_point(field_set_allocated:atom.proto.meshes.MeshPointsChanged.MeshName)
}

// repeated .atom.proto.Vertex Vertices = 2;
int MeshPointsChanged::vertices_size() const {
  return vertices_.size();
}
void MeshPointsChanged::clear_vertices() {
  vertices_.Clear();
}
const ::atom::proto::Vertex& MeshPointsChanged::vertices(int index) const {
  // @@protoc_insertion_point(field_get:atom.proto.meshes.MeshPointsChanged.Vertices)
  return vertices_.Get(index);
}
::atom::proto::Vertex* MeshPointsChanged::mutable_vertices(int index) {
  // @@protoc_insertion_point(field_mutable:atom.proto.meshes.MeshPointsChanged.Vertices)
  return vertices_.Mutable(index);
}
::atom::proto::Vertex* MeshPointsChanged::add_vertices() {
  // @@protoc_insertion_point(field_add:atom.proto.meshes.MeshPointsChanged.Vertices)
  return vertices_.Add();
}
::google::protobuf::RepeatedPtrField< ::atom::proto::Vertex >*
MeshPointsChanged::mutable_vertices() {
  // @@protoc_insertion_point(field_mutable_list:atom.proto.meshes.MeshPointsChanged.Vertices)
  return &vertices_;
}
const ::google::protobuf::RepeatedPtrField< ::atom::proto::Vertex >&
MeshPointsChanged::vertices() const {
  // @@protoc_insertion_point(field_list:atom.proto.meshes.MeshPointsChanged.Vertices)
  return vertices_;
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace meshes
}  // namespace proto
}  // namespace atom

// @@protoc_insertion_point(global_scope)
