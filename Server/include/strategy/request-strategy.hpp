#pragma once

#include "repository/repository.hpp"
#include "session-parameters.hpp"

#include <protocol/protocol.hpp>

namespace strategy {
    class RequestStrategy {
        protocol::request::RequestType type_;

        repository::Repository& repository_;

    public:
        RequestStrategy(protocol::request::RequestType type,
                        repository::Repository& repository);

        virtual ~RequestStrategy() {}

        virtual protocol::response::ResponseFactory::response_ptr
        getResponse(protocol::request::RequestFactory::request_ptr request,
                    SessionParameters& session_parameters) = 0;

        protocol::request::RequestType getType() const;

        repository::Repository& getRepository();
        const repository::Repository& getRepository() const;
    };
}  // namespace strategy
