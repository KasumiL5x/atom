// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Vertex.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "Vertex.pb.h"

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

const ::google::protobuf::Descriptor* Vertex_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Vertex_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_Vertex_2eproto() {
  protobuf_AddDesc_Vertex_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "Vertex.proto");
  GOOGLE_CHECK(file != NULL);
  Vertex_descriptor_ = file->message_type(0);
  static const int Vertex_offsets_[7] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Vertex, index_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Vertex, position_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Vertex, normal_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Vertex, texcoord_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Vertex, tangent_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Vertex, binormal_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Vertex, color_),
  };
  Vertex_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      Vertex_descriptor_,
      Vertex::default_instance_,
      Vertex_offsets_,
      -1,
      -1,
      -1,
      sizeof(Vertex),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Vertex, _internal_metadata_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Vertex, _is_default_instance_));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_Vertex_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      Vertex_descriptor_, &Vertex::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_Vertex_2eproto() {
  delete Vertex::default_instance_;
  delete Vertex_reflection_;
}

void protobuf_AddDesc_Vertex_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::atom::proto::protobuf_AddDesc_Vector2_2eproto();
  ::atom::proto::protobuf_AddDesc_Vector3_2eproto();
  ::atom::proto::protobuf_AddDesc_Color_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\014Vertex.proto\022\natom.proto\032\rVector2.prot"
    "o\032\rVector3.proto\032\013Color.proto\"\371\001\n\006Vertex"
    "\022\r\n\005Index\030\001 \001(\005\022%\n\010Position\030\002 \001(\0132\023.atom"
    ".proto.Vector3\022#\n\006Normal\030\003 \001(\0132\023.atom.pr"
    "oto.Vector3\022%\n\010Texcoord\030\004 \003(\0132\023.atom.pro"
    "to.Vector2\022$\n\007Tangent\030\005 \003(\0132\023.atom.proto"
    ".Vector3\022%\n\010Binormal\030\006 \003(\0132\023.atom.proto."
    "Vector3\022 \n\005Color\030\007 \003(\0132\021.atom.proto.Colo"
    "rb\006proto3", 329);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "Vertex.proto", &protobuf_RegisterTypes);
  Vertex::default_instance_ = new Vertex();
  Vertex::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_Vertex_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_Vertex_2eproto {
  StaticDescriptorInitializer_Vertex_2eproto() {
    protobuf_AddDesc_Vertex_2eproto();
  }
} static_descriptor_initializer_Vertex_2eproto_;

namespace {

static void MergeFromFail(int line) GOOGLE_ATTRIBUTE_COLD;
static void MergeFromFail(int line) {
  GOOGLE_CHECK(false) << __FILE__ << ":" << line;
}

}  // namespace


// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int Vertex::kIndexFieldNumber;
const int Vertex::kPositionFieldNumber;
const int Vertex::kNormalFieldNumber;
const int Vertex::kTexcoordFieldNumber;
const int Vertex::kTangentFieldNumber;
const int Vertex::kBinormalFieldNumber;
const int Vertex::kColorFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

Vertex::Vertex()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:atom.proto.Vertex)
}

void Vertex::InitAsDefaultInstance() {
  _is_default_instance_ = true;
  position_ = const_cast< ::atom::proto::Vector3*>(&::atom::proto::Vector3::default_instance());
  normal_ = const_cast< ::atom::proto::Vector3*>(&::atom::proto::Vector3::default_instance());
}

Vertex::Vertex(const Vertex& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:atom.proto.Vertex)
}

void Vertex::SharedCtor() {
    _is_default_instance_ = false;
  _cached_size_ = 0;
  index_ = 0;
  position_ = NULL;
  normal_ = NULL;
}

Vertex::~Vertex() {
  // @@protoc_insertion_point(destructor:atom.proto.Vertex)
  SharedDtor();
}

void Vertex::SharedDtor() {
  if (this != default_instance_) {
    delete position_;
    delete normal_;
  }
}

