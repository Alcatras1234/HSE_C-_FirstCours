#pragma once

#include <functional>
#include <list>
#include <vector>

template <typename KeyT>
class UnorderedSet {
public:
    UnorderedSet() : n_elements_(0), data_(0){
    }

    explicit UnorderedSet(size_t count) :n_elements_(0), data_(count) {
    }

    UnorderedSet(const UnorderedSet& other) : n_elements_(other.n_elements_), data_(other.data_){
    }

    UnorderedSet(UnorderedSet&& other) noexcept : n_elements_(other.n_elements_), data_(std::move(other.data_)) {
        other.n_elements_ = 0;
    }

    ~UnorderedSet() = default;

    template <typename IteratorType,
              typename = std::enable_if_t<std::is_base_of_v<
                  std::forward_iterator_tag, typename std::iterator_traits<IteratorType>::iterator_category>>>
    UnorderedSet(IteratorType first, IteratorType last) {
        n_elements_ = 0;
        size_t count = std::distance(first, last);
        size_t bucket_count = count > 0 ? count : 1;
        data_.resize(bucket_count);

        for (auto it = first; it != last; ++it) {
            Insert(*it);
        }
    }

    UnorderedSet& operator=(UnorderedSet&& other) noexcept {
        if (this != &other) {
            n_elements_ = other.n_elements_;
            other.n_elements_ = 0;
            data_ = std::move(other.data_);
        }
        return *this;
    }


    UnorderedSet& operator=(const UnorderedSet& other) {
        if (this != &other) {
            n_elements_ = other.n_elements_;
            data_ = other.data_;
        }
        return *this;
    }

    bool Empty() const {
        return n_elements_ == 0;
    }

    void Clear() {
        n_elements_ = 0;
        data_.clear();
        data_.resize(1);
    }

    size_t Size() const {
        return n_elements_;
    }

    void Insert(const KeyT& key) {
        if (BucketCount() == 0) {
            Rehash(1);
        }
        if (LoadFactor() == 1.0) {
            Rehash(data_.size() * 2);
        }
        size_t bucket = Bucket(key);
        auto& bucket_list = data_[bucket];
        auto it = std::find(bucket_list.begin(), bucket_list.end(), key);
        if (it == bucket_list.end()) {
            bucket_list.push_back(key);
            ++n_elements_;
        }
    }

    void Erase(const KeyT& key) {
        if (BucketCount() != 0) {
            size_t bucket = Bucket(key);
            auto& bucket_list = data_[bucket];
            auto it = std::find(bucket_list.begin(), bucket_list.end(), key);
            if (it != bucket_list.end()) {
                bucket_list.erase(it);
                --n_elements_;
            }
        }
    }

    void Insert(KeyT&& key) {
        if (BucketCount() == 0) {
            Rehash(1);
        }
        if (LoadFactor() == 1.0) {
            Rehash(data_.size() * 2);
        }
        size_t bucket = Bucket(key);
        auto& bucket_list = data_[bucket];
        auto it = std::find(bucket_list.begin(), bucket_list.end(), key);
        if (it == bucket_list.end()) {
            bucket_list.push_back(std::move(key));
            ++n_elements_;
        }
    }

    bool Find(const KeyT& key) const {
        if (Empty()) {
            return false;
        }
        size_t bucket = Bucket(key);
        const auto& bucket_list = data_[bucket];
        return std::find(bucket_list.begin(), bucket_list.end(), key) != bucket_list.end();
    }

    void Reserve(size_t new_bucket_count) {
        if (new_bucket_count > data_.size()) {
            Rehash(new_bucket_count);
        }
    }

    void Rehash(size_t new_bucket_count) {
        if (new_bucket_count >= Size()) {
            std::vector<std::list<KeyT>> new_data(new_bucket_count);
            for (const auto& bucket_list : data_) {
                for (const auto& key : bucket_list) {
                    size_t new_bucket = std::hash<KeyT>{}(key) % new_bucket_count;
                    new_data[new_bucket].push_back(key);
                }
            }
            data_ = std::move(new_data);
        }
    }

    size_t BucketCount() const {
        return data_.size();
    }

    size_t BucketSize(size_t id) const {
        if (Empty()) {
            return 0;
        }
        if (id >= data_.size()) {
            return 0;
        }
        return data_[id].size();
    }

    double LoadFactor() const {
        if (BucketCount() == 0) {
            return 0;
        } else {
            return static_cast<double>(n_elements_) / data_.size();
        }
    }

    size_t Bucket(const KeyT& key) const {
        if (BucketCount() == 0) {
            return 0;
        } else {
            return std::hash<KeyT>{}(key) % data_.size();
        }
    }


private:
    size_t n_elements_;
    std::vector<std::list<KeyT>> data_;
};
