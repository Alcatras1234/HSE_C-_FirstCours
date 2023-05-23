#include "rational.h"

void Rational::Set(int64_t numer, int64_t denom) {
    if (denom == 0) {
        throw RationalDivisionByZero{};
    }
    int mult = (denom > 0 ? 1 : -1);
    numer_ = static_cast<int>(numer);
    denom_ = static_cast<int>(denom) * mult;
}

Rational::Rational() : numer_(0), denom_(1) {
}

Rational::Rational(int value) {
    numer_ = value;
    denom_ = 1;
}
Rational::Rational(int numer, int denom) : numer_(0), denom_(0) {
    int gcd = std::gcd(numer, denom);
    int new_numer = numer / gcd;
    int new_denom = denom / gcd;
    Set(new_numer, new_denom);
}
int Rational::GetNumerator() const {
    return numer_;
}
int Rational::GetDenominator() const {
    return denom_;
}

void Rational::SetNumerator(int value) {
    Set(value, denom_);
}

void Rational::SetDenominator(int value) {
    Set(numer_, value);
}

Rational operator+(const Rational& ratio) {
    return ratio;
}

Rational operator-(const Rational& ratio) {
    return {-ratio.GetNumerator(), ratio.GetDenominator()};
}

Rational& operator+=(Rational& lhs, const Rational& rhs) {
    int answerdenom = lhs.denom_ * rhs.denom_;
    int answernumer = lhs.numer_ * rhs.denom_ + rhs.numer_ * lhs.denom_;
    int gcd = std::gcd(answerdenom, answernumer);
    lhs.denom_ = answerdenom / gcd;
    lhs.numer_ = answernumer / gcd;
    return lhs;
}

Rational& operator-=(Rational& lhs, const Rational& rhs) {
    Rational inverse = -rhs;
    return (lhs += inverse);
}

Rational& operator*=(Rational& lhs, const Rational& rhs) {
    int answerdenom = lhs.denom_ * rhs.denom_;
    int answernumer = lhs.numer_ * rhs.numer_;
    int gcd = std::gcd(answerdenom, answernumer);
    lhs.denom_ = answerdenom / gcd;
    lhs.numer_ = answernumer / gcd;
    return lhs;
}

Rational& operator/=(Rational& lhs, const Rational& rhs) {
    Rational flip{rhs.GetDenominator(), rhs.GetNumerator()};
    return (lhs *= flip);
}

Rational operator+(const Rational& lhs, const Rational& rhs) {
    Rational copy = lhs;
    return (copy += rhs);
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
    Rational copy = lhs;
    return (copy -= rhs);
}

Rational operator*(const Rational& lhs, const Rational& rhs) {
    Rational copy = lhs;
    return (copy *= rhs);
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
    Rational copy = lhs;
    return (copy /= rhs);
}

Rational& operator++(Rational& ratio) {
    ratio.numer_ += ratio.denom_;
    return ratio;
}

Rational operator++(Rational& ratio, int) {
    Rational copy = ratio;
    ++copy;
    return copy;
}

Rational& operator--(Rational& ratio) {
    ratio.numer_ -= ratio.denom_;
    return ratio;
}

Rational operator--(Rational& ratio, int) {
    Rational copy = ratio;
    --copy;
    return copy;
}

bool operator<(const Rational& lhs, const Rational& rhs) {
    return ((lhs - rhs).GetNumerator() < 0);
}

bool operator>(const Rational& lhs, const Rational& rhs) {
    return (rhs < lhs);
}

bool operator<=(const Rational& lhs, const Rational& rhs) {
    return !(rhs < lhs);
}

bool operator>=(const Rational& lhs, const Rational& rhs) {
    return !(lhs < rhs);
}

bool operator==(const Rational& lhs, const Rational& rhs) {
    return !(lhs < rhs || rhs < lhs);
}

bool operator!=(const Rational& lhs, const Rational& rhs) {
    return (lhs < rhs || rhs < lhs);
}

std::ostream& operator<<(std::ostream& os, const Rational& ratio) {
    os << ratio.GetNumerator();
    if (ratio.GetDenominator() != 1) {
        os << '/' << ratio.GetNumerator();
    }
    return os;
}
std::istream& operator>>(std::istream& is, Rational& ratio) {
    int numer = 0;
    int denom = 0;
    is >> numer;
    if (is.peek() == '/') {
        is.ignore();
        is >> denom;
    } else {
        denom = 1;
    }
    ratio.Set(numer, denom);
    return is;
}