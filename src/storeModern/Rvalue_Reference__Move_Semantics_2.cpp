/*
C++11: Rvalue Reference

now the question is what is the usefulness of this kind of function overloading?
- in our simple example this kind of overloading is not very useful
    because the parameter i is a very small integer.
- but if the parameter is a resource managing object then this kind of overloading 
becomes very useful

let's look at a more realistic example

#1:
here we have a class called a boVector which is managing a bigger array of doubles
it has a copy constructor which basically creates a new array and then copy each and 
every item from the right-hand side boVector to itself.

--so this is a very costly deep copy it also has a destructor  which basically 
deletes the array

- the Foo() function is a function that takes a boVector as a parameter
- the createBoVector function creates a new boVector

#1.1
in the main function first I create a new boVector it is called a reusable 
because it is intended to be reused.
- we use the function createBoVector
- we call the function foo(reusable)
    - this will invoke the costly copy constructor.
to make a exact copy of the reusable and then pass it to the function foo
this is an expensive operation but I'm okay with it because the reusable will be 
reused later on and I don't want function foo() to mess up the content of that 
reusable

#1.2
this one will call the costly copy constructor
will I be okay with it now ?
definitely not!

because the create boVector will return a rvalue which is a temporary that will 
be destroyed momentarily

so what's the point of making a copy of the temporary and passed to foo()

why don't we just use this already created object and then pass it a foo() directly
and that is exactly what we are going to do

we'll have another constructor and this one is taking rvalue reference as parameter
this is called move constructor
that the move constructor doesn't create a new array instead it just take the 
right-hand side array and use it.
however we need to clear the right-hand side array to nullptr

this is what we mean by move constructor we're moving the right-hand side boVectors 
array into this boVector and it is very important to remember to set the right-hand 
side boVectors array to null.
because otherwise when the right-hand side boVector is destroyed, its destructor 
will delete this array
and since we need to change the right-hand side boVector we don't want the parameter 
to be a constant

- so the move constructor is making an inexpensive shallow copying
- the copy constructor is making expensive deep copy

when the first foo() function call, its parameter as a lvalue, it will call the 
expensive copy constructor(#1.1)

the second foo() function call, its parameter as are rvalue and it will call the 
inexpensive move constructor(#1.2)

-- so this is the kind of flexibility and the efficiency you can achieve with the 
move constructor

*/

#include <iostream>

class boVector
{
    int size;
    double *arr_; //A big array
public:
    boVector(const boVector &rhs)
    { //Copy Ctor
        size = rhs.size;
        arr_ = new double[size];
        for (int i = 0; i < size; i++)
        {
            arr_[i] = rhs.arr_[i];
        }
    }
    boVector(boVector &&rhs)
    { //Move Ctor
        size = rhs.size;
        arr_ = rhs.arr_;
        rhs.arr_ = nullptr;
    }
    ~boVector() { delete arr_; }
};

void foo(boVector v);

boVector createBoVector(); //Creates a boVector

int main()
{
    //#1.1
    boVector reusable = createBoVector();
    foo(reusable);

    //#1.2
    foo(createBoVector());
}