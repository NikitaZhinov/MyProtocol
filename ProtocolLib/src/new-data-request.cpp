#include "request/new-data-request.hpp"

#include "request/type.hpp"

using namespace protocol;

NewDataRequest::NewDataRequest() : Request(request::RequestType::NewData) {}

NewDataRequest::NewDataRequest(std::uint64_t user_id, const std::string_view& data) :
    user_id_(user_id),
    data_(data),
    Request(request::RequestType::NewData) {}

void NewDataRequest::setUserId(std::size_t user_id) {
    user_id_ = user_id;
}

void NewDataRequest::setData(const std::string_view& data) {
    data_ = data;
}

std::uint64_t NewDataRequest::getUserId() const {
    return user_id_;
}

std::string NewDataRequest::getData() const {
    return data_;
}
