#include "Form.hpp"

int main()
{
    try
    {
    Bureaucrat john("John Doe", 50);
    std::cout << john << std::endl;

    Form gus("Gus",66,44);
    john.signForm(gus);

    Form sophia("sophia", 40, 80);
    john.signForm(sophia);

    std::cout << gus << std::endl;
    std::cout << sophia << std::endl;


    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}