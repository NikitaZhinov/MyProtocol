#include "strategy/get-data-request-strategy.hpp"

strategy::GetDataRequestStrategy::GetDataRequestStrategy(
    repository::Repository& repository) :
    RequestStrategy(protocol::request::RequestType::GetData, repository) {}

protocol::response::ResponseFactory::response_ptr
strategy::GetDataRequestStrategy::getResponse(
    protocol::request::RequestFactory::request_ptr request,
    SessionParameters& session_parameters) {
    auto& repository = getRepository();

    auto get_data_request =
        std::static_pointer_cast<protocol::request::GetDataRequest>(request);

    auto res = repository.getUserData(get_data_request->getUserId());

    protocol::response::GetDataResponseFactory factory;

    std::vector<std::pair<std::uint64_t, std::string>> response_init;
    response_init.reserve(res.size());

    for (auto& model : res) {
        response_init.emplace_back(model.id, model.data);
    }

    auto response = factory.create(response_init);

    return response;
}
