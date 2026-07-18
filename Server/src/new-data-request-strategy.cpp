#include "strategy/new-data-request-strategy.hpp"

strategy::NewDataRequestStrategy::NewDataRequestStrategy(
    repository::Repository& repository) :
    RequestStrategy(protocol::request::RequestType::NewData, repository) {}

protocol::response::ResponseFactory::response_ptr
strategy::NewDataRequestStrategy::getResponse(
    protocol::request::RequestFactory::request_ptr request,
    SessionParameters& session_parameters) {
    auto& repository = getRepository();

    auto new_data_request =
        std::static_pointer_cast<protocol::request::NewDataRequest>(request);

    auto data_id =
        repository.add(new_data_request->getUserId(), new_data_request->getData());

    protocol::response::NewDataResponseFactory factory;

    auto response = factory.create(data_id);

    return response;
}
