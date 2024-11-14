#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "AForm.hpp"

class AForm;


class Bureaucrat
{
    private:
       std::string _name;
        int _grade;
    //SETTERS
        void setName(std::string name){_name = name;}
        void setGrade(int grade){_grade = grade;}

    public:
        Bureaucrat(const std::string name, int grade);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat& copy);
        Bureaucrat &operator=(const Bureaucrat& copy);

    //GETTERS
        std::string getName() const {return _name;}
        int getGrade() const {return _grade;};


    //ACTIONS
        void incrementGrade();
        void decrementGrade();
        void signForm(AForm& form);
        void executeForm(AForm const & form) const;

        class GradeTooHighException : public std::exception {
                const char *what() const throw()
                {
                    return "Grade is too high";
                }
        };

        class GradeTooLowException : public std::exception {
                const char *what() const throw()
                {
                    return "Grade is too low";
                }
        };


};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif