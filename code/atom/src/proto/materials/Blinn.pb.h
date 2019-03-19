// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: materials/Blinn.proto

#ifndef PROTOBUF_materials_2fBlinn_2eproto__INCLUDED
#define PROTOBUF_materials_2fBlinn_2eproto__INCLUDED

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
#include "materials/TexturedParameter.pb.h"
// @@protoc_insertion_point(includes)

namespace atom {
namespace proto {
namespace materials {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_materials_2fBlinn_2eproto();
void protobuf_AssignDesc_materials_2fBlinn_2eproto();
void protobuf_ShutdownFile_materials_2fBlinn_2eproto();

class Blinn;

// ===================================================================

class Blinn : public ::google::protobuf::Message {
 public:
  Blinn();
  virtual ~Blinn();

  Blinn(const Blinn& from);

  inline Blinn& operator=(const Blinn& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Blinn& default_instance();

  void Swap(Blinn* other);

  // implements Message ----------------------------------------------

  inline Blinn* New() const { return New(NULL); }

  Blinn* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Blinn& from);
  void MergeFrom(const Blinn& from);
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
  void InternalSwap(Blinn* other);
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

  // optional .atom.proto.materials.TexturedParameter Color = 1;
  bool has_color() const;
  void clear_color();
  static const int kColorFieldNumber = 1;
  const ::atom::proto::materials::TexturedParameter& color() const;
  ::atom::proto::materials::TexturedParameter* mutable_color();
  ::atom::proto::materials::TexturedParameter* release_color();
  void set_allocated_color(::atom::proto::materials::TexturedParameter* color);

  // optional .atom.proto.materials.TexturedParameter Transparency = 2;
  bool has_transparency() const;
  void clear_transparency();
  static const int kTransparencyFieldNumber = 2;
  const ::atom::proto::materials::TexturedParameter& transparency() const;
  ::atom::proto::materials::TexturedParameter* mutable_transparency();
  ::atom::proto::materials::TexturedParameter* release_transparency();
  void set_allocated_transparency(::atom::proto::materials::TexturedParameter* transparency);

  // optional .atom.proto.materials.TexturedParameter AmbientColor = 3;
  bool has_ambientcolor() const;
  void clear_ambientcolor();
  static const int kAmbientColorFieldNumber = 3;
  const ::atom::proto::materials::TexturedParameter& ambientcolor() const;
  ::atom::proto::materials::TexturedParameter* mutable_ambientcolor();
  ::atom::proto::materials::TexturedParameter* release_ambientcolor();
  void set_allocated_ambientcolor(::atom::proto::materials::TexturedParameter* ambientcolor);

  // optional .atom.proto.materials.TexturedParameter Incandescence = 4;
  bool has_incandescence() const;
  void clear_incandescence();
  static const int kIncandescenceFieldNumber = 4;
  const ::atom::proto::materials::TexturedParameter& incandescence() const;
  ::atom::proto::materials::TexturedParameter* mutable_incandescence();
  ::atom::proto::materials::TexturedParameter* release_incandescence();
  void set_allocated_incandescence(::atom::proto::materials::TexturedParameter* incandescence);

  // optional string BumpMap = 5;
  void clear_bumpmap();
  static const int kBumpMapFieldNumber = 5;
  const ::std::string& bumpmap() const;
  void set_bumpmap(const ::std::string& value);
  void set_bumpmap(const char* value);
  void set_bumpmap(const char* value, size_t size);
  ::std::string* mutable_bumpmap();
  ::std::string* release_bumpmap();
  void set_allocated_bumpmap(::std::string* bumpmap);

  // optional .atom.proto.materials.TexturedParameter DiffuseAmount = 6;
  bool has_diffuseamount() const;
  void clear_diffuseamount();
  static const int kDiffuseAmountFieldNumber = 6;
  const ::atom::proto::materials::TexturedParameter& diffuseamount() const;
  ::atom::proto::materials::TexturedParameter* mutable_diffuseamount();
  ::atom::proto::materials::TexturedParameter* release_diffuseamount();
  void set_allocated_diffuseamount(::atom::proto::materials::TexturedParameter* diffuseamount);

