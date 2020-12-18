/*
C++11: Rvalue Reference

#1:
#1.1
if we don't have rvalue reference and move constructor and we want to achieve the 
same kind of efficiency
- we would have to have different version of the foo() function will have one 
version that called a foo_by_value() and then will have a different version called 
foo_by_ref() that's taking above vector reference as parameter
in the first function we'll call foo_by_value() and the second foo() function will 
call foo_by_ref() 
so you will have a lot of function by value and function by referencing 
your code which you will make it very messy

#1.2
now let's talk a little bit more about this example since we are already using C++11
and we have defined a move constructor for our object so for this kind of function 
we shouldn't call it foo_by_value() because when this function is taking rvalue 
as a parameter it will actually call the move constructor to move the object so 
we'll just call it foo()

and suppose that reusable will no longer be reused so after this foo() function 
reusable is destroyed

even though reusable is lvalue we don't want to make a copy of it and pass it to foo
we want to reuse the object for the foo() function 
what can we do?
we can call (#1.3)foo(std::move(reusable));
this will move the object of reusable to the foo function with the move constructor 
but you need to be very careful that after you call the move function on the 
reusable that we use a both member we use about that array is equal to null(#1.5)

so you really shouldn't be using the object of reusable again after calling the move 
function on it and when the reusable is destroyed it will call its destructor which 
will delete the array and in this case it is just deleting a null pointer

there is one last thing I want to talk about this example 
suppose we have another function call foo_by_ref reusable

so now we have a three function calls
if you look at the efficiency of the three function calls, 
1."Call no Ctor" is the most efficient function call. 
2."Call Move Ctor" is almost as efficient as the first one
3."Call Copy Ctor" function is the most expensive function call.
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
        rhs.arr_ = nullptr; //#1.5
    }
    ~boVector() { delete arr_; }
};

void foo(boVector v);

//#1.1
void foo_by_value(boVector v);
void foo_by_ref(boVector &v);

boVector createBoVector(); //Creates a boVector

int main()
{

    boVector reusable = createBoVector();
    //#1.2
    foo(reusable); //Call Copy Ctor
    //#1.3
    foo(std::move(reusable)); //reusable.arr_ == nullptr // Call Move Ctor
    //#2.1
    foo_by_ref(reusable); //Call No Ctor

    //#1.2
    foo(createBoVector());

    //#1.1
    //foo_by_value(reusable);
    //foo_by_ref(createBoVector);
}