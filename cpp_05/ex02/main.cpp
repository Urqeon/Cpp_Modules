#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat john("John", 50);
        
        ShrubberyCreationForm shrubberyForm("Garden");
        RobotomyRequestForm robotomyForm("Target");
        PresidentialPardonForm pardonForm("Victim");

        john.signForm(shrubberyForm);
        john.executeForm(shrubberyForm);
        
        john.signForm(robotomyForm);
        john.executeForm(robotomyForm);
        
        john.signForm(pardonForm);
        john.executeForm(pardonForm);
        
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
