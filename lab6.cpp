#include <algorithm>
#include <iostream>
#include <random>
#include <type_traits>
#include <vector>

/* Ćwiczenie V - std::find i std::sort */

template < typename T >
std::vector< T > make_random_vector(size_t size, T min_value, T max_value)
{
    static_assert(std::is_arithmetic_v< T >, "T must be an arithmetic type");

    std::mt19937     prng{std::random_device{}()};
    std::vector< T > ret_v;
    ret_v.reserve(size);
    auto bi = std::back_inserter(ret_v);

    using dist_t = std::conditional_t< std::is_integral_v< T >,
                                       std::uniform_int_distribution< T >,
                                       std::uniform_real_distribution< T > >;

    dist_t dist{min_value, max_value};
    std::generate_n(bi, size, [&]() { return dist(prng); });

    return ret_v;
}

void print_vector(std::vector< int > wektor)
{
    for (const int i : wektor)
        std::cout << i << " ";
    std::cout << std::endl;
}

void findAndMoveAtEnd()
{
    std::vector< int > wektor = make_random_vector< int >(10, 0, 10);
    std::cout << "Wygenerowany wektor:" << std::endl;
    print_vector(wektor);

    std::rotate(wektor.begin(), std::find(wektor.begin(), wektor.end(), 7), wektor.end());

    std::cout << "Obrocony wektor:" << std::endl;
    print_vector(wektor);
}

int main()
{
    findAndMoveAtEnd();
    return 0;
}