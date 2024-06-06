#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template<class T>
Array<T>::Array()
{
    array = NULL;
    length = 0;
}

template<class T>
Array<T>::Array(unsigned int n)
{
    array = new T[n];
    length = n;
}

template<class T>
Array<T>::Array(const Array &src)
{
    array = NULL;
    length = 0;
    *this = src;
}

template<class T>
Array<T>::~Array()
{
    delete[] array;
}

template<class T>
Array<T> &Array<T>::operator=(const Array &src)
{
	if (this == &src)
		return *this;
	if (this->array)
		delete[] array;
	array = new T[src.length];
	for (unsigned int i = 0; i < src.length; i++)
		array[i] = src.array[i];
    length = src.length;
	return *this;
}

template<class T>
unsigned int Array<T>::size() const
{
	return length;
}

template<class T>
T& Array<T>::operator[](const int index)
{

	if (index < 0 || index >= (int)length)
		throw std::out_of_range("index out of bounds");
	return array[index];

}
#endif