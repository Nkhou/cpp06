#ifndef SERIALIZER_H
#define SERIALIZER_H
#include <cstdint>
#include <iostream>
struct Data
{
    int a;
    int b;
};

class Serializer
{
    private:
        Serializer();
        Serializer &operator=(Serializer const &other);
        Serializer(Serializer const &other);
    public:
        Serializer(Data Data);
        ~Serializer();
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};



#endif