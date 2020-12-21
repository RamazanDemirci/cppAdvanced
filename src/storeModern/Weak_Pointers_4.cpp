/*
Weak Pointers:

as a result of this concept is a weak pointer is not always valid if the object 
that the weak pointer is pointing to is deleted the weak pointer becomes a empty 
pointer 

so another level of protection that a weak pointer provides is a safer access to 
the pointer

note that if the weak pointer is an empty pointer the lock function will throw 
an exception 

#1.1
so if if you don't want the exception to be strong you need to add that check 
    - if 'mp_friend' is not expired 
    - then print out the friend the weak pointer 

#1.2
also provides another API to check 
    - how many shared pointers are pointing to that object 
        - this API called use count 
        
so we'll clean out he is owned by this amount of pointers
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
        if (!m_pFriend.expired())
        { //#1.1
            std::cout << "My friend is: " << m_pFriend.lock()->m_name << std::endl;
        }
        //#1.2
        std::cout << "He is owned by " << m_pFriend.use_count() << " pointers." << std::endl;
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