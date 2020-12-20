/*
Shared Pointer:

std::shared_ptr.get()

the shared pointer has another function called get. and this function returns the 
raw pointer which points to the object that the shared point is managing

#1.1:
so in this case we have a dog pointer d will be returned


and as I said before once you have created an object and assign it to a shared 
pointer you should avoid using the raw pointer again because the raw pointer 
provides you many ways of shooting yourself on the foot.

#1.2:
for example if I do a delete d then dog gunner will be deleted but when p1 goes out 
of scope the dog gunner will be deleted again which is undefined behavior

#1.3:
or if I do shared pointer dog p2 which is constructed from d and then when p2 goes 
out of scope the dog gunner will be deleted and when p1 goes out of scope dog 
gunner will be deleted again.

#1.4:
and suppose we have an object doghouse which called function called saveDog() and 
we pass it d to this function and even if we don't have these bad boys in the way 
when p1 goes out of scope the dog gunner will be deleted so the doghouse will end 
up holding a dangling pointer.

so this is why you should avoid using the raw pointer once you have created a 
shared pointer

and if you really have to use the raw pointer again make sure you know what are you
doing and they use it with extra care
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
{
    std::shared_ptr<Dog> p1 = std::make_shared<Dog>("Gunner");
    //#1.1
    Dog *d = p1.get(); // return raw pointer
    //#1.2
    delete d; //undefined behavior
    //#1.3
    std::shared_ptr<Dog> p2(d);
    //#1.4
}

int main()
{
    foo();
}