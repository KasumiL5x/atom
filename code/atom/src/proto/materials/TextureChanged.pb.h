// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: materials/TextureChanged.proto

#ifndef PROTOBUF_materials_2fTextureChanged_2eproto__INCLUDED
#define PROTOBUF_materials_2fTextureChanged_2eproto__INCLUDED

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
void protobuf_AddDesc_materials_2fTextureChanged_2eproto();
void protobuf_AssignDesc_materials_2fTextureChanged_2eproto();
void protobuf_ShutdownFile_materials_2fTextureChanged_2eproto();

class TextureChanged;

// ===================================================================

class TextureChanged : public ::google::protobuf::Message {
 public:
  TextureChanged();
  virtual ~TextureChanged();

  TextureChanged(const TextureChanged& from);

  inline TextureChanged& operator=(const TextureChanged& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const TextureChanged& default_instance();

  enum PropertyCase {
    kData = 2,
    kTranslateFrame = 3,
    kRotateFrame = 4,
    kMirrorU = 5,
    kMirrorV = 6,
    kWrapU = 7,
    kWrapV = 8,
    kRepeat = 9,
    kOffset = 10,
    kRotate = 11,
    kNoise = 12,
    PROPERTY_NOT_SET = 0,
  };

  void Swap(TextureChanged* other);

  // implements Message ----------------------------------------------

  inline TextureChanged* New() const { return New(NULL); }

  TextureChanged* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const TextureChanged& from);
  void MergeFrom(const TextureChanged& from);
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
  void InternalSwap(TextureChanged* other);
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
  private:
  bool has_rotateframe() const;
  public:
  void clear_rotateframe();
  static const int kRotateFrameFieldNumber = 4;
  float rotateframe() const;
  void set_rotateframe(float value);

  // optional bool MirrorU = 5;
  private:
  bool has_mirroru() const;
  public:
  void clear_mirroru();
  static const int kMirrorUFieldNumber = 5;
  bool mirroru() const;
  void set_mirroru(bool value);

  // optional bool MirrorV = 6;
  private:
  bool has_mirrorv() const;
  public:
  void clear_mirrorv();
  static const int kMirrorVFieldNumber = 6;
  bool mirrorv() const;
  void set_mirrorv(bool value);

  // optional bool WrapU = 7;
  private:
  bool has_wrapu() const;
  public:
  void clear_wrapu();
  static const int kWrapUFieldNumber = 7;
  bool wrapu() const;
  void set_wrapu(bool value);

  // optional bool wrapV = 8;
  private:
  bool has_wrapv() const;
  public:
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
  private:
  bool has_rotate() const;
  public:
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

  PropertyCase Property_case() const;
  // @@protoc_insertion_point(class_scope:atom.proto.materials.TextureChanged)
 private:
  inline void set_has_data();
  inline void set_has_translateframe();
  inline void set_has_rotateframe();
  inline void set_has_mirroru();
  inline void set_has_mirrorv();
  inline void set_has_wrapu();
  inline void set_has_wrapv();
  inline void set_has_repeat();
  inline void set_has_offset();
  inline void set_has_rotate();
  inline void set_has_noise();

  inline bool has_Property() const;
  void clear_Property();
  inline void clear_has_Property();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::internal::ArenaStringPtr texturename_;
  union PropertyUnion {
    PropertyUnion() {}
    ::atom::proto::materials::TextureData* data_;
    ::atom::proto::Vector2* translateframe_;
    float rotateframe_;
    bool mirroru_;
    bool mirrorv_;
    bool wrapu_;
    bool wrapv_;
    ::atom::proto::Vector2* repeat_;
    ::atom::proto::Vector2* offset_;
    float rotate_;
    ::atom::proto::Vector2* noise_;
  } Property_;
  mutable int _cached_size_;
  ::google::protobuf::uint32 _oneof_case_[1];

  friend void  protobuf_AddDesc_materials_2fTextureChanged_2eproto();
  friend void protobuf_AssignDesc_materials_2fTextureChanged_2eproto();
  friend void protobuf_ShutdownFile_materials_2fTextureChanged_2eproto();

