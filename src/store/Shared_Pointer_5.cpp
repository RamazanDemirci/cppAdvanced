/*
Shared Pointer:

#1:

and in this case since we create an object but we haven't immediately assigned it 
to a shared pointer and later on we use the raw pointer again so that causes the 
trouble the correct way of using it is like this(#1.2) once the object is created 
immediately assigned to a shared pointer and then later on that the object is only 
accessed through p2 or P which are shared pointers


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
    //An object should be assigned to a smart pointer as soon as it is created.
    //Raw pointer should not be used
    Dog *d = new Dog("Tank");   //this is bad idea
    std::shared_ptr<Dog> p(d);  //p.use_count() : 1
    std::shared_ptr<Dog> p2(d); //p2.use_count() : 1
    return 0;
}