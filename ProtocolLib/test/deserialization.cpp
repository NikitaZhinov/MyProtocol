#include "deserialization/new-data-request-deserialization.hpp"
#include "deserialization/new-data-response-deserialization.hpp"
#include "deserialization/get-data-request-deserialization.hpp"
#include "deserialization/get-data-response-deserialization.hpp"

#include "request/new-data-request.hpp"
#include "request/new-data-request-factory.hpp"
#include "request/get-data-request.hpp"
#include "request/get-data-request-factory.hpp"
#include "response/new-data-response.hpp"
#include "response/new-data-response-factory.hpp"
#include "response/get-data-response.hpp"
#include "response/get-data-response-factory.hpp"

#include <gtest/gtest.h>

using namespace protocol;

TEST(DeserializationTest, NewDataRequestTest) {
    std::vector<std::uint8_t> message { 0,   0,   0,   0,   0,   0,   0,   0,
                                        10,  'H', 'e', 'l', 'l', 'o', ',', ' ',
                                        'W', 'o', 'r', 'l', 'd', '!' };

    NewDataRequestDeserialization deserializer;

    auto d_msg =
        std::static_pointer_cast<NewDataRequest>(deserializer.deserialize(message));

    ASSERT_EQ(d_msg->getUserId(), 10);
    ASSERT_EQ(d_msg->getData(), "Hello, World!");
}

TEST(DeserializationTest, GetDataRequestTest) {
    std::vector<std::uint8_t> message { 1, 0, 0, 0, 0, 0, 0, 0, 10 };

    GetDataRequestDeserialization deserializer;

    auto d_msg =
        std::static_pointer_cast<GetDataRequest>(deserializer.deserialize(message));

    ASSERT_EQ(d_msg->getUserId(), 10);
}

TEST(DeserializationTest, NewDataResponseTest) {
    std::vector<std::uint8_t> message { 0, 0, 0, 0, 0, 0, 0, 0, 123 };

    NewDataResponseDeserialization deserializer;

    auto d_msg =
        std::static_pointer_cast<NewDataResponse>(deserializer.deserialize(message));

    ASSERT_EQ(d_msg->getDataId(), 123);
}

TEST(DeserializationTest, GetDataResponseTest) {
    std::vector<std::uint8_t> message { 1,    0,   0,   0,   0,   0,   0,   0,   2,   0,
                                        0,    0,   0,   0,   0,   0,   0,   0,   0,   0,
                                        0,    0,   0,   0,   1,   'H', 'e', 'l', 'l', 'o',
                                        '\0', 'W', 'o', 'r', 'l', 'd', '\0' };

    GetDataResponseDeserialization deserializer;

    auto d_msg =
        std::static_pointer_cast<GetDataResponse>(deserializer.deserialize(message));

    std::vector<std::uint64_t> expected_ids { 0, 1 };
    std::vector<std::string> expected_data { "Hello", "World" };

    ASSERT_EQ(d_msg->getAmountData(), 2);
    ASSERT_EQ(d_msg->getDataIds(), expected_ids);
    ASSERT_EQ(d_msg->getData(), expected_data);
}
