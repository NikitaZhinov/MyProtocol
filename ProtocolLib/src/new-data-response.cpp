#include "response/new-data-response.hpp"

using namespace protocol;

NewDataResponse::NewDataResponse() : Response(response::ResponseType::NewData) {}

NewDataResponse::NewDataResponse(std::uint64_t data_id) :
    data_id_(data_id),
    Response(response::ResponseType::NewData) {}

void NewDataResponse::setDataId(std::uint64_t data_id) {
    data_id_ = data_id;
}

std::uint64_t NewDataResponse::getDataId() const {
    return data_id_;
}
