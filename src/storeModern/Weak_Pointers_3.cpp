/*
Weak Pointers:

as a result of this concept is a weak pointer is not always valid if the object 
that the weak pointer is pointing to is deleted the weak pointer becomes a empty 
pointer 

so another level of protection that a weak pointer provides is a safer access to 
the pointer

#1:
say we have the dog has another function called show friend.
#1.1:
-- this code cannot compile as you see so a weak pointer cannot be used just like a 
regular pointer

#1.2
- in order to use it we need to call the function lock()

- what the lock() function does is it creates a shared pointer out of the weak 
pointer
    
why does it do that? it does that to make sure two things
1. it checks if the weak pointer is still pointing to a valid object
2. it makes sure that while it is accessing that object 
    the object will not be deleted because an object will be deleted only when 
    there's no shared pointers pointing to it


*/

#include <iostream>
#include <memory>
#include <string>

class Dog
{
    //std::shared_ptr<Dog> m_pFriend; //cyclic reference
    std::weak_ptr<Dog> m_pFriend;

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
    //#1
    void showFriend()
    {
        //#1.1
        //std::cout << "My friend is: " << m_pFriend->m_name << std::endl;
        //#1.2
        std::cout << "My friend is: " << m_pFriend.lock()->m_name << std::endl;
    }
};

int main()
{
    std::shared_ptr<Dog> pD(new Dog("Gunner"));
    std::shared_ptr<Dog> pD2(new Dog("Smokey"));
    pD->makeFriend(pD2);
    pD2->makeFriend(pD);
    pD->showFriend();
}