  // optional .atom.proto.materials.TexturedParameter Translucence = 7;
  bool has_translucence() const;
  void clear_translucence();
  static const int kTranslucenceFieldNumber = 7;
  const ::atom::proto::materials::TexturedParameter& translucence() const;
  ::atom::proto::materials::TexturedParameter* mutable_translucence();
  ::atom::proto::materials::TexturedParameter* release_translucence();
  void set_allocated_translucence(::atom::proto::materials::TexturedParameter* translucence);

  // optional .atom.proto.materials.TexturedParameter TranslucenceDepth = 8;
  bool has_translucencedepth() const;
  void clear_translucencedepth();
  static const int kTranslucenceDepthFieldNumber = 8;
  const ::atom::proto::materials::TexturedParameter& translucencedepth() const;
  ::atom::proto::materials::TexturedParameter* mutable_translucencedepth();
  ::atom::proto::materials::TexturedParameter* release_translucencedepth();
  void set_allocated_translucencedepth(::atom::proto::materials::TexturedParameter* translucencedepth);

  // optional .atom.proto.materials.TexturedParameter TranslucenceFocus = 9;
  bool has_translucencefocus() const;
  void clear_translucencefocus();
  static const int kTranslucenceFocusFieldNumber = 9;
  const ::atom::proto::materials::TexturedParameter& translucencefocus() const;
  ::atom::proto::materials::TexturedParameter* mutable_translucencefocus();
  ::atom::proto::materials::TexturedParameter* release_translucencefocus();
  void set_allocated_translucencefocus(::atom::proto::materials::TexturedParameter* translucencefocus);

  // optional .atom.proto.materials.TexturedParameter GlowIntensity = 10;
  bool has_glowintensity() const;
  void clear_glowintensity();
  static const int kGlowIntensityFieldNumber = 10;
  const ::atom::proto::materials::TexturedParameter& glowintensity() const;
  ::atom::proto::materials::TexturedParameter* mutable_glowintensity();
  ::atom::proto::materials::TexturedParameter* release_glowintensity();
  void set_allocated_glowintensity(::atom::proto::materials::TexturedParameter* glowintensity);

  // optional .atom.proto.materials.TexturedParameter Eccentricity = 11;
  bool has_eccentricity() const;
  void clear_eccentricity();
  static const int kEccentricityFieldNumber = 11;
  const ::atom::proto::materials::TexturedParameter& eccentricity() const;
  ::atom::proto::materials::TexturedParameter* mutable_eccentricity();
  ::atom::proto::materials::TexturedParameter* release_eccentricity();
  void set_allocated_eccentricity(::atom::proto::materials::TexturedParameter* eccentricity);

  // optional .atom.proto.materials.TexturedParameter SpecularRollOff = 12;
  bool has_specularrolloff() const;
  void clear_specularrolloff();
  static const int kSpecularRollOffFieldNumber = 12;
  const ::atom::proto::materials::TexturedParameter& specularrolloff() const;
  ::atom::proto::materials::TexturedParameter* mutable_specularrolloff();
  ::atom::proto::materials::TexturedParameter* release_specularrolloff();
  void set_allocated_specularrolloff(::atom::proto::materials::TexturedParameter* specularrolloff);

  // optional .atom.proto.materials.TexturedParameter SpecularColor = 13;
  bool has_specularcolor() const;
  void clear_specularcolor();
  static const int kSpecularColorFieldNumber = 13;
  const ::atom::proto::materials::TexturedParameter& specularcolor() const;
  ::atom::proto::materials::TexturedParameter* mutable_specularcolor();
  ::atom::proto::materials::TexturedParameter* release_specularcolor();
  void set_allocated_specularcolor(::atom::proto::materials::TexturedParameter* specularcolor);

  // optional .atom.proto.materials.TexturedParameter Reflectivity = 14;
  bool has_reflectivity() const;
  void clear_reflectivity();
  static const int kReflectivityFieldNumber = 14;
  const ::atom::proto::materials::TexturedParameter& reflectivity() const;
  ::atom::proto::materials::TexturedParameter* mutable_reflectivity();
  ::atom::proto::materials::TexturedParameter* release_reflectivity();
  void set_allocated_reflectivity(::atom::proto::materials::TexturedParameter* reflectivity);

