#include "protocol/protocol.hpp"

using namespace protocol;

protocol::request::NewDataRequest::NewDataRequest() : Request(RequestType::NewData) {}

protocol::request::NewDataRequest::NewDataRequest(std::uint64_t user_id,
                                                  const std::string_view& data) :
    user_id_(user_id),
    data_(data),
    Request(RequestType::NewData) {}

void protocol::request::NewDataRequest::setUserId(std::size_t user_id) {
    user_id_ = user_id;
}

void protocol::request::NewDataRequest::setData(const std::string_view& data) {
    data_ = data;
}

std::uint64_t protocol::request::NewDataRequest::getUserId() const {
    return user_id_;
}

std::string protocol::request::NewDataRequest::getData() const {
    return data_;
}
