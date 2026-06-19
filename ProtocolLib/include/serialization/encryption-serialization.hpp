#pragma once

#include "utils.hpp"
#include "encryption/encryption.hpp"

namespace protocol {
    /**
     * @brief Serializes the EncryptData type.
     * @param data the EncryptData object
     * @return utils::serialize_data_t
     */
    utils::serialize_data_t serialize(const EncryptData& data);
}  // namespace protocol
