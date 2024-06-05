#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template <typename T>

void iter(T *array, size_t length, void (*f)(const T &))
{
    if (!array || !length)
        return ;

    size_t i = 0;
    while (i < length)
    {
        f(array[i]);
        i++;
    }
}

template <typename T>

void print(const T &info)
{
    std::cout << info << std::endl;
}

#endif