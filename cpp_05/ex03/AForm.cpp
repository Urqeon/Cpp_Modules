#include "AForm.hpp"

AForm::AForm(const std::string name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::~AForm(){}

AForm::AForm(const AForm& copy) : _name(copy.getName()),
                               _gradeToSign(getGradeToSign()),
                               _gradeToExecute(getGradeToExecute()) {
    *this = copy;
}

AForm &AForm::operator=(const AForm& copy) {
    if (this == &copy)
        return *this;
    _isSigned = copy._isSigned;
    return *this;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > getGradeToSign())
        throw GradeTooLowException();
    setIsSigned(true);
}

std::ostream& operator<<(std::ostream& out, const AForm& form)
{
    out << form.getName() << ", form grade to sign " << form.getGradeToSign()
        << ", form grade to execute " << form.getGradeToExecute()
        << ", is signed " << form.isSignedStatus() << std::endl;
    return out;
}