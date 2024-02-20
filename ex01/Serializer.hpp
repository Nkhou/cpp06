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
    public:
        ~Serializer();
        Serializer();
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};



#endif