  void InitAsDefaultInstance();
  static TextureChanged* default_instance_;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// TextureChanged

// optional string TextureName = 1;
inline void TextureChanged::clear_texturename() {
  texturename_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& TextureChanged::texturename() const {
  // @@protoc_insertion_point(field_get:atom.proto.materials.TextureChanged.TextureName)
  return texturename_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void TextureChanged::set_texturename(const ::std::string& value) {
  
  texturename_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:atom.proto.materials.TextureChanged.TextureName)
}
inline void TextureChanged::set_texturename(const char* value) {
  
  texturename_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:atom.proto.materials.TextureChanged.TextureName)
}
inline void TextureChanged::set_texturename(const char* value, size_t size) {
  
  texturename_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:atom.proto.materials.TextureChanged.TextureName)
}
inline ::std::string* TextureChanged::mutable_texturename() {
  
  // @@protoc_insertion_point(field_mutable:atom.proto.materials.TextureChanged.TextureName)
  return texturename_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* TextureChanged::release_texturename() {
  
  return texturename_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void TextureChanged::set_allocated_texturename(::std::string* texturename) {
  if (texturename != NULL) {
    
  } else {
    
  }
  texturename_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), texturename);
  // @@protoc_insertion_point(field_set_allocated:atom.proto.materials.TextureChanged.TextureName)
}

// optional .atom.proto.materials.TextureData Data = 2;
inline bool TextureChanged::has_data() const {
  return Property_case() == kData;
}
inline void TextureChanged::set_has_data() {
  _oneof_case_[0] = kData;
}
inline void TextureChanged::clear_data() {
  if (has_data()) {
    delete Property_.data_;
    clear_has_Property();
  }
}
inline  const ::atom::proto::materials::TextureData& TextureChanged::data() const {
  // @@protoc_insertion_point(field_get:atom.proto.materials.TextureChanged.Data)
  return has_data()
      ? *Property_.data_
      : ::atom::proto::materials::TextureData::default_instance();
}
inline ::atom::proto::materials::TextureData* TextureChanged::mutable_data() {
  if (!has_data()) {
    clear_Property();
    set_has_data();
    Property_.data_ = new ::atom::proto::materials::TextureData;
  }
  // @@protoc_insertion_point(field_mutable:atom.proto.materials.TextureChanged.Data)
  return Property_.data_;
}
inline ::atom::proto::materials::TextureData* TextureChanged::release_data() {
  if (has_data()) {
    clear_has_Property();
    ::atom::proto::materials::TextureData* temp = Property_.data_;
    Property_.data_ = NULL;
    return temp;
  } else {
    return NULL;
  }
}
inline void TextureChanged::set_allocated_data(::atom::proto::materials::TextureData* data) {
  clear_Property();
  if (data) {
    set_has_data();
    Property_.data_ = data;
  }
  // @@protoc_insertion_point(field_set_allocated:atom.proto.materials.TextureChanged.Data)
}

// optional .atom.proto.Vector2 TranslateFrame = 3;
inline bool TextureChanged::has_translateframe() const {
  return Property_case() == kTranslateFrame;
}
inline void TextureChanged::set_has_translateframe() {
  _oneof_case_[0] = kTranslateFrame;
}
inline void TextureChanged::clear_translateframe() {
  if (has_translateframe()) {
    delete Property_.translateframe_;
    clear_has_Property();
  }
}
inline  const ::atom::proto::Vector2& TextureChanged::translateframe() const {
  // @@protoc_insertion_point(field_get:atom.proto.materials.TextureChanged.TranslateFrame)
  return has_translateframe()
      ? *Property_.translateframe_
      : ::atom::proto::Vector2::default_instance();
}
inline ::atom::proto::Vector2* TextureChanged::mutable_translateframe() {
  if (!has_translateframe()) {
    clear_Property();
    set_has_translateframe();
    Property_.translateframe_ = new ::atom::proto::Vector2;
  }
  // @@protoc_insertion_point(field_mutable:atom.proto.materials.TextureChanged.TranslateFrame)
  return Property_.translateframe_;
}
inline ::atom::proto::Vector2* TextureChanged::release_translateframe() {
  if (has_translateframe()) {
    clear_has_Property();
    ::atom::proto::Vector2* temp = Property_.translateframe_;
    Property_.translateframe_ = NULL;
    return temp;
  } else {
    return NULL;
  }
}
inline void TextureChanged::set_allocated_translateframe(::atom::proto::Vector2* translateframe) {
  clear_Property();
  if (translateframe) {
    set_has_translateframe();
    Property_.translateframe_ = translateframe;
  }
  // @@protoc_insertion_point(field_set_allocated:atom.proto.materials.TextureChanged.TranslateFrame)
}

