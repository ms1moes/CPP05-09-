#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137)
{
    _target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy.getName(), copy.getGradeToSign(), copy.getGradeToExecute())
{
    *this = copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
    _target = src._target;
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!getIsSigned() || executor.getGrade() > getGradeToExecute())
        throw ShrubberyCreationForm::shrubberyException();
    std::string file_name;
    file_name = _target;
    file_name += "_shrubbery";
    std::ofstream file(file_name.c_str());
    if (!file.is_open())
        std::cout << "Error opening file " << file_name << std::endl;
    std::string tree = 
    "    ccee88oo\n"
    "  C8O8O8Q8PoOb o8oo\n"
    " dOB69QO8PdUOpugoO9bD\n"
    "CgggbU8OU qOp qOdoUOdcb\n"
    "     6OuU  /p u gcoUodpP\n"
    "       \\\\\\//  /douUP\n"
    "         \\\\\\////\n"
    "           |||/\\\n"
    "           |||\\/\n"
    "           |||||\n"
    "   .........||||..........\n";
    file << tree;
    file.close();
    std::cout << _target << " file got created by " << executor.getName() << std::endl;
}

const char *ShrubberyCreationForm::shrubberyException::what() const throw()
{
    return "ShrubberyCreationForm Exception: Form not signed or Grade too low to execute";
}