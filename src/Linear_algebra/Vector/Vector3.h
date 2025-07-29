#ifndef VECTOR3_H
#define VECTOR3_H

#include <cmath>
#include "../../Math_general/Math_general.h"

template <typename T>
class Vector3
{
public:
    T x = 0;
    T y = 0;
    T z = 0;

    // Constructors
    constexpr Vector3();
    constexpr Vector3(T x, T y, T z);

    // Element accessor / modifier
    constexpr T &operator()(int index = 0);
    constexpr const T &operator()(int index = 0) const;

    static inline constexpr Vector3<T> zero();
    static inline constexpr Vector3<T> ones();

    // Static member functions
    static inline constexpr Vector3<T> add(const Vector3<T> &v1, const Vector3<T> &v2);
    static inline constexpr Vector3<T> add(const Vector3<T> &v1, T s);
    static inline constexpr Vector3<T> add(T s, const Vector3<T> &v1);
    static inline constexpr Vector3<T> sub(const Vector3<T> &v1, const Vector3<T> &v2);
    static inline constexpr Vector3<T> sub(const Vector3<T> &v1, T s);
    static inline constexpr Vector3<T> sub(T s, const Vector3<T> &v1);
    static inline constexpr Vector3<T> mul(const Vector3<T> &v, T s);
    static inline constexpr Vector3<T> mul(T s, const Vector3<T> &v);
    static inline constexpr Vector3<T> div(const Vector3<T> &v, T s);
    static inline constexpr Vector3<T> div(T s, const Vector3<T> &v);

    static inline constexpr T dot(const Vector3<T> &v1, const Vector3<T> &v2);
    static inline constexpr Vector3<T> cross(const Vector3<T> &v1, const Vector3<T> &v2);
    static inline constexpr Vector3<T> normalize(const Vector3<T> &v);
    static inline constexpr T magnitude(const Vector3<T> &v);
    static inline constexpr T length(const Vector3<T> &v);
    static inline constexpr T norm(const Vector3<T> &v);
    static inline constexpr T angle(const Vector3<T> &v1, const Vector3<T> &v2);

    constexpr Vector3<T> operator+() const;
    constexpr Vector3<T> operator-() const;
    Vector3<T> &operator++();
    Vector3<T> operator++(int);
    Vector3<T> &operator--();
    Vector3<T> operator--(int);

    constexpr Vector3<T> operator+(const Vector3<T> &other) const;
    constexpr Vector3<T> operator-(const Vector3<T> &other) const;
    constexpr Vector3<T> operator+(T scalar) const;
    constexpr Vector3<T> operator-(T scalar) const;
    constexpr Vector3<T> operator*(T scalar) const;
    constexpr Vector3<T> operator/(T scalar) const;
    constexpr Vector3<T> operator%(T scalar) const;

    Vector3<T> &operator+=(const Vector3<T> &other);
    Vector3<T> &operator-=(const Vector3<T> &other);
    Vector3<T> &operator+=(T scalar);
    Vector3<T> &operator-=(T scalar);
    Vector3<T> &operator*=(T scalar);
    Vector3<T> &operator/=(T scalar);
    Vector3<T> &operator%=(T scalar);
    Vector3<T> &operator=(const Vector3<T> &other);
    Vector3<T> &normalize();

    constexpr bool operator==(const Vector3<T> &other) const;
    constexpr bool operator!=(const Vector3<T> &other) const;

    static inline constexpr bool is_parallel(const Vector3<T> &v1, const Vector3<T> &v2, T tolerance = T(0.0));
    static inline constexpr bool is_anti_parallel(const Vector3<T> &v1, const Vector3<T> &v2, T tolerance = T(0.0));
    static inline constexpr bool is_orthogonal(const Vector3<T> &v1, const Vector3<T> &v2, T tolerance = T(0.0));
};

#include "Vector3.tpp"

template <typename T>
constexpr Vector3<T> operator+(T scalar, const Vector3<T> &v)
{
    return Vector3<T>(scalar + v.x, scalar + v.y, scalar + v.z);
}

template <typename T>
constexpr Vector3<T> operator-(T scalar, const Vector3<T> &v)
{
    return Vector3<T>(scalar - v.x, scalar - v.y, scalar - v.z);
}

template <typename T>
constexpr Vector3<T> operator*(T scalar, const Vector3<T> &v)
{
    return Vector3<T>(scalar * v.x, scalar * v.y, scalar * v.z);
}

template <typename T>
constexpr Vector3<T> operator/(T scalar, const Vector3<T> &v)
{
    return Vector3<T>(scalar / v.x, scalar / v.y, scalar / v.z);
}

#endif
