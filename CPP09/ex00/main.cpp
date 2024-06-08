#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    BitcoinExchange btc;

    if (ac != 2)
    {
        std::cout << "wrong input !" << std::endl;
        return 1;
    }
    if (BitcoinExchange::loadDatabase(av[1], btc))
        btc.coverter(av[1]);
    else
        std::cout << "failed to open input OR database !" << std::endl;
    return 0;
}