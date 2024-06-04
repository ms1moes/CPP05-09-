#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <iostream>

class Intern
{
public:
    Intern();
    Intern(const Intern& copy);
    ~Intern();
    Intern& operator=(const Intern& src);
    AForm *makeForm(std::string form, std::string target);
   
};

#endif