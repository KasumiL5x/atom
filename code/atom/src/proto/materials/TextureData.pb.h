// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: materials/TextureData.proto

#ifndef PROTOBUF_materials_2fTextureData_2eproto__INCLUDED
#define PROTOBUF_materials_2fTextureData_2eproto__INCLUDED

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
// @@protoc_insertion_point(includes)

namespace atom {
namespace proto {
namespace materials {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_materials_2fTextureData_2eproto();
void protobuf_AssignDesc_materials_2fTextureData_2eproto();
void protobuf_ShutdownFile_materials_2fTextureData_2eproto();

class TextureData;

// ===================================================================

class TextureData : public ::google::protobuf::Message {
 public:
  TextureData();
  virtual ~TextureData();

  TextureData(const TextureData& from);

  inline TextureData& operator=(const TextureData& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const TextureData& default_instance();

  void Swap(TextureData* other);

  // implements Message ----------------------------------------------

  inline TextureData* New() const { return New(NULL); }

  TextureData* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const TextureData& from);
  void MergeFrom(const TextureData& from);
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
  void InternalSwap(TextureData* other);
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

  // optional string Filename = 1;
  void clear_filename();
  static const int kFilenameFieldNumber = 1;
  const ::std::string& filename() const;
  void set_filename(const ::std::string& value);
  void set_filename(const char* value);
  void set_filename(const char* value, size_t size);
  ::std::string* mutable_filename();
  ::std::string* release_filename();
  void set_allocated_filename(::std::string* filename);

  // optional string Extension = 2;
  void clear_extension();
  static const int kExtensionFieldNumber = 2;
  const ::std::string& extension() const;
  void set_extension(const ::std::string& value);
  void set_extension(const char* value);
  void set_extension(const char* value, size_t size);
  ::std::string* mutable_extension();
  ::std::string* release_extension();
  void set_allocated_extension(::std::string* extension);

  // optional bytes Bytes = 3;
  void clear_bytes();
  static const int kBytesFieldNumber = 3;
  const ::std::string& bytes() const;
  void set_bytes(const ::std::string& value);
  void set_bytes(const char* value);
  void set_bytes(const void* value, size_t size);
  ::std::string* mutable_bytes();
  ::std::string* release_bytes();
  void set_allocated_bytes(::std::string* bytes);

  // @@protoc_insertion_point(class_scope:atom.proto.materials.TextureData)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::internal::ArenaStringPtr filename_;
  ::google::protobuf::internal::ArenaStringPtr extension_;
  ::google::protobuf::internal::ArenaStringPtr bytes_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_materials_2fTextureData_2eproto();
  friend void protobuf_AssignDesc_materials_2fTextureData_2eproto();
  friend void protobuf_ShutdownFile_materials_2fTextureData_2eproto();

  void InitAsDefaultInstance();
  static TextureData* default_instance_;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// TextureData

// optional string Filename = 1;
inline void TextureData::clear_filename() {
  filename_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& TextureData::filename() const {
  // @@protoc_insertion_point(field_get:atom.proto.materials.TextureData.Filename)
  return filename_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void TextureData::set_filename(const ::std::string& value) {
  
  filename_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:atom.proto.materials.TextureData.Filename)
}
inline void TextureData::set_filename(const char* value) {
  
  filename_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:atom.proto.materials.TextureData.Filename)
}
inline void TextureData::set_filename(const char* value, size_t size) {
  
  filename_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:atom.proto.materials.TextureData.Filename)
}
inline ::std::string* TextureData::mutable_filename() {
  
  // @@protoc_insertion_point(field_mutable:atom.proto.materials.TextureData.Filename)
  return filename_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* TextureData::release_filename() {
  
  return filename_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void TextureData::set_allocated_filename(::std::string* filename) {
  if (filename != NULL) {
    
  } else {
    
  }
  filename_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), filename);
  // @@protoc_insertion_point(field_set_allocated:atom.proto.materials.TextureData.Filename)
}

// optional string Extension = 2;
inline void TextureData::clear_extension() {
  extension_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& TextureData::extension() const {
  // @@protoc_insertion_point(field_get:atom.proto.materials.TextureData.Extension)
  return extension_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void TextureData::set_extension(const ::std::string& value) {
  
  extension_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:atom.proto.materials.TextureData.Extension)
}
inline void TextureData::set_extension(const char* value) {
  
  extension_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:atom.proto.materials.TextureData.Extension)
}
inline void TextureData::set_extension(const char* value, size_t size) {
  
  extension_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:atom.proto.materials.TextureData.Extension)
}
inline ::std::string* TextureData::mutable_extension() {
  
  // @@protoc_insertion_point(field_mutable:atom.proto.materials.TextureData.Extension)
  return extension_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* TextureData::release_extension() {
  
  return extension_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void TextureData::set_allocated_extension(::std::string* extension) {
  if (extension != NULL) {
    
  } else {
    
  }
  extension_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), extension);
  // @@protoc_insertion_point(field_set_allocated:atom.proto.materials.TextureData.Extension)
}

// optional bytes Bytes = 3;
inline void TextureData::clear_bytes() {
  bytes_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& TextureData::bytes() const {
  // @@protoc_insertion_point(field_get:atom.proto.materials.TextureData.Bytes)
  return bytes_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void TextureData::set_bytes(const ::std::string& value) {
  
  bytes_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:atom.proto.materials.TextureData.Bytes)
}
inline void TextureData::set_bytes(const char* value) {
  
  bytes_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:atom.proto.materials.TextureData.Bytes)
}
inline void TextureData::set_bytes(const void* value, size_t size) {
  
  bytes_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:atom.proto.materials.TextureData.Bytes)
}
inline ::std::string* TextureData::mutable_bytes() {
  
  // @@protoc_insertion_point(field_mutable:atom.proto.materials.TextureData.Bytes)
  return bytes_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* TextureData::release_bytes() {
  
  return bytes_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void TextureData::set_allocated_bytes(::std::string* bytes) {
  if (bytes != NULL) {
    
  } else {
    
  }
  bytes_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), bytes);
  // @@protoc_insertion_point(field_set_allocated:atom.proto.materials.TextureData.Bytes)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace materials
}  // namespace proto
}  // namespace atom

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_materials_2fTextureData_2eproto__INCLUDED