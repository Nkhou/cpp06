#include "Serializer.hpp"

int main(int argc, char *argv[])
{
    (void)argv;
    (void)argc;
    // if (argc != 2)
    //     return (1);
    Serializer Serializer;
    Data data;
    data.a = 7;
    data.b = 10;
    uintptr_t ptr = Serializer.serialize(&data);
    Data *ptr2 = Serializer.deserialize(ptr);
    ptr2++;
    std::cout << "a: " << ptr2 << std::endl;
    std::cout << "a: " << ptr2->a << std::endl;
    std::cout << "b: " << ptr2->b << std::endl;
    std::cout << "ptr: " << ptr << std::endl;
    std::cout << "ptr2: " << ptr2 << std::endl;
    std::cout << "data: " << &data << std::endl;
    return (0);
}