// optional float RotateFrame = 4;
inline bool TextureChanged::has_rotateframe() const {
  return Property_case() == kRotateFrame;
}
inline void TextureChanged::set_has_rotateframe() {
  _oneof_case_[0] = kRotateFrame;
}
inline void TextureChanged::clear_rotateframe() {
  if (has_rotateframe()) {
    Property_.rotateframe_ = 0;
    clear_has_Property();
  }
}
inline float TextureChanged::rotateframe() const {
  // @@protoc_insertion_point(field_get:atom.proto.materials.TextureChanged.RotateFrame)
  if (has_rotateframe()) {
    return Property_.rotateframe_;
  }
  return 0;
}
inline void TextureChanged::set_rotateframe(float value) {
  if (!has_rotateframe()) {
    clear_Property();
    set_has_rotateframe();
  }
  Property_.rotateframe_ = value;
  // @@protoc_insertion_point(field_set:atom.proto.materials.TextureChanged.RotateFrame)
}

// optional bool MirrorU = 5;
inline bool TextureChanged::has_mirroru() const {
  return Property_case() == kMirrorU;
}
inline void TextureChanged::set_has_mirroru() {
  _oneof_case_[0] = kMirrorU;
}
inline void TextureChanged::clear_mirroru() {
  if (has_mirroru()) {
    Property_.mirroru_ = false;
    clear_has_Property();
  }
}
inline bool TextureChanged::mirroru() const {
  // @@protoc_insertion_point(field_get:atom.proto.materials.TextureChanged.MirrorU)
  if (has_mirroru()) {
    return Property_.mirroru_;
  }
  return false;
}
inline void TextureChanged::set_mirroru(bool value) {
  if (!has_mirroru()) {
    clear_Property();
    set_has_mirroru();
  }
  Property_.mirroru_ = value;
  // @@protoc_insertion_point(field_set:atom.proto.materials.TextureChanged.MirrorU)
}

// optional bool MirrorV = 6;
inline bool TextureChanged::has_mirrorv() const {
  return Property_case() == kMirrorV;
}
inline void TextureChanged::set_has_mirrorv() {
  _oneof_case_[0] = kMirrorV;
}
inline void TextureChanged::clear_mirrorv() {
  if (has_mirrorv()) {
    Property_.mirrorv_ = false;
    clear_has_Property();
  }
}
inline bool TextureChanged::mirrorv() const {
  // @@protoc_insertion_point(field_get:atom.proto.materials.TextureChanged.MirrorV)
  if (has_mirrorv()) {
    return Property_.mirrorv_;
  }
  return false;
}
inline void TextureChanged::set_mirrorv(bool value) {
  if (!has_mirrorv()) {
    clear_Property();
    set_has_mirrorv();
  }
  Property_.mirrorv_ = value;
  // @@protoc_insertion_point(field_set:atom.proto.materials.TextureChanged.MirrorV)
}

