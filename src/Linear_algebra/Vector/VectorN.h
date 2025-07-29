#ifndef VECTORN_H
#define VECTORN_H

#include <cmath>
#include <cstddef>
#include "../Math_general/Math_general.h"

template <typename T, std::size_t N>
class VectorN
{
public:
    T elements[N];

    // Constructors
    constexpr VectorN();
    constexpr VectorN(const T (&elements_)[N]);
    template <typename... Args>
    constexpr VectorN(Args... elements_) : elements{static_cast<T>(elements_)...}
    {
        static_assert(sizeof...(Args) == N, "Number of arguments must be equal to N");
    }

    // Element accessor / modifier
    constexpr T &operator()(int index = 0);
    constexpr const T &operator()(int index = 0) const;

    static inline constexpr VectorN<T, N> zero();
    static inline constexpr VectorN<T, N> ones();

    // Static member functions
    static inline constexpr VectorN<T, N> add(const VectorN<T, N> &v1, const VectorN<T, N> &v2);
    static inline constexpr VectorN<T, N> add(const VectorN<T, N> &v1, T s);
    static inline constexpr VectorN<T, N> add(T s, const VectorN<T, N> &v1);
    static inline constexpr VectorN<T, N> sub(const VectorN<T, N> &v1, const VectorN<T, N> &v2);
    static inline constexpr VectorN<T, N> sub(const VectorN<T, N> &v1, T s);
    static inline constexpr VectorN<T, N> sub(T s, const VectorN<T, N> &v1);
    static inline constexpr VectorN<T, N> mul(const VectorN<T, N> &v, T s);
    static inline constexpr VectorN<T, N> mul(T s, const VectorN<T, N> &v);
    static inline constexpr VectorN<T, N> div(const VectorN<T, N> &v, T s);
    static inline constexpr VectorN<T, N> div(T s, const VectorN<T, N> &v);

    static inline constexpr T dot(const VectorN<T, N> &v1, const VectorN<T, N> &v2);
    static inline constexpr VectorN<T, N> normalize(const VectorN<T, N> &v);
    static inline constexpr T magnitude(const VectorN<T, N> &v);
    static inline constexpr T length(const VectorN<T, N> &v);
    static inline constexpr T norm(const VectorN<T, N> &v);
    static inline constexpr T angle(const VectorN<T, N> &v1, const VectorN<T, N> &v2);

    constexpr VectorN<T, N> operator+() const;
    constexpr VectorN<T, N> operator-() const;
    VectorN<T, N> &operator++();
    VectorN<T, N> operator++(int);
    VectorN<T, N> &operator--();
    VectorN<T, N> operator--(int);

    constexpr VectorN<T, N> operator+(const VectorN<T, N> &other) const;
    constexpr VectorN<T, N> operator-(const VectorN<T, N> &other) const;
    constexpr VectorN<T, N> operator+(T scalar) const;
    constexpr VectorN<T, N> operator-(T scalar) const;
    constexpr VectorN<T, N> operator*(T scalar) const;
    constexpr VectorN<T, N> operator/(T scalar) const;
    constexpr VectorN<T, N> operator%(T scalar) const;

    VectorN<T, N> &operator+=(const VectorN<T, N> &other);
    VectorN<T, N> &operator-=(const VectorN<T, N> &other);
    VectorN<T, N> &operator+=(T scalar);
    VectorN<T, N> &operator-=(T scalar);
    VectorN<T, N> &operator*=(T scalar);
    VectorN<T, N> &operator/=(T scalar);
    VectorN<T, N> &operator%=(T scalar);
    VectorN<T, N> &operator=(const VectorN<T, N> &other);
    VectorN<T, N> &normalize();

    constexpr bool operator==(const VectorN<T, N> &other) const;
    constexpr bool operator!=(const VectorN<T, N> &other) const;

    static inline constexpr bool is_parallel(const VectorN<T, N> &v1, const VectorN<T, N> &v2, T tolerance = T(0.0));
    static inline constexpr bool is_anti_parallel(const VectorN<T, N> &v1, const VectorN<T, N> &v2, T tolerance = T(0.0));
    static inline constexpr bool is_orthogonal(const VectorN<T, N> &v1, const VectorN<T, N> &v2, T tolerance = T(0.0));
};

#include "VectorN.tpp"

template <typename T, std::size_t N>
constexpr VectorN<T, N> operator+(T scalar, const VectorN<T, N> &v)
{
    return VectorN<T, N>::mul(scalar + v);
}

template <typename T, std::size_t N>
constexpr VectorN<T, N> operator-(T scalar, const VectorN<T, N> &v)
{
    return VectorN<T, N>::mul(scalar - v);
}

template <typename T, std::size_t N>
constexpr VectorN<T, N> operator*(T scalar, const VectorN<T, N> &v)
{
    return VectorN<T, N>::mul(scalar * v);
}

template <typename T, std::size_t N>
constexpr VectorN<T, N> operator/(T scalar, const VectorN<T, N> &v)
{
    return VectorN<T, N>::mul(scalar / v);
}

#endif
