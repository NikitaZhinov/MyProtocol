#include "protocol/protocol.hpp"

protocol::response::NewDataResponse::NewDataResponse() :
    Response(ResponseType::NewData) {}

protocol::response::NewDataResponse::NewDataResponse(std::uint64_t data_id) :
    data_id_(data_id),
    Response(ResponseType::NewData) {}

void protocol::response::NewDataResponse::setDataId(std::uint64_t data_id) {
    data_id_ = data_id;
}

std::uint64_t protocol::response::NewDataResponse::getDataId() const {
    return data_id_;
}
