// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: position.proto

#include "position.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG
namespace position {
constexpr Data3d::Data3d(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : x_(0)
  , y_(0)
  , z_(0){}
struct Data3dDefaultTypeInternal {
  constexpr Data3dDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~Data3dDefaultTypeInternal() {}
  union {
    Data3d _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT Data3dDefaultTypeInternal _Data3d_default_instance_;
constexpr GeneratedPosition::GeneratedPosition(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : position_(nullptr)
  , sensorid_(uint64_t{0u})
  , timestampusec_(uint64_t{0u}){}
struct GeneratedPositionDefaultTypeInternal {
  constexpr GeneratedPositionDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~GeneratedPositionDefaultTypeInternal() {}
  union {
    GeneratedPosition _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT GeneratedPositionDefaultTypeInternal _GeneratedPosition_default_instance_;
}  // namespace position
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_position_2eproto[2];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_position_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_position_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_position_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::position::Data3d, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::position::Data3d, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::position::Data3d, x_),
  PROTOBUF_FIELD_OFFSET(::position::Data3d, y_),
  PROTOBUF_FIELD_OFFSET(::position::Data3d, z_),
  0,
  1,
  2,
  PROTOBUF_FIELD_OFFSET(::position::GeneratedPosition, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::position::GeneratedPosition, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::position::GeneratedPosition, sensorid_),
  PROTOBUF_FIELD_OFFSET(::position::GeneratedPosition, timestampusec_),
  PROTOBUF_FIELD_OFFSET(::position::GeneratedPosition, position_),
  1,
  2,
  0,
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 9, -1, sizeof(::position::Data3d)},
  { 12, 21, -1, sizeof(::position::GeneratedPosition)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::position::_Data3d_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::position::_GeneratedPosition_default_instance_),
};

const char descriptor_table_protodef_position_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\016position.proto\022\010position\")\n\006Data3d\022\t\n\001"
  "x\030\001 \002(\002\022\t\n\001y\030\002 \002(\002\022\t\n\001z\030\003 \002(\002\"`\n\021Generat"
  "edPosition\022\020\n\010sensorId\030\001 \002(\004\022\025\n\rtimeStam"
  "pUsec\030\002 \002(\004\022\"\n\010position\030\003 \002(\0132\020.position"
  ".Data3d"
  ;
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_position_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_position_2eproto = {
  false, false, 167, descriptor_table_protodef_position_2eproto, "position.proto", 
  &descriptor_table_position_2eproto_once, nullptr, 0, 2,
  schemas, file_default_instances, TableStruct_position_2eproto::offsets,
  file_level_metadata_position_2eproto, file_level_enum_descriptors_position_2eproto, file_level_service_descriptors_position_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable* descriptor_table_position_2eproto_getter() {
  return &descriptor_table_position_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_position_2eproto(&descriptor_table_position_2eproto);
namespace position {

// ===================================================================

class Data3d::_Internal {
 public:
  using HasBits = decltype(std::declval<Data3d>()._has_bits_);
  static void set_has_x(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static void set_has_y(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
  static void set_has_z(HasBits* has_bits) {
    (*has_bits)[0] |= 4u;
  }
  static bool MissingRequiredFields(const HasBits& has_bits) {
    return ((has_bits[0] & 0x00000007) ^ 0x00000007) != 0;
  }
};

Data3d::Data3d(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:position.Data3d)
}
Data3d::Data3d(const Data3d& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::memcpy(&x_, &from.x_,
    static_cast<size_t>(reinterpret_cast<char*>(&z_) -
    reinterpret_cast<char*>(&x_)) + sizeof(z_));
  // @@protoc_insertion_point(copy_constructor:position.Data3d)
}

void Data3d::SharedCtor() {
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&x_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&z_) -
    reinterpret_cast<char*>(&x_)) + sizeof(z_));
}

Data3d::~Data3d() {
  // @@protoc_insertion_point(destructor:position.Data3d)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void Data3d::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void Data3d::ArenaDtor(void* object) {
  Data3d* _this = reinterpret_cast< Data3d* >(object);
  (void)_this;
}
void Data3d::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void Data3d::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void Data3d::Clear() {
// @@protoc_insertion_point(message_clear_start:position.Data3d)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000007u) {
    ::memset(&x_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&z_) -
        reinterpret_cast<char*>(&x_)) + sizeof(z_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Data3d::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // required float x = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 13)) {
          _Internal::set_has_x(&has_bits);
          x_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else
          goto handle_unusual;
        continue;
      // required float y = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 21)) {
          _Internal::set_has_y(&has_bits);
          y_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else
          goto handle_unusual;
        continue;
      // required float z = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 29)) {
          _Internal::set_has_z(&has_bits);
          z_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  _has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* Data3d::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:position.Data3d)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required float x = 1;
  if (cached_has_bits & 0x00000001u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(1, this->_internal_x(), target);
  }

  // required float y = 2;
  if (cached_has_bits & 0x00000002u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(2, this->_internal_y(), target);
  }

  // required float z = 3;
  if (cached_has_bits & 0x00000004u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(3, this->_internal_z(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:position.Data3d)
  return target;
}

size_t Data3d::RequiredFieldsByteSizeFallback() const {
// @@protoc_insertion_point(required_fields_byte_size_fallback_start:position.Data3d)
  size_t total_size = 0;

  if (_internal_has_x()) {
    // required float x = 1;
    total_size += 1 + 4;
  }

  if (_internal_has_y()) {
    // required float y = 2;
    total_size += 1 + 4;
  }

  if (_internal_has_z()) {
    // required float z = 3;
    total_size += 1 + 4;
  }

  return total_size;
}
size_t Data3d::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:position.Data3d)
  size_t total_size = 0;

  if (((_has_bits_[0] & 0x00000007) ^ 0x00000007) == 0) {  // All required fields are present.
    // required float x = 1;
    total_size += 1 + 4;

    // required float y = 2;
    total_size += 1 + 4;

    // required float z = 3;
    total_size += 1 + 4;

  } else {
    total_size += RequiredFieldsByteSizeFallback();
  }
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Data3d::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    Data3d::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Data3d::GetClassData() const { return &_class_data_; }

void Data3d::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<Data3d *>(to)->MergeFrom(
      static_cast<const Data3d &>(from));
}


void Data3d::MergeFrom(const Data3d& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:position.Data3d)
  GOOGLE_DCHECK_NE(&from, this);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x00000007u) {
    if (cached_has_bits & 0x00000001u) {
      x_ = from.x_;
    }
    if (cached_has_bits & 0x00000002u) {
      y_ = from.y_;
    }
    if (cached_has_bits & 0x00000004u) {
      z_ = from.z_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Data3d::CopyFrom(const Data3d& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:position.Data3d)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Data3d::IsInitialized() const {
  if (_Internal::MissingRequiredFields(_has_bits_)) return false;
  return true;
}

void Data3d::InternalSwap(Data3d* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Data3d, z_)
      + sizeof(Data3d::z_)
      - PROTOBUF_FIELD_OFFSET(Data3d, x_)>(
          reinterpret_cast<char*>(&x_),
          reinterpret_cast<char*>(&other->x_));
}

::PROTOBUF_NAMESPACE_ID::Metadata Data3d::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_position_2eproto_getter, &descriptor_table_position_2eproto_once,
      file_level_metadata_position_2eproto[0]);
}

// ===================================================================

class GeneratedPosition::_Internal {
 public:
  using HasBits = decltype(std::declval<GeneratedPosition>()._has_bits_);
  static void set_has_sensorid(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
  static void set_has_timestampusec(HasBits* has_bits) {
    (*has_bits)[0] |= 4u;
  }
  static const ::position::Data3d& position(const GeneratedPosition* msg);
  static void set_has_position(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static bool MissingRequiredFields(const HasBits& has_bits) {
    return ((has_bits[0] & 0x00000007) ^ 0x00000007) != 0;
  }
};

const ::position::Data3d&
GeneratedPosition::_Internal::position(const GeneratedPosition* msg) {
  return *msg->position_;
}
GeneratedPosition::GeneratedPosition(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:position.GeneratedPosition)
}
GeneratedPosition::GeneratedPosition(const GeneratedPosition& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  if (from._internal_has_position()) {
    position_ = new ::position::Data3d(*from.position_);
  } else {
    position_ = nullptr;
  }
  ::memcpy(&sensorid_, &from.sensorid_,
    static_cast<size_t>(reinterpret_cast<char*>(&timestampusec_) -
    reinterpret_cast<char*>(&sensorid_)) + sizeof(timestampusec_));
  // @@protoc_insertion_point(copy_constructor:position.GeneratedPosition)
}

void GeneratedPosition::SharedCtor() {
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&position_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&timestampusec_) -
    reinterpret_cast<char*>(&position_)) + sizeof(timestampusec_));
}

