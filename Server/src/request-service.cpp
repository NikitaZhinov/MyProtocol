#include "service/request-service.hpp"

#include "strategy/take-key-request-strategy.hpp"
#include "strategy/new-data-request-strategy.hpp"
#include "strategy/get-data-request-strategy.hpp"

service::RequestService::RequestService(repository::Repository& repository) :
    repository_(repository) {
    request_strategies_.emplace_back(
        std::make_shared<strategy::TakeKeyRequestStrategy>(repository_));

    request_strategies_.emplace_back(
        std::make_shared<strategy::NewDataRequestStrategy>(repository_));

    request_strategies_.emplace_back(
        std::make_shared<strategy::GetDataRequestStrategy>(repository_));
}

protocol::response::ResponseFactory::response_ptr service::RequestService::getResponse(
    protocol::request::RequestFactory::request_ptr request,
    SessionParameters& session_parameters) {
    for (auto& strategy : request_strategies_) {
        if (strategy->getType() == request->getType()) {
            return strategy->getResponse(request, session_parameters);
        }
    }

    throw std::runtime_error("undefined request type");
}
