#include "easyfind.hpp"

int main()
{

std::vector<int> vect;

for (int i = 0; i < 5; i++)
    vect.push_back(i);

std::cout << "TESTS: " << std::endl;

std::cout << easyfind(vect, 1) << std::endl;
std::cout << easyfind(vect, 3) << std::endl;
std::cout << easyfind(vect, 4) << std::endl;
std::cout << easyfind(vect, 20) << std::endl;

}