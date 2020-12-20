/*
Shared Pointer:

#1:

the way to use a shared pointer is very simple all we need to do is wrap up the 
raw pointer with a shared pointer

the way the shared pointer works is it keep track of how many pointers or how many 
shared pointers are pointing to the object and when that number becomes zero that 
object will be deleted automatically

so at this point the count equal to one because we have one shared pointer p that 
is pointing to gunner and by the end of the foo() function because p will go out of 
scope so there will be no pointer or no shared pointer pointing to the gunner so 
the count becomes zero and at this point the dog gunner will be destroyed
*/

#include <iostream>
#include <string>
#include <memory>

class Dog
{
    std::string name_;

public:
    Dog(std::string name)
    {
        std::cout << "Dog is created: " << name << std::endl;
        name_ = name;
    }
    Dog() { std::cout << "Dog " << name_ << std::endl; }
    ~Dog() { std::cout << "dog is destroyed: " << name_ << std::endl; }
    void bark() { std::cout << "Dog " << name_ << "rules!" << std::endl; }
};

void foo()
{
    std::shared_ptr<Dog> p(new Dog("Gunner")); //count : 1
    p->bark();
} //count : 0

int main()
{
    return 0;
}