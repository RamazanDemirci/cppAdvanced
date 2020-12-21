/*
Unique Pointer: exclusive ownership, lightweight smart pointer.

#1.1:

now suppose we don't pass any parameter to the reset() function 
this has the same effect of setting pD = nullptr 
-- and again gunner is destroyed at the point of the reset function is called 
-- and now PD is empty

//Consequences
at the end when pD goes out of scope nothing is deleted 
so the reset() function destroys the original object 
and the release() function doesn't destroy the object

*/

#include <string>
#include <iostream>
#include <memory>

class Dog
{
public:
    std::string m_name;
    void bark() { std::cout << "Dog " << m_name << " rules!" << std::endl; }
    Dog()
    {
        std::cout << "Nameless dog created." << std::endl;
        m_name = "nameless";
    }
    Dog(std::string name)
    {
        std::cout << "Dog is created: " << name << std::endl;
        m_name = name;
    }
    ~Dog() { std::cout << "Dog is destroyed: " << m_name << std::endl; }
};

void test()
{
    //#1.1
    std::unique_ptr<Dog> pD(new Dog("Gunner"));
    pD->bark();
    //pD does a bunch of different things
    pD.reset(); // pD = nullptr;
    //#1.2
    if (!pD)
    {
        std::cout << "pD is empty.\n";
    }
    else
    {
        std::cout << "Pd is not empty.\n";
    }
}

int main()
{
    test();

    return 0;
}