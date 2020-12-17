/*
9. Compiler Generated Default Constructor

- the compiler generate a default constructor for you if you have a define any 
constructor at all

#1:
in this case since i've already define a constructor that takes an integer for Dog
the compiler will not generate a default constructor for me
so when i try the create a Dog instance d1 without any parameter it will error out 
because the compiler can not find a default constructor

#2:
C++11 allows to force the compiler to generate a default constructor even i've 
already defined any other constructor 
- this who could comes in handy sometime if the compiler generated default 
constructor is exactly what you want

*/

#include <iostream>

//#1
class Dog
{
    Dog(int age)
    {
        std::cout << "parameterized ctor" << std::endl;
    }
};

//#2
class Dog2
{
    Dog2(int age);
    Dog2() = default; // FOrce compiler to generate the default constructor
};

int main()
{
    Dog d1; //Error: compiler will not generate the default constructor
    return 0;
}