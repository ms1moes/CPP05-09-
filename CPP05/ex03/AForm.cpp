#include "AForm.hpp"

AForm::AForm() : name("empty"), isSigned(false), gradeToSign(0), gradeToExecute(0)
{
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& copy) : name(copy.name), isSigned(copy.isSigned), gradeToSign(copy.gradeToSign), gradeToExecute(copy.gradeToExecute)
{
    *this = copy;
}

AForm::~AForm()
{
}

AForm& AForm::operator=(const AForm& src)
{
    isSigned = src.getIsSigned();
    return (*this);
}

const std::string AForm::getName() const
{
    return (name);
}

int AForm::getGradeToSign() const
{
    return (gradeToSign);
}

int AForm::getGradeToExecute() const
{
    return (gradeToExecute);
}

bool AForm::getIsSigned() const
{
    return (isSigned);
}

void AForm::beSigned(Bureaucrat const &obj)
{
    if (obj.getGrade() > gradeToSign)
    {
        std::cout << obj.getName() << " cannot sign " << getName() << " because grade is too low" << std::endl;
        throw AForm::GradeTooLowException();
    }
    isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("grade is too high !");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("grade is too low !");
}

std::ostream& operator<<(std::ostream& os, AForm& object)
{
    os << "name:" << object.getName() << " required Grade: " << object.getGradeToExecute() << " exec grade: " << object.getGradeToSign() << std::endl;
    return (os);
}