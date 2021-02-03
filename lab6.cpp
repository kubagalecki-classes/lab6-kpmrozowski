#include <iostream>
#include <vector>
#include <numeric>

/* Ćwiczenie IV - std::inner_product */

void scalarProductExample()
{
    std::vector< float > first{1., 2., 3.};
    std::vector< float > second{1.1, 2.2, 3.3};
    float                ip = std::inner_product(first.begin(), first.end(), second.begin(), 0.);
    std::cout << "Iloczny sklarny:" << std::endl;
    /* 1. * 1.1 + 2. * 2.2 + 3. * 3.3. = 1.1 + 4.4. + 9.9 = 15.4 */
    std::cout << ip << std::endl;
}

int main()
{
    scalarProductExample();
    return 0;
}