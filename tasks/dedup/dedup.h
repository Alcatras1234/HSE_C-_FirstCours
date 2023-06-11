#pragma once

#include <memory>
#include <vector>
#include <string>
#include <set>

using std::string;

template <class T>
std::vector<std::unique_ptr<T>> Duplicate(const std::vector<std::shared_ptr<T>>& items) {
    std::vector<std::unique_ptr<T>> unshared;
    for (const auto& item : items) {
        unshared.emplace_back(std::make_unique<T>(*item));
    }
    return unshared;
}


template <class T>
std::vector<std::shared_ptr<T>> DeDuplicate(const std::vector<std::unique_ptr<T>>& items) {
    struct ComparePtrs {
        bool operator() (const std::shared_ptr<T> &lhs, const std::shared_ptr<T> &rhs) const {
            return *lhs < *rhs;
        }
    };
    std::vector<std::shared_ptr<T>> shared;
    std::set<std::shared_ptr<T>, ComparePtrs> pool;
    for (const auto& item : items) {
        auto copy = std::make_shared<T>(*item);
        auto first_copy = *pool.insert(copy).first;
        shared.push_back(first_copy);
    }
    return shared;
}
