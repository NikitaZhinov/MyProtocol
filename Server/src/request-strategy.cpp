#include "strategy/request-strategy.hpp"

strategy::RequestStrategy::RequestStrategy(protocol::request::RequestType type,
                                           repository::Repository& repository) :
    type_(type),
    repository_(repository) {}

protocol::request::RequestType strategy::RequestStrategy::getType() const {
    return type_;
}

repository::Repository& strategy::RequestStrategy::getRepository() {
    return repository_;
}

const repository::Repository& strategy::RequestStrategy::getRepository() const {
    return repository_;
}
