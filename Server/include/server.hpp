#pragma once

#include "repository/repository.hpp"
#include "service/deserialization-request-service.hpp"
#include "service/request-service.hpp"
#include "service/serialization-response-service.hpp"

class Server final {
    repository::Repository repository_;

    service::DeserializationRequestService deserialization_request_service_;
    service::RequestService request_service_;
    service::SerializationResponseService serialization_response_service_;

public:
    Server(boost::asio::io_context& ctx);

    repository::Repository& getRepository();
    const repository::Repository& getRepository() const;

    service::DeserializationRequestService& getDeserializationRequestService();
    const service::DeserializationRequestService&
    getDeserializationRequestService() const;

    service::RequestService& getRequestService();
    const service::RequestService& getRequestService() const;

    service::SerializationResponseService& getSerializationResponseService();
    const service::SerializationResponseService& getSerializationResponseService() const;
};
