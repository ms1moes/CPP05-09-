#include <cstdlib>
#include <ctime>
#include "Span.hpp"

int main()
{
{
    std::cout << "range exception test: " << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;
    try
    {
        Span sp(5);

        for (int i = 1; i <= 10; ++i)
            sp.addNumber(i);
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << e.what() << std::endl;
    }
}
     std::cout << std::endl; 
{
    std::cout << "1 or less nbrs exception test: " << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;

    try
    {
        Span sp(1);
        sp.addNumber(3);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << e.what() << std::endl;
    }
}
     std::cout << std::endl; 
{
    std::cout << "2 numbers test: " << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;

    try
    {
        Span sp(2);
        sp.addNumber(1);
        sp.addNumber(5);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << e.what() << std::endl;
    }
}
    std::cout << std::endl; 
{
    std::cout << "subject test: " << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;
}
   std::cout << std::endl; 
{
    std::cout << "10000 random numbers test: " << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;

    srand(time(NULL));
    std::vector<int> numbers(10000);
    for (int i = 0; i < 10000; ++i)
        numbers[i] = rand();
    Span sp2(10000);
    try
    {
        sp2.improvedAddNumber(numbers.begin(), numbers.end());
        std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << e.what() << std::endl;
    }   
}
    return 0;
}