// optional bool WrapU = 7;
inline bool TextureChanged::has_wrapu() const {
  return Property_case() == kWrapU;
}
inline void TextureChanged::set_has_wrapu() {
  _oneof_case_[0] = kWrapU;
}
inline void TextureChanged::clear_wrapu() {
  if (has_wrapu()) {
    Property_.wrapu_ = false;
    clear_has_Property();
  }
}
inline bool TextureChanged::wrapu() const {
  // @@protoc_insertion_point(field_get:atom.proto.materials.TextureChanged.WrapU)
  if (has_wrapu()) {
    return Property_.wrapu_;
  }
  return false;
}
inline void TextureChanged::set_wrapu(bool value) {
  if (!has_wrapu()) {
    clear_Property();
    set_has_wrapu();
  }
  Property_.wrapu_ = value;
  // @@protoc_insertion_point(field_set:atom.proto.materials.TextureChanged.WrapU)
}

// optional bool wrapV = 8;
inline bool TextureChanged::has_wrapv() const {
  return Property_case() == kWrapV;
}
inline void TextureChanged::set_has_wrapv() {
  _oneof_case_[0] = kWrapV;
}
inline void TextureChanged::clear_wrapv() {
  if (has_wrapv()) {
    Property_.wrapv_ = false;
    clear_has_Property();
  }
}
inline bool TextureChanged::wrapv() const {
  // @@protoc_insertion_point(field_get:atom.proto.materials.TextureChanged.wrapV)
  if (has_wrapv()) {
    return Property_.wrapv_;
  }
  return false;
}
inline void TextureChanged::set_wrapv(bool value) {
  if (!has_wrapv()) {
    clear_Property();
    set_has_wrapv();
  }
  Property_.wrapv_ = value;
  // @@protoc_insertion_point(field_set:atom.proto.materials.TextureChanged.wrapV)
}

// optional .atom.proto.Vector2 Repeat = 9;
inline bool TextureChanged::has_repeat() const {
  return Property_case() == kRepeat;
}
inline void TextureChanged::set_has_repeat() {
  _oneof_case_[0] = kRepeat;
}
inline void TextureChanged::clear_repeat() {
  if (has_repeat()) {
    delete Property_.repeat_;
    clear_has_Property();
  }
}
inline  const ::atom::proto::Vector2& TextureChanged::repeat() const {
  // @@protoc_insertion_point(field_get:atom.proto.materials.TextureChanged.Repeat)
  return has_repeat()
      ? *Property_.repeat_
      : ::atom::proto::Vector2::default_instance();
}
inline ::atom::proto::Vector2* TextureChanged::mutable_repeat() {
  if (!has_repeat()) {
    clear_Property();
    set_has_repeat();
    Property_.repeat_ = new ::atom::proto::Vector2;
  }
  // @@protoc_insertion_point(field_mutable:atom.proto.materials.TextureChanged.Repeat)
  return Property_.repeat_;
}
inline ::atom::proto::Vector2* TextureChanged::release_repeat() {
  if (has_repeat()) {
    clear_has_Property();
    ::atom::proto::Vector2* temp = Property_.repeat_;
    Property_.repeat_ = NULL;
    return temp;
  } else {
    return NULL;
  }
}
inline void TextureChanged::set_allocated_repeat(::atom::proto::Vector2* repeat) {
  clear_Property();
  if (repeat) {
    set_has_repeat();
    Property_.repeat_ = repeat;
  }
  // @@protoc_insertion_point(field_set_allocated:atom.proto.materials.TextureChanged.Repeat)
}

