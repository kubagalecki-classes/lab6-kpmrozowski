#include <algorithm>
#include <iostream>
#include <string>

/* zad II - std::search */

bool isPiesekOrKotekIn()
{
    std::string s;
    std::cout << "Podaj zmienna typu string" << std::endl;
    std::cin >> s;
    std::string           piesek = "piesek";
    std::string           kotek  = "kotek";
    std::string::iterator it     = std::search(s.begin(), s.end(), piesek.begin(), piesek.end());
    if (it == s.end()) {
        it = std::search(s.begin(), s.end(), kotek.begin(), kotek.end());
        if (it == s.end()) {
            return false;
        }
        else {
            std::cout << "Znaleziono podciag kotek" << std::endl;
            return true;
        }
    }
    else {
        std::cout << "Znaleziono podciag piesek" << std::endl;
        return true;
    }
}

int main()
{
    if (isPiesekOrKotekIn())
        std::cout << "Podciag piesek lub podciag kotek znaleziony" << std::endl;
    else
        std::cout << "Podciag piesek lub podciag kotek nie zostal znaleziony" << std::endl;
    return 0;
}