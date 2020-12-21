/*
Unique Pointer: exclusive ownership, lightweight smart pointer.

#1.1:

- now say we don't call the release() function 
- we call reset() function which resets pD to another dog smoking 
- and will also print out some message if the PD is not empty

-- both gunner and smokey are destroyed 
-- but gunner is destroyed when the reset() function is invoked 
    because pD starts to own another dog so the original dog gunner is destroyed 
-- and smokey is destroyed when pD goes out of scope 
-- and before smokey is destroyed pD is not empty

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
    pD.reset(new Dog("Smokey"));
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