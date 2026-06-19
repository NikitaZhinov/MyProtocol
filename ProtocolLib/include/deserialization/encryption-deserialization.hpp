#pragma once

#include "utils.hpp"
#include "encryption/encryption.hpp"

namespace protocol {
    /**
     * @brief Deserializes the data into an EncryptData object.
     * @param data the serialized EncryptData object
     * @return EncryptData
     */
    EncryptData deserialize(const utils::serialize_data_t& data);
}  // namespace protocol
