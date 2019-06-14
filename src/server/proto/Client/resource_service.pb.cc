// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: resource_service.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "resource_service.pb.h"

#include <algorithm>
#include <utility>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
#include "Log.h"
#include "Errors.h"
#include "BattlenetRpcErrorCodes.h"
// @@protoc_insertion_point(includes)

namespace bgs {
namespace protocol {
namespace resources {
namespace v1 {

namespace {

const ::google::protobuf::Descriptor* ContentHandleRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ContentHandleRequest_reflection_ = NULL;
const ::google::protobuf::ServiceDescriptor* ResourcesService_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_resource_5fservice_2eproto() {
  protobuf_AddDesc_resource_5fservice_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "resource_service.proto");
  GOOGLE_CHECK(file != NULL);
  ContentHandleRequest_descriptor_ = file->message_type(0);
  static const int ContentHandleRequest_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ContentHandleRequest, program_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ContentHandleRequest, stream_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ContentHandleRequest, version_),
  };
  ContentHandleRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ContentHandleRequest_descriptor_,
      ContentHandleRequest::default_instance_,
      ContentHandleRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ContentHandleRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ContentHandleRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ContentHandleRequest));
  ResourcesService_descriptor_ = file->service(0);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_resource_5fservice_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ContentHandleRequest_descriptor_, &ContentHandleRequest::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_resource_5fservice_2eproto() {
  delete ContentHandleRequest::default_instance_;
  delete ContentHandleRequest_reflection_;
}

void protobuf_AddDesc_resource_5fservice_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::bgs::protocol::protobuf_AddDesc_content_5fhandle_5ftypes_2eproto();
  ::bgs::protocol::protobuf_AddDesc_rpc_5ftypes_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\026resource_service.proto\022\031bgs.protocol.r"
    "esources.v1\032\032content_handle_types.proto\032"
    "\017rpc_types.proto\"\\\n\024ContentHandleRequest"
    "\022\017\n\007program\030\001 \002(\007\022\016\n\006stream\030\002 \002(\007\022\033\n\007ver"
    "sion\030\003 \001(\007:\n1701729619:\006\202\371+\002\010\0012\253\001\n\020Resou"
    "rcesService\022h\n\020GetContentHandle\022/.bgs.pr"
    "otocol.resources.v1.ContentHandleRequest"
    "\032\033.bgs.protocol.ContentHandle\"\006\202\371+\002\010\001\032-\202"
    "\371+#\n!bnet.protocol.resources.Resources\212\371"
    "+\002\020\001B\005H\001\200\001\000", 371);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "resource_service.proto", &protobuf_RegisterTypes);
  ContentHandleRequest::default_instance_ = new ContentHandleRequest();
  ContentHandleRequest::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_resource_5fservice_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_resource_5fservice_2eproto {
  StaticDescriptorInitializer_resource_5fservice_2eproto() {
    protobuf_AddDesc_resource_5fservice_2eproto();
  }
} static_descriptor_initializer_resource_5fservice_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int ContentHandleRequest::kProgramFieldNumber;
const int ContentHandleRequest::kStreamFieldNumber;
const int ContentHandleRequest::kVersionFieldNumber;
#endif  // !_MSC_VER

ContentHandleRequest::ContentHandleRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.resources.v1.ContentHandleRequest)
}

void ContentHandleRequest::InitAsDefaultInstance() {
}

ContentHandleRequest::ContentHandleRequest(const ContentHandleRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.resources.v1.ContentHandleRequest)
}

void ContentHandleRequest::SharedCtor() {
  _cached_size_ = 0;
  program_ = 0u;
  stream_ = 0u;
  version_ = 1701729619u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ContentHandleRequest::~ContentHandleRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.resources.v1.ContentHandleRequest)
  SharedDtor();
}

void ContentHandleRequest::SharedDtor() {
  if (this != default_instance_) {
  }
}

void ContentHandleRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ContentHandleRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ContentHandleRequest_descriptor_;
}

const ContentHandleRequest& ContentHandleRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_resource_5fservice_2eproto();
  return *default_instance_;
}

ContentHandleRequest* ContentHandleRequest::default_instance_ = NULL;

ContentHandleRequest* ContentHandleRequest::New() const {
  return new ContentHandleRequest;
}

void ContentHandleRequest::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<ContentHandleRequest*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 7) {
    ZR_(program_, stream_);
    version_ = 1701729619u;
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ContentHandleRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.resources.v1.ContentHandleRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required fixed32 program = 1;
      case 1: {
        if (tag == 13) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &program_)));
          set_has_program();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(21)) goto parse_stream;
        break;
      }

      // required fixed32 stream = 2;
      case 2: {
        if (tag == 21) {
         parse_stream:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &stream_)));
          set_has_stream();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(29)) goto parse_version;
        break;
      }

      // optional fixed32 version = 3 [default = 1701729619];
      case 3: {
        if (tag == 29) {
         parse_version:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &version_)));
          set_has_version();
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
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:bgs.protocol.resources.v1.ContentHandleRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.resources.v1.ContentHandleRequest)
  return false;
