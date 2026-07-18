#include "protocol/protocol.hpp"

protocol::response::GetDataResponse::GetDataResponse() :
    Response(ResponseType::GetData) {}

protocol::response::GetDataResponse::GetDataResponse(
    const std::vector<std::pair<std::uint64_t, std::string>>& data) :
    GetDataResponse() {
    setData(data);
}

void protocol::response::GetDataResponse::setData(
    const std::vector<std::pair<std::uint64_t, std::string>>& data) {
    amount_data_ = data.size();

    for (auto& pair : data) {
        ids_.push_back(pair.first);
        data_.push_back(pair.second);
    }
}

std::size_t protocol::response::GetDataResponse::getAmountData() const {
    return amount_data_;
}

std::vector<std::uint64_t> protocol::response::GetDataResponse::getDataIds() const {
    return ids_;
}

std::vector<std::string> protocol::response::GetDataResponse::getData() const {
    return data_;
}
