#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	try
    {
		if (ac < 3)
            throw "you need to pass at least two numbers to sort";
        parser(av);
		ft_sort(av);
    }
    catch (const char* msg)
    {
        std::cerr << "ERROR: " << msg << std::endl;
    }
}