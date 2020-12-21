/*
Unique Pointer: exclusive ownership, lightweight smart pointer.

#1.1:

- remember the shared pointer has a get function which returns the raw pointer
a unique pointer has a similar release function which also returns the raw pointer

- after calling the release() function pD has given up its ownership of the dog so 
    -- as a result nobody owns the dog anymore 
    -- and nobody will automatically delete the dock

#1.2:
we can check if a unique pointer is a null pointer same way as checking a raw 
pointer if PD is null at point out PD is empty.


if you recall the shared pointers get function doesn't give up at the ownership of 
the object but the unique pointers release function does give up the ownership








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
    Dog *p = pD.release();
    //#1.2
    if (!pD)
    {
        std::cout << "pD is empty.\n";
    }
}

int main()
{
    test();

    return 0;
}