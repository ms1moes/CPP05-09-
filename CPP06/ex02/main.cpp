#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base* generate(void)
{
    srand(time(NULL));
    int n = rand() % 3;

    if (n == 0)
        return (new A());
    else if (n == 1)
        return (new B());
    else 
        return (new C());
}

void identify(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "class type A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "class type B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "class type C" << std::endl;
    else    
        std::cout << "UNKNOWN" << std::endl;
}

void identify(Base& p){
    try
    {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "class type A" << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {
    }
    try
    {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "class type B" << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {
    }
    try
    {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "class type C" << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {
    }
    std::cout << "UNKNOWN" << std::endl;
}

int main(){

    Base *base1 = new Base(); //since this is not a derived class, it will output "UNKNOWN"
    Base *base2 = generate();

    identify(base1);
    identify(base2);
    std::cout << std::endl;
    identify(*base1);
    identify(*base2);
    
    delete base1;
    delete base2;
}