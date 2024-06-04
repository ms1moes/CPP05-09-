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

int Bureaucrat::getGrade() const
{
    return grade;
}

const std::string Bureaucrat::getName() const 
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

void Bureaucrat::signForm(AForm& form) const
{
    if (grade > form.getGradeToSign())
    {
        std::cout << name << " cannot sign " << form.getName() << " because grade is too low" << std::endl;
        throw AForm::GradeTooLowException();
    }
    std::cout << name << " signed " << form.getName() << std::endl;
    form.beSigned(*this);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("grade is too high !");
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
     return ("grade is too low !");
}

void Bureaucrat::executeForm(AForm const &form) const
{
   if (!form.getIsSigned() || grade > form.getGradeToExecute())
   {
        std::cout << name << " was not able to execute " << form.getName() << std::endl;
        return ;
   }
    std::cout << name << " executed " << form.getName() << std::endl;

}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& object)
{
    os << object.getName() << ", bureucrat grade " << object.getGrade() << std::endl;
    return os;
}
