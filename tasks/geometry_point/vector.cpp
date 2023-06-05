#include "vector.h"

#include <cstdint>

namespace geometry {
Vector::Vector() {
    x_coord_ = 0;
    y_coord_ = 0;
}

Vector::Vector(int64_t x, int64_t y) {
    x_coord_ = x;
    y_coord_ = y;
}

int64_t Vector::GetX() const {
    return x_coord_;
}

int64_t Vector::GetY() const {
    return y_coord_;
}

Vector Vector::operator+(const Vector& other) const {
    Vector in_this;
    in_this.x_coord_ = x_coord_ + other.x_coord_;
    in_this.y_coord_ = y_coord_ + other.y_coord_;
    return in_this;
}

Vector Vector::operator-(const Vector& other) const {
    Vector in_this;
    in_this.x_coord_ = x_coord_ - other.x_coord_;
    in_this.y_coord_ = y_coord_ - other.y_coord_;
    return in_this;
}

Vector Vector::operator+() const {
    return *this;
}

Vector Vector::operator-() const {
    return Vector(-x_coord_, -y_coord_);
}

Vector Vector::operator*(int64_t number) const {
    Vector in_this;
    in_this.x_coord_ = x_coord_ * number;
    in_this.y_coord_ = y_coord_ * number;
    return in_this;
}

Vector Vector::operator/(int64_t number) const {
    Vector in_this;
    in_this.x_coord_ = x_coord_ / number;
    in_this.y_coord_ = y_coord_ / number;
    return in_this;
}

Vector& Vector::operator+=(const Vector& other) {
    this->x_coord_ = this->x_coord_ + other.x_coord_;
    this->y_coord_ = this->y_coord_ + other.y_coord_;
    return *this;
}

Vector& Vector::operator-=(const Vector& other) {
    this->x_coord_ = this->x_coord_ - other.x_coord_;
    this->y_coord_ = this->y_coord_ - other.y_coord_;
    return *this;
}

Vector& Vector::operator*=(int64_t number) {
    this->x_coord_ = this->x_coord_ * number;
    this->y_coord_ = this->y_coord_ * number;
    return *this;
}

Vector& Vector::operator/=(int64_t number) {
    if (number != 0) {
        this->x_coord_ = this->x_coord_ / number;
        this->y_coord_ = this->y_coord_ / number;
    }
    return *this;
}

bool Vector::operator==(const Vector& other) const {
    return (this->x_coord_ - x_coord_ == this->y_coord_ - other.y_coord_);
}

int64_t ScalarMult(const Vector& first, const Vector& second) {
    return (first.x_coord_ * second.x_coord_ + first.y_coord_ * second.y_coord_);
}

int64_t VectorMult(const Vector& first, const Vector& second) {
    return (first.x_coord_ * second.y_coord_ - first.y_coord_ * second.x_coord_);
}

double Length(const Vector& vector) {
    double length = sqrt(static_cast<double>(vector.x_coord_) * static_cast<double>(vector.x_coord_) +
                         static_cast<double>(vector.y_coord_) * static_cast<double>(vector.y_coord_));
    return length;
}
}  // namespace geometry