void Vertex::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Vertex::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Vertex_descriptor_;
}

const Vertex& Vertex::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_Vertex_2eproto();
  return *default_instance_;
}

Vertex* Vertex::default_instance_ = NULL;

Vertex* Vertex::New(::google::protobuf::Arena* arena) const {
  Vertex* n = new Vertex;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void Vertex::Clear() {
  index_ = 0;
  if (GetArenaNoVirtual() == NULL && position_ != NULL) delete position_;
  position_ = NULL;
  if (GetArenaNoVirtual() == NULL && normal_ != NULL) delete normal_;
  normal_ = NULL;
  texcoord_.Clear();
  tangent_.Clear();
  binormal_.Clear();
  color_.Clear();
}

bool Vertex::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:atom.proto.Vertex)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int32 Index = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &index_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_Position;
        break;
      }

      // optional .atom.proto.Vector3 Position = 2;
      case 2: {
        if (tag == 18) {
         parse_Position:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_position()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_Normal;
        break;
      }

      // optional .atom.proto.Vector3 Normal = 3;
      case 3: {
        if (tag == 26) {
         parse_Normal:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_normal()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(34)) goto parse_Texcoord;
        break;
      }

      // repeated .atom.proto.Vector2 Texcoord = 4;
      case 4: {
        if (tag == 34) {
         parse_Texcoord:
          DO_(input->IncrementRecursionDepth());
         parse_loop_Texcoord:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtualNoRecursionDepth(
                input, add_texcoord()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(34)) goto parse_loop_Texcoord;
        if (input->ExpectTag(42)) goto parse_loop_Tangent;
        input->UnsafeDecrementRecursionDepth();
        break;
      }

      // repeated .atom.proto.Vector3 Tangent = 5;
      case 5: {
        if (tag == 42) {
          DO_(input->IncrementRecursionDepth());
         parse_loop_Tangent:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtualNoRecursionDepth(
                input, add_tangent()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(42)) goto parse_loop_Tangent;
        if (input->ExpectTag(50)) goto parse_loop_Binormal;
        input->UnsafeDecrementRecursionDepth();
        break;
      }

      // repeated .atom.proto.Vector3 Binormal = 6;
      case 6: {
        if (tag == 50) {
          DO_(input->IncrementRecursionDepth());
         parse_loop_Binormal:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtualNoRecursionDepth(
                input, add_binormal()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(50)) goto parse_loop_Binormal;
        if (input->ExpectTag(58)) goto parse_loop_Color;
        input->UnsafeDecrementRecursionDepth();
        break;
      }

      // repeated .atom.proto.Color Color = 7;
      case 7: {
        if (tag == 58) {
          DO_(input->IncrementRecursionDepth());
         parse_loop_Color:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtualNoRecursionDepth(
                input, add_color()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(58)) goto parse_loop_Color;
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
  // @@protoc_insertion_point(parse_success:atom.proto.Vertex)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:atom.proto.Vertex)
  return false;
#undef DO_
}

void Vertex::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:atom.proto.Vertex)
  // optional int32 Index = 1;
  if (this->index() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->index(), output);
  }

  // optional .atom.proto.Vector3 Position = 2;
  if (this->has_position()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, *this->position_, output);
  }

  // optional .atom.proto.Vector3 Normal = 3;
  if (this->has_normal()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      3, *this->normal_, output);
  }

  // repeated .atom.proto.Vector2 Texcoord = 4;
  for (unsigned int i = 0, n = this->texcoord_size(); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      4, this->texcoord(i), output);
  }

  // repeated .atom.proto.Vector3 Tangent = 5;
  for (unsigned int i = 0, n = this->tangent_size(); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      5, this->tangent(i), output);
  }

  // repeated .atom.proto.Vector3 Binormal = 6;
  for (unsigned int i = 0, n = this->binormal_size(); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      6, this->binormal(i), output);
  }

  // repeated .atom.proto.Color Color = 7;
  for (unsigned int i = 0, n = this->color_size(); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      7, this->color(i), output);
  }

  // @@protoc_insertion_point(serialize_end:atom.proto.Vertex)
}

