#include "iter.hpp"

int main(void)
{
    
    char characters[] = {'H','e','l','l','o'};

    std::cout << "array of characters: " << std::endl;
    ::iter(characters, 5, print);

    std::cout << std::endl;

    std::string names[] = {"Bob", "Jorge", "Miguel"};

    std::cout << "array of strings: " << std::endl;
    ::iter(names, 3, print);

    std::cout << std::endl;

    int integers[] = {42, 21, 33, 2, 1};

    std::cout << "array of integers: " << std::endl;
    ::iter(integers, 5, print);

    std::cout << std::endl;

    float floats[] = {1.1, 2.2, 3.3, 4.4, 42.42};

    std::cout << "array of floats: " << std::endl;
    ::iter(floats, 5, print);

    return 0;
}