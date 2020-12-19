/*
Understanding Rvalue and Lvalue

instead of continue to talk about what the rvalues and rvalues are let's talk 
about what they are not.

there are some misconception that needs to be cleared up.

misconception 1: function or operator always yields rvalues
this conclusion can be easily drawn from the example(#1)

#1:
x = i+3 is rvalue
sum(3,4) is rvalue 
however this conclusion is not right

#2:
here is my counter example
I have a function foo which returns an integer referenc and in the function I return 
the global valuable by reference
- so the return value from the function foo is a lvalue
-I can write code foo()=50 this will compile


you may say well this is a weird-looking code I never write code like this.

#3:
well point taken then how about this example
- in this example I'm invoking operator square bracket on array and operate a square 
bracket almost always generates lvalue

*/

int myglobal;

int &foo() { return myglobal; }

int sum(int x, int y) { return x + y; }

int main()
{
    int i = 5;
    //#1
    int x = i + 3;
    int y = sum(3, 4);

    //#2
    foo() = 50; //this will compile, foo() is lvalue

    //A more common example
    int array[5];
    array[3] = 50; // Operator [] almost always generates lvalue
}