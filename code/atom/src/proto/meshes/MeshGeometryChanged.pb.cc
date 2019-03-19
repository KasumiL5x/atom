// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: meshes/MeshGeometryChanged.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "meshes/MeshGeometryChanged.pb.h"

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

const ::google::protobuf::Descriptor* MeshGeometryChanged_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  MeshGeometryChanged_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_meshes_2fMeshGeometryChanged_2eproto() {
  protobuf_AddDesc_meshes_2fMeshGeometryChanged_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "meshes/MeshGeometryChanged.proto");
  GOOGLE_CHECK(file != NULL);
  MeshGeometryChanged_descriptor_ = file->message_type(0);
  static const int MeshGeometryChanged_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MeshGeometryChanged, meshname_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MeshGeometryChanged, vertices_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MeshGeometryChanged, indices_),
  };
  MeshGeometryChanged_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      MeshGeometryChanged_descriptor_,
      MeshGeometryChanged::default_instance_,
      MeshGeometryChanged_offsets_,
      -1,
      -1,
      -1,
      sizeof(MeshGeometryChanged),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MeshGeometryChanged, _internal_metadata_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MeshGeometryChanged, _is_default_instance_));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_meshes_2fMeshGeometryChanged_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      MeshGeometryChanged_descriptor_, &MeshGeometryChanged::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_meshes_2fMeshGeometryChanged_2eproto() {
  delete MeshGeometryChanged::default_instance_;
  delete MeshGeometryChanged_reflection_;
}

void protobuf_AddDesc_meshes_2fMeshGeometryChanged_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::atom::proto::protobuf_AddDesc_Vertex_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n meshes/MeshGeometryChanged.proto\022\021atom"
    ".proto.meshes\032\014Vertex.proto\"b\n\023MeshGeome"
    "tryChanged\022\020\n\010MeshName\030\001 \001(\t\022$\n\010Vertices"
    "\030\002 \003(\0132\022.atom.proto.Vertex\022\023\n\007Indices\030\003 "
    "\003(\005B\002\020\001b\006proto3", 175);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "meshes/MeshGeometryChanged.proto", &protobuf_RegisterTypes);
  MeshGeometryChanged::default_instance_ = new MeshGeometryChanged();
  MeshGeometryChanged::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_meshes_2fMeshGeometryChanged_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_meshes_2fMeshGeometryChanged_2eproto {
  StaticDescriptorInitializer_meshes_2fMeshGeometryChanged_2eproto() {
    protobuf_AddDesc_meshes_2fMeshGeometryChanged_2eproto();
  }
} static_descriptor_initializer_meshes_2fMeshGeometryChanged_2eproto_;

namespace {

static void MergeFromFail(int line) GOOGLE_ATTRIBUTE_COLD;
static void MergeFromFail(int line) {
  GOOGLE_CHECK(false) << __FILE__ << ":" << line;
}

}  // namespace


// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int MeshGeometryChanged::kMeshNameFieldNumber;
const int MeshGeometryChanged::kVerticesFieldNumber;
const int MeshGeometryChanged::kIndicesFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

MeshGeometryChanged::MeshGeometryChanged()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:atom.proto.meshes.MeshGeometryChanged)
}

void MeshGeometryChanged::InitAsDefaultInstance() {
  _is_default_instance_ = true;
}

MeshGeometryChanged::MeshGeometryChanged(const MeshGeometryChanged& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:atom.proto.meshes.MeshGeometryChanged)
}

void MeshGeometryChanged::SharedCtor() {
    _is_default_instance_ = false;
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  meshname_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

MeshGeometryChanged::~MeshGeometryChanged() {
  // @@protoc_insertion_point(destructor:atom.proto.meshes.MeshGeometryChanged)
  SharedDtor();
}

void MeshGeometryChanged::SharedDtor() {
  meshname_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (this != default_instance_) {
  }
}

void MeshGeometryChanged::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* MeshGeometryChanged::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return MeshGeometryChanged_descriptor_;
}

const MeshGeometryChanged& MeshGeometryChanged::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_meshes_2fMeshGeometryChanged_2eproto();
  return *default_instance_;
}

MeshGeometryChanged* MeshGeometryChanged::default_instance_ = NULL;

