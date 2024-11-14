#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _gradeToSign;
        const int           _gradeToExecute;  
        //SETTERS
        void setIsSigned(bool value){_isSigned = value;}   

    
    public:
        Form(const std::string name, int gradeToSign, int gradeToExecute);
        ~Form();
        Form(const Form& copy);
        Form &operator=(const Form& copy);


        //GETTERS
        std::string getName() const {return _name;}
        bool isSigned() const {return _isSigned;}
        int getGradeToSign() const {return _gradeToSign;}
        int getGradeToExecute() const {return _gradeToExecute;}
        std::string isSignedStatus() const {return isSigned() ? "yes" : "No";}

        //ACTIONS
        void beSigned(const Bureaucrat& bureaucrat);

        class GradeTooHighException : public std::exception {
            public:
                const char *what() const throw()
                {
                    return "Grade is too high";
                }
        };

        class GradeTooLowException : public std::exception {
            public:
                const char *what() const throw()
                {
                    return "Grade is too low";
                }
        };

};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif 