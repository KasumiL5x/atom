// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: materials/Texture.proto

#ifndef PROTOBUF_materials_2fTexture_2eproto__INCLUDED
#define PROTOBUF_materials_2fTexture_2eproto__INCLUDED

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
#include "materials/TextureData.pb.h"
#include "Vector2.pb.h"
// @@protoc_insertion_point(includes)

namespace atom {
namespace proto {
namespace materials {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_materials_2fTexture_2eproto();
void protobuf_AssignDesc_materials_2fTexture_2eproto();
void protobuf_ShutdownFile_materials_2fTexture_2eproto();

class Texture;

// ===================================================================

class Texture : public ::google::protobuf::Message {
 public:
  Texture();
  virtual ~Texture();

  Texture(const Texture& from);

  inline Texture& operator=(const Texture& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Texture& default_instance();

  void Swap(Texture* other);

  // implements Message ----------------------------------------------

  inline Texture* New() const { return New(NULL); }

  Texture* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Texture& from);
  void MergeFrom(const Texture& from);
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
  void InternalSwap(Texture* other);
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

  // optional string TextureName = 1;
  void clear_texturename();
  static const int kTextureNameFieldNumber = 1;
  const ::std::string& texturename() const;
  void set_texturename(const ::std::string& value);
  void set_texturename(const char* value);
  void set_texturename(const char* value, size_t size);
  ::std::string* mutable_texturename();
  ::std::string* release_texturename();
  void set_allocated_texturename(::std::string* texturename);

  // optional .atom.proto.materials.TextureData Data = 2;
  bool has_data() const;
  void clear_data();
  static const int kDataFieldNumber = 2;
  const ::atom::proto::materials::TextureData& data() const;
  ::atom::proto::materials::TextureData* mutable_data();
  ::atom::proto::materials::TextureData* release_data();
  void set_allocated_data(::atom::proto::materials::TextureData* data);

  // optional .atom.proto.Vector2 TranslateFrame = 3;
  bool has_translateframe() const;
  void clear_translateframe();
  static const int kTranslateFrameFieldNumber = 3;
  const ::atom::proto::Vector2& translateframe() const;
  ::atom::proto::Vector2* mutable_translateframe();
  ::atom::proto::Vector2* release_translateframe();
  void set_allocated_translateframe(::atom::proto::Vector2* translateframe);

  // optional float RotateFrame = 4;
  void clear_rotateframe();
  static const int kRotateFrameFieldNumber = 4;
  float rotateframe() const;
  void set_rotateframe(float value);

  // optional bool MirrorU = 5;
  void clear_mirroru();
  static const int kMirrorUFieldNumber = 5;
  bool mirroru() const;
  void set_mirroru(bool value);

  // optional bool MirrorV = 6;
  void clear_mirrorv();
  static const int kMirrorVFieldNumber = 6;
  bool mirrorv() const;
  void set_mirrorv(bool value);

  // optional bool WrapU = 7;
  void clear_wrapu();
  static const int kWrapUFieldNumber = 7;
  bool wrapu() const;
  void set_wrapu(bool value);

  // optional bool wrapV = 8;
  void clear_wrapv();
  static const int kWrapVFieldNumber = 8;
  bool wrapv() const;
  void set_wrapv(bool value);

  // optional .atom.proto.Vector2 Repeat = 9;
  bool has_repeat() const;
  void clear_repeat();
  static const int kRepeatFieldNumber = 9;
  const ::atom::proto::Vector2& repeat() const;
  ::atom::proto::Vector2* mutable_repeat();
  ::atom::proto::Vector2* release_repeat();
  void set_allocated_repeat(::atom::proto::Vector2* repeat);

  // optional .atom.proto.Vector2 Offset = 10;
  bool has_offset() const;
  void clear_offset();
  static const int kOffsetFieldNumber = 10;
  const ::atom::proto::Vector2& offset() const;
  ::atom::proto::Vector2* mutable_offset();
  ::atom::proto::Vector2* release_offset();
  void set_allocated_offset(::atom::proto::Vector2* offset);

