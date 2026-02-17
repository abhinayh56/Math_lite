#ifndef MATH_LITE_GEOMETRY_FOUNDATION_POINT_POINT_3D_H
#define MATH_LITE_GEOMETRY_FOUNDATION_POINT_POINT_3D_H

template <typename T>
class Point3D
{
public:
    T x = T(0);
    T y = T(0);
    T z = T(0);

    constexpr Point3D();
    constexpr Point3D(T x, T y, T z);
};

#include "point_3d.tpp"

#endif
