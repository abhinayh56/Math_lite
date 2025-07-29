#include <iostream>
#include "src/Linear_algebra/Vector/VectorN.h"

using namespace std;

template <typename T, std::size_t N>
void disp(std::string s, VectorN<T, N> v)
{
    cout << s << ": ";
    for (int i = 0; i < N - 1; i++)
    {
        cout << v(i) << ", ";
    }
    cout << v(N - 1) << endl;
}

int main()
{
    VectorN<float, 3> v1 = {12.3, 12.56, 612.78};

    v1 = {12.3, 12.56, 612.78};

    disp<float, 3>("v1", v1);

    return 0;
}
