/*
Weak Pointers:

shared pointer provides a shared ownership of an object. and when all the shared 
pointers of that object goes out of scope that object will be automatically 
deleted that means we should never need to worry about memory leaks anymore


#1:
the dog has a new member it is a shared pointer of dog it's called m_pFriend
it also has a member new member function could makeFriend so the dog can make new 
make friends

as you see gunner is created smokey is created but none of them are deleted the 
shared pointers are supposed to delete

the dog for me automatically but they are not doing their job and I'm still getting 
memory leaks.

what happened?

the reason is what's called cyclic reference gunner has a shared pointer points to 
smoky and smokey also has a shared pointer points to gunner
- this forms a cycle of shared pointers that's why it is called cyclic reference

and as a result none of the shared pointers will ever goes out of scope and none of 
the dog will ever be deleted that's why we have the memory leak again

*/

#include <iostream>
#include <memory>
#include <string>

class Dog
{
    std::shared_ptr<Dog> m_pFriend; // cyclic reference

public:
    std::string m_name;
    void bark() { std::cout << "Dog " << m_name << " rules" << std::endl; }
    Dog(std::string name)
    {
        std::cout << "Dog is created: " << m_name << std::endl;
        m_name = name;
    }
    ~Dog() { std::cout << "Dog is destroyed: " << m_name << std::endl; }
    void makeFriend(std::shared_ptr<Dog> f) { m_pFriend = f; }
};

int main()
{
    std::shared_ptr<Dog> pD(new Dog("Gunner"));
    std::shared_ptr<Dog> pD2(new Dog("Smokey"));
    pD->makeFriend(pD2);
    pD2->makeFriend(pD);
}