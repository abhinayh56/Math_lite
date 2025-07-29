#ifndef VECTOR2_H
#define VECTOR2_H

#include <cmath>
#include "../Math_general/Math_general.h"

template <typename T>
class Vector2
{
public:
    T x = 0;
    T y = 0;

    // Constructors
    constexpr Vector2();
    constexpr Vector2(T x, T y);

    // Element accessor / modifier
    constexpr T &operator()(int index = 0);
    constexpr const T &operator()(int index = 0) const;

    static inline constexpr Vector2<T> zero();
    static inline constexpr Vector2<T> ones();

    // Static member functions
    static inline constexpr Vector2<T> add(const Vector2<T> &v1, const Vector2<T> &v2);
    static inline constexpr Vector2<T> add(const Vector2<T> &v1, T s);
    static inline constexpr Vector2<T> add(T s, const Vector2<T> &v1);
    static inline constexpr Vector2<T> sub(const Vector2<T> &v1, const Vector2<T> &v2);
    static inline constexpr Vector2<T> sub(const Vector2<T> &v1, T s);
    static inline constexpr Vector2<T> sub(T s, const Vector2<T> &v1);
    static inline constexpr Vector2<T> mul(const Vector2<T> &v, T s);
    static inline constexpr Vector2<T> mul(T s, const Vector2<T> &v);
    static inline constexpr Vector2<T> div(const Vector2<T> &v, T s);
    static inline constexpr Vector2<T> div(T s, const Vector2<T> &v);

    static inline constexpr T dot(const Vector2<T> &v1, const Vector2<T> &v2);
    static inline constexpr T cross(const Vector2<T> &v1, const Vector2<T> &v2);
    static inline constexpr Vector2<T> normalize(const Vector2<T> &v);
    static inline constexpr T magnitude(const Vector2<T> &v);
    static inline constexpr T length(const Vector2<T> &v);
    static inline constexpr T norm(const Vector2<T> &v);
    static inline constexpr T angle(const Vector2<T> &v1, const Vector2<T> &v2);

    constexpr Vector2<T> operator+() const;
    constexpr Vector2<T> operator-() const;
    Vector2<T> &operator++();
    Vector2<T> operator++(int);
    Vector2<T> &operator--();
    Vector2<T> operator--(int);

    constexpr Vector2<T> operator+(const Vector2<T> &other) const;
    constexpr Vector2<T> operator-(const Vector2<T> &other) const;
    constexpr Vector2<T> operator+(T scalar) const;
    constexpr Vector2<T> operator-(T scalar) const;
    constexpr Vector2<T> operator*(T scalar) const;
    constexpr Vector2<T> operator/(T scalar) const;
    constexpr Vector2<T> operator%(T scalar) const;

    Vector2<T> &operator+=(const Vector2<T> &other);
    Vector2<T> &operator-=(const Vector2<T> &other);
    Vector2<T> &operator+=(T scalar);
    Vector2<T> &operator-=(T scalar);
    Vector2<T> &operator*=(T scalar);
    Vector2<T> &operator/=(T scalar);
    Vector2<T> &operator%=(T scalar);
    Vector2<T> &operator=(const Vector2<T> &other);
    Vector2<T> &normalize();

    constexpr bool operator==(const Vector2<T> &other) const;
    constexpr bool operator!=(const Vector2<T> &other) const;

    static inline constexpr bool is_parallel(const Vector2<T> &v1, const Vector2<T> &v2, T tolerance = T(0.0));
    static inline constexpr bool is_anti_parallel(const Vector2<T> &v1, const Vector2<T> &v2, T tolerance = T(0.0));
    static inline constexpr bool is_orthogonal(const Vector2<T> &v1, const Vector2<T> &v2, T tolerance = T(0.0));
};

#include "Vector2.tpp"

template <typename T>
constexpr Vector2<T> operator+(T scalar, const Vector2<T> &v)
{
    return Vector2<T>(scalar + v.x, scalar + v.y);
}

template <typename T>
constexpr Vector2<T> operator-(T scalar, const Vector2<T> &v)
{
    return Vector2<T>(scalar - v.x, scalar - v.y);
}

template <typename T>
constexpr Vector2<T> operator*(T scalar, const Vector2<T> &v)
{
    return Vector2<T>(scalar * v.x, scalar * v.y);
}

template <typename T>
constexpr Vector2<T> operator/(T scalar, const Vector2<T> &v)
{
    return Vector2<T>(scalar / v.x, scalar / v.y);
}

#endif
