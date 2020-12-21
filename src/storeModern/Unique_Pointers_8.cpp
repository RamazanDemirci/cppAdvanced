/*
Unique Pointer: exclusive ownership, lightweight smart pointer.

unique pointers can also be used as the number data 

- say the dog has the member data of four bones pointer pB and in that dog's 
- constructor will create a pB 
- and in the destructor will delete pB 

this is the conventional way of managing the resources in a class 

however this has a problem

say in the constructor we create a new bond but in the rest of the constructor 
some error happened and an exception is thrown then the created a bone will not be 
destroyed and the resource is leaked 

to overcome this problem:

instead of using the raw pointer we're using a unique pointer to manage the bone 
now even if some exception is wrong inside the constructor the bone will always be 
destroyed.

again we could use a shared pointer instead of a unique pointer to manage it the 
bone but if the dog will be instantiated a lot and the pointer to the bone is not 
shared anyway using the unique pointer is a better choice.

*/

#include <string>
#include <iostream>
#include <memory>

class Bone
{
};

class Dog
{
    //Bone *pB;
    std::unique_ptr<Bone> pB; // This prevents memory leak even constructor fails

public:
    std::string m_name;
    void bark() { std::cout << "Dog " << m_name << " rules!" << std::endl; }
    Dog()
    {
        pB = new Bone();
        std::cout << "Nameless dog created." << std::endl;
        m_name = "nameless";
    }
    Dog(std::string name)
    {
        std::cout << "Dog is created: " << name << std::endl;
        m_name = name;
    }
    ~Dog()
    {
        delete pB;
        std::cout << "Dog is destroyed: " << m_name << std::endl;
    }
};

void f(std::unique_ptr<Dog> p)
{
    p->bark();
}

std::unique_ptr<Dog> getDog()
{
    std::unique_ptr<Dog> p(new Dog("Smokey"));
    return p;
}

void test()
{
    //#1
    std::unique_ptr<Dog> pD(new Dog("Gunner"));
    f(std::move(pD));

    if (!pD)
    {
        std::cout << "pD is empty.\n";
    }
    std::unique_ptr<Dog> pD2 = getDog();

    //#1.1
    //std::shared_ptr<Dog> pDD(new Dog[3], [](Dog *p) { delete[] p; });
    std::unique_ptr<Dog[]> dogs(new Dog[3]);
}

int main()
{
    test();

    return 0;
}