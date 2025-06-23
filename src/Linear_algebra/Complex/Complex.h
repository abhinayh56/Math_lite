#ifndef COMPLEX_H
#define COMPLEX_H

#include <cmath>

template <typename T>
class Complex
{
public:
    T real = 0;
    T imag = 0;

    constexpr Complex();
    constexpr Complex(T real, T imag);

    static inline constexpr Complex<T> zero();
    static inline constexpr Complex<T> ones();

    static inline constexpr Complex<T> add(const Complex<T> &z1, const Complex<T> &z2);
    static inline constexpr Complex<T> sub(const Complex<T> &z1, const Complex<T> &z2);
    static inline constexpr Complex<T> mul(const Complex<T> &z1, const Complex<T> &z2);
    static inline constexpr Complex<T> mul(const Complex<T> &z, T s);
    static inline constexpr Complex<T> mul(T s, const Complex<T> &z);
    static inline constexpr Complex<T> div(const Complex<T> &z1, const Complex<T> &z2);
    static inline constexpr Complex<T> div(const Complex<T> &z, T s);

    static inline constexpr Complex<T> conj(const Complex<T> &z);
    static inline constexpr T abs(const Complex<T> &z);
    static inline constexpr T arg(const Complex<T> &z);
    static inline constexpr Complex<T> inv(const Complex<T> &z);
    static inline constexpr Complex<T> sqrt(const Complex<T> &z);
    static inline constexpr Complex<T> exp(const Complex<T> &z);
    static inline constexpr Complex<T> log(const Complex<T> &z);
    static inline constexpr Complex<T> pow(const Complex<T> &z, T n);
    static inline constexpr Complex<T> pow(const Complex<T> &z1, const Complex<T> &z2);

    static inline constexpr Complex<T> sin(const Complex<T> &z);
    static inline constexpr Complex<T> cos(const Complex<T> &z);
    static inline constexpr Complex<T> tan(const Complex<T> &z);

    static inline constexpr Complex<T> fromPolar(T r, T theta);
    inline constexpr void toPolar(T &r, T &theta) const;

    constexpr Complex<T> operator+() const;
    constexpr Complex<T> operator-() const;
    Complex<T> &operator++();
    Complex<T> operator++(int);
    Complex<T> &operator--();
    Complex<T> operator--(int);

    constexpr Complex<T> operator+(const Complex<T> &other) const;
    constexpr Complex<T> operator-(const Complex<T> &other) const;
    constexpr Complex<T> operator*(const Complex<T> &other) const;
    constexpr Complex<T> operator*(T scalar) const;
    constexpr Complex<T> operator/(const Complex<T> &other) const;
    constexpr Complex<T> operator/(T scalar) const;

    Complex<T> &operator+=(const Complex<T> &other);
    Complex<T> &operator-=(const Complex<T> &other);
    Complex<T> &operator*=(const Complex<T> &other);
    Complex<T> &operator*=(T scalar);
    Complex<T> &operator/=(const Complex<T> &other);
    Complex<T> &operator/=(T scalar);

    constexpr bool operator==(const Complex<T> &other) const;
    constexpr bool operator!=(const Complex<T> &other) const;
};

#include "Complex.tpp"

template <typename T>
constexpr Complex<T> operator*(T scalar, const Complex<T> &other)
{
    return Complex<T>(other.real * scalar, other.imag * scalar);
}

#endif
