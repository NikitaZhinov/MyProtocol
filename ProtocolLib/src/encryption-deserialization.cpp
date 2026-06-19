#include "deserialization/encryption-deserialization.hpp"

using namespace protocol;

EncryptData protocol::deserialize(const utils::serialize_data_t& data) {
    EncryptData deserialize_data;

    deserialize_data.iv.assign(data.begin(), data.begin() + 12);
    deserialize_data.data.assign(data.begin() + 12, data.end() - AES_BLOCK_SIZE);
    deserialize_data.tag.assign(data.end() - AES_BLOCK_SIZE, data.end());

    return deserialize_data;
}
