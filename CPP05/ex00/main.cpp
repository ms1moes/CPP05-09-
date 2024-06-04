#include "Bureaucrat.hpp"

int main()
{
    {
        std::cout << "valid bureaucrat creation" << std::endl;
        std::cout << "-----------------------------------" << std::endl;
        try
        {
            Bureaucrat nbr1("high", 1);
            Bureaucrat nbr2("low", 150);
            std::cout << nbr1;
            std::cout << nbr2;    
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << std::endl;
            std::cout << "not able to create bureaucrat" << std::endl;
        }

        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "invalid bureaucrat creation" << std::endl;
        std::cout << "-----------------------------------" << std::endl;
        try
        {
            Bureaucrat nbr3("supaLow", 151);
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << std::endl;
            std::cout << "not able to create bureaucrat" << std::endl;
        }
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::cout << "valid increment/decrement"<< std::endl;
        std::cout << "-----------------------------------" << std::endl;
        try
        {
            Bureaucrat nbr1("high", 1);
            Bureaucrat nbr2("low", 150);
            nbr1.Decrement();
            nbr2.Increment();
            std::cout << nbr1;
            std::cout << nbr2;

            std::cout << std::endl;
            std::cout << std::endl;

            std::cout << "invalid increment/decrement"<< std::endl;
            std::cout << "-----------------------------------" << std::endl;
            Bureaucrat nbr3("bad", 1);
            nbr3.Increment();
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
            std::cout << "not able to increment grade" << std::endl;
        }
    }
}