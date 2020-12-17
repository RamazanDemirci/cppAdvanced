/*
7. static assert

#1:
we are all familiar with assertion at any run-time of the program we can assert a 
certain condition is true 

#2:
C++ 11 provide a static assert which allows you to make a certian during the 
compile time

in this example I create static_assert that the size of integer equal to 4 which means the following
code will not work if the integer size is not 4.

*/

#include <vector>
#include <string>
#include <iostream>
#include <cassert>

int main()
{
    int *myPointer;

    //#1
    assert(myPointer != NULL);

    //#2
    static_assert(sizeof(int) == 4);

    return 0;
}