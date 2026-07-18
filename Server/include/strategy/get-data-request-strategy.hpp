#pragma once

#include "request-strategy.hpp"

namespace strategy {
    class GetDataRequestStrategy final : public RequestStrategy {
    public:
        GetDataRequestStrategy(repository::Repository& repository);

        protocol::response::ResponseFactory::response_ptr getResponse(protocol::request::RequestFactory::request_ptr request,
                    SessionParameters& session_parameters) override;
    };
}  // namespace strategy
