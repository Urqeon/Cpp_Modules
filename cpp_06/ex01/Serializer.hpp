#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <cstdint>

struct Data
{
	int i;
};

class Serializer
{
    private:
	    Serializer();
	    ~Serializer();
	    Serializer(const Serializer& oth);
	    Serializer& operator=(const Serializer& oth);

    public:
        static uintptr_t serialize(Data *ptr);
        static Data* deserialize(uintptr_t raw);
        
};

#endif