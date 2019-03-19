// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Camera.proto

#ifndef PROTOBUF_Camera_2eproto__INCLUDED
#define PROTOBUF_Camera_2eproto__INCLUDED

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
#include "Vector3.pb.h"
// @@protoc_insertion_point(includes)

namespace atom {
namespace proto {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_Camera_2eproto();
void protobuf_AssignDesc_Camera_2eproto();
void protobuf_ShutdownFile_Camera_2eproto();

class Camera;

// ===================================================================

class Camera : public ::google::protobuf::Message {
 public:
  Camera();
  virtual ~Camera();

  Camera(const Camera& from);

  inline Camera& operator=(const Camera& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Camera& default_instance();

  void Swap(Camera* other);

  // implements Message ----------------------------------------------

  inline Camera* New() const { return New(NULL); }

  Camera* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Camera& from);
  void MergeFrom(const Camera& from);
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
  void InternalSwap(Camera* other);
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

  // optional .atom.proto.Vector3 Position = 2;
  bool has_position() const;
  void clear_position();
  static const int kPositionFieldNumber = 2;
  const ::atom::proto::Vector3& position() const;
  ::atom::proto::Vector3* mutable_position();
  ::atom::proto::Vector3* release_position();
  void set_allocated_position(::atom::proto::Vector3* position);

  // optional .atom.proto.Vector3 Target = 3;
  bool has_target() const;
  void clear_target();
  static const int kTargetFieldNumber = 3;
  const ::atom::proto::Vector3& target() const;
  ::atom::proto::Vector3* mutable_target();
  ::atom::proto::Vector3* release_target();
  void set_allocated_target(::atom::proto::Vector3* target);

  // optional .atom.proto.Vector3 Up = 4;
  bool has_up() const;
  void clear_up();
  static const int kUpFieldNumber = 4;
  const ::atom::proto::Vector3& up() const;
  ::atom::proto::Vector3* mutable_up();
  ::atom::proto::Vector3* release_up();
  void set_allocated_up(::atom::proto::Vector3* up);

  // optional float FieldOfView = 5;
  void clear_fieldofview();
  static const int kFieldOfViewFieldNumber = 5;
  float fieldofview() const;
  void set_fieldofview(float value);

  // optional float AspectRatio = 6;
  void clear_aspectratio();
  static const int kAspectRatioFieldNumber = 6;
  float aspectratio() const;
  void set_aspectratio(float value);

  // optional float NearPlane = 7;
  void clear_nearplane();
  static const int kNearPlaneFieldNumber = 7;
  float nearplane() const;
  void set_nearplane(float value);

  // optional float FarPlane = 8;
  void clear_farplane();
  static const int kFarPlaneFieldNumber = 8;
  float farplane() const;
  void set_farplane(float value);

  // optional bool InitialVisibility = 9;
  void clear_initialvisibility();
  static const int kInitialVisibilityFieldNumber = 9;
  bool initialvisibility() const;
  void set_initialvisibility(bool value);

  // @@protoc_insertion_point(class_scope:atom.proto.Camera)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::internal::ArenaStringPtr name_;
  ::atom::proto::Vector3* position_;
  ::atom::proto::Vector3* target_;
  ::atom::proto::Vector3* up_;
  float fieldofview_;
  float aspectratio_;
  float nearplane_;
  float farplane_;
  bool initialvisibility_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_Camera_2eproto();
  friend void protobuf_AssignDesc_Camera_2eproto();
  friend void protobuf_ShutdownFile_Camera_2eproto();

  void InitAsDefaultInstance();
  static Camera* default_instance_;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// Camera

// optional string Name = 1;
inline void Camera::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Camera::name() const {
  // @@protoc_insertion_point(field_get:atom.proto.Camera.Name)
  return name_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Camera::set_name(const ::std::string& value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:atom.proto.Camera.Name)
}
inline void Camera::set_name(const char* value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:atom.proto.Camera.Name)
}
inline void Camera::set_name(const char* value, size_t size) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:atom.proto.Camera.Name)
}
inline ::std::string* Camera::mutable_name() {
  
  // @@protoc_insertion_point(field_mutable:atom.proto.Camera.Name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Camera::release_name() {
  
  return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Camera::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    
  } else {
    
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:atom.proto.Camera.Name)
}

// optional .atom.proto.Vector3 Position = 2;
inline bool Camera::has_position() const {
  return !_is_default_instance_ && position_ != NULL;
}
inline void Camera::clear_position() {
  if (GetArenaNoVirtual() == NULL && position_ != NULL) delete position_;
  position_ = NULL;
}
inline const ::atom::proto::Vector3& Camera::position() const {
  // @@protoc_insertion_point(field_get:atom.proto.Camera.Position)
  return position_ != NULL ? *position_ : *default_instance_->position_;
}
inline ::atom::proto::Vector3* Camera::mutable_position() {
  
  if (position_ == NULL) {
    position_ = new ::atom::proto::Vector3;
  }
  // @@protoc_insertion_point(field_mutable:atom.proto.Camera.Position)
  return position_;
}
inline ::atom::proto::Vector3* Camera::release_position() {
  
  ::atom::proto::Vector3* temp = position_;
  position_ = NULL;
  return temp;
}
inline void Camera::set_allocated_position(::atom::proto::Vector3* position) {
  delete position_;
  position_ = position;
  if (position) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:atom.proto.Camera.Position)
}

