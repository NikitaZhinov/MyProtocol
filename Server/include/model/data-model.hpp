#pragma once

#include <string>

namespace model {
    struct DataModel final {
        std::uint64_t id;
        std::uint64_t user_id;
        std::string data;
    };
}  // namespace model