  // optional float Rotate = 11;
  void clear_rotate();
  static const int kRotateFieldNumber = 11;
  float rotate() const;
  void set_rotate(float value);

  // optional .atom.proto.Vector2 Noise = 12;
  bool has_noise() const;
  void clear_noise();
  static const int kNoiseFieldNumber = 12;
  const ::atom::proto::Vector2& noise() const;
  ::atom::proto::Vector2* mutable_noise();
  ::atom::proto::Vector2* release_noise();
  void set_allocated_noise(::atom::proto::Vector2* noise);

  // @@protoc_insertion_point(class_scope:atom.proto.materials.Texture)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::internal::ArenaStringPtr texturename_;
  ::atom::proto::materials::TextureData* data_;
  ::atom::proto::Vector2* translateframe_;
  float rotateframe_;
  bool mirroru_;
  bool mirrorv_;
  bool wrapu_;
  bool wrapv_;
  ::atom::proto::Vector2* repeat_;
  ::atom::proto::Vector2* offset_;
  ::atom::proto::Vector2* noise_;
  float rotate_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_materials_2fTexture_2eproto();
  friend void protobuf_AssignDesc_materials_2fTexture_2eproto();
  friend void protobuf_ShutdownFile_materials_2fTexture_2eproto();

  void InitAsDefaultInstance();
  static Texture* default_instance_;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// Texture

// optional string TextureName = 1;
inline void Texture::clear_texturename() {
  texturename_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Texture::texturename() const {
  // @@protoc_insertion_point(field_get:atom.proto.materials.Texture.TextureName)
  return texturename_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Texture::set_texturename(const ::std::string& value) {
  
  texturename_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:atom.proto.materials.Texture.TextureName)
}
inline void Texture::set_texturename(const char* value) {
  
  texturename_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:atom.proto.materials.Texture.TextureName)
}
inline void Texture::set_texturename(const char* value, size_t size) {
  
  texturename_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:atom.proto.materials.Texture.TextureName)
}
inline ::std::string* Texture::mutable_texturename() {
  
  // @@protoc_insertion_point(field_mutable:atom.proto.materials.Texture.TextureName)
  return texturename_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Texture::release_texturename() {
  
  return texturename_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Texture::set_allocated_texturename(::std::string* texturename) {
  if (texturename != NULL) {
    
  } else {
    
  }
  texturename_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), texturename);
  // @@protoc_insertion_point(field_set_allocated:atom.proto.materials.Texture.TextureName)
}

// optional .atom.proto.materials.TextureData Data = 2;
inline bool Texture::has_data() const {
  return !_is_default_instance_ && data_ != NULL;
}
inline void Texture::clear_data() {
  if (GetArenaNoVirtual() == NULL && data_ != NULL) delete data_;
  data_ = NULL;
}
inline const ::atom::proto::materials::TextureData& Texture::data() const {
  // @@protoc_insertion_point(field_get:atom.proto.materials.Texture.Data)
  return data_ != NULL ? *data_ : *default_instance_->data_;
}
inline ::atom::proto::materials::TextureData* Texture::mutable_data() {
  
  if (data_ == NULL) {
    data_ = new ::atom::proto::materials::TextureData;
  }
  // @@protoc_insertion_point(field_mutable:atom.proto.materials.Texture.Data)
  return data_;
}
inline ::atom::proto::materials::TextureData* Texture::release_data() {
  
  ::atom::proto::materials::TextureData* temp = data_;
  data_ = NULL;
  return temp;
}
inline void Texture::set_allocated_data(::atom::proto::materials::TextureData* data) {
  delete data_;
  data_ = data;
  if (data) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:atom.proto.materials.Texture.Data)
}

// optional .atom.proto.Vector2 TranslateFrame = 3;
inline bool Texture::has_translateframe() const {
  return !_is_default_instance_ && translateframe_ != NULL;
}
inline void Texture::clear_translateframe() {
  if (GetArenaNoVirtual() == NULL && translateframe_ != NULL) delete translateframe_;
  translateframe_ = NULL;
}
inline const ::atom::proto::Vector2& Texture::translateframe() const {
  // @@protoc_insertion_point(field_get:atom.proto.materials.Texture.TranslateFrame)
  return translateframe_ != NULL ? *translateframe_ : *default_instance_->translateframe_;
}
inline ::atom::proto::Vector2* Texture::mutable_translateframe() {
  
  if (translateframe_ == NULL) {
    translateframe_ = new ::atom::proto::Vector2;
  }
  // @@protoc_insertion_point(field_mutable:atom.proto.materials.Texture.TranslateFrame)
  return translateframe_;
}
inline ::atom::proto::Vector2* Texture::release_translateframe() {
  
  ::atom::proto::Vector2* temp = translateframe_;
  translateframe_ = NULL;
  return temp;
}
inline void Texture::set_allocated_translateframe(::atom::proto::Vector2* translateframe) {
  delete translateframe_;
  translateframe_ = translateframe;
  if (translateframe) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:atom.proto.materials.Texture.TranslateFrame)
}

// optional float RotateFrame = 4;
inline void Texture::clear_rotateframe() {
  rotateframe_ = 0;
}
inline float Texture::rotateframe() const {
  // @@protoc_insertion_point(field_get:atom.proto.materials.Texture.RotateFrame)
  return rotateframe_;
}
inline void Texture::set_rotateframe(float value) {
  
  rotateframe_ = value;
  // @@protoc_insertion_point(field_set:atom.proto.materials.Texture.RotateFrame)
}

// optional bool MirrorU = 5;
inline void Texture::clear_mirroru() {
  mirroru_ = false;
}
inline bool Texture::mirroru() const {
  // @@protoc_insertion_point(field_get:atom.proto.materials.Texture.MirrorU)
  return mirroru_;
}
inline void Texture::set_mirroru(bool value) {
  
  mirroru_ = value;
  // @@protoc_insertion_point(field_set:atom.proto.materials.Texture.MirrorU)
}

// optional bool MirrorV = 6;
inline void Texture::clear_mirrorv() {
  mirrorv_ = false;
}
inline bool Texture::mirrorv() const {
  // @@protoc_insertion_point(field_get:atom.proto.materials.Texture.MirrorV)
  return mirrorv_;
}
inline void Texture::set_mirrorv(bool value) {
  
  mirrorv_ = value;
  // @@protoc_insertion_point(field_set:atom.proto.materials.Texture.MirrorV)
}

// optional bool WrapU = 7;
inline void Texture::clear_wrapu() {
  wrapu_ = false;
}
inline bool Texture::wrapu() const {
  // @@protoc_insertion_point(field_get:atom.proto.materials.Texture.WrapU)
  return wrapu_;
}
inline void Texture::set_wrapu(bool value) {
  
  wrapu_ = value;
  // @@protoc_insertion_point(field_set:atom.proto.materials.Texture.WrapU)
}

// optional bool wrapV = 8;
inline void Texture::clear_wrapv() {
  wrapv_ = false;
}
inline bool Texture::wrapv() const {
  // @@protoc_insertion_point(field_get:atom.proto.materials.Texture.wrapV)
  return wrapv_;
}
inline void Texture::set_wrapv(bool value) {
  
  wrapv_ = value;
  // @@protoc_insertion_point(field_set:atom.proto.materials.Texture.wrapV)
}

// optional .atom.proto.Vector2 Repeat = 9;
inline bool Texture::has_repeat() const {
  return !_is_default_instance_ && repeat_ != NULL;
}
inline void Texture::clear_repeat() {
  if (GetArenaNoVirtual() == NULL && repeat_ != NULL) delete repeat_;
  repeat_ = NULL;
}
inline const ::atom::proto::Vector2& Texture::repeat() const {
  // @@protoc_insertion_point(field_get:atom.proto.materials.Texture.Repeat)
  return repeat_ != NULL ? *repeat_ : *default_instance_->repeat_;
}
inline ::atom::proto::Vector2* Texture::mutable_repeat() {
  
  if (repeat_ == NULL) {
    repeat_ = new ::atom::proto::Vector2;
  }
  // @@protoc_insertion_point(field_mutable:atom.proto.materials.Texture.Repeat)
  return repeat_;
}
inline ::atom::proto::Vector2* Texture::release_repeat() {
  
  ::atom::proto::Vector2* temp = repeat_;
  repeat_ = NULL;
  return temp;
}
inline void Texture::set_allocated_repeat(::atom::proto::Vector2* repeat) {
  delete repeat_;
  repeat_ = repeat;
  if (repeat) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:atom.proto.materials.Texture.Repeat)
}

