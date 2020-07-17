#include <algorithm>
#include <iostream>
#include <vector>
#include <list>

int main()
{
    char c1[4] = "123";
    char c2[4] = "123";
    for (auto u : c1)
    {
        std::cout << u << " ";
    }
    for (auto u : c2) 
    { 
        std::cout << u << " "; 
    }
    std::cout << std::endl;
    std::cout << strlen(c1) << strlen(c2) << std::endl;
    std::vector<char*> roster1{ c1 };
    std::list<char*> roster2{ c2 };
    std::cout << strcmp(c1, c2) << std::endl;
    std::cout << std::equal(roster1.cbegin(), roster1.cend(), roster2.cbegin());
    return 0;
}