# include "RPN.hpp"

int main(int ac, char **av)
{

    if (ac != 2)
    {
        std::cout << "need more args" << std::endl;
        return 1;
    }
    RPN::validate(av[1]);
    RPN::handleNotation(av[1]);

    return 0;
}