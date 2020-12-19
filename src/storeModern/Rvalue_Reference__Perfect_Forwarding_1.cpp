/*
C++11: Rvalue Reference

Perfect Farwarding:

//#1
- we know that boVector has both moved constructor and copy constructor defined
- we have a second function relay which is a temperate function and it will take its
argument and pass the argument over to function foo()
    -- this is called argument forwarding
- the relay() function will be invoked with the lvalue or with rvalue.

- as we've talked about in previous session when the relay() function is invoked 
with the lvalue then the boVectors copy constructor will be invoked.

- when the relay() function is invoked with rvalue then the move constructor of 
boVector will be invoked.
    -- that's the whole purpose of moving move semantics

let's take a closer look at the inside the relay() function

- now think about it in the ideal world how should the delay() function pass over 
its argument to foo() function
    - there are at least two requirements that need to be met
1. No costly and unnecessary copy construction of boVector is made;
2. rvalue is forwarded as rvalue, and lvalue is forwarded as l value.

- if rvalue is passed over to delay() function and rvalue should be passed 
over to foo() function
- if lvalue is passed over to delay() function and lvalue should be passed 
over to foo() function

-- so only then we can create a perfect forwarding of the parameters

#2:
our solution is actually quite simple all we need to do is rewrite the relay() 
function
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

void foo(boVector arg);

boVector createBoVector(); //Creates a boVector

//#1
/*
template <typename T>
void relay(T arg)
{
    foo(arg);
}
*/

//#2
template <typename T>
void relay(T &&arg)
{
    foo(std::forward<T>(arg));
}

int main()
{
    boVector reusable = createBoVector();
    relay(reusable);

    relay(createBoVector());
}