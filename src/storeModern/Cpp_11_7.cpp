/*
3. enum class

#1:C++03
in C++03 enumerators are basically integers
-- this code will indeed print out 'green apple and big orange are the same'

#2: C++11
C++ 11 introduced enum class

the apple and orange are not just numerators their classes 
- so when I define Apple2 'a2' and orange2 'o2' 
    - I have to add the apple2 and orange2 scope operator(::) in front of 
- if I want to compare 'a2' and 'o2' it will give me a compile error because I 
haven't defined the equal operator for class Apple2 and class Orange2.

you've seen the Enuma class and the null pointer has made the C++ more strong typed 
and more safe to use

*/

#include <vector>
#include <string>
#include <iostream>

int main()
{
    //#1
    enum apple
    {
        green_a,
        red_a
    };

    enum orange
    {
        big_o,
        small_o
    };

    apple a = green_a;
    orange o = big_o;

    if (a == o)
        std::cout << "green apple and big orange are the same\n";
    else
        std::cout << "green apple and big orange are not the same\n";

    //#2
    enum class apple2
    {
        green,
        red
    };
    enum class orange2
    {
        big,
        small
    };

    apple2 a2 = apple2::green;
    orange2 o2 = orange2::big;

    if (a2 == o2) //conpile error
        std::cout << "green apple and big orange are the same\n";
    else
        std::cout << "green apple and big orange are not the same\n";

    return 0;
}