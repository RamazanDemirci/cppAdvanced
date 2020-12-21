/*
Unique Pointer: exclusive ownership, lightweight smart pointer.

#1.1:
so the better solution is using a unique pointer to manage the dog and now we 
even don't need to delete the dog

and of course if we change the unique pointer to a shared pointer this code will 
work equally well however since the Dog pointer will not be shared using a shared 
pointer is overkill
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
}

int main()
{
    test();

    return 0;
}