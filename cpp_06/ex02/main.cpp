#include "Base.hpp"

void initializeRandomSeed() {
    clock_t time_now = clock();
    srand(time_now);
}

int main()
{
    initializeRandomSeed();
    
    Base *base = generate();
	identify(base);
	identify(*base);
	delete base;

}