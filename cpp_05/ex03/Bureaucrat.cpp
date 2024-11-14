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

void Bureaucrat::signForm(AForm& form)
{
    try
    {
        form.beSigned(*this);
        std::cout << getName() << " signed " << form.getName() << std::endl;
    }
    catch (const AForm::GradeTooLowException& e)
    {
        std::cout << getName() << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form) const {
    try {
        form.execute(*this);
        std::cout << getName() << " executed " << form.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cout << getName() << " couldn’t execute " << form.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return out;
}