MeshGeometryChanged* MeshGeometryChanged::New(::google::protobuf::Arena* arena) const {
  MeshGeometryChanged* n = new MeshGeometryChanged;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void MeshGeometryChanged::Clear() {
  meshname_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  vertices_.Clear();
  indices_.Clear();
}

bool MeshGeometryChanged::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:atom.proto.meshes.MeshGeometryChanged)
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
            "atom.proto.meshes.MeshGeometryChanged.MeshName"));
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
        if (input->ExpectTag(26)) goto parse_Indices;
        break;
      }

      // repeated int32 Indices = 3 [packed = true];
      case 3: {
        if (tag == 26) {
         parse_Indices:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, this->mutable_indices())));
        } else if (tag == 24) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitiveNoInline<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 1, 26, input, this->mutable_indices())));
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
  // @@protoc_insertion_point(parse_success:atom.proto.meshes.MeshGeometryChanged)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:atom.proto.meshes.MeshGeometryChanged)
  return false;
#undef DO_
}

void MeshGeometryChanged::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:atom.proto.meshes.MeshGeometryChanged)
  // optional string MeshName = 1;
  if (this->meshname().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->meshname().data(), this->meshname().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "atom.proto.meshes.MeshGeometryChanged.MeshName");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->meshname(), output);
  }

  // repeated .atom.proto.Vertex Vertices = 2;
  for (unsigned int i = 0, n = this->vertices_size(); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->vertices(i), output);
  }

  // repeated int32 Indices = 3 [packed = true];
  if (this->indices_size() > 0) {
    ::google::protobuf::internal::WireFormatLite::WriteTag(3, ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
    output->WriteVarint32(_indices_cached_byte_size_);
  }
  for (int i = 0; i < this->indices_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(
      this->indices(i), output);
  }

  // @@protoc_insertion_point(serialize_end:atom.proto.meshes.MeshGeometryChanged)
}

::google::protobuf::uint8* MeshGeometryChanged::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:atom.proto.meshes.MeshGeometryChanged)
  // optional string MeshName = 1;
  if (this->meshname().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->meshname().data(), this->meshname().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "atom.proto.meshes.MeshGeometryChanged.MeshName");
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

  // repeated int32 Indices = 3 [packed = true];
  if (this->indices_size() > 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(
      3,
      ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED,
      target);
    target = ::google::protobuf::io::CodedOutputStream::WriteVarint32ToArray(
      _indices_cached_byte_size_, target);
  }
  for (int i = 0; i < this->indices_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteInt32NoTagToArray(this->indices(i), target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:atom.proto.meshes.MeshGeometryChanged)
  return target;
}

