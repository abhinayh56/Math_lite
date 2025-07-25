#include "../VectorN.h"
#include <iostream>

int main()
{
    VectorN<int, 4> v1 = {12, 34, 3, 74};

    std::cout << "v1: (" << v1(0) << ", " << v1(1) << ")\n";
    v1(0) = 56;
    v1(1) = 58;
    std::cout << "v1: (" << v1(0) << ", " << v1(1) << ")\n";

    int *aaa = &v1(0);

    *aaa = 5412;

    std::cout << "v1: (" << v1(0) << ", " << v1(1) << ")\n";

    return 0;
}
