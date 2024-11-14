#include "Base.hpp"

Base::~Base(){}


Base* generate()
{
    int randValue = rand() % 3;

    if (randValue == 0)
        return new A();
    else if (randValue == 1)
        return new B();
    else
        return new C();
}
void identify(Base* p) {
    if (dynamic_cast<A*>(p)) 
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p)) 
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p)) 
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p); 
        std::cout << "A" << std::endl;
    } catch (std::bad_cast&) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
    } catch (std::bad_cast&) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
    } catch (std::bad_cast&) {}
}
