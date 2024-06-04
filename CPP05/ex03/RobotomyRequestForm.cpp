#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
}   

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
    _target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm(copy.getName(), copy.getGradeToSign(), copy.getGradeToExecute())
{
    *this = copy;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
    _target = src._target;
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (!getIsSigned() || executor.getGrade() > getGradeToExecute())
        throw RobotomyRequestForm::robotomyException();
    srand((unsigned) time(0));
    if (rand() % 2 == 0)
        std::cout << "*drilling noises* " << _target << " has been robotomized" << std::endl;
    else
        std::cout << "*drilling noises* " << _target << " was not robotomized" << std::endl;
}

const char *RobotomyRequestForm::robotomyException::what() const throw()
{
    return "RobotomyRequestForm Exception: Form not signed or Grade too low to execute";
}