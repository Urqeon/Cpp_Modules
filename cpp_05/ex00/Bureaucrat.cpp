#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
    if(grade < 1)
        throw GradeTooHighException();
        
    if(grade > 150)
        throw GradeTooLowException();
}
Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy.getName()) {
    *this = copy;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& copy) {
    if (this == &copy)
        return *this;
    _grade = copy._grade;
    return *this;
}

void Bureaucrat::incrementGrade()
{
    if (getGrade() <= 1)
        throw GradeTooHighException();
    setGrade(getGrade() - 1);
}

void Bureaucrat::decrementGrade()
{
    if (getGrade() >= 150)
        throw GradeTooLowException();
    setGrade(getGrade() + 1);
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return out;
}
