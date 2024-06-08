#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>
#include <bits/stdc++.h>

class RPN
{
    public:
        RPN();
        RPN(const RPN& src);
        ~RPN();
        RPN& operator=(const RPN& src);

        static bool isOperator(const char c);
        static void handleNotation(const std::string str);
        static void validate(const std::string str);
        static int calculate(int, int, char);


};

#endif