# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

int main()
{
    {
        std::cout << "Shrubbery form test" << std::endl;
        std::cout << "-----------------------------------" << std::endl;
        Bureaucrat nbr1("test1", 145);
        Bureaucrat nbr2("test2", 1);
        ShrubberyCreationForm form1("Shrubbery");
        nbr1.signForm(form1);
        try
        {
            form1.execute(nbr2);
            form1.execute(nbr1);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << std::endl;
    std::cout << std::endl;
    {
        std::cout << "Presidential form test" << std::endl;
        std::cout << "-----------------------------------" << std::endl;
        Bureaucrat nbr1("test1", 145);
        Bureaucrat nbr2("test2", 1);
        PresidentialPardonForm form1("Presidential");
        nbr2.signForm(form1);
        try
        {
            form1.execute(nbr2);
            form1.execute(nbr1);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << std::endl;
    std::cout << std::endl;
    {
        std::cout << "Robotomy form test" << std::endl;
        std::cout << "-----------------------------------" << std::endl;
        Bureaucrat nbr1("test1", 145);
        Bureaucrat nbr2("test2", 1);
        RobotomyRequestForm form1("Robotomy");
        nbr2.signForm(form1);
        try
        {
            form1.execute(nbr2);
            form1.execute(nbr1);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    std::cout << std::endl;
    std::cout << std::endl;
    {
        std::cout << "Bureaucrat form execution method"<< std::endl;
        std::cout << "-----------------------------------" << std::endl;

        Bureaucrat nbr1("test1", 145);
        Bureaucrat nbr2("test2", 1);
        RobotomyRequestForm form1("Robotomy");
        nbr2.signForm(form1);

        nbr1.executeForm(form1);
        nbr2.executeForm(form1);
    }
    return 0;
}