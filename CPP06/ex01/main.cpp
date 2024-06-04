#include "Serializer.hpp"

int main()
{
    Data *data = new Data();
    data->n1 = 42,
    data->n2 = 24;

    std::cout << "address of Data: " << data << std::endl; 
    std::cout << "first value: " << data->n1 << std::endl;
    std::cout << "second value: " << data->n2 << std::endl;
    
    
    uintptr_t ptr = Serializer::serialize(data); 
	Data *d2 = Serializer::deserialize(ptr);
    
    std::cout << "------------------------" << std::endl;
    std::cout << std::endl;

    std::cout << "source numbers" << std::endl;
    std::cout << data->n1 << std::endl;
    std::cout << data->n2 << std::endl;

    std::cout << std::endl;

    std::cout << "after convertions " << std::endl;
    std::cout << d2->n1 << std::endl;
    std::cout << d2->n2 << std::endl;

    delete data;
}
