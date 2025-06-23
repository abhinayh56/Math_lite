#include <iostream>
#include  "./src/Math_lite.h"

template<typename T>
void disp(Vector2<T> v)
{
    std::cout << v.x << ", " << v.y << "\n";
}

template<typename T>
void disp(T x)
{
    std::cout << x << "\n";
}

int main()
{
    std::cout << "aaaaa\n";

    Vector2<double> v1(2, 3);
    Vector2<double> v2(4, 8);
    disp(v1);
    disp(v2);
    std::cout << "---\n";

    Vector2<double> v3 = Vector2<double>::add(v1, v2);
    Vector2<double> v4 = Vector2<double>::sub(v1, v2);
    Vector2<double> v5 = Vector2<double>::mul(v1, 5);
    Vector2<double> v6 = Vector2<double>::mul(5, v2);
    Vector2<double> v7 = Vector2<double>::div(v1, 2);
    disp(v3);
    disp(v4);
    disp(v5);
    disp(v6);
    disp(v7);
    std::cout << "---\n";

    double          v8  = Vector2<double>::dot(v1, v2);
    double          v9  = Vector2<double>::cross(v1, v2);
    Vector2<double> v10 = Vector2<double>::normalize(v1);
    double          v11 = Vector2<double>::magnitude(v1);
    double          v12 = Vector2<double>::length(v1);
    double          v13 = Vector2<double>::norm(v1);
    double          v14 = Vector2<double>::angle(v1);
    disp(v8);
    disp(v9);
    disp(v10);
    disp(v11);
    disp(v12);
    disp(v13);
    disp(v14);
    std::cout << "---\n";

    disp(v1);
    v1.normalize();
    disp(v1);
    disp(v1*v12);
    std::cout << "---\n";

    std::cout << "bbbbb\n";

    return 0;
}
