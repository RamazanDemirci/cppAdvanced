/*
C++11: Rvalue Reference

rvalue reference is mainly used for two things:
    1.Moving Semantics
    2.Perfect Forwarding

Prerequisite: understanding rvalue and lvalue

rvalue reference is a new feature introduced in c++11.

if you don't I highly recommend you to watch my another video called or read  
Understanding_Rvalue_and_Lvalue notes.

what is rvalue reference?

#1:
b is a lvalue reference because it is a reference that is referencing to lvalue 
which is a before C++11 we just call it reference

rvalue reference, is represented with && sign.

how can this thing be used?

#2:
we have two printInt functions
- the first one is taking our value reference as parameter 
- the second one is taking our value reference as a parameter

so with the rvalue reference we can overload a function based on the parameter type
whether the parameter is a lvalue or rvalue
- so this is the basic concept of our value reference

#3:
if we have a function void printInt that takes a I as an integer then this code 
won't work because if you look at the first one print in a the compiler won't 
know which function to call.

and when the compiler see the second function call(printInt(6)) it doesn't know 
which one to call either
--so you can only overload the function with the r-value reference and l value 
reference
*/

#include <iostream>

//#2
void printInt(int &i) { std::cout << "lvalue reference: " << i << std::endl; }
void printInt(int &&i) { std::cout << "rvalue reference: " << i << std::endl; }
//#3
void printInt(int i) { std::cout << "i: " << i << std::endl; }

int main()
{
    int a = 5; // a is a lvalue
    //#1
    int &b = a;  // b is a lvalue reference(reference)
    int &&c = 6; // c is a rvalue reference

    //#2
    printInt(a); //Call printInt(int &i)
    printInt(6); //Call printInt(int &&i)
}