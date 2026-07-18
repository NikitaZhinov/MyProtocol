#pragma once

#include <boost/asio.hpp>
#include <protocol/protocol.hpp>

class Network final {
    boost::asio::io_context io_ctx_;
    boost::asio::ip::tcp::resolver resolver_ { io_ctx_ };
    boost::asio::ip::tcp::socket socket_ { io_ctx_ };

    std::vector<std::uint8_t> secret_key_;

    Network();

public:
    static Network& getInstance();

    void send(const protocol::serialization::utils::serialize_data_t& data);

    protocol::serialization::utils::serialize_data_t wait();
};
