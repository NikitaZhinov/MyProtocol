#include "protocol/response/connect-response.hpp"

protocol::response::ConnectResponse::ConnectResponse() :
    Response(response::ResponseType::Connect) {}

protocol::response::ConnectResponse::ConnectResponse(
    const std::vector<std::uint8_t>& public_key) :
    public_key_(public_key),
    Response(response::ResponseType::Connect) {}

protocol::response::ConnectResponse::ConnectResponse(
    std::vector<std::uint8_t>&& public_key) :
    public_key_(std::move(public_key)),
    Response(response::ResponseType::Connect) {}

void protocol::response::ConnectResponse::setPublicKey(
    const std::vector<std::uint8_t>& public_key) {
    public_key_ = public_key;
}

void protocol::response::ConnectResponse::setPublicKey(
    std::vector<std::uint8_t>&& public_key) {
    public_key_ = std::move(public_key);
}

std::vector<std::uint8_t> protocol::response::ConnectResponse::getPublicKey() const {
    return public_key_;
}