int MeshGeometryChanged::ByteSize() const {
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

  // repeated int32 Indices = 3 [packed = true];
  {
    int data_size = 0;
    for (int i = 0; i < this->indices_size(); i++) {
      data_size += ::google::protobuf::internal::WireFormatLite::
        Int32Size(this->indices(i));
    }
    if (data_size > 0) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(data_size);
    }
    GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
    _indices_cached_byte_size_ = data_size;
    GOOGLE_SAFE_CONCURRENT_WRITES_END();
    total_size += data_size;
  }

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void MeshGeometryChanged::MergeFrom(const ::google::protobuf::Message& from) {
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  const MeshGeometryChanged* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const MeshGeometryChanged>(
          &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void MeshGeometryChanged::MergeFrom(const MeshGeometryChanged& from) {
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  vertices_.MergeFrom(from.vertices_);
  indices_.MergeFrom(from.indices_);
  if (from.meshname().size() > 0) {

    meshname_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.meshname_);
  }
}

void MeshGeometryChanged::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void MeshGeometryChanged::CopyFrom(const MeshGeometryChanged& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MeshGeometryChanged::IsInitialized() const {

  return true;
}

void MeshGeometryChanged::Swap(MeshGeometryChanged* other) {
  if (other == this) return;
  InternalSwap(other);
}
void MeshGeometryChanged::InternalSwap(MeshGeometryChanged* other) {
  meshname_.Swap(&other->meshname_);
  vertices_.UnsafeArenaSwap(&other->vertices_);
  indices_.UnsafeArenaSwap(&other->indices_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata MeshGeometryChanged::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = MeshGeometryChanged_descriptor_;
  metadata.reflection = MeshGeometryChanged_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// MeshGeometryChanged

// optional string MeshName = 1;
void MeshGeometryChanged::clear_meshname() {
  meshname_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 const ::std::string& MeshGeometryChanged::meshname() const {
  // @@protoc_insertion_point(field_get:atom.proto.meshes.MeshGeometryChanged.MeshName)
  return meshname_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void MeshGeometryChanged::set_meshname(const ::std::string& value) {
  
  meshname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:atom.proto.meshes.MeshGeometryChanged.MeshName)
}
 void MeshGeometryChanged::set_meshname(const char* value) {
  
  meshname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:atom.proto.meshes.MeshGeometryChanged.MeshName)
}
 void MeshGeometryChanged::set_meshname(const char* value, size_t size) {
  
  meshname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:atom.proto.meshes.MeshGeometryChanged.MeshName)
}
 ::std::string* MeshGeometryChanged::mutable_meshname() {
  
  // @@protoc_insertion_point(field_mutable:atom.proto.meshes.MeshGeometryChanged.MeshName)
  return meshname_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 ::std::string* MeshGeometryChanged::release_meshname() {
  
  return meshname_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void MeshGeometryChanged::set_allocated_meshname(::std::string* meshname) {
  if (meshname != NULL) {
    
  } else {
    
  }
  meshname_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), meshname);
  // @@protoc_insertion_point(field_set_allocated:atom.proto.meshes.MeshGeometryChanged.MeshName)
}

// repeated .atom.proto.Vertex Vertices = 2;
int MeshGeometryChanged::vertices_size() const {
  return vertices_.size();
}
void MeshGeometryChanged::clear_vertices() {
  vertices_.Clear();
}
const ::atom::proto::Vertex& MeshGeometryChanged::vertices(int index) const {
  // @@protoc_insertion_point(field_get:atom.proto.meshes.MeshGeometryChanged.Vertices)
  return vertices_.Get(index);
}
::atom::proto::Vertex* MeshGeometryChanged::mutable_vertices(int index) {
  // @@protoc_insertion_point(field_mutable:atom.proto.meshes.MeshGeometryChanged.Vertices)
  return vertices_.Mutable(index);
}
::atom::proto::Vertex* MeshGeometryChanged::add_vertices() {
  // @@protoc_insertion_point(field_add:atom.proto.meshes.MeshGeometryChanged.Vertices)
  return vertices_.Add();
}
::google::protobuf::RepeatedPtrField< ::atom::proto::Vertex >*
MeshGeometryChanged::mutable_vertices() {
  // @@protoc_insertion_point(field_mutable_list:atom.proto.meshes.MeshGeometryChanged.Vertices)
  return &vertices_;
}
const ::google::protobuf::RepeatedPtrField< ::atom::proto::Vertex >&
MeshGeometryChanged::vertices() const {
  // @@protoc_insertion_point(field_list:atom.proto.meshes.MeshGeometryChanged.Vertices)
  return vertices_;
}

// repeated int32 Indices = 3 [packed = true];
int MeshGeometryChanged::indices_size() const {
  return indices_.size();
}
void MeshGeometryChanged::clear_indices() {
  indices_.Clear();
}
 ::google::protobuf::int32 MeshGeometryChanged::indices(int index) const {
  // @@protoc_insertion_point(field_get:atom.proto.meshes.MeshGeometryChanged.Indices)
  return indices_.Get(index);
}
 void MeshGeometryChanged::set_indices(int index, ::google::protobuf::int32 value) {
  indices_.Set(index, value);
  // @@protoc_insertion_point(field_set:atom.proto.meshes.MeshGeometryChanged.Indices)
}
 void MeshGeometryChanged::add_indices(::google::protobuf::int32 value) {
  indices_.Add(value);
  // @@protoc_insertion_point(field_add:atom.proto.meshes.MeshGeometryChanged.Indices)
}
 const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
MeshGeometryChanged::indices() const {
  // @@protoc_insertion_point(field_list:atom.proto.meshes.MeshGeometryChanged.Indices)
  return indices_;
}
 ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
MeshGeometryChanged::mutable_indices() {
  // @@protoc_insertion_point(field_mutable_list:atom.proto.meshes.MeshGeometryChanged.Indices)
  return &indices_;
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace meshes
}  // namespace proto
}  // namespace atom

// @@protoc_insertion_point(global_scope)