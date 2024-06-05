#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
#include <stdexcept>

template <typename T>
class Array
{
    private:
        T *array;
        unsigned int length;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array &src);
        ~Array();

        Array &operator=(const Array &src);
        T &operator[](const int index);

        unsigned int size() const;
};

#include "Array.tpp"

#endif