// optional .atom.proto.Vector2 Offset = 10;
inline bool Texture::has_offset() const {
  return !_is_default_instance_ && offset_ != NULL;
}
inline void Texture::clear_offset() {
  if (GetArenaNoVirtual() == NULL && offset_ != NULL) delete offset_;
  offset_ = NULL;
}
inline const ::atom::proto::Vector2& Texture::offset() const {
  // @@protoc_insertion_point(field_get:atom.proto.materials.Texture.Offset)
  return offset_ != NULL ? *offset_ : *default_instance_->offset_;
}
inline ::atom::proto::Vector2* Texture::mutable_offset() {
  
  if (offset_ == NULL) {
    offset_ = new ::atom::proto::Vector2;
  }
  // @@protoc_insertion_point(field_mutable:atom.proto.materials.Texture.Offset)
  return offset_;
}
inline ::atom::proto::Vector2* Texture::release_offset() {
  
  ::atom::proto::Vector2* temp = offset_;
  offset_ = NULL;
  return temp;
}
inline void Texture::set_allocated_offset(::atom::proto::Vector2* offset) {
  delete offset_;
  offset_ = offset;
  if (offset) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:atom.proto.materials.Texture.Offset)
}

// optional float Rotate = 11;
inline void Texture::clear_rotate() {
  rotate_ = 0;
}
inline float Texture::rotate() const {
  // @@protoc_insertion_point(field_get:atom.proto.materials.Texture.Rotate)
  return rotate_;
}
inline void Texture::set_rotate(float value) {
  
  rotate_ = value;
  // @@protoc_insertion_point(field_set:atom.proto.materials.Texture.Rotate)
}

