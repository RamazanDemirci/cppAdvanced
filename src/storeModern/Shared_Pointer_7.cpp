/*
Shared Pointer:

#1:
when p1, p2 goes out of the scope both the Gunner and the tank will be deleted
tank will be deleted first because both p1 and p2 are stored on the 'stack' and 
the tank is on top of the stack. (remember stack is LIFO)

#1.2:
if we do p1 equal to p2 and both p1 and p2 are pointing to tank and so the gunner 
is deleted. at this point because there's no shared pointer pointing to gunner 
anymore(use_count become 0 because of this operation.)

#1.3:
same thing if i do p1 = nullptr, gunner also will be deleted 
#1.4
or i can do p1.reset() it resets the point of p1 to be empty and then the gunner is 
deleted

so if any one of the three things(1.2 or 1.3 or 1.4) happens gunner will be deleted
*/

#include <string>
#include <iostream>
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
{ //#1
    std::shared_ptr<Dog> p1 = std::make_shared<Dog>("Gunner");
    std::shared_ptr<Dog> p2 = std::make_shared<Dog>("Tank");
    //#1.2
    p1 = p2;
    //#1.3
    p1 = nullptr;
    //#1.4
    p1.reset();
}

int main()
{
    foo();
}