#include "server.hpp"

Server::Server(boost::asio::io_context& ctx) :
    repository_(ctx, "localhost", "root", "1234", "sibsuti-practice", "data"),
    request_service_(repository_) {}

repository::Repository& Server::getRepository() {
    return repository_;
}

const repository::Repository& Server::getRepository() const {
    return repository_;
}

service::DeserializationRequestService& Server::getDeserializationRequestService() {
    return deserialization_request_service_;
}

const service::DeserializationRequestService&
Server::getDeserializationRequestService() const {
    return deserialization_request_service_;
}

service::RequestService& Server::getRequestService() {
    return request_service_;
}

const service::RequestService& Server::getRequestService() const {
    return request_service_;
}

service::SerializationResponseService& Server::getSerializationResponseService() {
    return serialization_response_service_;
}

const service::SerializationResponseService&
Server::getSerializationResponseService() const {
    return serialization_response_service_;
}
