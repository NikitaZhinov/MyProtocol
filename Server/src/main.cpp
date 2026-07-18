#include "session.hpp"

#include <iostream>
#include <format>

using boost::asio::ip::tcp;

static boost::asio::awaitable<void> listener(tcp::acceptor acceptor, Server& server) {
    while (true) {
        std::make_shared<Session>(
            co_await acceptor.async_accept(boost::asio::use_awaitable), std::ref(server))
            ->start();
    }
}

int main(int argc, const char* argv[]) {
    try {
        boost::asio::io_context io_context;

        Server server(io_context);

        boost::asio::co_spawn(
            io_context,
            listener(tcp::acceptor(io_context, { tcp::v4(), 6789 }), std::ref(server)),
            boost::asio::detached);

        boost::asio::signal_set signals(io_context, SIGINT, SIGTERM);
        signals.async_wait([&](auto, auto) { io_context.stop(); });

        io_context.run();
    } catch (const std::exception& ex) {
        std::cerr << std::format("Exception: {}\n", ex.what());
    }
}