  // optional .atom.proto.materials.TexturedParameter ReflectedColor = 15;
  bool has_reflectedcolor() const;
  void clear_reflectedcolor();
  static const int kReflectedColorFieldNumber = 15;
  const ::atom::proto::materials::TexturedParameter& reflectedcolor() const;
  ::atom::proto::materials::TexturedParameter* mutable_reflectedcolor();
  ::atom::proto::materials::TexturedParameter* release_reflectedcolor();
  void set_allocated_reflectedcolor(::atom::proto::materials::TexturedParameter* reflectedcolor);

  // @@protoc_insertion_point(class_scope:atom.proto.materials.Blinn)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::atom::proto::materials::TexturedParameter* color_;
  ::atom::proto::materials::TexturedParameter* transparency_;
  ::atom::proto::materials::TexturedParameter* ambientcolor_;
  ::atom::proto::materials::TexturedParameter* incandescence_;
  ::google::protobuf::internal::ArenaStringPtr bumpmap_;
  ::atom::proto::materials::TexturedParameter* diffuseamount_;
  ::atom::proto::materials::TexturedParameter* translucence_;
  ::atom::proto::materials::TexturedParameter* translucencedepth_;
  ::atom::proto::materials::TexturedParameter* translucencefocus_;
  ::atom::proto::materials::TexturedParameter* glowintensity_;
  ::atom::proto::materials::TexturedParameter* eccentricity_;
  ::atom::proto::materials::TexturedParameter* specularrolloff_;
  ::atom::proto::materials::TexturedParameter* specularcolor_;
  ::atom::proto::materials::TexturedParameter* reflectivity_;
  ::atom::proto::materials::TexturedParameter* reflectedcolor_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_materials_2fBlinn_2eproto();
  friend void protobuf_AssignDesc_materials_2fBlinn_2eproto();
  friend void protobuf_ShutdownFile_materials_2fBlinn_2eproto();

