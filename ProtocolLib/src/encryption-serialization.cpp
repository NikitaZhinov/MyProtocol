#include "serialization/encryption-serialization.hpp"

using namespace protocol;

utils::serialize_data_t protocol::serialize(const EncryptData& data) {
    utils::serialize_data_t serialize_data;

    serialize_data.append_range(data.iv);
    serialize_data.append_range(data.data);
    serialize_data.append_range(data.tag);

    return serialize_data;
}
