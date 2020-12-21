/*
Weak Pointers:

the solution for cyclic reference:
instead of using shared pointer for the friends I will use weak pointer for the 
friend 
-- now both smokey and ganner are destroyed.

so what is this weak pointer?

we know shared pointer provides a shared ownership of an object.

- what the weak pointer says is I only want to access that object and I don't want 
to have any ownership of the object


what it means is when and how that object will be deleted is none of my business 
I don't want to interfere with that at all so having a weak pointer is similar to 
having a lower pointer but the weak pointer provides a one level of protection that 
nobody can perform operator delete on this pointer

*/

#include <iostream>
#include <memory>
#include <string>

class Dog
{
    //std::shared_ptr<Dog> m_pFriend; //cyclic reference
    std::weak_ptr<Dog> m_pFriend; // Dog* m_pFriend;

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