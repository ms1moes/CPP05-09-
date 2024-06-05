#include <iostream>
#include "Array.hpp"


int main()
{

    std::cout << "Empty array______________________________________" << std::endl;
    Array<int> obj;
    try
    {
       obj[0] = 1;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    


    std::cout << "int object array_________________________________" << std::endl;
    Array<int> int_obj(4);

    for (int i = 0; i < 4 ; i++)
        int_obj[i] = i;
    for (int i = 0; i < 4 ; i++)
        std::cout << int_obj[i] << std::endl;



    std::cout << "string object array_________________________________" << std::endl;
    Array<std::string> str_obj(4);
    str_obj[0] = "str 0";
    str_obj[1] = "str 1";
    str_obj[2] = "str 2";
    str_obj[3] = "str 3";

    for (int i = 0; i < 4 ; i++)
        std::cout << str_obj[i] << std::endl;



    std::cout << "copy const and assig_________________________________" << std::endl;
    Array<std::string> dale(str_obj); //copy from str obj
    for (int i = 0; i < 4 ; i++)
        std::cout << dale[i] << std::endl;

    Array<std::string> dale2(4);
    for (int i = 0 ; i < 4 ; i++)
        dale2[i] = "dale";

    std::cout << "updated value" << std::endl;
    dale = dale2; //changing 
    for (int i = 0 ; i < 4 ; i++)
        std::cout << dale[i] << std::endl;

    std::cout << "invalid index_________________________________" << std::endl;
    try
    {
        std::cout << dale[3] << std::endl; //should print
        std::cout << dale[5] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "BOOM " << e.what() << '\n';
    }
    

}