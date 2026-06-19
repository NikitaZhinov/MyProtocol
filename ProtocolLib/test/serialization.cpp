#include "serialization/new-data-request-serialization.hpp"
#include "serialization/new-data-response-serialization.hpp"
#include "serialization/get-data-request-serialization.hpp"
#include "serialization/get-data-response-serialization.hpp"

#include "request/new-data-request.hpp"
#include "request/new-data-request-factory.hpp"
#include "request/get-data-request.hpp"
#include "request/get-data-request-factory.hpp"
#include "response/new-data-response.hpp"
#include "response/new-data-response-factory.hpp"
#include "response/get-data-response.hpp"
#include "response/get-data-response-factory.hpp"

#include <gtest/gtest.h>
#include <print>

using namespace protocol;

TEST(SerializationTest, NewDataRequestTest) {
    NewDataRequestFactory factory;

    auto message =
        std::static_pointer_cast<NewDataRequest>(factory.create(10, "Hello, World!"));

    NewDataRequestSerialization serializer;

    auto s_msg = serializer.serialize(message);

    std::vector<std::uint8_t> expected { 0,   0,   0,   0,   0,   0,   0,   0,
                                         10,  'H', 'e', 'l', 'l', 'o', ',', ' ',
                                         'W', 'o', 'r', 'l', 'd', '!' };

    ASSERT_EQ(s_msg, expected);
}

TEST(SerializationTest, GetDataRequestTest) {
    GetDataRequestFactory factory;

    auto message = std::static_pointer_cast<GetDataRequest>(factory.create(10));

    GetDataRequestSerialization serializer;

    auto s_msg = serializer.serialize(message);

    std::vector<std::uint8_t> expected { 1, 0, 0, 0, 0, 0, 0, 0, 10 };

    ASSERT_EQ(s_msg, expected);
}

TEST(SerializationTest, NewDataResponseTest) {
    NewDataResponseFactory factory;

    auto message = std::static_pointer_cast<NewDataResponse>(factory.create(123));

    NewDataResponseSerialization serializer;

    auto s_msg = serializer.serialize(message);

    std::vector<std::uint8_t> expected { 0, 0, 0, 0, 0, 0, 0, 0, 123 };

    ASSERT_EQ(s_msg, expected);
}

TEST(SerializationTest, GetDataResponseTest) {
    GetDataResponseFactory factory;

    std::vector<std::pair<std::uint64_t, std::string>> data {
        { 0, "Hello" },
        { 1, "World" }
    };

    auto message = std::static_pointer_cast<GetDataResponse>(factory.create(data));

    GetDataResponseSerialization serializer;

    auto s_msg = serializer.serialize(message);

    std::vector<std::uint8_t> expected {
        1, 0, 0, 0, 0, 0, 0,   0,   2,   0,   0,   0,    0,   0,   0,   0,   0,   0,   0,
        0, 0, 0, 0, 0, 1, 'H', 'e', 'l', 'l', 'o', '\0', 'W', 'o', 'r', 'l', 'd', '\0'
    };

    ASSERT_EQ(s_msg, expected);
}
