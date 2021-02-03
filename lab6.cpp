#include <algorithm>
#include <iomanip>
#include <iostream>
#include <random>
#include <type_traits>
#include <vector>

/* Ćwiczenie IX - std::transform */

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

void sinOfaVect()
{
    std::vector< float > wektor = make_random_vector< float >(5, -1., 1.);
    std::cout << "Wygenerowany wektor:" << std::endl;
    print_float_vector(wektor);
    std::vector< float > wektorSinusow(5);

    std::transform(
        wektor.begin(), wektor.end(), wektorSinusow.begin(), [&](float i) { return sin(i); });

    std::cout << "Wektor sinusow:" << std::endl;
    print_float_vector(wektorSinusow);
}

int main()
{
    sinOfaVect();
    return 0;
}