#include "line.h"

#include "i_shape.h"
#include "point.h"
#include "vector.h"
#include "segment.h"

namespace geometry {
Line::Line(geometry::Point start, geometry::Point end) {
    start_ = start;
    end_ = end;
}

int64_t Line::GetA() const {
    return -(end_.GetY() - start_.GetY());
}

int64_t Line::GetB() const {
    return (end_.GetX() - start_.GetX());
}

int64_t Line::GetC() const {
    return -(GetA() * start_.GetX() + GetB() * start_.GetY());
}

double Line::Distance(Point point) const {
    double num = GetA() * point.GetX() + GetB() * point.GetY()
                 + GetC();
    double abs_num = std::abs(num);
    double denom = std::sqrt(GetA() * GetA() + GetB() * GetB());
    return (abs_num / denom);
}

Line &Line::Move(const geometry::Vector &vector) {
    start_.Move(vector);
    end_.Move(vector);
    return *this;
}

bool Line::ContainsPoint(const geometry::Point &point) const {
    return(GetA() * point.GetX() + GetB() * point.GetY() + GetC() == 0);
}

bool Line::CrossesSegment(const Segment& segment) const {
    int64_t first = GetA() * segment.GetStart().GetX() + GetB() * segment.GetStart().GetY() + GetC();
    int64_t second = GetA() * segment.GetEnd().GetX() + GetB() * segment.GetEnd().GetY() + GetC();
    return (first * second <= 0);
}

Line *Line::Clone() const {
    auto clone = new Line (start_, end_);
    return clone;
}
}  // namespace geometry