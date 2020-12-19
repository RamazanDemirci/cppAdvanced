/*
C++11: Rvalue Reference

Perfect Farwarding:

Reference Collapsing Rules (C++11):

C++11 defined a reference collapsing rules for type of deduction

1. T& &     ==> T&
2. T& &&    ==> T&
3. T&& &    ==> T&
4. T&& &%   ==> T&&

- you as the programmer cannot write code like this but the compiler can generate a 
code like above. and then deduce its type to right-side

- the rule actually is not hard to remember it seems that
    -- there is single ref deduce to single ref
    -- there is only double ref deduce to double ref

Remove Reference:
#1:
if I create a remove_reference integer refference then the resulted type is a integer
so this line of code is exactly the same as code in comment out

#2:
if I create and remove_reference integer and because there's no reference to remove 
so the result is also the integer i
*/

#include <iostream>

template <class T>
struct remove_reference; // It removes reference on type T

//#1:
// T is int&
remove_reference<int &>::type i; //int i

// T is int
remove_reference<int>::type i; //int i

int main()
{
}