  void InitAsDefaultInstance();
  static Blinn* default_instance_;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// Blinn

// optional .atom.proto.materials.TexturedParameter Color = 1;
inline bool Blinn::has_color() const {
  return !_is_default_instance_ && color_ != NULL;
}
inline void Blinn::clear_color() {
  if (GetArenaNoVirtual() == NULL && color_ != NULL) delete color_;
  color_ = NULL;
}
inline const ::atom::proto::materials::TexturedParameter& Blinn::color() const {
  // @@protoc_insertion_point(field_get:atom.proto.materials.Blinn.Color)
  return color_ != NULL ? *color_ : *default_instance_->color_;
}
inline ::atom::proto::materials::TexturedParameter* Blinn::mutable_color() {
  
  if (color_ == NULL) {
    color_ = new ::atom::proto::materials::TexturedParameter;
  }
  // @@protoc_insertion_point(field_mutable:atom.proto.materials.Blinn.Color)
  return color_;
}
inline ::atom::proto::materials::TexturedParameter* Blinn::release_color() {
  
  ::atom::proto::materials::TexturedParameter* temp = color_;
  color_ = NULL;
  return temp;
}
inline void Blinn::set_allocated_color(::atom::proto::materials::TexturedParameter* color) {
  delete color_;
  color_ = color;
  if (color) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:atom.proto.materials.Blinn.Color)
}

// optional .atom.proto.materials.TexturedParameter Transparency = 2;
inline bool Blinn::has_transparency() const {
  return !_is_default_instance_ && transparency_ != NULL;
}
inline void Blinn::clear_transparency() {
  if (GetArenaNoVirtual() == NULL && transparency_ != NULL) delete transparency_;
  transparency_ = NULL;
}
inline const ::atom::proto::materials::TexturedParameter& Blinn::transparency() const {
  // @@protoc_insertion_point(field_get:atom.proto.materials.Blinn.Transparency)
  return transparency_ != NULL ? *transparency_ : *default_instance_->transparency_;
}
inline ::atom::proto::materials::TexturedParameter* Blinn::mutable_transparency() {
  
  if (transparency_ == NULL) {
    transparency_ = new ::atom::proto::materials::TexturedParameter;
  }
  // @@protoc_insertion_point(field_mutable:atom.proto.materials.Blinn.Transparency)
  return transparency_;
}
inline ::atom::proto::materials::TexturedParameter* Blinn::release_transparency() {
  
  ::atom::proto::materials::TexturedParameter* temp = transparency_;
  transparency_ = NULL;
  return temp;
}
inline void Blinn::set_allocated_transparency(::atom::proto::materials::TexturedParameter* transparency) {
  delete transparency_;
  transparency_ = transparency;
  if (transparency) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:atom.proto.materials.Blinn.Transparency)
}

// optional .atom.proto.materials.TexturedParameter AmbientColor = 3;
inline bool Blinn::has_ambientcolor() const {
  return !_is_default_instance_ && ambientcolor_ != NULL;
}
inline void Blinn::clear_ambientcolor() {
  if (GetArenaNoVirtual() == NULL && ambientcolor_ != NULL) delete ambientcolor_;
  ambientcolor_ = NULL;
}
inline const ::atom::proto::materials::TexturedParameter& Blinn::ambientcolor() const {
  // @@protoc_insertion_point(field_get:atom.proto.materials.Blinn.AmbientColor)
  return ambientcolor_ != NULL ? *ambientcolor_ : *default_instance_->ambientcolor_;
}
inline ::atom::proto::materials::TexturedParameter* Blinn::mutable_ambientcolor() {
  
  if (ambientcolor_ == NULL) {
    ambientcolor_ = new ::atom::proto::materials::TexturedParameter;
  }
  // @@protoc_insertion_point(field_mutable:atom.proto.materials.Blinn.AmbientColor)
  return ambientcolor_;
}
inline ::atom::proto::materials::TexturedParameter* Blinn::release_ambientcolor() {
  
  ::atom::proto::materials::TexturedParameter* temp = ambientcolor_;
  ambientcolor_ = NULL;
  return temp;
}
inline void Blinn::set_allocated_ambientcolor(::atom::proto::materials::TexturedParameter* ambientcolor) {
  delete ambientcolor_;
  ambientcolor_ = ambientcolor;
  if (ambientcolor) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:atom.proto.materials.Blinn.AmbientColor)
}

// optional .atom.proto.materials.TexturedParameter Incandescence = 4;
inline bool Blinn::has_incandescence() const {
  return !_is_default_instance_ && incandescence_ != NULL;
}
inline void Blinn::clear_incandescence() {
  if (GetArenaNoVirtual() == NULL && incandescence_ != NULL) delete incandescence_;
  incandescence_ = NULL;
}
inline const ::atom::proto::materials::TexturedParameter& Blinn::incandescence() const {
  // @@protoc_insertion_point(field_get:atom.proto.materials.Blinn.Incandescence)
  return incandescence_ != NULL ? *incandescence_ : *default_instance_->incandescence_;
}
inline ::atom::proto::materials::TexturedParameter* Blinn::mutable_incandescence() {
  
  if (incandescence_ == NULL) {
    incandescence_ = new ::atom::proto::materials::TexturedParameter;
  }
  // @@protoc_insertion_point(field_mutable:atom.proto.materials.Blinn.Incandescence)
  return incandescence_;
}
inline ::atom::proto::materials::TexturedParameter* Blinn::release_incandescence() {
  
  ::atom::proto::materials::TexturedParameter* temp = incandescence_;
  incandescence_ = NULL;
  return temp;
}
inline void Blinn::set_allocated_incandescence(::atom::proto::materials::TexturedParameter* incandescence) {
  delete incandescence_;
  incandescence_ = incandescence;
  if (incandescence) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:atom.proto.materials.Blinn.Incandescence)
}

