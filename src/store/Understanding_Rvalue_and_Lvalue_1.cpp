/*
Understanding Rvalue and Lvalue

Rvalue and Lvalue are not something that you learn into very often some people has 
programmed the C++ for years and they still don't have a good understanding of what 
Rvalues and Lvalues are.



Why do I care?
1. Understand C++ construct, and decypher compiler errors or warnings.
    - Rvalue and L value are actually two very important concept in C++ core 
    language having a good knowledge of them will help you understand C++ construct 
    and to explain some similar strange behavior of C++ it also can help you to 
    decipher compiler errors and warnings because these two terms appears quite 
    often in the compiler messages.
2. C++11 introduced rvalue reference.
    if you don't have a good grasp of Rvalue and Lvalue it will be impossible for 
    you to learn Rvalue reference

Simplified Definition:
- lvalue: An object that occupies some identifiable ocation in memory
    - something in memory not something in the register
    - it has identifiable address
- rvalue: Any object that is not lvalue

#1:Lvalue
i is lvalue; 
- because I can get its address with & and assign the address to a 
integer pointer
- so it's address it not only has a address and it's address is identifiable
- the content of that address can be modified by assigning.


it is fair to say that most of the variables in C++ code are lvalues

#2:Rvalue

#2.1:
why are they rvalues?
- because if I try to get their address like this the compiler will error out
- I also cannot assign a different value to them

#2.2:
Dog is rvalue of user defined type class.






*/

class Dog
{
};

//#2
int sum(int x, int y) { return x + y; }

int main()
{
    //#1
    int i;       // i is a lvalue
    int *p = &i; //i's address is identifiable
    i = 2;       //memory content is modified

    Dog d1; //lvalue of user defined type(class)
    //Most variables in C++ code are lvalues

    //#2:
    //#2.1
    int x = 2;        //2 is an rvalue
    int c = i + 2;    //(i+2) is an rvalue
    int *p = (i + 2); //Error
    i + 2 = 4;        //Error
    2 = i;            //Error

    Dog d2;
    d2 = Dog();        // Dog() is rvalue of user defined type(class)
    int i = sum(3, 4); //sum is rvalue

    //Rvalues: 2, i+2, Dog(), sum(3,4), x+y
    //Lvalues: x, i, d1, , d2, p
}