#undef DO_
}

void ContentHandleRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.resources.v1.ContentHandleRequest)
  // required fixed32 program = 1;
  if (has_program()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(1, this->program(), output);
  }

  // required fixed32 stream = 2;
  if (has_stream()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(2, this->stream(), output);
  }

  // optional fixed32 version = 3 [default = 1701729619];
  if (has_version()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(3, this->version(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.resources.v1.ContentHandleRequest)
}

::google::protobuf::uint8* ContentHandleRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.resources.v1.ContentHandleRequest)
  // required fixed32 program = 1;
  if (has_program()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(1, this->program(), target);
  }

  // required fixed32 stream = 2;
  if (has_stream()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(2, this->stream(), target);
  }

  // optional fixed32 version = 3 [default = 1701729619];
  if (has_version()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(3, this->version(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.resources.v1.ContentHandleRequest)
  return target;
}

int ContentHandleRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required fixed32 program = 1;
    if (has_program()) {
      total_size += 1 + 4;
    }

    // required fixed32 stream = 2;
    if (has_stream()) {
      total_size += 1 + 4;
    }

    // optional fixed32 version = 3 [default = 1701729619];
    if (has_version()) {
      total_size += 1 + 4;
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void ContentHandleRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ContentHandleRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ContentHandleRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ContentHandleRequest::MergeFrom(const ContentHandleRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_program()) {
      set_program(from.program());
    }
    if (from.has_stream()) {
      set_stream(from.stream());
    }
    if (from.has_version()) {
      set_version(from.version());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ContentHandleRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ContentHandleRequest::CopyFrom(const ContentHandleRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ContentHandleRequest::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;

  return true;
}

void ContentHandleRequest::Swap(ContentHandleRequest* other) {
  if (other != this) {
    std::swap(program_, other->program_);
    std::swap(stream_, other->stream_);
    std::swap(version_, other->version_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ContentHandleRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ContentHandleRequest_descriptor_;
  metadata.reflection = ContentHandleRequest_reflection_;
  return metadata;
}


// ===================================================================

ResourcesService::ResourcesService(bool use_original_hash) : service_hash_(use_original_hash ? OriginalHash::value : NameHash::value) {
}

ResourcesService::~ResourcesService() {
}

google::protobuf::ServiceDescriptor const* ResourcesService::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ResourcesService_descriptor_;
}

void ResourcesService::GetContentHandle(::bgs::protocol::resources::v1::ContentHandleRequest const* request, std::function<void(::bgs::protocol::ContentHandle const*)> responseCallback) {
  TC_LOG_DEBUG("service.protobuf", "%s Server called client method ResourcesService.GetContentHandle(bgs.protocol.resources.v1.ContentHandleRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::ContentHandle response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 1, request, std::move(callback));
}

void ResourcesService::CallServerMethod(uint32 token, uint32 methodId, MessageBuffer buffer) {
  switch(methodId) {
    case 1: {
      ::bgs::protocol::resources::v1::ContentHandleRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG("service.protobuf", "%s Failed to parse request for ResourcesService.GetContentHandle server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 1, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }
      TC_LOG_DEBUG("service.protobuf", "%s Client called server method ResourcesService.GetContentHandle(bgs.protocol.resources.v1.ContentHandleRequest{ %s }).",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str());
      std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)> continuation = [token](ServiceBase* service, uint32 status, ::google::protobuf::Message const* response)
      {
        ASSERT(response->GetDescriptor() == ::bgs::protocol::ContentHandle::descriptor());
        ResourcesService* self = static_cast<ResourcesService*>(service);
        TC_LOG_DEBUG("service.protobuf", "%s Client called server method ResourcesService.GetContentHandle() returned bgs.protocol.ContentHandle{ %s } status %u.",
          self->GetCallerInfo().c_str(), response->ShortDebugString().c_str(), status);
        if (!status)
          self->SendResponse(self->service_hash_, 1, token, response);
        else
          self->SendResponse(self->service_hash_, 1, token, status);
      };
      ::bgs::protocol::ContentHandle response;
      uint32 status = HandleGetContentHandle(&request, &response, continuation);
      if (continuation)
        continuation(this, status, &response);
      break;
    }
    default:
      TC_LOG_ERROR("service.protobuf", "Bad method id %u.", methodId);
      SendResponse(service_hash_, methodId, token, ERROR_RPC_INVALID_METHOD);
      break;
    }
}

uint32 ResourcesService::HandleGetContentHandle(::bgs::protocol::resources::v1::ContentHandleRequest const* request, ::bgs::protocol::ContentHandle* response, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& continuation) {
  TC_LOG_ERROR("service.protobuf", "%s Client tried to call not implemented method ResourcesService.GetContentHandle({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace v1
}  // namespace resources
}  // namespace protocol
}  // namespace bgs

// @@protoc_insertion_point(global_scope)
