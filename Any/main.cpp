#include <iostream>
#include "Any.h"
#include "Type.h"


void func (Any a)
{
    std::cout << a.As<int>() << "\n";
    std::cout << "From func" << "\n"; 
}

class A
{
public:
    ~A()
    {
        std::cout << "Destructor from class A" << "\n";
    }
};

int main(int argc, const char * argv[])
{
    Any any(5);
    Any a = any;    
    const char* abc = "abc";
    a = abc;
    
    try
    {
        std::cout << a.As<const char*>() << "\n";
    }
    catch(std::exception &err)
    {
        std::cout << err.what();
    }
    
    // smart pointer -> shared_ptr -> RAII
    //                  C++ 11 effective
    // deep copy
    // move semantics
    
//    func(any);
}
