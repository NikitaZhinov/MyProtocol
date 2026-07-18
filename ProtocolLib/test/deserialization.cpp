#include "protocol/protocol.hpp"

#include <gtest/gtest.h>

using namespace protocol;

TEST(DeserializationTest, NewDataRequestTest) {
    std::vector<std::uint8_t> message { 1,   0,   0,   0,   0,   0,   0,   0,
                                        10,  'H', 'e', 'l', 'l', 'o', ',', ' ',
                                        'W', 'o', 'r', 'l', 'd', '!' };

    deserialization::NewDataRequestDeserialization deserializer;

    auto d_msg = std::static_pointer_cast<request::NewDataRequest>(
        deserializer.deserialize(message));

    ASSERT_EQ(d_msg->getUserId(), 10);
    ASSERT_EQ(d_msg->getData(), "Hello, World!");
}

TEST(DeserializationTest, GetDataRequestTest) {
    std::vector<std::uint8_t> message { 2, 0, 0, 0, 0, 0, 0, 0, 10 };

    deserialization::GetDataRequestDeserialization deserializer;

    auto d_msg = std::static_pointer_cast<request::GetDataRequest>(
        deserializer.deserialize(message));

    ASSERT_EQ(d_msg->getUserId(), 10);
}

TEST(DeserializationTest, NewDataResponseTest) {
    std::vector<std::uint8_t> message { 1, 0, 0, 0, 0, 0, 0, 0, 123 };

    deserialization::NewDataResponseDeserialization deserializer;

    auto d_msg = std::static_pointer_cast<response::NewDataResponse>(
        deserializer.deserialize(message));

    ASSERT_EQ(d_msg->getDataId(), 123);
}

TEST(DeserializationTest, GetDataResponseTest) {
    std::vector<std::uint8_t> message { 2,    0,   0,   0,   0,   0,   0,   0,   2,   0,
                                        0,    0,   0,   0,   0,   0,   0,   0,   0,   0,
                                        0,    0,   0,   0,   1,   'H', 'e', 'l', 'l', 'o',
                                        '\0', 'W', 'o', 'r', 'l', 'd', '\0' };

    deserialization::GetDataResponseDeserialization deserializer;

    auto d_msg = std::static_pointer_cast<response::GetDataResponse>(
        deserializer.deserialize(message));

    std::vector<std::uint64_t> expected_ids { 0, 1 };
    std::vector<std::string> expected_data { "Hello", "World" };

    ASSERT_EQ(d_msg->getAmountData(), 2);
    ASSERT_EQ(d_msg->getDataIds(), expected_ids);
    ASSERT_EQ(d_msg->getData(), expected_data);
}

TEST(DeserializationTest, TakeKeyRequestTest) {
    std::vector<std::uint8_t> message { 0 };

    auto key = encryption::aes::generateKey();
    message.append_range(key);

    deserialization::TakeKeyRequestDeserialization deserializer;

    auto d_msg = std::static_pointer_cast<request::TakeKeyRequest>(
        deserializer.deserialize(message));

    ASSERT_EQ(d_msg->getSecretKey(), key);
}

TEST(DeserializationTest, ConnectResponseTest) {
    std::vector<std::uint8_t> message { 0 };

    auto key = encryption::rsa::generatePairKey();
    message.append_range(key.public_key);

    deserialization::ConnectResponseDeserialization deserializer;

    auto d_msg = std::static_pointer_cast<response::ConnectResponse>(
        deserializer.deserialize(message));

    ASSERT_EQ(d_msg->getPublicKey(), key.public_key);
}
