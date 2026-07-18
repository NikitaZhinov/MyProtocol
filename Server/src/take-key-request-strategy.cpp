#include "strategy/take-key-request-strategy.hpp"

strategy::TakeKeyRequestStrategy::TakeKeyRequestStrategy(
    repository::Repository& repository) :
    RequestStrategy(protocol::request::RequestType::TakeKey, repository) {}

protocol::response::ResponseFactory::response_ptr
strategy::TakeKeyRequestStrategy::getResponse(
    protocol::request::RequestFactory::request_ptr request,
    SessionParameters& session_parameters) {
    session_parameters.secret_key_ =
        std::static_pointer_cast<protocol::request::TakeKeyRequest>(request)
            ->getSecretKey();

    return nullptr;
}
