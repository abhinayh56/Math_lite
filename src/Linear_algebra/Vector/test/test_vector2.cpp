#include <iostream>
#include "../Vector2.h"
#include <string>

using namespace std;

template <typename T>
void disp(std::string s, Vector2<T> v)
{
    cout << s << ": " << "(" << v.x << ", " << v.y << ")" << endl;
}

int main()
{
    Vector2<float> v1;
    disp("v1", v1);

    Vector2<float> v2(65, 7864);
    disp("v2", v2);

    v1(0) = 555;
    v1(1) = 123;
    disp("v1", v1);

    v1(0) = v2(0);
    v1(1) = v2(1);
    disp("v1", v1);

    v2(0) = 5555;
    v2(1) = 1233;
    disp("v1", v1);
    disp("v2", v2);

    cout << v1(0) << ", " << v1(1) << endl;
    cout << v2(0) << ", " << v2(1) << endl;

    v1 = Vector2<float>::zero();
    disp("v1", v1);

    v1 = Vector2<float>::ones();
    disp("v1", v1);

    v1 = {7, 3};
    disp("v1", v1);

    v2 = {5, 4};
    disp("v2", v2);

    Vector2<float> v3;

    v3 = Vector2<float>::add(v1, v2);
    disp("v3", v3);
    v3 = Vector2<float>::sub(v1, v2);
    disp("v3", v3);
    v3 = Vector2<float>::mul(v1, 12);
    disp("v3", v3);
    v3 = Vector2<float>::mul(12, v1);
    disp("v3", v3);
    v3 = Vector2<float>::div(v1, 5);
    disp("v3", v3);

    double d = Vector2<float>::dot(v1, v2);
    cout << "d: " << d << endl;

    d = Vector2<float>::cross(v1, v2);
    cout << "d: " << d << endl;

    v3 = Vector2<float>::normalize(v1);
    disp("v3", v3);

    d = Vector2<float>::magnitude(v3);
    cout << "d: " << d << endl;

    d = Vector2<float>::length(v3);
    cout << "d: " << d << endl;

    d = Vector2<float>::norm(v3);
    cout << "d: " << d << endl;

    d = Vector2<float>::angle(v3);
    cout << "d: " << d * 180.0/3.1417 << endl;

    v3 = +v1;
    disp("v3", v3);

    v3 = -v1;
    disp("v3", v3);

    v3++;
    disp("v3", v3);

    ++v3;
    disp("v3", v3);

    v3--;
    disp("v3", v3);

    --v3;
    disp("v3", v3);

    v3 = -v3;
    disp("v3", v3);

    v3  = v3 + v1;
    disp("v3", v3);

    v3  = v3 - v1;
    disp("v3", v3);

    v3  = v3 * 4.0;
    disp("v3", v3);

    v3  = 1.0f/3.0f * v3;
    disp("v3", v3);

    v3 += v1;
    disp("v3", v3);

    v3 -= v1;
    disp("v3", v3);

    v3 *= 3.0f;
    disp("v3", v3);

    v3 /= 2.0;
    disp("v3", v3);

    // v3 %= 5.0f;
    // disp("v3", v3);

    v3 = v2;
    disp("v3", v3);

    bool flag = (v3 == v2);
    cout << "flag: " << flag << endl;

    flag = (v3 == v1);
    cout << "flag: " << flag << endl;

    flag = (v3 != v2);
    cout << "flag: " << flag << endl;

    flag = (v3 != v1);
    cout << "flag: " << flag << endl;

    return 0;
}
