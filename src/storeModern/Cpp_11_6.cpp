/*
5. nullptr

- To replace NULL in C++ 03

#1:C++03
null pointer is represented with NULL which is defined as integer zero, 

--however this could be a problem
    - suppose I have a function foo with integer and another function foo is child pointer
    when I call food now which function

#2:
C++11, introduced a new keyword nullptr which is dedicated to represent now null 
pointer 
when I call foo(nullptr) it is very clear I'm calling the foo with char pointer

*/

#include <vector>
#include <string>
#include <iostream>

void foo(int i) { std::cout << "foo_int" << std::endl; }
void foo(char *pc) { std::cout << "foo_char" << std::endl; }

int main()
{
    //#1
    //foo(NULL); // Ambiguity

    //#2
    foo(nullptr); // call foo(char*)
    return 0;
}