#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    {
        std::cout << "invalid form creation" << std::endl;
        std::cout << "-----------------------------------" << std::endl;
        try
        {
            Form form1("wrong_form", 160, 4);
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << std::endl;
            std::cout << "not able to create form" << std::endl;
        }
        std::cout << std::endl;

        std::cout << "valid form creation" << std::endl;
        std::cout << "-----------------------------------" << std::endl;
        try
        {
            Form form2("correct_form", 150, 1);
            std::cout << form2 << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << std::endl;
            std::cout << "not able to create form" << std::endl;
        }
    }
    {

        std::cout << "signing form without valid grade" << std::endl;
        std::cout << "-----------------------------------" << std::endl;

        Bureaucrat bureau1("teste1", 3);
        Bureaucrat bureau2("teste2", 1);
        Form form1("good_form", 1, 5);
        try
        {
            bureau1.signForm(form1);
            
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
        
        std::cout << std::endl;
        std::cout << "signing form with valid grade" << std::endl;
        std::cout << "-----------------------------------" << std::endl;
        
        bureau2.signForm(form1);   
    }


}