GeneratedPosition::~GeneratedPosition() {
  // @@protoc_insertion_point(destructor:position.GeneratedPosition)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void GeneratedPosition::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  if (this != internal_default_instance()) delete position_;
}

void GeneratedPosition::ArenaDtor(void* object) {
  GeneratedPosition* _this = reinterpret_cast< GeneratedPosition* >(object);
  (void)_this;
}
void GeneratedPosition::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void GeneratedPosition::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void GeneratedPosition::Clear() {
// @@protoc_insertion_point(message_clear_start:position.GeneratedPosition)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    GOOGLE_DCHECK(position_ != nullptr);
    position_->Clear();
  }
  if (cached_has_bits & 0x00000006u) {
    ::memset(&sensorid_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&timestampusec_) -
        reinterpret_cast<char*>(&sensorid_)) + sizeof(timestampusec_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* GeneratedPosition::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // required uint64 sensorId = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          _Internal::set_has_sensorid(&has_bits);
          sensorid_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // required uint64 timeStampUsec = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          _Internal::set_has_timestampusec(&has_bits);
          timestampusec_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // required .position.Data3d position = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 26)) {
          ptr = ctx->ParseMessage(_internal_mutable_position(), ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  _has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* GeneratedPosition::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:position.GeneratedPosition)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required uint64 sensorId = 1;
  if (cached_has_bits & 0x00000002u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt64ToArray(1, this->_internal_sensorid(), target);
  }

  // required uint64 timeStampUsec = 2;
  if (cached_has_bits & 0x00000004u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt64ToArray(2, this->_internal_timestampusec(), target);
  }

  // required .position.Data3d position = 3;
  if (cached_has_bits & 0x00000001u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        3, _Internal::position(this), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:position.GeneratedPosition)
  return target;
}