::google::protobuf::uint8* Vertex::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:atom.proto.Vertex)
  // optional int32 Index = 1;
  if (this->index() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->index(), target);
  }

  // optional .atom.proto.Vector3 Position = 2;
  if (this->has_position()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, *this->position_, target);
  }

  // optional .atom.proto.Vector3 Normal = 3;
  if (this->has_normal()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        3, *this->normal_, target);
  }

  // repeated .atom.proto.Vector2 Texcoord = 4;
  for (unsigned int i = 0, n = this->texcoord_size(); i < n; i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        4, this->texcoord(i), target);
  }

  // repeated .atom.proto.Vector3 Tangent = 5;
  for (unsigned int i = 0, n = this->tangent_size(); i < n; i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        5, this->tangent(i), target);
  }

  // repeated .atom.proto.Vector3 Binormal = 6;
  for (unsigned int i = 0, n = this->binormal_size(); i < n; i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        6, this->binormal(i), target);
  }

  // repeated .atom.proto.Color Color = 7;
  for (unsigned int i = 0, n = this->color_size(); i < n; i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        7, this->color(i), target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:atom.proto.Vertex)
  return target;
}

int Vertex::ByteSize() const {
  int total_size = 0;

  // optional int32 Index = 1;
  if (this->index() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->index());
  }

  // optional .atom.proto.Vector3 Position = 2;
  if (this->has_position()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        *this->position_);
  }

  // optional .atom.proto.Vector3 Normal = 3;
  if (this->has_normal()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        *this->normal_);
  }

  // repeated .atom.proto.Vector2 Texcoord = 4;
  total_size += 1 * this->texcoord_size();
  for (int i = 0; i < this->texcoord_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->texcoord(i));
  }

  // repeated .atom.proto.Vector3 Tangent = 5;
  total_size += 1 * this->tangent_size();
  for (int i = 0; i < this->tangent_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->tangent(i));
  }

  // repeated .atom.proto.Vector3 Binormal = 6;
  total_size += 1 * this->binormal_size();
  for (int i = 0; i < this->binormal_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->binormal(i));
  }

  // repeated .atom.proto.Color Color = 7;
  total_size += 1 * this->color_size();
  for (int i = 0; i < this->color_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->color(i));
  }

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Vertex::MergeFrom(const ::google::protobuf::Message& from) {
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  const Vertex* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const Vertex>(
          &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Vertex::MergeFrom(const Vertex& from) {
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  texcoord_.MergeFrom(from.texcoord_);
  tangent_.MergeFrom(from.tangent_);
  binormal_.MergeFrom(from.binormal_);
  color_.MergeFrom(from.color_);
  if (from.index() != 0) {
    set_index(from.index());
  }
  if (from.has_position()) {
    mutable_position()->::atom::proto::Vector3::MergeFrom(from.position());
  }
  if (from.has_normal()) {
    mutable_normal()->::atom::proto::Vector3::MergeFrom(from.normal());
  }
}

void Vertex::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Vertex::CopyFrom(const Vertex& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Vertex::IsInitialized() const {

  return true;
}

void Vertex::Swap(Vertex* other) {
  if (other == this) return;
  InternalSwap(other);
}
void Vertex::InternalSwap(Vertex* other) {
  std::swap(index_, other->index_);
  std::swap(position_, other->position_);
  std::swap(normal_, other->normal_);
  texcoord_.UnsafeArenaSwap(&other->texcoord_);
  tangent_.UnsafeArenaSwap(&other->tangent_);
  binormal_.UnsafeArenaSwap(&other->binormal_);
  color_.UnsafeArenaSwap(&other->color_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata Vertex::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Vertex_descriptor_;
  metadata.reflection = Vertex_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// Vertex

// optional int32 Index = 1;
void Vertex::clear_index() {
  index_ = 0;
}
 ::google::protobuf::int32 Vertex::index() const {
  // @@protoc_insertion_point(field_get:atom.proto.Vertex.Index)
  return index_;
}
 void Vertex::set_index(::google::protobuf::int32 value) {
  
  index_ = value;
  // @@protoc_insertion_point(field_set:atom.proto.Vertex.Index)
}

// optional .atom.proto.Vector3 Position = 2;
bool Vertex::has_position() const {
  return !_is_default_instance_ && position_ != NULL;
}
void Vertex::clear_position() {
  if (GetArenaNoVirtual() == NULL && position_ != NULL) delete position_;
  position_ = NULL;
}
const ::atom::proto::Vector3& Vertex::position() const {
  // @@protoc_insertion_point(field_get:atom.proto.Vertex.Position)
  return position_ != NULL ? *position_ : *default_instance_->position_;
}
::atom::proto::Vector3* Vertex::mutable_position() {
  
  if (position_ == NULL) {
    position_ = new ::atom::proto::Vector3;
  }
  // @@protoc_insertion_point(field_mutable:atom.proto.Vertex.Position)
  return position_;
}
::atom::proto::Vector3* Vertex::release_position() {
  
  ::atom::proto::Vector3* temp = position_;
  position_ = NULL;
  return temp;
}
void Vertex::set_allocated_position(::atom::proto::Vector3* position) {
  delete position_;
  position_ = position;
  if (position) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:atom.proto.Vertex.Position)
}

// optional .atom.proto.Vector3 Normal = 3;
bool Vertex::has_normal() const {
  return !_is_default_instance_ && normal_ != NULL;
}
void Vertex::clear_normal() {
  if (GetArenaNoVirtual() == NULL && normal_ != NULL) delete normal_;
  normal_ = NULL;
}
const ::atom::proto::Vector3& Vertex::normal() const {
  // @@protoc_insertion_point(field_get:atom.proto.Vertex.Normal)
  return normal_ != NULL ? *normal_ : *default_instance_->normal_;
}
::atom::proto::Vector3* Vertex::mutable_normal() {
  
  if (normal_ == NULL) {
    normal_ = new ::atom::proto::Vector3;
  }
  // @@protoc_insertion_point(field_mutable:atom.proto.Vertex.Normal)
  return normal_;
}
::atom::proto::Vector3* Vertex::release_normal() {
  
  ::atom::proto::Vector3* temp = normal_;
  normal_ = NULL;
  return temp;
}
void Vertex::set_allocated_normal(::atom::proto::Vector3* normal) {
  delete normal_;
  normal_ = normal;
  if (normal) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:atom.proto.Vertex.Normal)
}

// repeated .atom.proto.Vector2 Texcoord = 4;
int Vertex::texcoord_size() const {
  return texcoord_.size();
}
void Vertex::clear_texcoord() {
  texcoord_.Clear();
}
const ::atom::proto::Vector2& Vertex::texcoord(int index) const {
  // @@protoc_insertion_point(field_get:atom.proto.Vertex.Texcoord)
  return texcoord_.Get(index);
}
::atom::proto::Vector2* Vertex::mutable_texcoord(int index) {
  // @@protoc_insertion_point(field_mutable:atom.proto.Vertex.Texcoord)
  return texcoord_.Mutable(index);
}
::atom::proto::Vector2* Vertex::add_texcoord() {
  // @@protoc_insertion_point(field_add:atom.proto.Vertex.Texcoord)
  return texcoord_.Add();
}
::google::protobuf::RepeatedPtrField< ::atom::proto::Vector2 >*
Vertex::mutable_texcoord() {
  // @@protoc_insertion_point(field_mutable_list:atom.proto.Vertex.Texcoord)
  return &texcoord_;
}
const ::google::protobuf::RepeatedPtrField< ::atom::proto::Vector2 >&
Vertex::texcoord() const {
  // @@protoc_insertion_point(field_list:atom.proto.Vertex.Texcoord)
  return texcoord_;
}

// repeated .atom.proto.Vector3 Tangent = 5;
int Vertex::tangent_size() const {
  return tangent_.size();
}
void Vertex::clear_tangent() {
  tangent_.Clear();
}
const ::atom::proto::Vector3& Vertex::tangent(int index) const {
  // @@protoc_insertion_point(field_get:atom.proto.Vertex.Tangent)
  return tangent_.Get(index);
}
::atom::proto::Vector3* Vertex::mutable_tangent(int index) {
  // @@protoc_insertion_point(field_mutable:atom.proto.Vertex.Tangent)
  return tangent_.Mutable(index);
}
::atom::proto::Vector3* Vertex::add_tangent() {
  // @@protoc_insertion_point(field_add:atom.proto.Vertex.Tangent)
  return tangent_.Add();
}
::google::protobuf::RepeatedPtrField< ::atom::proto::Vector3 >*
Vertex::mutable_tangent() {
  // @@protoc_insertion_point(field_mutable_list:atom.proto.Vertex.Tangent)
  return &tangent_;
}
const ::google::protobuf::RepeatedPtrField< ::atom::proto::Vector3 >&
Vertex::tangent() const {
  // @@protoc_insertion_point(field_list:atom.proto.Vertex.Tangent)
  return tangent_;
}

// repeated .atom.proto.Vector3 Binormal = 6;
int Vertex::binormal_size() const {
  return binormal_.size();
}
void Vertex::clear_binormal() {
  binormal_.Clear();
}
const ::atom::proto::Vector3& Vertex::binormal(int index) const {
  // @@protoc_insertion_point(field_get:atom.proto.Vertex.Binormal)
  return binormal_.Get(index);
}
::atom::proto::Vector3* Vertex::mutable_binormal(int index) {
  // @@protoc_insertion_point(field_mutable:atom.proto.Vertex.Binormal)
  return binormal_.Mutable(index);
}
::atom::proto::Vector3* Vertex::add_binormal() {
  // @@protoc_insertion_point(field_add:atom.proto.Vertex.Binormal)
  return binormal_.Add();
}
::google::protobuf::RepeatedPtrField< ::atom::proto::Vector3 >*
Vertex::mutable_binormal() {
  // @@protoc_insertion_point(field_mutable_list:atom.proto.Vertex.Binormal)
  return &binormal_;
}
const ::google::protobuf::RepeatedPtrField< ::atom::proto::Vector3 >&
Vertex::binormal() const {
  // @@protoc_insertion_point(field_list:atom.proto.Vertex.Binormal)
  return binormal_;
}

// repeated .atom.proto.Color Color = 7;
int Vertex::color_size() const {
  return color_.size();
}
void Vertex::clear_color() {
  color_.Clear();
}
const ::atom::proto::Color& Vertex::color(int index) const {
  // @@protoc_insertion_point(field_get:atom.proto.Vertex.Color)
  return color_.Get(index);
}
::atom::proto::Color* Vertex::mutable_color(int index) {
  // @@protoc_insertion_point(field_mutable:atom.proto.Vertex.Color)
  return color_.Mutable(index);
}
::atom::proto::Color* Vertex::add_color() {
  // @@protoc_insertion_point(field_add:atom.proto.Vertex.Color)
  return color_.Add();
}
::google::protobuf::RepeatedPtrField< ::atom::proto::Color >*
Vertex::mutable_color() {
  // @@protoc_insertion_point(field_mutable_list:atom.proto.Vertex.Color)
  return &color_;
}
const ::google::protobuf::RepeatedPtrField< ::atom::proto::Color >&
Vertex::color() const {
  // @@protoc_insertion_point(field_list:atom.proto.Vertex.Color)
  return color_;
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace proto
}  // namespace atom

// @@protoc_insertion_point(global_scope)