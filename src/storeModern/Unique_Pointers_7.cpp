/*
Unique Pointer: exclusive ownership, lightweight smart pointer.

we have said that two unique pointers cannot share the same object at at the same 
time, but they could share the same object at a different time

#1:
- now let's say we have a function f which takes a unique pointer as a parameter 
- and the inside f it calls bark() 
- and suppose we only have one unique pointer PD 
- and how do we call the function f ? 

again we can use the move semantics to pass the unique pointer to the f() function

- now here's the question where is the corner destroyed?
    -- is it destroyed inside f() function or inside of the test() function

#1.2:
to find it out let's print some message

- it prints out gunner is destroyed and then PD is empty 
-- so the gunner is destroyed inside the f() function

since we have used the move semantics to move the dog gunner from pD to f 
function's parameter p 

so pD is no longer the owner of the dog gunner 
and p is the sole owner of the dog gunner 
so when he goes out of the scope the dog is destroyed


#1.3:
the similar things happens to the returned value from a function

say we have a function called getDog() which creates a new dog and it returns a 
unique pointer of that new dog

and the in the test function will call that getDog() function


since the unique pointer is returned by value so this will automatically use the 
Move semantics and as a result of that p is no longer the owner of the new dog 
smokey 
and pD2 is the sole owner of the dog smokey
so when pD2 goes out of the scope dog smokey is destroyed

#1.4:

if you remember for the shared pointers when I create array of objects I have to 
use a custom deleter to delete all the objects but for the unique pointer I don't 
have to do that

for unique pointer I can simply do this(#1.1) because unique pointer is partially 
specialized for array so all you need to make sure is the template parameter of 
the unique pointer is array

*/

#include <string>
#include <iostream>
#include <memory>

class Dog
{
public:
    std::string m_name;
    void bark() { std::cout << "Dog " << m_name << " rules!" << std::endl; }
    Dog()
    {
        std::cout << "Nameless dog created." << std::endl;
        m_name = "nameless";
    }
    Dog(std::string name)
    {
        std::cout << "Dog is created: " << name << std::endl;
        m_name = name;
    }
    ~Dog() { std::cout << "Dog is destroyed: " << m_name << std::endl; }
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
    //#1.2
    if (!pD)
    {
        std::cout << "pD is empty.\n";
    }
    //#1.3
    std::unique_ptr<Dog> pD2 = getDog();

    //#1.4
    //std::shared_ptr<Dog> pDD(new Dog[3], [](Dog *p) { delete[] p; });
    std::unique_ptr<Dog[]> dogs(new Dog[3]);
}

int main()
{
    test();

    return 0;
}