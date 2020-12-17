/*
9. constexpr

#1:
#1.1
i have a function A() which returns a constant 3.
#1.2
this is equivalent of creating a 6 item array but it will not compile because
the compiler doesn't know that the function A() will always return constant 

#2:

#2.1
C++11 provides a keyword constexpr which tells the compiler the function will 
always return a constant so the compiler will compute the function during the 
compile time 

#2.2
as a result i can create an array 6 item array like this

#3
the const expression sometimes can help you to write fast function for example 
#3.1
i have a function cubed() which computes the x^3 if i know that the cube function 
will be always working with a constant parameter i can add a constexpr in front of 
it 
#3.2
as a result when the cubed function is used the result of this function will
be computed at compile time in other words this function will not consume any 
cycles during the runtime ow fast is that 

*/

#include <iostream>

//#1.1
int A() { return 3; }

//#2.1
constexpr int A2() { return 3; } // Forces the computation to happen at compile time

//#3.1
//Write faster program with constexpr
constexpr int cubed(int x) { return x * x * x; }

int main()
{
    int arr[6]; // OK
    //#1.2
    int arr[A() + 3]; //Compile Error

    //#2.2
    int arr[A2() + 3]; //Create an array of size 6

    //#3.2
    int y = cubed(1789); //computed at compile time

    return 0;
}