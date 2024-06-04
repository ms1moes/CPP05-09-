#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include <iostream>

struct Data
{
    int n1;
    int n2;
};

class Serializer
{
private:
    Serializer();
public:
    Serializer(const Serializer& obj);
    ~Serializer();
    Serializer &operator=(const Serializer& obj);

    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif