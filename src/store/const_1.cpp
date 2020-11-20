#include <iostream>

/*
Why use const 
    - Guard aginst inadvertent write to the variable
    - self documenting
    - Enable compiler to do optimization, making code tighter
*/

int main()
{
    const int i = 9;
    int b = 6;
    //i = 6
    const_cast<int &>(b) = 6;

    int j;
    //static_cast<const int &>(j) = 7; // compile error. static cast only work with modifiable
}
