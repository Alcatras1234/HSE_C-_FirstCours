#pragma once

#include <iterator>
#include <type_traits>

template <typename Iter>
class Range {
public:
    Range(Iter first, Iter last) : begin_(first), end_(last) {
    }

    Iter begin() const {
        return begin_;
    }

    Iter end() const {
        return end_;
    }

private:
    Iter begin_, end_;
};

template <typename Iter, typename Idx = typename std::iterator_traits<Iter>::difference_type>
class Enum {
    // NOLINTBEGIN
public:
    explicit Enum(Range<Iter> range, Idx start = Idx{}) : range_(range), start_(start) {
    }

    class iterator {
    public:
        using iterator_category = typename std::iterator_traits<Iter>::iterator_category;
        using value_type = std::pair<Idx, typename std::iterator_traits<Iter>::value_type>;
        using difference_type = typename std::iterator_traits<Iter>::difference_type;
        using ptr = typename std::iterator_traits<Iter>::pointer;
        using ref = std::pair<Idx, typename std::iterator_traits<Iter>::reference>;

        iterator(Iter it, Idx idx) : it_(it), index_(idx) {
        }

        iterator& operator++() {
            ++it_;
            ++index_;
            return *this;
        }

        iterator operator++(int) {
            auto temp(*this);
            ++(*this);
            return temp;
        }

        bool operator==(const iterator& other) const {
            return it_ == other.it_;
        }

        bool operator!=(const iterator& other) const {
            return !(*this == other);
        }

        ref operator*() const {
            return {index_, *it_};
        }

        ptr operator->() const {
            return std::addressof(operator*());
        }

    private:
        Iter it_;
        Idx index_;
    };

    iterator begin() const {
        return {range_.begin(), start_};
    }

    iterator end() const {
        return {range_.end(), start_ + std::distance(range_.begin(), range_.end())};
    }
    // NOLINTEND

private:
    Range<Iter> range_;
    Idx start_;
};

template <typename Container>
auto Enumerate(Container&& cont) {
    using std::begin, std::end;
    return Enum{Range{begin(cont), end(cont)}};
}

template <typename Container>
[[maybe_unused]] auto Enumerate(const Container&& cont) {
    using std::cbegin, std::cend;
    return Enum{Range{cbegin(cont), cend(cont)}};
}