#include "protocol/protocol.hpp"

#include <gtest/gtest.h>

using namespace protocol::encryption;

TEST(EncryptionTest, AESTest) {
    std::string msg = "Hello, World!";

    std::vector<std::uint8_t> v_msg(msg.begin(), msg.end());
    std::vector<std::uint8_t> key = aes::generateKey();

    auto encrypt_data = aes::encrypt(v_msg, key);

    ASSERT_TRUE(v_msg.size() < encrypt_data.size());
    ASSERT_TRUE(v_msg != encrypt_data);

    auto decrypt_data = aes::decrypt(encrypt_data, key);

    ASSERT_EQ(v_msg, decrypt_data);
}

TEST(EncryptionTest, RSATest) {
    std::string msg = "Hello, World!";
    std::vector<std::uint8_t> v_msg(msg.begin(), msg.end());

    auto keypair = rsa::generatePairKey();

    ASSERT_FALSE(keypair.private_key.empty());
    ASSERT_FALSE(keypair.public_key.empty());

    ASSERT_TRUE(keypair.private_key != keypair.public_key);

    auto encrypt_data = rsa::encrypt(v_msg, keypair.public_key);

    ASSERT_TRUE(v_msg != encrypt_data);

    auto decrypt_data = rsa::decrypt(encrypt_data, keypair.private_key);
    decrypt_data.resize(v_msg.size());

    ASSERT_EQ(v_msg, decrypt_data);
}