// optional .atom.proto.Vector2 Noise = 12;
inline bool Texture::has_noise() const {
  return !_is_default_instance_ && noise_ != NULL;
}
inline void Texture::clear_noise() {
  if (GetArenaNoVirtual() == NULL && noise_ != NULL) delete noise_;
  noise_ = NULL;
}
inline const ::atom::proto::Vector2& Texture::noise() const {
  // @@protoc_insertion_point(field_get:atom.proto.materials.Texture.Noise)
  return noise_ != NULL ? *noise_ : *default_instance_->noise_;
}
inline ::atom::proto::Vector2* Texture::mutable_noise() {
  
  if (noise_ == NULL) {
    noise_ = new ::atom::proto::Vector2;
  }
  // @@protoc_insertion_point(field_mutable:atom.proto.materials.Texture.Noise)
  return noise_;
}
inline ::atom::proto::Vector2* Texture::release_noise() {
  
  ::atom::proto::Vector2* temp = noise_;
  noise_ = NULL;
  return temp;
}
inline void Texture::set_allocated_noise(::atom::proto::Vector2* noise) {
  delete noise_;
  noise_ = noise;
  if (noise) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:atom.proto.materials.Texture.Noise)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace materials
}  // namespace proto
}  // namespace atom

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_materials_2fTexture_2eproto__INCLUDED
