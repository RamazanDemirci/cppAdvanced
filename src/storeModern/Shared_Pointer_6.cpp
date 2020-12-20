/*
Shared Pointer:

#1:
this issue is so important C++ has provided a shortcut way of wrapping an object 
with shared pointer. using std::make_shared is the preferred way of creating a 
shared pointer. because this guy is not only faster but also safer. 
std::make_shared function will take the parameter that you use to construct of 
class(in this case Dog ctor)

std::make_shared better because;


int this code(std::shared_ptr<Dog> p(new Dog("Gunner")); ) there are two step 
(1."Gunner is created; 2 p is created") but std::make_shared combines this two 
steps into one single step. and std::_make_shared is faster.

in addition to that if you look at what happened here(#1.2) what if the gunner is 
created successfully but the shared pointer P has failed to be created maybe 
because of memory allocation failure then the dog gunner will end up not being 
managed by a shared pointer therefore it will not be deleted and its memory will 
be leaked so this code is not exception safe 

but std::make_shared is exception safe 

so as I said once you have started using shared pointers you should always use 
shared pointers to access those dynamically created objects and as you've seen a 
shared pointer can be used pretty much like a regular pointer you can use the arrow 
operator because it is overloaded for shared pointer you can even use the 
dereference operator bark (*p).bark(); (#1.4)


there's one more thing with a raw pointer we can cast it into a different type of 
pointer.
Well! Can we do that with shared pointer?  Yes! we can.
- with shared pointer there are a couple of special function just for that purpose
-- static_pointer_cast
-- dynamic_pointer_cast
-- const_pointer_cast

so you can use these functions to cast a shared pointer just like you're casting a 
raw pointer.
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
    std::shared_ptr<Dog> p(new Dog("Gunner")); //#1.2

    {
        std::shared_ptr<Dog> p2 = p;
        p2->bark();
        std::cout << "use count of p : " << p.use_count() << std::endl; //2
    }
    p->bark();
}

int main()
{
    foo();
    //#1
    std::shared_ptr<Dog> p = std::make_shared<Dog>("Tank");
    (*p).bark(); //#1.4
    return 0;
}