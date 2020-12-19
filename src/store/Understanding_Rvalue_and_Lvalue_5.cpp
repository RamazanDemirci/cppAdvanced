/*
Understanding Rvalue and Lvalue

#1
Misconception 2: lvalues are modifiable.

C language: lvalue means "value suitable for left-hand-side of assignment"

however this definition is no longer true in C++ because C++ has a Const and a Const 
although is a l value it is not modifiable.

#2.1:
Misconception 3: rvalues are not modifiable. this seems to be pretty obvious in our 
examples
i + 3 = 6;
sum(3, 4) = 7; these rvalues are not modifable however this conclusion is only true 
for the built-in type. it is not true for user-defined the type or class

#2.2
I can call the default constructor of Dog to create a dog and then invoke the 
function bark() on the dog. the function bark() could change the state of the dog so 
this rvalue dog is modifiable.

a summary if you cannot remember everything that I've talked about rvalue and L 
value please do remember the summary

Summary:
    1. Every C++ expression yield either an rvalue or lvalue.
    2. If the expression has an identifiable memory address, it's lvalue; 
    otherwise, rvalue.

*/

int sum(int x, int y) { return x + y; }

class Dog
{
    void bark(){};
};

int main()
{
    //#1
    const int c = 1; //c is a lvalue
    c = 2;           //Error, c is not modifiable.

    //#2.1
    int i = 3;
    i + 3 = 6;
    sum(3, 4) = 7;

    //#2.2
    //It is not true for user defined type(class)
    Dog().bark(); //bark may change the state of the dog object
}