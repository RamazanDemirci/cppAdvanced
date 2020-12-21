/*
Unique Pointer: exclusive ownership, lightweight smart pointer.

we have said that two unique pointers cannot share the same object at at the same 
time, but they could share the same object at a different time

#1:

so the pD to first dog smokey rules 
and then smoke is destroyed 
then gunner rules 
and then gunner is destroyed 

here we are using move semantics to move gunner from pD to  pD2 

- Consequences
1. smokey is destroyed
2. pD becomes empty
3. pD2 owns gunner

so this is how you transfer the ownership from one unique pointer to another 
unique pointer

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
    //#1
    std::unique_ptr<Dog> pD(new Dog("Gunner"));
    std::unique_ptr<Dog> pD2(new Dog("Smokey"));
    pD2->bark();
    pD2 = std::move(pD);
    pD2->bark();
}

int main()
{
    test();

    return 0;
}