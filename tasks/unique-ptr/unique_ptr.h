#pragma once

template <class T>
class UniquePtr {
public:
    // put all required methods and operators here

    // see http://en.cppreference.com/w/cpp/memory/unique_ptr
    // and test.cpp
    explicit UniquePtr(T* ptr = nullptr) : ptr_(ptr) {
    }
    ~UniquePtr() {
        delete ptr_;
    }

    UniquePtr(const UniquePtr&) = delete;
    UniquePtr& operator=(const UniquePtr&) = delete;

    UniquePtr(UniquePtr&& other) : ptr_(other.ptr_) {
        other.ptr_ = nullptr;
    }
    UniquePtr& operator=(UniquePtr&& other) {
        if (this != &other) {
            delete ptr_;
            ptr_ = other.ptr_;
            other.ptr_ = nullptr;
        }
        return *this;
    }

    T* operator->() const {
        return ptr_;
    }
    T& operator*() const {
        return *ptr_;
    }
    operator bool() const {
        return ptr_ != nullptr;
    }

    void Reset(T* ptr = nullptr) {
        if (ptr_ != ptr) {
            delete ptr_;
            ptr_ = ptr;
        }
    }

private:
    T* ptr_;
};