// optional string BumpMap = 5;
inline void Blinn::clear_bumpmap() {
  bumpmap_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Blinn::bumpmap() const {
  // @@protoc_insertion_point(field_get:atom.proto.materials.Blinn.BumpMap)
  return bumpmap_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Blinn::set_bumpmap(const ::std::string& value) {
  
  bumpmap_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:atom.proto.materials.Blinn.BumpMap)
}
inline void Blinn::set_bumpmap(const char* value) {
  
  bumpmap_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:atom.proto.materials.Blinn.BumpMap)
}
inline void Blinn::set_bumpmap(const char* value, size_t size) {
  
  bumpmap_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:atom.proto.materials.Blinn.BumpMap)
}
inline ::std::string* Blinn::mutable_bumpmap() {
  
  // @@protoc_insertion_point(field_mutable:atom.proto.materials.Blinn.BumpMap)
  return bumpmap_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Blinn::release_bumpmap() {
  
  return bumpmap_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Blinn::set_allocated_bumpmap(::std::string* bumpmap) {
  if (bumpmap != NULL) {
    
  } else {
    
  }
  bumpmap_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), bumpmap);
  // @@protoc_insertion_point(field_set_allocated:atom.proto.materials.Blinn.BumpMap)
}

// optional .atom.proto.materials.TexturedParameter DiffuseAmount = 6;
inline bool Blinn::has_diffuseamount() const {
  return !_is_default_instance_ && diffuseamount_ != NULL;
}
inline void Blinn::clear_diffuseamount() {
  if (GetArenaNoVirtual() == NULL && diffuseamount_ != NULL) delete diffuseamount_;
  diffuseamount_ = NULL;
}
inline const ::atom::proto::materials::TexturedParameter& Blinn::diffuseamount() const {
  // @@protoc_insertion_point(field_get:atom.proto.materials.Blinn.DiffuseAmount)
  return diffuseamount_ != NULL ? *diffuseamount_ : *default_instance_->diffuseamount_;
}
inline ::atom::proto::materials::TexturedParameter* Blinn::mutable_diffuseamount() {
  
  if (diffuseamount_ == NULL) {
    diffuseamount_ = new ::atom::proto::materials::TexturedParameter;
  }
  // @@protoc_insertion_point(field_mutable:atom.proto.materials.Blinn.DiffuseAmount)
  return diffuseamount_;
}
inline ::atom::proto::materials::TexturedParameter* Blinn::release_diffuseamount() {
  
  ::atom::proto::materials::TexturedParameter* temp = diffuseamount_;
  diffuseamount_ = NULL;
  return temp;
}
inline void Blinn::set_allocated_diffuseamount(::atom::proto::materials::TexturedParameter* diffuseamount) {
  delete diffuseamount_;
  diffuseamount_ = diffuseamount;
  if (diffuseamount) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:atom.proto.materials.Blinn.DiffuseAmount)
}

// optional .atom.proto.materials.TexturedParameter Translucence = 7;
inline bool Blinn::has_translucence() const {
  return !_is_default_instance_ && translucence_ != NULL;
}
inline void Blinn::clear_translucence() {
  if (GetArenaNoVirtual() == NULL && translucence_ != NULL) delete translucence_;
  translucence_ = NULL;
}
inline const ::atom::proto::materials::TexturedParameter& Blinn::translucence() const {
  // @@protoc_insertion_point(field_get:atom.proto.materials.Blinn.Translucence)
  return translucence_ != NULL ? *translucence_ : *default_instance_->translucence_;
}
inline ::atom::proto::materials::TexturedParameter* Blinn::mutable_translucence() {
  
  if (translucence_ == NULL) {
    translucence_ = new ::atom::proto::materials::TexturedParameter;
  }
  // @@protoc_insertion_point(field_mutable:atom.proto.materials.Blinn.Translucence)
  return translucence_;
}
inline ::atom::proto::materials::TexturedParameter* Blinn::release_translucence() {
  
  ::atom::proto::materials::TexturedParameter* temp = translucence_;
  translucence_ = NULL;
  return temp;
}
inline void Blinn::set_allocated_translucence(::atom::proto::materials::TexturedParameter* translucence) {
  delete translucence_;
  translucence_ = translucence;
  if (translucence) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:atom.proto.materials.Blinn.Translucence)
}

