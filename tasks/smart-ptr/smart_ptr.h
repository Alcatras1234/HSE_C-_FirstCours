#pragma once

#include <string>

template <class T>
class WeakPtr;

template <class T>
class SharedPtr {
public:
    SharedPtr() {
        count_ = nullptr;
        cur_ = nullptr;
    }

    explicit SharedPtr(T* ptr) : count_(new Counter()), cur_(ptr) {
        if (cur_) {
            count_->strong_rel = 1;
        }
    }

    SharedPtr(SharedPtr&& other) noexcept {
        count_ = other.count_;
        cur_ = other.cur_;
        other.count_ = nullptr;
        other.cur_ = nullptr;
    }

    SharedPtr(const SharedPtr& other) {
        count_ = other.count_;
        cur_ = other.cur_;
        if (count_) {
            ++count_->strong_rel;
        }
    }

    template <class N>
    explicit SharedPtr(const SharedPtr<N>& other) {
        count_ = other.count_;
        cur_ = other.cur_;
        if (count_) {
            ++count_->strong_rel;
        }
    }

    explicit SharedPtr(const WeakPtr<T>& rhs);

    ~SharedPtr() {
        Reset();
    }

    SharedPtr& operator=(const SharedPtr& other) {
        if (this != &other) {
            Reset();
            count_ = other.count_;
            cur_ = other.cur_;
            if (count_) {
                ++count_->strong_rel;
            }
        }
        return *this;
    }

    template <class N>
    explicit SharedPtr(SharedPtr<N>&& other) noexcept {
        count_ = other.count_;
        cur_ = other.cur_;
        other.count_ = nullptr;
        other.cur_ = nullptr;
    }

    template <class N>
    SharedPtr& operator=(const SharedPtr<N>& other) {
        if (this != static_cast<const void*>(&other)) {
            Reset();
            count_ = other.count_;
            cur_ = other.cur_;
            if (count_) {
                ++count_->strong_rel;
            }
        }
        return *this;
    }

    SharedPtr& operator=(SharedPtr&& other) noexcept {
        if (this != &other) {
            Reset();
            count_ = other.count_;
            cur_ = other.cur_;
            other.count_ = nullptr;
            other.cur_ = nullptr;
        }
        return *this;
    }

    template <class N>
    SharedPtr& operator=(SharedPtr<N>&& other) noexcept {
        if (this != static_cast<const void*>(&other)) {
            Reset();
            count_ = other.count_;
            cur_ = other.cur_;
            other.count_ = nullptr;
            other.cur_ = nullptr;
        }
        return *this;
    }

    void Reset() {
        if (count_ && --count_->strong_rel == 0) {
            delete cur_;
            if (count_->weak_rel == 0) {
                delete count_;
            }
        }
        count_ = nullptr;
        cur_ = nullptr;
    }

    void Reset(T* p) {
        Reset();
        if (p) {
            count_ = new Counter();
            cur_ = p;
            count_->strong_rel = 1;
        }
    }

    T* Get() const {
        return cur_;
    }

    T& operator*() const {
        return *cur_;
    }

    T* operator->() const {
        return cur_;
    }

private:
    struct Counter {
        int strong_rel = 0;
        int weak_rel = 0;
    };

    template <class N>
    friend class WeakPtr;

    Counter* count_;
    T* cur_;
};

template <class T>
class WeakPtr {
public:
    WeakPtr() {
        count_ = nullptr;
        cur_ = nullptr;
    }

    template <class N>
    explicit WeakPtr(const WeakPtr<N>& other) {
        count_ = other.count_;
        cur_ = other.cur_;
        if (count_) {
            ++count_->weak_rel;
        }
    }

    explicit WeakPtr(const SharedPtr<T>& shared_ptr) {
        count_ = shared_ptr.count_;
        cur_ = shared_ptr.cur_;
        if (count_) {
            ++count_->weak_rel;
        }
    }

    WeakPtr(const WeakPtr& other) {
        count_ = other.count_;
        cur_ = other.cur_;
        if (count_) {
            ++count_->weak_rel;
        }
    }

    WeakPtr(WeakPtr&& other) noexcept : count_(other.count_), cur_(other.cur_) {
        other.count_ = nullptr;
        other.cur_ = nullptr;
    }

    ~WeakPtr() {
        Reset();
    }

    WeakPtr& operator=(WeakPtr&& other) noexcept {
        if (this != &other) {
            Reset();
            count_ = other.count_;
            cur_ = other.cur_;
            other.count_ = nullptr;
            other.cur_ = nullptr;
        }
        return *this;
    }

    WeakPtr& operator=(const WeakPtr& other) {
        if (this != &other) {
            Reset();
            count_ = other.count_;
            cur_ = other.cur_;
            if (count_) {
                ++count_->weak_rel;
            }
        }
        return *this;
    }

    template <class N>
    WeakPtr& operator=(const WeakPtr<N>& other) {
        if (this != static_cast<const void*>(&other)) {
            Reset();
            count_ = other.count_;
            cur_ = other.cur_;
            if (count_) {
                ++count_->weak_rel;
            }
        }
        return *this;
    }

    template <class N>
    WeakPtr& operator=(WeakPtr<N>&& other) noexcept {
        if (this != static_cast<const void*>(&other)) {
            Reset();
            count_ = other.count_;
            cur_ = other.cur_;
            other.count_ = nullptr;
            other.cur_ = nullptr;
        }
        return *this;
    }

    SharedPtr<T> Lock() const {
        if (count_ && count_->strong_rel > 0) {
            return SharedPtr<T>(*this);
        } else {
            return SharedPtr<T>();
        }
    }

    bool IsExpired() const {
        return count_ == nullptr || count_->strong_rel == 0;
    }

    void Reset() {
        if (count_) {
            count_->weak_rel--;
            if (count_->weak_rel == 0 && count_->strong_rel == 0) {
                delete count_;
            }
        }
        cur_ = nullptr;
        count_ = nullptr;
    }


private:
    template <class N>
    friend class SharedPtr;

    typename SharedPtr<T>::Counter* count_;
    T* cur_;
};

template <class T>
SharedPtr<T>::SharedPtr(const WeakPtr<T>& rhs) {
    count_ = rhs.count_;
    cur_ = rhs.cur_;
    if (count_ && count_->strong_rel > 0) {
        ++count_->strong_rel;
    } else {
        count_ = nullptr;
        cur_ = nullptr;
    }
}
