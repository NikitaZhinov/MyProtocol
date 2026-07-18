#pragma once

#include "server.hpp"
#include "session-parameters.hpp"

#include <boost/asio.hpp>

class Session : public std::enable_shared_from_this<Session> {
    boost::asio::ip::tcp::socket socket_;
    boost::asio::steady_timer timer_;
    std::vector<std::uint8_t> response_;
    SessionParameters parameters_;

    Server& server_;

    boost::asio::awaitable<void> reader();

    boost::asio::awaitable<void> writer();

    void stop();

    void sendPublicKey();

public:
    Session(boost::asio::ip::tcp::socket&& socket, Server& server);
    ~Session();

    void start();
};
