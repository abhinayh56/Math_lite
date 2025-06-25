#ifndef VECTORN_H
#define VECTORN_H

#include <cmath>
#include <stddef.h>

template <typename T, std::size_t N>
class VectorN
{
public:
    T *elements;

    constexpr VectorN();
    constexpr VectorN(const T *elements_);

    static inline constexpr VectorN<T, N> zero();
    static inline constexpr VectorN<T, N> ones();
    static inline constexpr VectorN<T, N> const_value();
    static inline constexpr VectorN<T, N> rand();
    static inline constexpr VectorN<T, N> unit(uint16_t index);
    static inline constexpr VectorN<T, N> basis(uint16_t index);

private:
};

#endif // VECTORN_H