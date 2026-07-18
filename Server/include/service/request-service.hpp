#pragma once

#include "repository/repository.hpp"
#include "strategy/request-strategy.hpp"
#include "session-parameters.hpp"

namespace service {
    class RequestService final {
        std::vector<std::shared_ptr<strategy::RequestStrategy>> request_strategies_;

        repository::Repository& repository_;

    public:
        RequestService(repository::Repository& repository);

        protocol::response::ResponseFactory::response_ptr
        getResponse(protocol::request::RequestFactory::request_ptr request,
                    SessionParameters& session_parameters);
    };
}  // namespace service
