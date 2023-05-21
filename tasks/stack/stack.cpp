#include "stack.h"

Node::Node(int32_t v, Node* p) : value(v), previous(p) {
}

Stack::Stack() : head_(nullptr), size_(0) {
}

int32_t Stack::Size() const {
    return size_;
}

bool Stack::Empty() const {
    return head_ == nullptr;
}

int32_t Stack::Top() const {
    return head_->value;
}

void Stack::Push(int32_t value) {
    Node* new_node = new Node(value, head_);
    head_ = new_node;
    ++size_;
}

void Stack::Pop() {
    Node* deleter = head_;
    head_ = head_->previous;
    delete deleter;
    --size_;
}

void Stack::Clear() {
    while (head_ != nullptr) {
        Pop();
    }
}

Stack::~Stack() {
    Clear();
}
