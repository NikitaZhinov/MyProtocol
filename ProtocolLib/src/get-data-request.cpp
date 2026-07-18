#include "protocol/protocol.hpp"

protocol::request::GetDataRequest::GetDataRequest() : Request(RequestType::GetData) {}

protocol::request::GetDataRequest::GetDataRequest(std::uint64_t user_id) :
    user_id_(user_id),
    Request(RequestType::GetData) {}

void protocol::request::GetDataRequest::setUserId(std::uint64_t user_id) {
    user_id_ = user_id;
}

std::uint64_t protocol::request::GetDataRequest::getUserId() const {
    return user_id_;
}
