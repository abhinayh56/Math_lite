#include "../Vector2.h"
#include <iostream>
int main()
{
    Vector2<int> v1(3, 4);

    std::cout << "v1: (" << v1(0) << ", " << v1(1) << ")\n";
    v1(0) = 56;
    v1(1) = 58;
    std::cout << "v1: (" << v1(0) << ", " << v1(1) << ")\n";

    int *aaa = &v1(0);

    *aaa = 447;

    std::cout << "v1: (" << v1(0) << ", " << v1(1) << ")\n";

    return 0;
}
