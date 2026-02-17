#ifndef MATH_LITE_GEOMETRY_FOUNDATION_POINT_POINT_2D_H
#define MATH_LITE_GEOMETRY_FOUNDATION_POINT_POINT_2D_H

template <typename T>
class Point2D
{
public:
    T x = T(0);
    T y = T(0);

    constexpr Point2D();
    constexpr Point2D(T x, T y);
    static inline constexpr T distance(const Point2D<T> &p1, const Point2D<T> &p2);
};

#include "point_2d.tpp"

#endif
