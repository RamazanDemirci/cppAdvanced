/*
Understanding Rvalue and Lvalue

Reference (or lvalue reference):

I assume you are already familiar with the reference in C++ here
#1:
#1.1
I create an integer  and initialize the integer reference r with i
- this reference is actually should be called lvalue reference
    -- because R is a reference to lvalue i
#1.2
and if I initialize the reference r with rvalue 5 then the compiler will error out
#1.3
the only exception for this is if R is a constant reference then it can be assigned 
with five

you really should consider this is a shortcut of two step operation 
- step one r lvalue is created with five 
- step two the reference R is initialized with this temporary lvalue

#2:
now let's look at the same idea with the function

I have a function square() which takes lvalue reference x and returns x^2.

when I invoke the function square(i),  i is a integer and it is okay
if I invoke the function square(40) it is an error because 40 is not a lvalue

#3:
how can I make the function square(40) work?

the workaround is I can change the parameter of the square function into a Const 
integer reference 
    - as we've seen in previous example a Const individual reference can be 
    initialized with our value(#1.3)
-- so the square(40) will work and the square(i) still will work.






*/

//#2
int square(int &x) { return x * x; }

//#3
int csquare(const int &x){return x * x};

int main()
{
    //#1
    int i;
    //#1.1
    int &r = i;
    //#1.2
    int &r = 5; //Error

    //Exception: Constant lvalue reference can be assign a rvalue;
    //#1.3
    const int &r = 5;

    //#2
    square(i);  //OK
    square(40); //Error

    //#3
    csquare(i);  //OK
    csquare(40); //OK
}