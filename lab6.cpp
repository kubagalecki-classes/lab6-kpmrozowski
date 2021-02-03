#include <algorithm>
#include <iostream>
#include <string>

/* Ćwiczenie III - std::reverse */

void makeInputReversed()
{
    std::string s;
    std::cout << "Podaj ciag znakow" << std::endl;
    std::cin >> s;
    std::reverse(s.begin(), s.end());
    std::cout << "Ciag znakow od tylu" << std::endl;
    std::cout << s << std::endl;
}

int main()
{
    makeInputReversed();
    return 0;
}