// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Annotation.proto

#ifndef PROTOBUF_Annotation_2eproto__INCLUDED
#define PROTOBUF_Annotation_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3000000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3000000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
#include "Matrix.pb.h"
// @@protoc_insertion_point(includes)

namespace atom {
namespace proto {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_Annotation_2eproto();
void protobuf_AssignDesc_Annotation_2eproto();
void protobuf_ShutdownFile_Annotation_2eproto();

class Annotation;

// ===================================================================

class Annotation : public ::google::protobuf::Message {
 public:
  Annotation();
  virtual ~Annotation();

  Annotation(const Annotation& from);

  inline Annotation& operator=(const Annotation& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Annotation& default_instance();

  void Swap(Annotation* other);

  // implements Message ----------------------------------------------

  inline Annotation* New() const { return New(NULL); }

  Annotation* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Annotation& from);
  void MergeFrom(const Annotation& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(Annotation* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional string Name = 1;
  void clear_name();
  static const int kNameFieldNumber = 1;
  const ::std::string& name() const;
  void set_name(const ::std::string& value);
  void set_name(const char* value);
  void set_name(const char* value, size_t size);
  ::std::string* mutable_name();
  ::std::string* release_name();
  void set_allocated_name(::std::string* name);

  // optional string Text = 2;
  void clear_text();
  static const int kTextFieldNumber = 2;
  const ::std::string& text() const;
  void set_text(const ::std::string& value);
  void set_text(const char* value);
  void set_text(const char* value, size_t size);
  ::std::string* mutable_text();
  ::std::string* release_text();
  void set_allocated_text(::std::string* text);

  // optional .atom.proto.Matrix World = 3;
  bool has_world() const;
  void clear_world();
  static const int kWorldFieldNumber = 3;
  const ::atom::proto::Matrix& world() const;
  ::atom::proto::Matrix* mutable_world();
  ::atom::proto::Matrix* release_world();
  void set_allocated_world(::atom::proto::Matrix* world);

  // optional bool InitialVisibility = 4;
  void clear_initialvisibility();
  static const int kInitialVisibilityFieldNumber = 4;
  bool initialvisibility() const;
  void set_initialvisibility(bool value);

  // @@protoc_insertion_point(class_scope:atom.proto.Annotation)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::internal::ArenaStringPtr name_;
  ::google::protobuf::internal::ArenaStringPtr text_;
  ::atom::proto::Matrix* world_;
  bool initialvisibility_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_Annotation_2eproto();
  friend void protobuf_AssignDesc_Annotation_2eproto();
  friend void protobuf_ShutdownFile_Annotation_2eproto();

  void InitAsDefaultInstance();
  static Annotation* default_instance_;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// Annotation

// optional string Name = 1;
inline void Annotation::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Annotation::name() const {
  // @@protoc_insertion_point(field_get:atom.proto.Annotation.Name)
  return name_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Annotation::set_name(const ::std::string& value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:atom.proto.Annotation.Name)
}
inline void Annotation::set_name(const char* value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:atom.proto.Annotation.Name)
}
inline void Annotation::set_name(const char* value, size_t size) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:atom.proto.Annotation.Name)
}
inline ::std::string* Annotation::mutable_name() {
  
  // @@protoc_insertion_point(field_mutable:atom.proto.Annotation.Name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Annotation::release_name() {
  
  return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Annotation::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    
  } else {
    
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:atom.proto.Annotation.Name)
}

// optional string Text = 2;
inline void Annotation::clear_text() {
  text_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Annotation::text() const {
  // @@protoc_insertion_point(field_get:atom.proto.Annotation.Text)
  return text_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Annotation::set_text(const ::std::string& value) {
  
  text_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:atom.proto.Annotation.Text)
}
inline void Annotation::set_text(const char* value) {
  
  text_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:atom.proto.Annotation.Text)
}
inline void Annotation::set_text(const char* value, size_t size) {
  
  text_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:atom.proto.Annotation.Text)
}
inline ::std::string* Annotation::mutable_text() {
  
  // @@protoc_insertion_point(field_mutable:atom.proto.Annotation.Text)
  return text_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Annotation::release_text() {
  
  return text_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Annotation::set_allocated_text(::std::string* text) {
  if (text != NULL) {
    
  } else {
    
  }
  text_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), text);
  // @@protoc_insertion_point(field_set_allocated:atom.proto.Annotation.Text)
}

// optional .atom.proto.Matrix World = 3;
inline bool Annotation::has_world() const {
  return !_is_default_instance_ && world_ != NULL;
}
inline void Annotation::clear_world() {
  if (GetArenaNoVirtual() == NULL && world_ != NULL) delete world_;
  world_ = NULL;
}
inline const ::atom::proto::Matrix& Annotation::world() const {
  // @@protoc_insertion_point(field_get:atom.proto.Annotation.World)
  return world_ != NULL ? *world_ : *default_instance_->world_;
}
inline ::atom::proto::Matrix* Annotation::mutable_world() {
  
  if (world_ == NULL) {
    world_ = new ::atom::proto::Matrix;
  }
  // @@protoc_insertion_point(field_mutable:atom.proto.Annotation.World)
  return world_;
}
inline ::atom::proto::Matrix* Annotation::release_world() {
  
  ::atom::proto::Matrix* temp = world_;
  world_ = NULL;
  return temp;
}
inline void Annotation::set_allocated_world(::atom::proto::Matrix* world) {
  delete world_;
  world_ = world;
  if (world) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:atom.proto.Annotation.World)
}

// optional bool InitialVisibility = 4;
inline void Annotation::clear_initialvisibility() {
  initialvisibility_ = false;
}
inline bool Annotation::initialvisibility() const {
  // @@protoc_insertion_point(field_get:atom.proto.Annotation.InitialVisibility)
  return initialvisibility_;
}
inline void Annotation::set_initialvisibility(bool value) {
  
  initialvisibility_ = value;
  // @@protoc_insertion_point(field_set:atom.proto.Annotation.InitialVisibility)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace proto
}  // namespace atom

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_Annotation_2eproto__INCLUDED
