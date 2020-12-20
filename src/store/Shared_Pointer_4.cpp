/*
Shared Pointer:

#1:

to notice that I use arrow to access the objects member (p->bark() bark is Dog 
member function) and I use dot(p.use_count() use_count is shared pointer class 
member function) to access the shared pointer itself member there is a very 
important pitfall for that you need to be careful

suppose I want to use the shared pointer in the main function
I'll create a dog called tank
and then I create a shared pointer dog p which is constructed from the dog p
and then I create another shared pointer p2 also created from the dog tank
so now I would think that p and p2 are two shared pointers pointing to a tank
and when both p and p2 goes out of scope the tank will be destroyed

actually this is a very bad way of using the shared pointer

so what has happened is when P is constructed from the dog d p.use_count() is equal 
to 1 and when p2 is constructed from dog pointer p2.use_count()  also equal to 1. 
when p goes of for scope the dog tank will be destroyed and when p2 goes out to 
scope the dog tank will be destroyed again which is undefined at the behavior 

so the key thing about using shared pointer that you should remember is an object 
should be assigned to a smart pointer as soon as it s created raw pointer should 
not be used again 
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
    std::shared_ptr<Dog> p(new Dog("Gunner"));

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
    Dog *d = new Dog("Tank");
    std::shared_ptr<Dog> p(d);  //p.use_count() : 1
    std::shared_ptr<Dog> p2(d); //p2.use_count() : 1
    return 0;
}