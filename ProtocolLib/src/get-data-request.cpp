#include "request/get-data-request.hpp"

using namespace protocol;

GetDataRequest::GetDataRequest() : Request(request::RequestType::GetData) {}

GetDataRequest::GetDataRequest(std::uint64_t user_id) :
    user_id_(user_id),
    Request(request::RequestType::GetData) {}

void GetDataRequest::setUserId(std::uint64_t user_id) {
    user_id_ = user_id;
}

std::uint64_t GetDataRequest::getUserId() const {
    return user_id_;
}
