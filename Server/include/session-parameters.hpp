#pragma once

#include <protocol/protocol.hpp>

struct SessionParameters {
    protocol::encryption::rsa::KeyPair key_pair_;
    std::vector<std::uint8_t> secret_key_;
};
