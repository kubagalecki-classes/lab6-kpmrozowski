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

bool isGreater(int i, int j)
{
    return (i > j);
}

// Global Variable
int a;

bool isGreaterThana(int i)
{
    return (i > a);
}

int main()
{
    std::vector< int > wektor = makeRandomVector< int >(10, 0, 10);
    printVector(wektor);
    std::sort(wektor.begin(), wektor.end(), isGreater);
    printVector(wektor);
    std::cout << "Liczba wystapien elementu 7:";
    std::cout << std::count(wektor.begin(), wektor.end(), 7) << std::endl;
    std::cout << "Podaj liczbe:" << std::endl;
    std::cin >> a;
    std::cout << "Liczba wystapien elementow wiekszych od podanej liczby:" << std::endl;
    std::cout << std::count_if(wektor.begin(), wektor.end(), isGreaterThana) << std::endl;
}
