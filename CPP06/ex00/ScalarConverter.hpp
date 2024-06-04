#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP


#include <string>
#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <limits>

class ScalarConverter
{
public:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& copy);
    ~ScalarConverter();
    ScalarConverter& operator=(const ScalarConverter& src);

    static void convert(const std::string str);
};

int getType(std::string str);

int isChar(std::string str);
int isInt(std::string str);
int isFloat(std::string str);
int isDouble(std::string str);

void getChar(std::string str);
void getInt(std::string str);
void getFloat(std::string str);
void getDouble(std::string str);

#endif