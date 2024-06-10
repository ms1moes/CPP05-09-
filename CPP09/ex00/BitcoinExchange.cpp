#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src)
{
    *this = src;
}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src)
{
    if (this == &src)
        return *this;
    database = src.database;
    value = src.value;
    date = src.date;
    return *this;
}

bool BitcoinExchange::loadDatabase(const std::string input, BitcoinExchange &src)
{
    std::ifstream in(input.c_str());
    std::ifstream data("data.csv");

    double amount = 0;
    std::string str;
    std::string time;

    if (!in.is_open() || !data.is_open())
        return false;
    while (std::getline(data, str))
    {
        time = str.substr(0, str.find(","));
        amount = std::atof(str.substr(str.find_last_of(",") + 1).c_str());
        src.database[time] = amount;
    }

    return true;
}

bool BitcoinExchange::formatCheck(std::string line)
{
    if (line.length() < 14 || line[11] != '|' || !isdigit(line[9]) || !isdigit(line[13]))
    {
        std::cout << "ERROR: Invalid format OR number => ";
        return true;
    }
    for (unsigned int i = 0; i < line.length(); i++)
        if (!isdigit(line[i]) && line[i] != ' ' && line[i] != '|' && line[i] != '.' && line[i] != '-')
        {
            std::cout << "ERROR: Invalid character detected => ";
            return true;
        }
    return false;
}

bool BitcoinExchange::dateCheck(std::string line)
{
    if (line[4] != '-' || line[7] != '-' || line[10] != ' ')
    {
        std::cout << "ERROR: Invalid date format detected => ";
        return true;
    }
    int year = std::atoi(line.substr(0, 4).c_str());
    int month = std::atoi(line.substr(5, 2).c_str());
    int day = std::atoi(line.substr(8, 2).c_str());

    if (year > 2024 || year < 2009 || month > 12 || month < 1 || day > 31 || day < 1)
    {
        std::cout << "ERROR: Invalid date range detected => ";
        return true;
    }
    if (month == 2 && day > 29)
    {
        std::cout << "ERROR: February cannot have more than 29 days => ";
        return true;
    }
    if (month % 3 == 0 && day > 30)
    {
        std::cout << "ERROR: Invalid day for the given month => ";
        return true;
    }
    date = line.substr(0, 10);
    return false;
}

bool BitcoinExchange::valueCheck(std::string line)
{
    unsigned int i = 13;
    int dot_count = 0;

    if (line[11] != '|' || line[12] != ' ' || !isdigit(line[13]))
    {
        std::cout << "ERROR: Invalid value format detected => ";
        return true;
    }
    
    while (isdigit(line[i]) || line[i] == '.')
    {
        if (line[i] == '.')
            dot_count++;
        if (dot_count > 1)
        {
            std::cout << "ERROR: Multiple dots on value => ";
            return true;
        }
        i++;
    }

    while (i < line.length())
    {
        if (line[i] != ' ' && line[i] != '\t')
        {
            std::cout << "ERROR: Invalid characters after numeric value => ";
            return true;
        }
        i++;
    }

    double n = std::atof(line.substr(line.find("|") + 1).c_str());
    if (n > 1000 || n < 0)
    {
        std::cout << "ERROR: Value out of range => ";
        return true;
    }
    value = n;
    return false;
}


bool BitcoinExchange::parser(std::string line){
    if (formatCheck(line) || dateCheck(line) || valueCheck(line))
        return true;
    return false;
}

void BitcoinExchange::coverter(const std::string input)
{
    std::ifstream in(input.c_str());
    std::string line;

    std::cout << std::fixed << std::setprecision(3);
    bool flag = false;
    while (std::getline(in, line))
    {
        if (!flag)
        {
            flag = true;
            if (line.compare("date | value"))
                std::cout << "format: \"date | value\" was not respected! " << std::endl;
        }
        else if (parser(line))
            std::cout << line << std::endl;
        else
        {
            std::map<std::string, double>::iterator it = database.find(date);
            if (it != database.end())
                std::cout << date << " => " << value << " = " << it->second * value << std::endl;
            else
            {
                it = database.lower_bound(date);
                if (it != database.begin())
                    --it;
                std::cout << date << " => " << value << " = " << it->second * value << std::endl;
            }
        }
    }
}
