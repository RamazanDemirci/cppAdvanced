/*
9. delete

keyword delete is for deleting functions

for exampe class Dog has a constructor which takes a integer parameter. 
#1.1
in this line of code; it will work
#1.2
it will also work because 3.0 can be converted from double to integer.
#1.3
it will work too because the compiler generates assignment operator for me.

sometime you disallow your client to use your interface in a certain way in this 
case say 
    - i only want my client to create a Dog with integer 
    - i don't want them to pass over a parameter of float or double
    - i don't want to them to make a copy of the Dog maybe because the Dog is 
    holding some unsure about resource like mutex

#2:
C++11 provides a easy way to do  
i can simply define these #2.1 and #2.2
as a result both line of code will generated compile time error(#2.3, #2.4)
because these two functions has been deleted

*/
#include <iostream>

class Dog
{
public:
    Dog(int age)
    {
        std::cout << "parameterized ctor" << std::endl;
    }
};
//#2
class Dog2
{
    Dog2(int age)
    {
        std::cout << "parameterized ctor" << std::endl;
    }
    //#2.1
    Dog2(double) = delete;
    //#2.2
    Dog2 &operator=(const Dog2 &) = delete;
};

int main()
{
    //#1.1
    Dog a(2);
    //#1.2
    Dog b(3.0); // 3.0 is converted from double to int
    //#1.3
    a = b; // compiler generated assignment operator

    Dog a2(2);
    //#2.3
    Dog2 b2(3.0); // 3.0 is converted from double to int
    //#2.4
    a2 = b2; // compiler generated assignment operator

    return 0;
}