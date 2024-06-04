#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5)
{
    _target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm(copy.getName(), copy.getGradeToSign(), copy.getGradeToExecute())
{
    *this = copy;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& src)
{
    _target = src._target;
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (!getIsSigned() || executor.getGrade() > getGradeToExecute())
        throw PresidentialPardonForm::pardonException();
    std::cout << _target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

const char *PresidentialPardonForm::pardonException::what() const throw()
{
    return "PresidentialPardonForm Exception: Form not signed or Grade too low to execute";
}