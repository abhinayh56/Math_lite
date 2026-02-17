#ifndef MATH_LITE_GEOMETRY_FOUNDATION_POINT_POINT_ND_H
#define MATH_LITE_GEOMETRY_FOUNDATION_POINT_POINT_ND_H

#include <cstddef>

template <typename T, std::size_t N>
class PointND
{
public:
    T coordinates[N];

    // Constructors
    constexpr PointND();
    constexpr PointND(const T *coordinates_);
};

#include "point_nd.tpp"

#endif