// optional .atom.proto.Vector3 Target = 3;
inline bool Camera::has_target() const {
  return !_is_default_instance_ && target_ != NULL;
}
inline void Camera::clear_target() {
  if (GetArenaNoVirtual() == NULL && target_ != NULL) delete target_;
  target_ = NULL;
}
inline const ::atom::proto::Vector3& Camera::target() const {
  // @@protoc_insertion_point(field_get:atom.proto.Camera.Target)
  return target_ != NULL ? *target_ : *default_instance_->target_;
}
inline ::atom::proto::Vector3* Camera::mutable_target() {
  
  if (target_ == NULL) {
    target_ = new ::atom::proto::Vector3;
  }
  // @@protoc_insertion_point(field_mutable:atom.proto.Camera.Target)
  return target_;
}
inline ::atom::proto::Vector3* Camera::release_target() {
  
  ::atom::proto::Vector3* temp = target_;
  target_ = NULL;
  return temp;
}
inline void Camera::set_allocated_target(::atom::proto::Vector3* target) {
  delete target_;
  target_ = target;
  if (target) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:atom.proto.Camera.Target)
}

// optional .atom.proto.Vector3 Up = 4;
inline bool Camera::has_up() const {
  return !_is_default_instance_ && up_ != NULL;
}
inline void Camera::clear_up() {
  if (GetArenaNoVirtual() == NULL && up_ != NULL) delete up_;
  up_ = NULL;
}
inline const ::atom::proto::Vector3& Camera::up() const {
  // @@protoc_insertion_point(field_get:atom.proto.Camera.Up)
  return up_ != NULL ? *up_ : *default_instance_->up_;
}
inline ::atom::proto::Vector3* Camera::mutable_up() {
  
  if (up_ == NULL) {
    up_ = new ::atom::proto::Vector3;
  }
  // @@protoc_insertion_point(field_mutable:atom.proto.Camera.Up)
  return up_;
}
inline ::atom::proto::Vector3* Camera::release_up() {
  
  ::atom::proto::Vector3* temp = up_;
  up_ = NULL;
  return temp;
}
inline void Camera::set_allocated_up(::atom::proto::Vector3* up) {
  delete up_;
  up_ = up;
  if (up) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:atom.proto.Camera.Up)
}

// optional float FieldOfView = 5;
inline void Camera::clear_fieldofview() {
  fieldofview_ = 0;
}
inline float Camera::fieldofview() const {
  // @@protoc_insertion_point(field_get:atom.proto.Camera.FieldOfView)
  return fieldofview_;
}
inline void Camera::set_fieldofview(float value) {
  
  fieldofview_ = value;
  // @@protoc_insertion_point(field_set:atom.proto.Camera.FieldOfView)
}

// optional float AspectRatio = 6;
inline void Camera::clear_aspectratio() {
  aspectratio_ = 0;
}
inline float Camera::aspectratio() const {
  // @@protoc_insertion_point(field_get:atom.proto.Camera.AspectRatio)
  return aspectratio_;
}
inline void Camera::set_aspectratio(float value) {
  
  aspectratio_ = value;
  // @@protoc_insertion_point(field_set:atom.proto.Camera.AspectRatio)
}

// optional float NearPlane = 7;
inline void Camera::clear_nearplane() {
  nearplane_ = 0;
}
inline float Camera::nearplane() const {
  // @@protoc_insertion_point(field_get:atom.proto.Camera.NearPlane)
  return nearplane_;
}
inline void Camera::set_nearplane(float value) {
  
  nearplane_ = value;
  // @@protoc_insertion_point(field_set:atom.proto.Camera.NearPlane)
}

// optional float FarPlane = 8;
inline void Camera::clear_farplane() {
  farplane_ = 0;
}
inline float Camera::farplane() const {
  // @@protoc_insertion_point(field_get:atom.proto.Camera.FarPlane)
  return farplane_;
}
inline void Camera::set_farplane(float value) {
  
  farplane_ = value;
  // @@protoc_insertion_point(field_set:atom.proto.Camera.FarPlane)
}

// optional bool InitialVisibility = 9;
inline void Camera::clear_initialvisibility() {
  initialvisibility_ = false;
}
inline bool Camera::initialvisibility() const {
  // @@protoc_insertion_point(field_get:atom.proto.Camera.InitialVisibility)
  return initialvisibility_;
}
inline void Camera::set_initialvisibility(bool value) {
  
  initialvisibility_ = value;
  // @@protoc_insertion_point(field_set:atom.proto.Camera.InitialVisibility)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace proto
}  // namespace atom

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_Camera_2eproto__INCLUDED