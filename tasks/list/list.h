#pragma once

#include <algorithm>
#include <utility>

template <typename T>
class List {
private:
    struct ListNode {
        explicit ListNode(const T& value) : value_(value), next_(nullptr), prev_(nullptr) {
        }

        explicit ListNode(T&& value) : value_(std::move(value)), next_(nullptr), prev_(nullptr) {
        }

        ListNode(const ListNode& other) : value_(other.value_), next_(nullptr), prev_(nullptr) {
        }

        T value_;
        ListNode* next_;
        ListNode* prev_;
    };

public:
    class Iterator {
    public:
        explicit Iterator(ListNode* cur, ListNode* last, ListNode* first) {
            cur_ = cur;
            last_ = last;
            first_ = first;
        }

        Iterator& operator++() {
            if (cur_ == nullptr) {
                cur_ = first_;
                return *this;
            }
            cur_ = cur_->next_;
            return *this;
        }

        Iterator& operator--() {
            if (cur_ == nullptr) {
                cur_ = last_;
                return *this;
            }
            cur_ = cur_->prev_;
            return *this;
        }

        Iterator operator--(int) {
            Iterator tmp = *this;
            --(*this);
            return tmp;
        }

        Iterator operator++(int) {
            Iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        T& operator*() const {
            return cur_->value_;
        }

        T* operator->() const {
            return &(cur_->value_);
        }

        bool operator!=(const Iterator& rhs) const {
            return cur_ != rhs.cur_;
        }

        bool operator==(const Iterator& rhs) const {
            return cur_ == rhs.cur_;
        }

    private:
        ListNode* cur_;
        ListNode* first_;
        ListNode* last_;
    };

    List() {
        begin_ = nullptr;
        end_ = nullptr;
        size_ = 0;
    }

    List(const List& other) {
        begin_ = nullptr;
        end_ = nullptr;
        size_ = 0;
        for (const T& elem : other) {
            PushBack(elem);
        }
    }

    List(List&& other) {
        begin_ = nullptr;
        end_ = nullptr;
        size_ = 0;
        std::swap(begin_, other.begin_);
        std::swap(end_, other.end_);
        std::swap(size_, other.size_);
    }

    ~List() {
        while (!IsEmpty()) {
            PopBack();
        }
    }

    List& operator=(List&& other) {
        if (this != &other) {
            std::swap(size_, other.size_);
            std::swap(begin_, other.begin_);
            std::swap(end_, other.end_);
        }
        return *this;
    }

    List& operator=(const List& other) {
        if (this != &other) {
            List temp(other);
            std::swap(size_, temp.size_);
            std::swap(begin_, temp.begin_);
            std::swap(end_, temp.end_);
        }
        return *this;
    }

    size_t Size() const {
        return size_;
    }

    bool IsEmpty() const {
        return size_ == 0;
    }

    void PushBack(const T& elem) {
        ListNode* new_node = new ListNode(elem);
        if (IsEmpty()) {
            begin_ = new_node;
            end_ = new_node;
        } else {
            end_->next_ = new_node;
            new_node->prev_ = end_;
            end_ = new_node;
        }
        ++size_;
    }

    void PushBack(T&& elem) {
        ListNode* new_node = new ListNode(std::move(elem));
        if (IsEmpty()) {
            begin_ = new_node;
            end_ = new_node;
        } else {
            end_->next_ = new_node;
            new_node->prev_ = end_;
            end_ = new_node;
        }
        ++size_;
    }

    void PushFront(T&& elem) {
        ListNode* new_node = new ListNode(std::move(elem));
        if (IsEmpty()) {
            begin_ = new_node;
            end_ = new_node;
        } else {
            begin_->prev_ = new_node;
            new_node->next_ = begin_;
            begin_ = new_node;
        }
        ++size_;
    }

    T& Front() {
        return begin_->value_;
    }

    const T& Front() const {
        return begin_->value_;
    }

    T& Back() {
        return end_->value_;
    }

    const T& Back() const {
        return end_->value_;
    }

    void PopBack() {
        if (IsEmpty()) {
            return;
        }
        ListNode* tmp_node = end_;
        if (size_ == 1) {
            begin_ = nullptr;
            end_ = nullptr;
        } else {
            end_ = end_->prev_;
            end_->next_ = nullptr;
        }
        delete tmp_node;
        --size_;
    }

    void PopFront() {
        if (IsEmpty()) {
            return;
        }
        ListNode* tmp_node = begin_;
        if (size_ == 1) {
            begin_ = nullptr;
            end_ = nullptr;
        } else {
            begin_ = begin_->next_;
            begin_->prev_ = nullptr;
        }
        delete tmp_node;
        --size_;
    }

    Iterator Begin() const {
        return Iterator(begin_, end_, begin_);
    }

    Iterator End() const {
        return Iterator(nullptr, end_, begin_);
    }

private:
    ListNode* begin_;
    ListNode* end_;
    int size_;
};

template <typename T>
typename List<T>::Iterator begin(const List<T>& list) {  // NOLINT
    return list.Begin();
}

template <typename T>
typename List<T>::Iterator end(const List<T>& list) {  // NOLINT
    return list.End();
}