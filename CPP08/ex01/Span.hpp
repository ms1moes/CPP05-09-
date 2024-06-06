#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

class Span
{
    private:
        unsigned int N;
        std::vector<int> vect;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span &src);
        ~Span();
        Span &operator=(const Span &src);

        void addNumber(int nbr);
        int shortestSpan();
        int longestSpan();

        void improvedAddNumber(std::vector<int>::iterator start, std::vector<int>::iterator end);
        void printNums();
};

#endif