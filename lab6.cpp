#include <algorithm>
#include <iostream>
#include <random>
#include <type_traits>
#include <vector>

template < typename T >
std::vector< T > makeRandomVector(size_t size, T minValue, T maxValue)
{
    static_assert(std::is_arithmetic_v< T >, "T must be an arithmetic type");

    std::mt19937     prng{std::random_device{}()};
    std::vector< T > retV;
    retV.reserve(size);
    auto bi = std::back_inserter(retV);

    using dist_t = std::conditional_t< std::is_integral_v< T >,
                                       std::uniform_int_distribution< T >,
                                       std::uniform_real_distribution< T > >;

    dist_t dist{minValue, maxValue};
    std::generate_n(bi, size, [&]() { return dist(prng); });

    return retV;
}

void printVector(std::vector< int > wektor)
{
    for (const int i : wektor)
        std::cout << i << " ";
    std::cout << std::endl;
}

int main()
{
    std::vector< int > wektor = makeRandomVector< int >(10, 0, 10);
    printVector(wektor);
    std::sort(wektor.begin(), wektor.end());
    printVector(wektor);
}