// optional .atom.proto.Vector2 Offset = 10;
inline bool TextureChanged::has_offset() const {
  return Property_case() == kOffset;
}
inline void TextureChanged::set_has_offset() {
  _oneof_case_[0] = kOffset;
}
inline void TextureChanged::clear_offset() {
  if (has_offset()) {
    delete Property_.offset_;
    clear_has_Property();
  }
}
inline  const ::atom::proto::Vector2& TextureChanged::offset() const {
  // @@protoc_insertion_point(field_get:atom.proto.materials.TextureChanged.Offset)
  return has_offset()
      ? *Property_.offset_
      : ::atom::proto::Vector2::default_instance();
}
inline ::atom::proto::Vector2* TextureChanged::mutable_offset() {
  if (!has_offset()) {
    clear_Property();
    set_has_offset();
    Property_.offset_ = new ::atom::proto::Vector2;
  }
  // @@protoc_insertion_point(field_mutable:atom.proto.materials.TextureChanged.Offset)
  return Property_.offset_;
}
inline ::atom::proto::Vector2* TextureChanged::release_offset() {
  if (has_offset()) {
    clear_has_Property();
    ::atom::proto::Vector2* temp = Property_.offset_;
    Property_.offset_ = NULL;
    return temp;
  } else {
    return NULL;
  }
}
inline void TextureChanged::set_allocated_offset(::atom::proto::Vector2* offset) {
  clear_Property();
  if (offset) {
    set_has_offset();
    Property_.offset_ = offset;
  }
  // @@protoc_insertion_point(field_set_allocated:atom.proto.materials.TextureChanged.Offset)
}

// optional float Rotate = 11;
inline bool TextureChanged::has_rotate() const {
  return Property_case() == kRotate;
}
inline void TextureChanged::set_has_rotate() {
  _oneof_case_[0] = kRotate;
}
inline void TextureChanged::clear_rotate() {
  if (has_rotate()) {
    Property_.rotate_ = 0;
    clear_has_Property();
  }
}
inline float TextureChanged::rotate() const {
  // @@protoc_insertion_point(field_get:atom.proto.materials.TextureChanged.Rotate)
  if (has_rotate()) {
    return Property_.rotate_;
  }
  return 0;
}
inline void TextureChanged::set_rotate(float value) {
  if (!has_rotate()) {
    clear_Property();
    set_has_rotate();
  }
  Property_.rotate_ = value;
  // @@protoc_insertion_point(field_set:atom.proto.materials.TextureChanged.Rotate)
}

// optional .atom.proto.Vector2 Noise = 12;
inline bool TextureChanged::has_noise() const {
  return Property_case() == kNoise;
}
inline void TextureChanged::set_has_noise() {
  _oneof_case_[0] = kNoise;
}
inline void TextureChanged::clear_noise() {
  if (has_noise()) {
    delete Property_.noise_;
    clear_has_Property();
  }
}
inline  const ::atom::proto::Vector2& TextureChanged::noise() const {
  // @@protoc_insertion_point(field_get:atom.proto.materials.TextureChanged.Noise)
  return has_noise()
      ? *Property_.noise_
      : ::atom::proto::Vector2::default_instance();
}
inline ::atom::proto::Vector2* TextureChanged::mutable_noise() {
  if (!has_noise()) {
    clear_Property();
    set_has_noise();
    Property_.noise_ = new ::atom::proto::Vector2;
  }
  // @@protoc_insertion_point(field_mutable:atom.proto.materials.TextureChanged.Noise)
  return Property_.noise_;
}
inline ::atom::proto::Vector2* TextureChanged::release_noise() {
  if (has_noise()) {
    clear_has_Property();
    ::atom::proto::Vector2* temp = Property_.noise_;
    Property_.noise_ = NULL;
    return temp;
  } else {
    return NULL;
  }
}
inline void TextureChanged::set_allocated_noise(::atom::proto::Vector2* noise) {
  clear_Property();
  if (noise) {
    set_has_noise();
    Property_.noise_ = noise;
  }
  // @@protoc_insertion_point(field_set_allocated:atom.proto.materials.TextureChanged.Noise)
}

inline bool TextureChanged::has_Property() const {
  return Property_case() != PROPERTY_NOT_SET;
}
inline void TextureChanged::clear_has_Property() {
  _oneof_case_[0] = PROPERTY_NOT_SET;
}
inline TextureChanged::PropertyCase TextureChanged::Property_case() const {
  return TextureChanged::PropertyCase(_oneof_case_[0]);
}
#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace materials
}  // namespace proto
}  // namespace atom

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_materials_2fTextureChanged_2eproto__INCLUDED
