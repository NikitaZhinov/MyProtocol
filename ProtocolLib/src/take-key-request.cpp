#include "protocol/request/take-key-request.hpp"

protocol::request::TakeKeyRequest::TakeKeyRequest() :
    Request(request::RequestType::TakeKey) {}

protocol::request::TakeKeyRequest::TakeKeyRequest(
    const std::vector<std::uint8_t>& secret_key) :
    secret_key_(secret_key),
    Request(request::RequestType::TakeKey) {}

protocol::request::TakeKeyRequest::TakeKeyRequest(
    std::vector<std::uint8_t>&& secret_key) :
    secret_key_(std::move(secret_key)),
    Request(request::RequestType::TakeKey) {}

void protocol::request::TakeKeyRequest::setSecretKey(
    const std::vector<std::uint8_t>& secret_key) {
    secret_key_ = secret_key;
}

void protocol::request::TakeKeyRequest::setSecretKey(
    std::vector<std::uint8_t>&& secret_key) {
    secret_key_ = std::move(secret_key);
}

std::vector<std::uint8_t> protocol::request::TakeKeyRequest::getSecretKey() const {
    return secret_key_;
}
