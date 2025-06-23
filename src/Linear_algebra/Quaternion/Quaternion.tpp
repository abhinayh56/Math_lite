#include "Quaternion.h"

template <typename T>
constexpr Quaternion<T>::Quaternion() : q0(0), q1(0), q2(0), q3(0)
{
}

template <typename T>
constexpr Quaternion<T>::Quaternion(T q0, T q1, T q2, T q3) : q0(q0), q1(q1), q2(q2), q3(q3)
{
}

template <typename T>
inline constexpr Quaternion<T> Quaternion<T>::zero()
{
    return Quaternion<T>(0, 0, 0, 0);
}

template <typename T>
inline constexpr Quaternion<T> Quaternion<T>::ones()
{
    return Quaternion<T>(1, 1, 1, 1);
}

template <typename T>
inline constexpr Quaternion<T> Quaternion<T>::identity()
{
    return Quaternion<T>(1, 0, 0, 0);
}

template <typename T>
inline constexpr Quaternion<T> Quaternion<T>::add(const Quaternion<T> &q_1, const Quaternion<T> &q_2)
{
    return Quaternion<T>(q_1.q0 + q_2.q0, q_1.q1 + q_2.q1, q_1.q2 + q_2.q2, q_1.q3 + q_2.q3);
}

template <typename T>
inline constexpr Quaternion<T> Quaternion<T>::sub(const Quaternion<T> &q_1, const Quaternion<T> &q_2)
{
    return Quaternion<T>(q_1.q0 - q_2.q0, q_1.q1 - q_2.q1, q_1.q2 - q_2.q2, q_1.q3 - q_2.q3);
}

template <typename T>
inline constexpr Quaternion<T> Quaternion<T>::mul(const Quaternion<T> &q_1, const Quaternion<T> &q_2)
{
    return Quaternion<T>(
        q_1.q0 * q_2.q0 - q_1.q1 * q_2.q1 - q_1.q2 * q_2.q2 - q_1.q3 * q_2.q3,
        q_1.q0 * q_2.q1 + q_1.q1 * q_2.q0 + q_1.q2 * q_2.q3 - q_1.q3 * q_2.q2,
        q_1.q0 * q_2.q2 - q_1.q1 * q_2.q3 + q_1.q2 * q_2.q0 + q_1.q3 * q_2.q1,
        q_1.q0 * q_2.q3 + q_1.q1 * q_2.q2 - q_1.q2 * q_2.q1 + q_1.q3 * q_2.q0);
}

template <typename T>
inline constexpr Quaternion<T> Quaternion<T>::mul(const Quaternion<T> &q, T s)
{
    return Quaternion<T>(q.q0 * s, q.q1 * s, q.q2 * s, q.q3 * s);
}

template <typename T>
inline constexpr Quaternion<T> Quaternion<T>::mul(T s, const Quaternion<T> &q)
{
    return Quaternion<T>(q.q0 * s, q.q1 * s, q.q2 * s, q.q3 * s);
}

template <typename T>
inline constexpr Quaternion<T> Quaternion<T>::div(const Quaternion<T> &q, T s)
{
    return Quaternion<T>(q.q0 / s, q.q1 / s, q.q2 / s, q.q3 / s);
}

template <typename T>
inline constexpr Quaternion<T> Quaternion<T>::conj(const Quaternion<T> &q)
{
    return Quaternion<T>(q.q0, -q.q1, -q.q2, -q.q3);
}

template <typename T>
inline constexpr Quaternion<T> Quaternion<T>::normalize(const Quaternion<T> &q)
{
    T mag = std::sqrt(q.q0 * q.q0 + q.q1 * q.q1 + q.q2 * q.q2 + q.q3 * q.q3);
    return Quaternion<T>(q.q0 / mag, q.q1 / mag, q.q2 / mag, q.q3 / mag);
}

template <typename T>
inline constexpr T Quaternion<T>::magnitude(const Quaternion<T> &q)
{
    return std::sqrt(q.q0 * q.q0 + q.q1 * q.q1 + q.q2 * q.q2 + q.q3 * q.q3);
}

template <typename T>
inline constexpr T Quaternion<T>::length(const Quaternion<T> &q)
{
    return std::sqrt(q.q0 * q.q0 + q.q1 * q.q1 + q.q2 * q.q2 + q.q3 * q.q3);
}

