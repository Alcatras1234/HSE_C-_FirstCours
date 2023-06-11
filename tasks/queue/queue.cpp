#include "queue.h"

Node::Node(int32_t value, Node* next) : value(value), next(next) {
}

Queue::Queue() {
    front_ = nullptr;
    size_ = 0;
    tail_ = nullptr;
}
void Queue::Push(int32_t value) {
    Node* new_elem = new Node(value, nullptr);
    if (!Empty()) {
        tail_->next = new_elem;
        tail_ = new_elem;
    } else {
        tail_ = new_elem;
        front_ = new_elem;
    }
    ++size_;
}

void Queue::Pop() {
    if (!Empty()) {
        Node* temp = front_;
        front_ = front_->next;
        delete temp;
        --size_;
    }
}

void Queue::Clear() {
    while (front_ != nullptr) {
        Pop();
    }
}

int32_t Queue::Size() const {
    return size_;
}

int32_t Queue::Front() const {
    if (front_ != nullptr) {
        return front_->value;
    }
    return 0;
}

bool Queue::Empty() const {
    return (size_ == 0);
}

Queue::~Queue() {
    Clear();
}