#ifndef MATH_LITE_GEOMETRY_FOUNDATION_POINT_POINT_1D_H
#define MATH_LITE_GEOMETRY_FOUNDATION_POINT_POINT_1D_H

#include <cmath>

template <typename T>
class Point1D
{
public:
    T x = T(0);

    constexpr Point1D();
    constexpr Point1D(T x);
    static inline constexpr T distance(const Point1D<T> &p1, const Point1D<T> &p2);
    static inline constexpr bool is_coincident(const Point1D<T> &p1, const Point1D<T> &p2);
};

#include "../../../../../src/math_lite/geometry/foundation/point/point_1d.tpp"

#endif
