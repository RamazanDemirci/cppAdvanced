/*
Shared Pointer:

as I said last time it is usually preferred to use the make_shared function to 
create a shared pointer but sometimes you have to use a shared pointers constructor 
to create a shared pointer one such case is when you want to have a custom deleter

#1:
what is a custom deleter?

now what is a custom deleter let's look at this case:
when p1 the shared pointer goes out of the scope it will cause some delete function
to delete the dog gunner ant that delete function is called a 'deleter' 
and by default that deleter is the operator delete

#1.1:
using default deleter : operator delete

#1.2:
sometimes you want to use a different deleter and if that's the case you have to 
use the constructor of the shared pointer to create a shared pointer

- you have seen this function before but now instead of ending the function here we 
are going to specify a second parameter for the constructor of the shared pointer 
which is the delete and we are going to use the lambda function for that

this lambda function will take a pointer of dog and the suppose we are going to 
print out something and then we'll just delete the dog2.


there is one case where the custom deleter is actually very important to have

#1.3
suppose we have shared pointer of p3 which is constructed with new dog[3] so this 
will create an array of dogs and in this case new dog 3 will return a dog's pointer 
which points to the first dog.

so as a result p3 is a shared pointer that is only managing the first dog.

so when p3 goes out of the scope only the first is deleted and the other two dogs 
are leaked
- dog[1] and dog[2] have memory leak.

#1.4
so in this case we need to use a custom deleter. shared pointer dog p4 which create 
about and then we use the second parameter to define the custom deleter. and in 
this case All 3 dogs will be deleted when p4 goes out of scope
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
{                                                              //#1
    std::shared_ptr<Dog> p1 = std::make_shared<Dog>("Gunner"); //#1.1
    std::shared_ptr<Dog> p2 = std::shared_ptr<Dog>(new Dog("Tank"),
                                                   [](Dog *p) {
                                                       std::cout << "Custom deleting. ";
                                                       delete p;
                                                   }); //#1.2
    //#1.3
    std::shared_ptr<Dog> p3(new Dog[3]); //memory leak
    //#1.4
    std::shared_ptr<Dog> p4(new Dog[3], [](Dog *p) {
        delete[] p;
    }); //OK!
}

int main()
{
    foo();
}