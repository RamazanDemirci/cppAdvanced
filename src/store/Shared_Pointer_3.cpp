/*
Shared Pointer:

#1:
in this case the pointer is not really shared because we only have one pointer 
that's pointing to gunner 

suppose we have another shared pointer dog p2 and p2 is also pointing to gunner the 
dog and now we have a situation that the pointer is shared and suppose p2 barked

#1.2:
so at this point (#1.2) the count become 2 
#1.3
and at this point(#1.3) the count become 1 again because p2 goes out of scope

so there's only one pointer that's pointing to gunner and by the end of the foo() 
function again the count becomes zero and the dog is destroyed


#1.4
and that the shared pointer actually has a member function which can report how 
many shared pointers are pointing to the object

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
    std::shared_ptr<Dog> p(new Dog("Gunner")); //count : 1

    {                                //#1.2
        std::shared_ptr<Dog> p2 = p; // count : 2
        p2->bark();
        //# 1.4
        std::cout << "use count of p : " << p.use_count() << std::endl; //2
    }
    //#1.3
    // count : 1
    p->bark();
} //count : 0

int main()
{
    foo();
    return 0;
}