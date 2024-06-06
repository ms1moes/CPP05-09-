#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>
#include <list>
#include <vector>
#include <iterator>

template<typename T>
class MutantStack : public std::stack<T>
{
   public:
        MutantStack();
        MutantStack(const MutantStack &src);
        ~MutantStack();
        MutantStack &operator=(const MutantStack &src);
        typedef typename std::deque<T>::iterator iterator;
        iterator begin()
        {
            return this->c.begin();
        }
        iterator end()
        {
            return this->c.end();
        }
};

template<typename T>
MutantStack<T>::MutantStack(){}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack &src)
{
    *this = src;
}

template<typename T>
MutantStack<T>::~MutantStack(){}

template<typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &src)
{
    (void)src;
    return *this;
}

#endif