template <typename T>
inline constexpr T Quaternion<T>::norm(const Quaternion<T> &q)
{
    return std::sqrt(q.q0 * q.q0 + q.q1 * q.q1 + q.q2 * q.q2 + q.q3 * q.q3);
}

template <typename T>
inline constexpr Quaternion<T> Quaternion<T>::inv(const Quaternion<T> &q)
{
    T len = q.q0 * q.q0 + q.q1 * q.q1 + q.q2 * q.q2 + q.q3 * q.q3;
    if (len == T(1))
    {
        return Quaternion<T>(q.q0, -q.q1, -q.q2, -q.q3);
    }
    else
    {
        return Quaternion<T>(q.q0 / len, -q.q1 / len, -q.q2 / len, -q.q3 / len);
    }
}

template <typename T>
inline constexpr Quaternion<T> Quaternion<T>::log_e(const Quaternion<T> &q)
{
    T norm_q = std::sqrt(q.q0 * q.q0 + q.q1 * q.q1 + q.q2 * q.q2 + q.q3 * q.q3);
    T acos_q0_norm_q_by_u_norm = std::acos(q.q0 / norm_q) / std::sqrt(q.q1 * q.q1 + q.q2 * q.q2 + q.q3 * q.q3);
    return Quaternion<T>(std::log(norm_q), acos_q0_norm_q_by_u_norm * q.q1, acos_q0_norm_q_by_u_norm * q.q2, acos_q0_norm_q_by_u_norm * q.q3);
}

template <typename T>
inline constexpr Quaternion<T> Quaternion<T>::exp(const Quaternion<T> &q)
{
    Quaternion<T> q_2;
    T u_norm = std::sqrt(q.q1 * q.q1 + q.q2 * q.q2 + q.q3 * q.q3);
    q_2.q0 = std::cos(u_norm);
    q_2.q1 = std::sin(u_norm) * q.q1 / u_norm;
    q_2.q2 = std::sin(u_norm) * q.q2 / u_norm;
    q_2.q3 = std::sin(u_norm) * q.q3 / u_norm;

    return mul(q_2, std::exp(q.q0));
}

template <typename T>
inline constexpr Quaternion<T> Quaternion<T>::pow(const Quaternion<T> &q, T r)
{
    T u_norm = std::sqrt(q.q1 * q.q1 + q.q2 * q.q2 + q.q3 * q.q3);

    if (u_norm == 0.0)
    {
        return Quaternion<T>(std::pow(q.q0, r), 0.0, 0.0, 0.0);
    }
    else
    {
        T th = std::acos(q.q0 / std::sqrt(q.q0 * q.q0 + q.q1 * q.q1 + q.q2 * q.q2 + q.q3 * q.q3));
        T sin_r_th = std::sin(r * th);
        Quaternion<T> q_2(std::cos(r * th), (q.q1 / u_norm) * sin_r_th, (q.q2 / u_norm) * sin_r_th, (q.q3 / u_norm) * sin_r_th);

        return mul(q_2, std::pow(std::sqrt(q.q0 * q.q0 + q.q1 * q.q1 + q.q2 * q.q2 + q.q3 * q.q3), r));
    }
}

template <typename T>
inline constexpr Quaternion<T> Quaternion<T>::LERP(const Quaternion<T> &q_1, const Quaternion<T> &q_2, T tau)
{
    return q_1 + tau * (q_2 - q_1);
}

template <typename T>
inline constexpr Quaternion<T> Quaternion<T>::SLERP(const Quaternion<T> &q_1, const Quaternion<T> &q_2, T tau)
{
    T cos_theta = q_1.q0 * q_2.q0 + q_1.q1 * q_2.q1 + q_1.q2 * q_2.q2 + q_1.q3 * q_2.q3;

    // If the dot product is negative, slerp won't take the shorter path.
    // Fix by reversing one quaternion
    Quaternion<T> q_tmp;
    if (cos_theta < 0)
    {
        q_tmp = mul(q_2, -1);
        cos_theta = -cos_theta;
    }
    else
    {
        q_tmp = q_2;
    }

    // If the quaternions are very close, use linear interpolation
    if (cos_theta > T(0.9995))
    {
        return normalize(LERP(q_1, q_tmp, tau));
    }

    T theta = std::acos(cos_theta);
    T sin_theta = std::sin(theta);

    T s1 = std::sin((T(1) - tau) * theta) / sin_theta;
    T s2 = std::sin(tau * theta) / sin_theta;

    return add(mul(q_1, s1), mul(q_tmp, s2));
}

