#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
    *this = copy;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
    (void)src;
    return *this;
}

void ScalarConverter::convert(std::string input)
{
    std::string literals[] = {"nanf", "+inff", "-inff", "nan", "+inf", "-inf"};

    for (size_t i = 0; i < 6; i++)
        if (input == literals[i])
        {   
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(strtod(input.c_str(), NULL)) << 'f' << std::endl;
            std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(strtod(input.c_str(), NULL)) << std::endl;
            return;
        }

    switch (getType(input))
    {
    case 0:
        getChar(input);
        break;
    case 1:
        getInt(input);
        break;
    case 2:
        getFloat(input);
        break;
    case 3:
        getDouble(input);
        break;
    default:
        std::cout << "error: invalid input" << std::endl;
        break;
    }

}

int getType(std::string str)
{
    if (isChar(str))
        return 0;
    if (isInt(str))
        return 1;
    if (isFloat(str))
        return 2;
    if (isDouble(str))
        return 3;
    return -1;
}

int isChar(std::string str)
{
    if (str.length() == 1 && !isdigit(str[0]))
        return 1;
    return 0;
}

int isInt(std::string str)
{
    int i = 0;

    if (str[i] == '+' || str[i] == '-')
        i++;
    while (str[i] && isdigit(str[i]))
        i++;
    if (str[i])
        return 0;
    return 1;
}

int isFloat(std::string str)
{
    int i = 0;
    int dot = 0;
    int nbr = 0;
    int f = 0;

    if (str[i] == '+' || str[i] == '-')
        i++;
    while (str[i])
    {
        if (str[i] == '.')
        {
            if (!std::isdigit(str[i + 1]))
                return 0;
            dot++;
        }
        if (isdigit(str[i]))
            nbr++;
        if (str[i] == 'f')
            f++;
        if (!std::isdigit(str[i]) && (str[i] != '.' && str[i] != 'f'))
            break;
        i++;
    }
    if (dot == 1 && nbr && f == 1 && str[i - 1] == 'f')
        return 1;
    return 0;
}

int isDouble(std::string str)
{
    int i = 0;
    int dot = 0;
    int nbr = 0;

    if (str[i] == '+' || str[i] == '-')
        i++;
    while (str[i])
    {
        if (str[i] == '.')
        {
            if (!std::isdigit(str[i + 1]))
                return 0;
            dot++;
        }
        if (isdigit(str[i]))
            nbr++;
        if (!std::isdigit(str[i]) && str[i] != '.')
            break;
        i++;
    }
    if (dot == 1 && nbr && str[i] == '\0')
        return 1;
    return 0;
}

void getChar(std::string str)
{
    if (!std::isprint(str[0]))
        std::cout << "Char: not printable" << std::endl;
    else
        std::cout << "Char: '" << str[0] << "'" << std::endl; 
    std::cout << "Int: " << static_cast<int>(str[0]) << std::endl;
    std::cout << "Float: " << static_cast<float>(str[0]) << ".0f" << std::endl;
    std::cout << "Double: " << static_cast<double>(str[0]) << ".0" << std::endl;
}

void getInt(std::string str)
{
    long long int n = std::atoll(str.c_str());

    if (n > 31 && n < 128)
        std::cout << "Char: '" << static_cast<char>(n) << "'" << std::endl;
    else
        std::cout << "Char: character is unprintable" << std::endl;
    if (n > 2147483647 || n < -2147483648)
        std::cout << "Int: overflow" << std::endl;
    else 
        std::cout << "Int: " << n << std::endl;
    std::cout << "Float: " << std::fixed << std::setprecision(1) << static_cast<float>(n) << "f" << std::endl;
    std::cout << "Double: " << std::setprecision(1) << static_cast<double>(n) << std::endl;
}

void    getFloat(std::string str)
{
    float n = std::atof(str.c_str());

    if (n > 31 && n < 128)
		std::cout << "Char: '" << static_cast<char>(n) << "'" << std::endl;
	else
		std::cout << "Char: character is unprintable" << std::endl;
	if (static_cast<int>(n) > 2147483647 || static_cast<int>(n) <= -2147483648) 
		std::cout << "Int: overflow" << std::endl;
	else
		std::cout << "Int: " << static_cast<int>(n) << std::endl;

    std::cout << "Float: "  << std::fixed << std::setprecision(1) << n << 'f' << std::endl;
    std::cout << "Double: " << std::setprecision(1) << static_cast<double>(n) << std::endl;
}

void getDouble(std::string str)
{
    double n = strtod(str.c_str(), NULL);

	if (n > 31 && n < 128)
		std::cout << "Char: '" << static_cast<char>(n) << "'" << std::endl;
	else
		std::cout << "Char: character is unprintable" << std::endl;
	if (n > 2147483647 || n < -2147483648) 
		std::cout << "Int: overflow" << std::endl;
	else
		std::cout << "Int: " << static_cast<int>(n) << std::endl;

    std::cout << "Float: " << std::fixed << std::setprecision(1) << static_cast<float>(n) << 'f' << std::endl;
    std::cout << "Double: " << std::fixed << std::setprecision(1) << n << std::endl;
}
