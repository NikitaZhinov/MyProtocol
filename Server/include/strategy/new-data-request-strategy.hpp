#pragma once

#include "request-strategy.hpp"

namespace strategy {
    class NewDataRequestStrategy final : public RequestStrategy {
    public:
        NewDataRequestStrategy(repository::Repository& repository);

        protocol::response::ResponseFactory::response_ptr
        getResponse(protocol::request::RequestFactory::request_ptr request,
                    SessionParameters& session_parameters) override;
    };
}  // namespace strategy
