#include <iostream>
#include  "./src/Math_lite.h"

template<typename T>
void disp(Quaternion<T> q)
{
    std::cout << q.q0 << ", " << q.q1  << ", " << q.q2 << ", " << q.q3 << "\n";
}

template<typename T>
void disp(T x)
{
    std::cout << x << "\n";
}

int main()
{
    std::cout << "aaaaa\n";

    Quaternion<double> q1(1, 2, 4, 5);
    Quaternion<double> q2(4, 7, 8, 6);
    disp(q1);
    disp(q2);
    std::cout << "---\n";
    disp(Quaternion<double>::LERP(q1, q2, 0));
    disp(Quaternion<double>::LERP(q1, q2, 0.5));
    disp(Quaternion<double>::LERP(q1, q2, 1.0));

    std::cout << "bbbbb\n";

    return 0;
}
