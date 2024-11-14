#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
    const std::string   _name;
    bool                _isSigned;
    const int           _gradeToSign;
    const int           _gradeToExecute;
    void setIsSigned(bool value){_isSigned = value;}

    public:
        AForm(const std::string name, int gradeToSign, int gradeToExecute);
        virtual ~AForm();
        AForm(const AForm& copy);
        AForm &operator=(const AForm& copy);

        //GETTERS
        std::string getName() const {return _name;}
        bool isSigned() const {return _isSigned;}
        int getGradeToSign() const {return _gradeToSign;}
        int getGradeToExecute() const {return _gradeToExecute;}
        std::string isSignedStatus() const {return isSigned() ? "yes" : "No";}

        void beSigned(const Bureaucrat& bureaucrat);

        class GradeTooHighException : public std::exception {
            public:
                const char *what() const throw(){
                    return "Grade is too high";}
        };

        class GradeTooLowException : public std::exception {
            public:
                const char *what() const throw(){
                    return "Grade is too low";}
        };

        class FormNotSignedException : public std::exception {
            public:
                const char *what() const throw() {
                    return "Form is not signed";}
        };

        virtual void execute(Bureaucrat const & executor) const = 0;

};

std::ostream& operator<<(std::ostream& out, const AForm& form);


#endif 




