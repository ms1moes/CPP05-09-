#include "Intern.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(const Intern& copy)
{
    *this = copy;
}

Intern& Intern::operator=(const Intern& src)
{
    (void)src;
    return *this;
}

AForm* Intern::makeForm(std::string form, std::string target)
{
    std::string formName[3] = {"shrubbery", "robotomy", "presidential"};
    int i = -1;

    while (++i < 3)
    {
       if(!formName[i].compare(form))
        break;
    }
    
    switch (i)
    {
    case 0:
        std::cout << "Intern creates " << form << std::endl;
        return new ShrubberyCreationForm(target);
        break;
    case 1:
        std::cout << "Intern creates " << form << std::endl;
        return new RobotomyRequestForm(target);
        break;
    case 2:
        std::cout << "Intern creates " << form << std::endl;
        return new PresidentialPardonForm(target);
        break;
    default:
        std::cout << "Intern cannot create " << form << std::endl;
        return NULL;
    }
}