// optional .atom.proto.materials.TexturedParameter TranslucenceDepth = 8;
inline bool Blinn::has_translucencedepth() const {
  return !_is_default_instance_ && translucencedepth_ != NULL;
}
inline void Blinn::clear_translucencedepth() {
  if (GetArenaNoVirtual() == NULL && translucencedepth_ != NULL) delete translucencedepth_;
  translucencedepth_ = NULL;
}
inline const ::atom::proto::materials::TexturedParameter& Blinn::translucencedepth() const {
  // @@protoc_insertion_point(field_get:atom.proto.materials.Blinn.TranslucenceDepth)
  return translucencedepth_ != NULL ? *translucencedepth_ : *default_instance_->translucencedepth_;
}
inline ::atom::proto::materials::TexturedParameter* Blinn::mutable_translucencedepth() {
  
  if (translucencedepth_ == NULL) {
    translucencedepth_ = new ::atom::proto::materials::TexturedParameter;
  }
  // @@protoc_insertion_point(field_mutable:atom.proto.materials.Blinn.TranslucenceDepth)
  return translucencedepth_;
}
inline ::atom::proto::materials::TexturedParameter* Blinn::release_translucencedepth() {
  
  ::atom::proto::materials::TexturedParameter* temp = translucencedepth_;
  translucencedepth_ = NULL;
  return temp;
}
inline void Blinn::set_allocated_translucencedepth(::atom::proto::materials::TexturedParameter* translucencedepth) {
  delete translucencedepth_;
  translucencedepth_ = translucencedepth;
  if (translucencedepth) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:atom.proto.materials.Blinn.TranslucenceDepth)
}

// optional .atom.proto.materials.TexturedParameter TranslucenceFocus = 9;
inline bool Blinn::has_translucencefocus() const {
  return !_is_default_instance_ && translucencefocus_ != NULL;
}
inline void Blinn::clear_translucencefocus() {
  if (GetArenaNoVirtual() == NULL && translucencefocus_ != NULL) delete translucencefocus_;
  translucencefocus_ = NULL;
}
inline const ::atom::proto::materials::TexturedParameter& Blinn::translucencefocus() const {
  // @@protoc_insertion_point(field_get:atom.proto.materials.Blinn.TranslucenceFocus)
  return translucencefocus_ != NULL ? *translucencefocus_ : *default_instance_->translucencefocus_;
}
inline ::atom::proto::materials::TexturedParameter* Blinn::mutable_translucencefocus() {
  
  if (translucencefocus_ == NULL) {
    translucencefocus_ = new ::atom::proto::materials::TexturedParameter;
  }
  // @@protoc_insertion_point(field_mutable:atom.proto.materials.Blinn.TranslucenceFocus)
  return translucencefocus_;
}
inline ::atom::proto::materials::TexturedParameter* Blinn::release_translucencefocus() {
  
  ::atom::proto::materials::TexturedParameter* temp = translucencefocus_;
  translucencefocus_ = NULL;
  return temp;
}
inline void Blinn::set_allocated_translucencefocus(::atom::proto::materials::TexturedParameter* translucencefocus) {
  delete translucencefocus_;
  translucencefocus_ = translucencefocus;
  if (translucencefocus) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:atom.proto.materials.Blinn.TranslucenceFocus)
}

// optional .atom.proto.materials.TexturedParameter GlowIntensity = 10;
inline bool Blinn::has_glowintensity() const {
  return !_is_default_instance_ && glowintensity_ != NULL;
}
inline void Blinn::clear_glowintensity() {
  if (GetArenaNoVirtual() == NULL && glowintensity_ != NULL) delete glowintensity_;
  glowintensity_ = NULL;
}
inline const ::atom::proto::materials::TexturedParameter& Blinn::glowintensity() const {
  // @@protoc_insertion_point(field_get:atom.proto.materials.Blinn.GlowIntensity)
  return glowintensity_ != NULL ? *glowintensity_ : *default_instance_->glowintensity_;
}
inline ::atom::proto::materials::TexturedParameter* Blinn::mutable_glowintensity() {
  
  if (glowintensity_ == NULL) {
    glowintensity_ = new ::atom::proto::materials::TexturedParameter;
  }
  // @@protoc_insertion_point(field_mutable:atom.proto.materials.Blinn.GlowIntensity)
  return glowintensity_;
}
inline ::atom::proto::materials::TexturedParameter* Blinn::release_glowintensity() {
  
  ::atom::proto::materials::TexturedParameter* temp = glowintensity_;
  glowintensity_ = NULL;
  return temp;
}
inline void Blinn::set_allocated_glowintensity(::atom::proto::materials::TexturedParameter* glowintensity) {
  delete glowintensity_;
  glowintensity_ = glowintensity;
  if (glowintensity) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:atom.proto.materials.Blinn.GlowIntensity)
}

