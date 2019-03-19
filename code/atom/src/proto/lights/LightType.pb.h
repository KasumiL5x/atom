// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: lights/LightType.proto

#ifndef PROTOBUF_lights_2fLightType_2eproto__INCLUDED
#define PROTOBUF_lights_2fLightType_2eproto__INCLUDED

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
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_enum_reflection.h>
// @@protoc_insertion_point(includes)

namespace atom {
namespace proto {
namespace lights {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_lights_2fLightType_2eproto();
void protobuf_AssignDesc_lights_2fLightType_2eproto();
void protobuf_ShutdownFile_lights_2fLightType_2eproto();


enum LightType {
  kLightTypeAmbient = 0,
  kLightTypeDirectional = 1,
  kLightTypeSpot = 2,
  kLightTypePoint = 3,
  LightType_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  LightType_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool LightType_IsValid(int value);
const LightType LightType_MIN = kLightTypeAmbient;
const LightType LightType_MAX = kLightTypePoint;
const int LightType_ARRAYSIZE = LightType_MAX + 1;

const ::google::protobuf::EnumDescriptor* LightType_descriptor();
inline const ::std::string& LightType_Name(LightType value) {
  return ::google::protobuf::internal::NameOfEnum(
    LightType_descriptor(), value);
}
inline bool LightType_Parse(
    const ::std::string& name, LightType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<LightType>(
    LightType_descriptor(), name, value);
}
// ===================================================================


// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace lights
}  // namespace proto
}  // namespace atom

#ifndef SWIG
namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::atom::proto::lights::LightType> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::atom::proto::lights::LightType>() {
  return ::atom::proto::lights::LightType_descriptor();
}

}  // namespace protobuf
}  // namespace google
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_lights_2fLightType_2eproto__INCLUDED
