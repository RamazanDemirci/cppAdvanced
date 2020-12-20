/*
Shared Pointer:

we all know that pointers are very important feature in C++ they are very powerful 
they enable you to do very low-level operations which are not possible in other 
languages however pointers are often troublemakers 

#1:
we have a dog and the dog has a constructor and destructor and the bark() function

let's say we have a function foo and inside the function we create a dog let's call 
it a 'Gunner' 
and then we did a bunch of different things
and then we delete the dog 
and then we did a bunch of other things 
and then when you want to use the dog again so we call p->bark() this is silly because the dog gunner has been deleted how can you 
use the p again so p is a 'dangling pointer' and if you're using a object that's 
deleted the result is undefined behavior

if we don't delete 'p' 
then the bark() function will be executed okay but by the end of this function the 
dog gunner is never deleted 
so the storage of the dog is never the allocated

-- so the result is a memory leak 

it may seem silly in our simplistic example here but these two kind of bugs happen 
a lot in C++ programming

if you think about it what is the main trouble here?

the main trouble is with the delete we were not able to delete the dog at the 
properly time

if we deleted a dog too early we have a dangling pointer if we forgot to delete at 
all then we have a memory leak but the problem is keeping track of when to delete every object is not only hard it 
is a tedious work 

a programmer should never do tedious work tedious work is meant 
to be done by the computer this is why we need smart pointers if you include the 
memory header you can use the different flavor of smart pointers today will mainly 
talk about shared pointer
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
    Dog *p = new Dog("Gunner");
    //...
    //delete p;
    //...
    p->bark(); // p is a dangling pointer - undefined behavior
} //Memory leak

int main()
{
    return 0;
}