template <typename T>
constexpr Quaternion<T> Quaternion<T>::operator+() const
{
    return *this;
}

template <typename T>
constexpr Quaternion<T> Quaternion<T>::operator-() const
{
    return Quaternion<T>(-q0, -q1, -q2, -q3);
}

template <typename T>
Quaternion<T> &Quaternion<T>::operator++()
{
    ++q0;
    ++q1;
    ++q2;
    ++q3;
    return *this;
}

template <typename T>
Quaternion<T> Quaternion<T>::operator++(int)
{
    Quaternion<T> temp = *this;
    ++(*this);
    return temp;
}

template <typename T>
Quaternion<T> &Quaternion<T>::operator--()
{
    --q0;
    --q1;
    --q2;
    --q3;
    return *this;
}

template <typename T>
Quaternion<T> Quaternion<T>::operator--(int)
{
    Quaternion<T> temp = *this;
    --(*this);
    return temp;
}

template <typename T>
constexpr Quaternion<T> Quaternion<T>::operator+(const Quaternion<T> &other) const
{
    return Quaternion<T>(q0 + other.q0, q1 + other.q1, q2 + other.q2, q3 + other.q3);
}

template <typename T>
constexpr Quaternion<T> Quaternion<T>::operator-(const Quaternion<T> &other) const
{
    return Quaternion<T>(q0 - other.q0, q1 - other.q1, q2 - other.q2, q3 - other.q3);
}

template <typename T>
constexpr Quaternion<T> Quaternion<T>::operator*(T scalar) const
{
    return Quaternion<T>(q0 * scalar, q1 * scalar, q2 * scalar, q3 * scalar);
}

template <typename T>
constexpr Quaternion<T> Quaternion<T>::operator/(T scalar) const
{
    return Quaternion<T>(q0 / scalar, q1 / scalar, q2 / scalar, q3 / scalar);
}

template <typename T>
constexpr Quaternion<T> Quaternion<T>::operator%(T scalar) const
{
    return Quaternion<T>(q0 % scalar, q1 % scalar, q2 % scalar, q3 % scalar);
}

template <typename T>
Quaternion<T> &Quaternion<T>::operator+=(const Quaternion<T> &other)
{
    q0 += other.q0;
    q1 += other.q1;
    q2 += other.q2;
    q3 += other.q3;
    return *this;
}

template <typename T>
Quaternion<T> &Quaternion<T>::operator-=(const Quaternion<T> &other)
{
    q0 -= other.q0;
    q1 -= other.q1;
    q2 -= other.q2;
    q3 -= other.q3;
    return *this;
}

template <typename T>
Quaternion<T> &Quaternion<T>::operator*=(const Quaternion<T> &other)
{
    T q0_new = q0 * other.q0 - q1 * other.q1 - q2 * other.q2 - q3 * other.q3;
    T q1_new = q0 * other.q1 + q1 * other.q0 + q2 * other.q3 - q3 * other.q2;
    T q2_new = q0 * other.q2 - q1 * other.q3 + q2 * other.q0 + q3 * other.q1;
    T q3_new = q0 * other.q3 + q1 * other.q2 - q2 * other.q1 + q3 * other.q0;

    q0 = q0_new;
    q1 = q1_new;
    q2 = q2_new;
    q3 = q3_new;

    return *this;
}

template <typename T>
Quaternion<T> &Quaternion<T>::operator*=(T scalar)
{
    q0 *= scalar;
    q1 *= scalar;
    q2 *= scalar;
    q3 *= scalar;
    return *this;
}

template <typename T>
Quaternion<T> &Quaternion<T>::operator/=(T scalar)
{
    q0 /= scalar;
    q1 /= scalar;
    q2 /= scalar;
    q3 /= scalar;
    return *this;
}

template <typename T>
Quaternion<T> &Quaternion<T>::operator%=(T scalar)
{
    q0 %= scalar;
    q1 %= scalar;
    q2 %= scalar;
    q3 %= scalar;
    return *this;
}

template <typename T>
constexpr bool Quaternion<T>::operator==(const Quaternion<T> &other) const
{
    return (q0 == other.q0) && (q1 == other.q1) && (q2 == other.q2) && (q3 == other.q3);
}

template <typename T>
constexpr bool Quaternion<T>::operator!=(const Quaternion<T> &other) const
{
    return (q0 != other.q0) || (q1 != other.q1) || (q2 != other.q2) || (q3 != other.q3);
}
