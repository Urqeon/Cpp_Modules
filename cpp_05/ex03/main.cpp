#include <iostream>
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <exception>


int main() {
    Intern slave;
    AForm* form;
 
 try{

    form = slave.makeForm("shrubbery creation", "Bender");

    Bureaucrat jo("John",42);

    jo.signForm(*form);
    jo.executeForm(*form);
    delete form;
    }

    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    AForm* form2;
    try{
        form2 = slave.makeForm("void request", "Bender");
        delete form2;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    
    return 0;  
}

