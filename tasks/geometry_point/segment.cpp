#include "segment.h"

namespace geometry {
Segment::Segment(geometry::Point a, geometry::Point b) {
    start_ = a;
    end_ = b;
}

Point Segment::GetStart() const {
    return start_;
}

Point Segment::GetEnd() const {
    return end_;
}
}  // namespace geometry