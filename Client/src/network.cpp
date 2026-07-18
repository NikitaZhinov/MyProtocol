#include "network.hpp"

Network::Network() {
    boost::asio::connect(socket_, resolver_.resolve("127.0.0.1", "6789"));

    std::size_t connect_response_size = 0;
    boost::asio::read(socket_, boost::asio::buffer(&connect_response_size,
                                                   sizeof(connect_response_size)));

    protocol::serialization::utils::serialize_data_t serialized_connect_response(
        connect_response_size, 0);
    boost::asio::read(socket_, boost::asio::buffer(serialized_connect_response));

    protocol::deserialization::ConnectResponseDeserialization
        connect_response_deserializer;
    auto connect_response_ptr =
        connect_response_deserializer.deserialize(serialized_connect_response);

    auto connect_response = std::static_pointer_cast<protocol::response::ConnectResponse>(
        connect_response_ptr);

    auto server_public_key = connect_response->getPublicKey();

    secret_key_ = protocol::encryption::aes::generateKey();

    protocol::request::TakeKeyRequestFactory take_key_request_factory;
    auto take_key_request = take_key_request_factory.create(secret_key_);

    protocol::serialization::TakeKeyRequestSerialization take_key_request_serializer;
    auto serialized_take_key_request =
        take_key_request_serializer.serialize(take_key_request);

    auto encrypted_take_key_request = protocol::encryption::rsa::encrypt(
        serialized_take_key_request, server_public_key);

    std::uint64_t take_key_request_size = encrypted_take_key_request.size();
    boost::asio::write(socket_, boost::asio::buffer(&take_key_request_size,
                                                    sizeof(take_key_request_size)));
    boost::asio::write(socket_, boost::asio::buffer(encrypted_take_key_request));
}

Network& Network::getInstance() {
    static Network instance;
    return instance;
}

void Network::send(const protocol::serialization::utils::serialize_data_t& data) {
    auto encrypted_data = protocol::encryption::aes::encrypt(data, secret_key_);
    std::uint64_t data_size = encrypted_data.size();

    boost::asio::write(socket_, boost::asio::buffer(&data_size, sizeof(data_size)));
    boost::asio::write(socket_, boost::asio::buffer(encrypted_data));
}

protocol::serialization::utils::serialize_data_t Network::wait() {
    std::uint64_t data_size = 0;
    boost::asio::read(socket_, boost::asio::buffer(&data_size, sizeof(data_size)));

    protocol::serialization::utils::serialize_data_t encrypted_data(data_size, 0);
    boost::asio::read(socket_, boost::asio::buffer(encrypted_data));

    auto data = protocol::encryption::aes::decrypt(encrypted_data, secret_key_);

    return data;
}
