#include "protocol/protocol.hpp"

#include <gtest/gtest.h>

using namespace protocol;

TEST(SerializationTest, NewDataRequestTest) {
    request::NewDataRequestFactory factory;

    auto message = std::static_pointer_cast<request::NewDataRequest>(
        factory.create(10, "Hello, World!"));

    serialization::NewDataRequestSerialization serializer;

    auto s_msg = serializer.serialize(message);

    std::vector<std::uint8_t> expected { 1,   0,   0,   0,   0,   0,   0,   0,
                                         10,  'H', 'e', 'l', 'l', 'o', ',', ' ',
                                         'W', 'o', 'r', 'l', 'd', '!' };

    ASSERT_EQ(s_msg, expected);
}

TEST(SerializationTest, GetDataRequestTest) {
    request::GetDataRequestFactory factory;

    auto message = std::static_pointer_cast<request::GetDataRequest>(factory.create(10));

    serialization::GetDataRequestSerialization serializer;

    auto s_msg = serializer.serialize(message);

    std::vector<std::uint8_t> expected { 2, 0, 0, 0, 0, 0, 0, 0, 10 };

    ASSERT_EQ(s_msg, expected);
}

TEST(SerializationTest, NewDataResponseTest) {
    response::NewDataResponseFactory factory;

    auto message =
        std::static_pointer_cast<response::NewDataResponse>(factory.create(123));

    serialization::NewDataResponseSerialization serializer;

    auto s_msg = serializer.serialize(message);

    std::vector<std::uint8_t> expected { 1, 0, 0, 0, 0, 0, 0, 0, 123 };

    ASSERT_EQ(s_msg, expected);
}

TEST(SerializationTest, GetDataResponseTest) {
    response::GetDataResponseFactory factory;

    std::vector<std::pair<std::uint64_t, std::string>> data {
        { 0, "Hello" },
        { 1, "World" }
    };

    auto message =
        std::static_pointer_cast<response::GetDataResponse>(factory.create(data));

    serialization::GetDataResponseSerialization serializer;

    auto s_msg = serializer.serialize(message);

    std::vector<std::uint8_t> expected {
        2, 0, 0, 0, 0, 0, 0,   0,   2,   0,   0,   0,    0,   0,   0,   0,   0,   0,   0,
        0, 0, 0, 0, 0, 1, 'H', 'e', 'l', 'l', 'o', '\0', 'W', 'o', 'r', 'l', 'd', '\0'
    };

    ASSERT_EQ(s_msg, expected);
}

TEST(SerializationTest, TakeKeyRequestTest) {
    request::TakeKeyRequestFactory factory;

    auto key = encryption::aes::generateKey();

    auto message = std::static_pointer_cast<request::TakeKeyRequest>(factory.create(key));

    serialization::TakeKeyRequestSerialization serializer;

    auto s_msg = serializer.serialize(message);

    std::vector<std::uint8_t> expected { 0 };
    expected.append_range(key);

    ASSERT_EQ(s_msg, expected);
}

TEST(SerializationTest, ConnectResponseTest) {
    response::ConnectResponseFactory factory;

    auto key = encryption::rsa::generatePairKey();

    auto message = std::static_pointer_cast<response::ConnectResponse>(
        factory.create(key.public_key));

    serialization::ConnectResponseSerialization serializer;

    auto s_msg = serializer.serialize(message);

    std::vector<std::uint8_t> expected { 0 };
    expected.append_range(key.public_key);

    ASSERT_EQ(s_msg, expected);
}
