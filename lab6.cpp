#include <algorithm>
#include <iomanip>
#include <iostream>
#include <random>
#include <type_traits>
#include <vector>

/* Ćwiczenie VIII - std::any_of */

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

void print_float_vector(std::vector< float > wektor)
{
    for (const float i : wektor)
        std::cout << std::fixed << std::setprecision(2) << i << std::endl;
    std::cout << std::endl;
}

void anyMoreThan0p9()
{
    std::vector< float > wektor = make_random_vector< float >(10, -1., 1.);
    std::cout << "Wygenerowany wektor:" << std::endl;
    print_float_vector(wektor);
    if (std::any_of(wektor.begin(), wektor.end(), [&](float i) { return (i > 0.9); }))
        std::cout << "Jest element wiekszy od 0.9" << std::endl;
    else
        std::cout << "Nie ma elementu wiekszego od 0.9" << std::endl;
}

int main()
{
    anyMoreThan0p9();
    return 0;
}