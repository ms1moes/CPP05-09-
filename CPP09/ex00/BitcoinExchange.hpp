#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cstring>

class BitcoinExchange
{
private:
    std::map<std::string, double> database;
    double value;
    std::string date;
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& src);
    ~BitcoinExchange();
    BitcoinExchange& operator=(const BitcoinExchange& src);

    static bool loadDatabase(const std::string str, BitcoinExchange &src);
    bool formatCheck(std::string line);
    bool dateCheck(std::string line);
    bool valueCheck(std::string line);
    bool parser(std::string line);
    void coverter(std::string input);
};

#endif