// optional .atom.proto.materials.TexturedParameter Eccentricity = 11;
inline bool Blinn::has_eccentricity() const {
  return !_is_default_instance_ && eccentricity_ != NULL;
}
inline void Blinn::clear_eccentricity() {
  if (GetArenaNoVirtual() == NULL && eccentricity_ != NULL) delete eccentricity_;
  eccentricity_ = NULL;
}
inline const ::atom::proto::materials::TexturedParameter& Blinn::eccentricity() const {
  // @@protoc_insertion_point(field_get:atom.proto.materials.Blinn.Eccentricity)
  return eccentricity_ != NULL ? *eccentricity_ : *default_instance_->eccentricity_;
}
inline ::atom::proto::materials::TexturedParameter* Blinn::mutable_eccentricity() {
  
  if (eccentricity_ == NULL) {
    eccentricity_ = new ::atom::proto::materials::TexturedParameter;
  }
  // @@protoc_insertion_point(field_mutable:atom.proto.materials.Blinn.Eccentricity)
  return eccentricity_;
}
inline ::atom::proto::materials::TexturedParameter* Blinn::release_eccentricity() {
  
  ::atom::proto::materials::TexturedParameter* temp = eccentricity_;
  eccentricity_ = NULL;
  return temp;
}
inline void Blinn::set_allocated_eccentricity(::atom::proto::materials::TexturedParameter* eccentricity) {
  delete eccentricity_;
  eccentricity_ = eccentricity;
  if (eccentricity) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:atom.proto.materials.Blinn.Eccentricity)
}

// optional .atom.proto.materials.TexturedParameter SpecularRollOff = 12;
inline bool Blinn::has_specularrolloff() const {
  return !_is_default_instance_ && specularrolloff_ != NULL;
}
inline void Blinn::clear_specularrolloff() {
  if (GetArenaNoVirtual() == NULL && specularrolloff_ != NULL) delete specularrolloff_;
  specularrolloff_ = NULL;
}
inline const ::atom::proto::materials::TexturedParameter& Blinn::specularrolloff() const {
  // @@protoc_insertion_point(field_get:atom.proto.materials.Blinn.SpecularRollOff)
  return specularrolloff_ != NULL ? *specularrolloff_ : *default_instance_->specularrolloff_;
}
inline ::atom::proto::materials::TexturedParameter* Blinn::mutable_specularrolloff() {
  
  if (specularrolloff_ == NULL) {
    specularrolloff_ = new ::atom::proto::materials::TexturedParameter;
  }
  // @@protoc_insertion_point(field_mutable:atom.proto.materials.Blinn.SpecularRollOff)
  return specularrolloff_;
}
inline ::atom::proto::materials::TexturedParameter* Blinn::release_specularrolloff() {
  
  ::atom::proto::materials::TexturedParameter* temp = specularrolloff_;
  specularrolloff_ = NULL;
  return temp;
}
inline void Blinn::set_allocated_specularrolloff(::atom::proto::materials::TexturedParameter* specularrolloff) {
  delete specularrolloff_;
  specularrolloff_ = specularrolloff;
  if (specularrolloff) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:atom.proto.materials.Blinn.SpecularRollOff)
}

