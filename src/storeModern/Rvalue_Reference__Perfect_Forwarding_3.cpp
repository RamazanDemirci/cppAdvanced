/*
C++11: Rvalue Reference

-now let's go back to the solution of function relay that I gave you the function 
relay takes a parameter of T&&

What is type &&?

rvalue reference is specified with type&&. type&& is rvalue reference ? No!

#1:
the type of T&& depends on how the arg is initialized.
- if arg is initialized with rvalue then T&& is rvalue reference.
- if arg is initialized with lvalue then T&& is lvalue reference.

how does it happen?

//T&& variable is initialized with rvalue => rvalue reference
relay(9); => T = int&& => T&& = int&& && = int&&

- 9 is rvalue. => then T will be replaced with int&&
- then T&& will become int&& && applying the reference collapsing rule it becomes 
int&&
- so T&& is equivalent to int&& it's rvalue reference

//T&& variable is initialized with lvalue => lvalue reference
relay(x); => T = int& => T&& = int& && = int&

- now relay function invoked the lvalue x.
- regardless of X is a integer or integer reference as far as that type deduction is 
concerned T will be replaced with int&
- so T&& is equivalent to int& it's lvalue reference

as you see by giving the function relay at T&& type of argument, we are giving the 
function relay a enormous power to take on any kind of argument
    --it can take on rvalue, lvalue, const, non-const... anything
    this is what Scott Meyer called a universal reference

you're confusing me at, first you say && means rvalue reference and now you say 
&& means a universal reference.

how do I know which one it is?

T&& is a universal reference if and only if the following two condition is met;
1. T is a template type.
2. Type deduction(reference collapsing) happens to T.
    - T is a function template type, not class template type

in any other case whenever you see T&& it's rvalue reference.

--------------------------------------------------------------------------
now we are well equipped to tackle the perfect forwarding problem

#2:
here is the complete solution of perfect forwarding

- the relay function will take a universal reference of arg.
- and then it perform the std::forward function of arg
- then pass it over to foo()

#3:
what does the proof the forward function do?
here is the implementation of the forward function
what it essentially does is cast arg to the type of T&&.

in other words relay functions will cast the arg bavk to the type of T&& and then 
pass is over to foo()
so relay function will have exact same type of argument of arg

if function relay gets lvalue function foo will get an lvalue 
if function relay gets an rvalue function foo we'll get rvalue 

this is how perfect farwarding is achieved


------------------------------------------------------------------
//std::move() vs std::forward()
std::move<T>(arg);      //Turns arg into an rvalue type
std::forward<T>(arg);   // Turns arg to type of T&&

some people especially the beginnners are confused by the function move and function
forward 
they have similarity they both perform static casting of their argument to a certain
type but the difference are the function move turns its argument into rvalue type 
and function forward turns its argument to type T&& whatever the T&& is 

------------------------------------------------------------------
Summary
Usage of rvalue reference: the main usage of our value reference is in two places
1. Move Semantics
    - it's typically done by overloading the copy constructor and copy assignment 
    operator. with different type of rvalue reference and lvalue reference 
2. Perfect Forwarding











*/

#include <iostream>

//#1
template <typename T>
void relay(T &&arg)
{
    //#2
    foo(std::forward<T>(arg));
}
//#3
//implementation of std::forward()
template <class T>
T &&forward(typename remove_reference<T>::type &arg)
{
    return static_cast<T &&>(arg);
}

int main()
{
}