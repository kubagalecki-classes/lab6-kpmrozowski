#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <vector>

/* Ćwiczenie XI - std::sorted_indices "sortowanie elementów wektora większych od wartości" */

void print_vector(std::vector< int > wektor)
{
    for (const int i : wektor)
        std::cout << i << " ";
    std::cout << std::endl;
}

template < typename ConstIt, typename Comp >
std::vector< size_t > sorted_indices(ConstIt first, ConstIt last, Comp compare)
{
    std::vector< size_t > wektor(std::distance(first, last));
    std::iota(wektor.begin(), wektor.end(), 0u);

    std::sort(wektor.begin(), wektor.end(), [&](size_t a, size_t b) {
        return compare(first[a], first[b]);
    });
    return wektor;
}

int main()
{
    std::vector< unsigned > v = {1, 4, 0, 3, 4, 5};
    auto                    r = sorted_indices(v.begin(), v.end(), std::less< unsigned >{});
    unsigned int            a = 0;
    for (size_t i = 0; i < v.size(); ++i) {
        assert(a <= v[r[i]]);
        a = v[r[i]];
    }
    return 0;
}

/* Po uruchomieniu otrzymano:

*/
