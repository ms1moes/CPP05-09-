# include "AForm.hpp"
# include "Intern.hpp"
# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

int main()
{
    Bureaucrat nbr1("BOB", 1);
    Intern my_intern;

    AForm *form1 = my_intern.makeForm("shrubbery", "shrub");
    if (form1)
    {
        nbr1.signForm(*form1);
        form1->execute(nbr1);
        delete form1;
    }
    else
    {
        std::cout << "not able to create form" << std::endl;
    }
    std::cout << std::endl;

    AForm *form2 = my_intern.makeForm("robotomy", "robot");
    if (form2)
    {
        nbr1.signForm(*form2);
        form2->execute(nbr1);
        delete form2;
    }
    else
    {
        std::cout << "not able to create form" << std::endl;
    }
    std::cout << std::endl;

    AForm *form3 = my_intern.makeForm("presidential", "president");
    if (form3)
    {
        nbr1.signForm(*form3);
        form3->execute(nbr1);
        delete form3;
    }
    else
    {
        std::cout << "not able to create form" << std::endl;
    }
    std::cout << std::endl;

    AForm *form4 = my_intern.makeForm("BAD FORM", "NotWorking");
    (void)form4;

    return 0;
}
