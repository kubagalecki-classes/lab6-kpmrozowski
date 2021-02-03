#pragma once

#include "Human.hpp"

#include <algorithm>
#include <list>
#include <vector>

std::vector< char > foo(std::list< Human >& people)
{
    std::vector< char > ret_v(people.size());

    std::transform(people.begin(), people.end(), ret_v.rbegin(), [](const Human& i) {
        if (i.isMonster())
            return 'n';
        else
            return 'y';
    });

    std::for_each(people.begin(), people.end(), [](Human& i) { i.birthday(); });

    return ret_v;
}