// optional .atom.proto.materials.TexturedParameter SpecularColor = 13;
inline bool Blinn::has_specularcolor() const {
  return !_is_default_instance_ && specularcolor_ != NULL;
}
inline void Blinn::clear_specularcolor() {
  if (GetArenaNoVirtual() == NULL && specularcolor_ != NULL) delete specularcolor_;
  specularcolor_ = NULL;
}
inline const ::atom::proto::materials::TexturedParameter& Blinn::specularcolor() const {
  // @@protoc_insertion_point(field_get:atom.proto.materials.Blinn.SpecularColor)
  return specularcolor_ != NULL ? *specularcolor_ : *default_instance_->specularcolor_;
}
inline ::atom::proto::materials::TexturedParameter* Blinn::mutable_specularcolor() {
  
  if (specularcolor_ == NULL) {
    specularcolor_ = new ::atom::proto::materials::TexturedParameter;
  }
  // @@protoc_insertion_point(field_mutable:atom.proto.materials.Blinn.SpecularColor)
  return specularcolor_;
}
inline ::atom::proto::materials::TexturedParameter* Blinn::release_specularcolor() {
  
  ::atom::proto::materials::TexturedParameter* temp = specularcolor_;
  specularcolor_ = NULL;
  return temp;
}
inline void Blinn::set_allocated_specularcolor(::atom::proto::materials::TexturedParameter* specularcolor) {
  delete specularcolor_;
  specularcolor_ = specularcolor;
  if (specularcolor) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:atom.proto.materials.Blinn.SpecularColor)
}

// optional .atom.proto.materials.TexturedParameter Reflectivity = 14;
inline bool Blinn::has_reflectivity() const {
  return !_is_default_instance_ && reflectivity_ != NULL;
}
inline void Blinn::clear_reflectivity() {
  if (GetArenaNoVirtual() == NULL && reflectivity_ != NULL) delete reflectivity_;
  reflectivity_ = NULL;
}
inline const ::atom::proto::materials::TexturedParameter& Blinn::reflectivity() const {
  // @@protoc_insertion_point(field_get:atom.proto.materials.Blinn.Reflectivity)
  return reflectivity_ != NULL ? *reflectivity_ : *default_instance_->reflectivity_;
}
inline ::atom::proto::materials::TexturedParameter* Blinn::mutable_reflectivity() {
  
  if (reflectivity_ == NULL) {
    reflectivity_ = new ::atom::proto::materials::TexturedParameter;
  }
  // @@protoc_insertion_point(field_mutable:atom.proto.materials.Blinn.Reflectivity)
  return reflectivity_;
}
inline ::atom::proto::materials::TexturedParameter* Blinn::release_reflectivity() {
  
  ::atom::proto::materials::TexturedParameter* temp = reflectivity_;
  reflectivity_ = NULL;
  return temp;
}
inline void Blinn::set_allocated_reflectivity(::atom::proto::materials::TexturedParameter* reflectivity) {
  delete reflectivity_;
  reflectivity_ = reflectivity;
  if (reflectivity) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:atom.proto.materials.Blinn.Reflectivity)
}

// optional .atom.proto.materials.TexturedParameter ReflectedColor = 15;
inline bool Blinn::has_reflectedcolor() const {
  return !_is_default_instance_ && reflectedcolor_ != NULL;
}
inline void Blinn::clear_reflectedcolor() {
  if (GetArenaNoVirtual() == NULL && reflectedcolor_ != NULL) delete reflectedcolor_;
  reflectedcolor_ = NULL;
}
inline const ::atom::proto::materials::TexturedParameter& Blinn::reflectedcolor() const {
  // @@protoc_insertion_point(field_get:atom.proto.materials.Blinn.ReflectedColor)
  return reflectedcolor_ != NULL ? *reflectedcolor_ : *default_instance_->reflectedcolor_;
}
inline ::atom::proto::materials::TexturedParameter* Blinn::mutable_reflectedcolor() {
  
  if (reflectedcolor_ == NULL) {
    reflectedcolor_ = new ::atom::proto::materials::TexturedParameter;
  }
  // @@protoc_insertion_point(field_mutable:atom.proto.materials.Blinn.ReflectedColor)
  return reflectedcolor_;
}
inline ::atom::proto::materials::TexturedParameter* Blinn::release_reflectedcolor() {
  
  ::atom::proto::materials::TexturedParameter* temp = reflectedcolor_;
  reflectedcolor_ = NULL;
  return temp;
}
inline void Blinn::set_allocated_reflectedcolor(::atom::proto::materials::TexturedParameter* reflectedcolor) {
  delete reflectedcolor_;
  reflectedcolor_ = reflectedcolor;
  if (reflectedcolor) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:atom.proto.materials.Blinn.ReflectedColor)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace materials
}  // namespace proto
}  // namespace atom

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_materials_2fBlinn_2eproto__INCLUDED