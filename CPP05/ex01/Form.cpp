#include "Form.hpp"

Form::Form() : name("empty"), isSigned(false), gradeToSign(0), gradeToExecute(0)
{
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form& copy) : name(copy.name), isSigned(copy.isSigned), gradeToSign(copy.gradeToSign), gradeToExecute(copy.gradeToExecute)
{
}

Form::~Form()
{
}

Form& Form::operator=(const Form& src)
{
    (void)src;
    return (*this);
}

const std::string Form::getName() const
{
    return (name);
}

int Form::getGradeToSign() const
{
    return (gradeToSign);
}

int Form::getGradeToExecute() const
{
    return (gradeToExecute);
}

bool Form::getIsSigned() const
{
    return (isSigned);
}

void Form::beSigned(Bureaucrat const &obj)
{
    if (obj.getGrade() > gradeToSign)
    {
        std::cout << obj.getName() << " cannot sign " << getName() << " because grade is too low" << std::endl;
        throw Form::GradeTooLowException();
    }
    isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("grade is too high !");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("grade is too low !");
}

std::ostream& operator<<(std::ostream& os, Form& object)
{
    os << "name: " << object.getName() <<  ", grade to sign: " << object.getGradeToSign() << ", grade to execute: " << object.getGradeToExecute() << std::endl;
    return (os);
}