#include "Span.hpp"

Span::Span()
{
    N = 0;
}

Span::Span(unsigned int N)
{
    this->N = N;
}

Span::Span(const Span &src)
{
    *this = src;
}

Span::~Span(){
}

Span &Span::operator=(const Span &src)
{
    if(this == &src)
        return *this;
    N = src.N;
    vect = src.vect;
    return *this;
}

void Span::addNumber(int nbr)
{
    if(vect.size() < N)
        vect.push_back(nbr);
    else
        throw std::out_of_range("cant add more numbers");
}

int Span::shortestSpan()
{
    if(vect.size() < 2)
        throw std::out_of_range("not enough numbers");
    std::sort(vect.begin(), vect.end());
    int min = INT_MAX;
    for (unsigned int i = 0; i < vect.size() - 1; i++)
        min = std::min(min, (vect[i + 1] - vect[i]));
    return min;
}

int Span::longestSpan()
{
    if(vect.size() < 2)
        throw std::out_of_range("not enough numbers");
    std::sort(vect.begin(), vect.end());
    return vect[vect.size() - 1] - vect[0];
}

void Span::improvedAddNumber(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
    if (vect.size() + std::distance(start, end) > N)
        throw std::out_of_range("too much numbers");
    vect.insert(vect.end(), start, end);
}
