#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("empty"), grade(150)
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name) 
{
    if(grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else if(grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else
        this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy)
{
    *this = copy;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src)
{
    grade = src.grade;
    return *this;
}

int Bureaucrat::getGrade()
{
    return grade;
}

const std::string Bureaucrat::getName()
{
    return name;
}

void Bureaucrat::Increment()
{
    if (grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    else 
        grade--;
}

void Bureaucrat::Decrement()
{
    if (grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("grade is too high !");
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
     return ("grade is too low !");
}

std::ostream& operator<<(std::ostream& os, Bureaucrat& object)
{
    os << object.getName() << ", bureucrat grade " << object.getGrade() << std::endl;
    return os;
}