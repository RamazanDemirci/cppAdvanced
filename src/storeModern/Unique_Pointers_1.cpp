/*
Unique Pointer: exclusive ownership, lightweight smart pointer.

a unique pointer represents exclusive ownership of an object.


so unlike the shared pointers where multiple shared pointers can share the 
ownership of the same object.

- for unique pointer one object can only be owned by one unique pointer and when 
that one unique pointer goes out of scope or it starts to own another object then 
the original object will be automatically deleted

- another difference between a unique pointer and a shared pointer is a unique 
pointer is a lightweight smart pointer so it is less expensive to use then a shared 
pointer if you have a lot of pointers saved in your program and they are not shared 
it is preferred to use unique pointer rather than shared pointers


#1:
- we have a test() function and the test() function will be invoked by the main 
function 
- inside the test function we create a new dog gunner on the heap 
- and then we call the function bark() 
- and imagine it also there's a bunch of different things 
- and eventually the dog pD is deleted this is the old-fashioned way of programming 
in C++

however this code has some problems:

imagine when pD does a bunch of different things it returned to the main function 
prematurely or it throw some exceptions 
-- in either case the dog would not be deleted the dog's resource will be leaked



*/

#include <string>
#include <iostream>

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
    Dog *pD = new Dog("Gunner");
    pD->bark();
    //pD does a bunch of different things
    delete pD;
}

int main()
{
    test();

    return 0;
}