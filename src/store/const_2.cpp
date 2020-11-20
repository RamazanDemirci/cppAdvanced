#include <iostream>

/*

const : - A compile time constraint that an object can not be modified
*/

int main()
{
    std::cout << "Hello Easy C++ project!" << std::endl;

    const int i = 9;
    int b;

    //i = 8;              // compile errors. because it is const.
    const int *p1 = &i; //data is const, pointer is not
    //*p1 = 5;            //compile errors. because data is const.
    p1++; //this ok. because pointer is not const.

    int *const p2 = &b; //pointer is const, data is not.
    //int *const p2 = &i; //compile errors. because data of i is const but data of p2 is not constant but pointer is const.

    const int *const p3 = &i; //data and pointer are both const.

    int const *p4 = &i;

    //if const is on the left of *, data is const
    //if const is on the right of *, pointer is const
}