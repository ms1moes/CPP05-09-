#include "RPN.hpp"

RPN::RPN(){}

RPN::RPN(const RPN& src)
{
    *this = src;
}

RPN::~RPN(){}

RPN& RPN::operator=(const RPN& src)
{
    (void)src;
    return *this;
}

bool RPN::isOperator(const char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    return false;
}

void RPN::validate(const std::string str )
{
    for (unsigned int i = 0; i < str.size() ; i++)
    {
        if (str[i] != ' ' && str[i] != '+' && str[i] != '-' && str[i] != '/' && str[i] != '*' && !isdigit(str[i]))
        {
            std::cout << "invalid character" << std::endl;
            exit(1) ;
        }
        if (isdigit(str[i]) || isOperator(str[i]))
            if (str[i + 1] && str[i + 1] != ' ')
            {
                std::cout << "invalid format (no space)" << std::endl;
                exit(1) ;
            }
    }
}

int RPN::calculate(int n1, int n2, char op)
{
    switch (op)
    {
    case '+':
        return n1 + n2;
    case '-':
        return n1 - n2;
    case '*':
        return n1 * n2;
    case '/':
        if (n1 == 0 || n2 == 0)
        {
            std::cout << "division by 0" << std::endl;
            exit (1);
        }
        return n1 / n2;
    }
    return 0;
}
    



void RPN::handleNotation(const std::string str)
{
    std::stack<int, std::list<int> > stack;
    std::string tmp;
    int n1;
    int n2;
    int result;

    for (unsigned int i = 0; i < str.size(); i++)
    {
        if (isdigit(str[i]))
            stack.push(std::atoi(&str[i]));
        else if (isOperator(str[i]))
        {
            if (stack.size() < 2)
            {
                std::cout << "invalid format, missing numbers" << std::endl;
                return ;
            }
            n1 = stack.top();
            stack.pop();
            n2 = stack.top();
            stack.pop();
            result = calculate(n2, n1, str[i]);
            stack.push(result);
        }
    }
    if (stack.size() != 1)
    {
        std::cout << "invalid format" << std::endl;
        return ;
    }
    std::cout << stack.top() << std::endl;
}