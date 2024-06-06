#include <iostream>
#include "Array.hpp"


int main()
{
    std::cout << "empty" << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;
    Array<int> empty;
    try
    {
       empty[0] = 42;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    std::cout << std::endl;

    std::cout << "with integers" << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;
    Array<int> arr_int(4);
    int i = -1;
    while(++i < 4)
    {
        arr_int[i] = i;
        std::cout << arr_int[i] << std::endl;
    }

    std::cout << std::endl;

    std::cout << "with strings" << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;
    Array<std::string> arr_str(4);
    arr_str[0] = "AAAA";
    arr_str[1] = "BBBB";
    arr_str[2] = "CCCC";
    arr_str[3] = "DDDD";
    i = -1;
    while(++i < 4)
        std::cout << arr_str[i] << std::endl;

    std::cout << std::endl;

    std::cout << "with a complex type" << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;
    Array< std::pair<int, std::string> > arr_pair(4);
    arr_pair[0] = std::make_pair(1, "one");
    arr_pair[1] = std::make_pair(2, "two");
    arr_pair[2] = std::make_pair(3, "three");
    arr_pair[3] = std::make_pair(42, "fourty two");
    i = -1;
    while(++i < 4)
        std::cout << arr_pair[i].first << ", " << arr_pair[i].second << std::endl;

    std::cout << std::endl;

    std::cout << "copy constructor" << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;
    Array<std::string> test1(arr_str);
    i = -1;
    while(++i < 4)
        std::cout << test1[i] << std::endl;

    std::cout << std::endl;
    
    std::cout << "assignment operator" << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;
    Array<std::string> test2(4);
    i = -1;
    while(++i < 4)
        test2[i] = "string";
    test1 = test2;
    i = -1;
    while(++i < 4)
        std::cout << test1[i] << std::endl;

    std::cout << std::endl;

    std::cout << "index out of bounds" << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;
    try
    {
        std::cout << test1[1] << std::endl;
        std::cout << test1[4] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;   
}