#include "session.hpp"

#include <print>
#include <iostream>

using boost::asio::awaitable;
using boost::asio::use_awaitable;

awaitable<void> Session::reader() {
    try {
        for (protocol::serialization::utils::serialize_data_t request;;) {
            std::uint64_t request_size = 0;
            co_await boost::asio::async_read(
                socket_, boost::asio::buffer(&request_size, sizeof(request_size)),
                use_awaitable);

            request.resize(request_size);

            co_await boost::asio::async_read(socket_, boost::asio::buffer(request),
                                             use_awaitable);

            std::println("New request");

            std::vector<std::uint8_t> decryption_request;

            if (parameters_.secret_key_.empty()) {
                decryption_request = protocol::encryption::rsa::decrypt(
                    request, parameters_.key_pair_.private_key);
            } else {
                decryption_request =
                    protocol::encryption::aes::decrypt(request, parameters_.secret_key_);
            }

            auto deserialized_request =
                server_.getDeserializationRequestService().deserializationRequest(
                    decryption_request);

            auto response = server_.getRequestService().getResponse(deserialized_request,
                                                                    parameters_);

            if (response) {
                auto serialized_response =
                    server_.getSerializationResponseService().serializationResponse(
                        response);

                response_ = protocol::encryption::aes::encrypt(serialized_response,
                                                               parameters_.secret_key_);

                timer_.cancel_one();
            }

            request.clear();
        }
    } catch (std::exception& ex) {
        std::cerr << std::format("Exception: {}\n", ex.what());
        stop();
    }
}

awaitable<void> Session::writer() {
    try {
        while (socket_.is_open()) {
            if (response_.empty()) {
                boost::system::error_code ec;
                co_await timer_.async_wait(redirect_error(use_awaitable, ec));
            } else {
                std::println("New response");

                auto size = response_.size();
                co_await boost::asio::async_write(
                    socket_, boost::asio::buffer(&size, sizeof(size)), use_awaitable);

                co_await boost::asio::async_write(socket_, boost::asio::buffer(response_),
                                                  use_awaitable);
                response_.clear();
            }
        }
    } catch (std::exception& ex) {
        std::cerr << std::format("Exception: {}\n", ex.what());
        stop();
    }
}

void Session::stop() {
    socket_.close();
    timer_.cancel();
}

void Session::sendPublicKey() {
    parameters_.key_pair_ = protocol::encryption::rsa::generatePairKey();

    protocol::response::ConnectResponseFactory factory;

    auto response = factory.create(parameters_.key_pair_.public_key);

    protocol::serialization::ConnectResponseSerialization serializer;

    response_ = serializer.serialize(response);

    timer_.cancel_one();
}

Session::Session(boost::asio::ip::tcp::socket&& socket, Server& server) :
    socket_(std::move(socket)),
    timer_(socket_.get_executor()),
    server_(server) {
    timer_.expires_at(std::chrono::steady_clock::time_point::max());
}

Session::~Session() {
    std::println("Disconnected client");
}

void Session::start() {
    std::println("Connected new client");

    boost::asio::co_spawn(
        socket_.get_executor(), [self = shared_from_this()] { return self->reader(); },
        boost::asio::detached);

    boost::asio::co_spawn(
        socket_.get_executor(), [self = shared_from_this()] { return self->writer(); },
        boost::asio::detached);

    sendPublicKey();
}