size_t GeneratedPosition::RequiredFieldsByteSizeFallback() const {
// @@protoc_insertion_point(required_fields_byte_size_fallback_start:position.GeneratedPosition)
  size_t total_size = 0;

  if (_internal_has_position()) {
    // required .position.Data3d position = 3;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *position_);
  }

  if (_internal_has_sensorid()) {
    // required uint64 sensorId = 1;
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt64SizePlusOne(this->_internal_sensorid());
  }

  if (_internal_has_timestampusec()) {
    // required uint64 timeStampUsec = 2;
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt64SizePlusOne(this->_internal_timestampusec());
  }

  return total_size;
}
size_t GeneratedPosition::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:position.GeneratedPosition)
  size_t total_size = 0;

  if (((_has_bits_[0] & 0x00000007) ^ 0x00000007) == 0) {  // All required fields are present.
    // required .position.Data3d position = 3;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *position_);

    // required uint64 sensorId = 1;
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt64SizePlusOne(this->_internal_sensorid());

    // required uint64 timeStampUsec = 2;
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt64SizePlusOne(this->_internal_timestampusec());

  } else {
    total_size += RequiredFieldsByteSizeFallback();
  }
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData GeneratedPosition::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    GeneratedPosition::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GeneratedPosition::GetClassData() const { return &_class_data_; }

void GeneratedPosition::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<GeneratedPosition *>(to)->MergeFrom(
      static_cast<const GeneratedPosition &>(from));
}


void GeneratedPosition::MergeFrom(const GeneratedPosition& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:position.GeneratedPosition)
  GOOGLE_DCHECK_NE(&from, this);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x00000007u) {
    if (cached_has_bits & 0x00000001u) {
      _internal_mutable_position()->::position::Data3d::MergeFrom(from._internal_position());
    }
    if (cached_has_bits & 0x00000002u) {
      sensorid_ = from.sensorid_;
    }
    if (cached_has_bits & 0x00000004u) {
      timestampusec_ = from.timestampusec_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void GeneratedPosition::CopyFrom(const GeneratedPosition& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:position.GeneratedPosition)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GeneratedPosition::IsInitialized() const {
  if (_Internal::MissingRequiredFields(_has_bits_)) return false;
  if (_internal_has_position()) {
    if (!position_->IsInitialized()) return false;
  }
  return true;
}

void GeneratedPosition::InternalSwap(GeneratedPosition* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(GeneratedPosition, timestampusec_)
      + sizeof(GeneratedPosition::timestampusec_)
      - PROTOBUF_FIELD_OFFSET(GeneratedPosition, position_)>(
          reinterpret_cast<char*>(&position_),
          reinterpret_cast<char*>(&other->position_));
}

::PROTOBUF_NAMESPACE_ID::Metadata GeneratedPosition::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_position_2eproto_getter, &descriptor_table_position_2eproto_once,
      file_level_metadata_position_2eproto[1]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace position
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::position::Data3d* Arena::CreateMaybeMessage< ::position::Data3d >(Arena* arena) {
  return Arena::CreateMessageInternal< ::position::Data3d >(arena);
}
template<> PROTOBUF_NOINLINE ::position::GeneratedPosition* Arena::CreateMaybeMessage< ::position::GeneratedPosition >(Arena* arena) {
  return Arena::CreateMessageInternal< ::position::GeneratedPosition >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>