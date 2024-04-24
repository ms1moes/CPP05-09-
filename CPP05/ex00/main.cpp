#include "Bureaucrat.hpp"

//main do leandroooooooooooooooooooo falta mudar
int main()
{
    {
        std::cout << "__________________valid Bure creation//invalid__________________" << std::endl;

        try
        {
            Bureaucrat b1("Thomas Turban", 1);
            Bureaucrat b2("Isadora pin", 150);
            std::cout << b1;
            std::cout << b2;    
            std::cout << "no exception thrown " << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << std::endl;
            std::cout << "invalid Bure creation detected, please check values meu parceiro" << std::endl;
        }

        std::cout << "invalid creation here .............:" << std::endl;
        try
        {
            //Bureaucrat b4("Cuca Beludo", 0);
            Bureaucrat b3("Cuca Beludo", 160);
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << std::endl;
            std::cout << "invalid Bure creation detected, please check values meu parceiro" << std::endl;
        }
        
    }

    {
        std::cout << '\n';
        std::cout << '\n';
        std::cout << "____________________________valid/invalid increment or decrement_____________________"<< std::endl;
        
        try
        {
            Bureaucrat b1("Armando", 1);
            Bureaucrat b2("Jacinto", 150);
            b1.Decrement();
            b2.Increment();
            std::cout << b1;
            std::cout << b2;

            std::cout << "invalid incremente/decrement :" << std::endl;
            Bureaucrat b4("fael", 1);
            b4.Increment();
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
            std::cout << "not able to incremet meu anjo" << std::endl;
        }

        
    }

}