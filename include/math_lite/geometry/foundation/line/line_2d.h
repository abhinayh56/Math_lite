#ifndef MATH_LITE_GEOMETRY_FOUNDATION_LINE_LINE_2D_H
#define MATH_LITE_GEOMETRY_FOUNDATION_LINE_LINE_2D_H

#include "../point/point_2d.h"
#include "../../../linear_algebra/vector/vector_2.h"

template <typename T>
class Line2D
{
public:
    Point2D<T> p(0, 0);
    Vector2<T> v(0, 0);

    constexpr Line2D();
    constexpr Line2D(Point2D<T> p_, Vector2<T> v_);

    static inline constexpr T distance(const Line2D<T>& l, const Point2D<T>& p1);
    static inline constexpr T angle(const Line2D<T>& l1, const Line2D<T>& l2);
    bool is_coincident(const Point2D<T>& p1) const;
    bool is_coincident(const Line2D<T>& l2) const;
    bool is_parallel(const Line2D<T>& l2) const;
    bool is_intersecting(const Line2D<T>& l2) const;
};

#include "line_2d.tpp"

#endif
