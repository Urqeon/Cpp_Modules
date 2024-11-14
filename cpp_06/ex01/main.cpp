#include "Serializer.hpp"

int main()
{
    Data *ptr = new Data;
    ptr->i = 42;

    std::cout << ptr << std::endl;

    uintptr_t serializedData = Serializer::serialize(ptr);
    std::cout << serializedData << std::endl;

    Data *tmp =  Serializer::deserialize(serializedData);
    std::cout << tmp  << std::endl;

    delete ptr;

}