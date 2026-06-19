#include "encryption/encryption.hpp"

#include <gtest/gtest.h>
#include <print>

using namespace protocol;

TEST(EncryptionTest, EncryptTest) {
    std::string msg = "Hello, World!";
    std::string key = "1234567890123456";

    std::vector<std::uint8_t> v_msg(msg.begin(), msg.end());
    std::vector<std::uint8_t> v_key(key.begin(), key.end());

    ASSERT_EQ(msg.size(), v_msg.size());
    ASSERT_EQ(key.size(), v_key.size());

    auto encrypt_data = Encryption::encrypt(v_msg, v_key);

    ASSERT_FALSE(encrypt_data.data.empty());
    ASSERT_FALSE(encrypt_data.iv.empty());
    ASSERT_FALSE(encrypt_data.tag.empty());

    ASSERT_FALSE(v_msg == encrypt_data.data);
}

TEST(EncryptionTest, DecryptTest) {
    std::string msg = "Hello, World!";
    std::string key = "1234567890123456";

    std::vector<std::uint8_t> v_msg(msg.begin(), msg.end());
    std::vector<std::uint8_t> v_key(key.begin(), key.end());

    ASSERT_EQ(msg.size(), v_msg.size());
    ASSERT_EQ(key.size(), v_key.size());

    auto encrypt_data = Encryption::encrypt(v_msg, v_key);

    ASSERT_FALSE(encrypt_data.data.empty());
    ASSERT_FALSE(encrypt_data.iv.empty());
    ASSERT_FALSE(encrypt_data.tag.empty());

    ASSERT_FALSE(v_msg == encrypt_data.data);

    auto decrypt_data = Encryption::decrypt(encrypt_data, v_key);

    ASSERT_EQ(v_msg, decrypt_data);
}
