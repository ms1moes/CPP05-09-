# include "MutantStack.hpp"
int main( void ) 
{
    std::cout << "SUBJECT TEST" << std::endl;
    std::cout << "---------------------------------------" << std::endl;
	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;

		mstack.pop();

		std::cout << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it; 	

		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
    std::cout << std::endl;
	std::cout << "COMPARING WITH LIST" << std::endl;
    std::cout << "---------------------------------------" << std::endl;
	{
		std::list<int> lstack;

		lstack.push_front(5);
		lstack.push_front(17);

		std::cout << lstack.front() << std::endl;

		lstack.pop_front();

		std::cout << lstack.size() << std::endl;

		lstack.push_back(3);
		lstack.push_back(5);
		lstack.push_back(737);
		lstack.push_back(0);

		std::list<int>::iterator it = lstack.begin();
		std::list<int>::iterator ite = lstack.end();

		++it;
		--it; 	

		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
    std::cout << std::endl;
    std::cout << "MORE TESTS USING STRINGS" << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    {
        
        MutantStack<std::string> sstack;

        sstack.push("one");
        sstack.push("two");
        sstack.push("three");
        sstack.push("four");
        sstack.push("five");

        std::cout << "size: " << sstack.size() << std::endl;
        std::cout << "* adding 3 strings *" << std::endl;
        sstack.push("six");
        sstack.push("seven");
        sstack.push("eight");
        std::cout << "size: " << sstack.size() << std::endl;
        std::cout << "* printing strings and deleting them *" << std::endl;
        MutantStack<std::string>::iterator it = sstack.begin();
        MutantStack<std::string>::iterator ite = sstack.end();
        while (it != ite)
        {
            std::cout << *it << std::endl;
            sstack.pop();
            ++it;
        }
        std::cout << "size after deleting: " << sstack.size() << std::endl;
        std::cout << std::endl;
        std::cout << "copy constructor test" << std::endl;
        sstack.push("one");
        sstack.push("two");
        sstack.push("three");
        std::stack<std::string> copytest(sstack);
        std::cout << copytest.size() << std::endl;
        std::cout << copytest.top() << std::endl;
    }

    return 0;
}
