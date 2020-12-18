/*
C++11: Rvalue Reference

Note1: The most useful place for rvalue reference is overloading copy constructor
and copy assignment operator, to achive move semantics.

- we already have seen the example of overloading and copy constructor with a move 
constructor and similarly we can overload the copy assignment operator with a move 
assignment operator

X& X::operator=(X const &rhs);
X& X::operator=(X&& rhs);

Note2: Move semantics is implement for all ATL containers, which means:
    a. Move C++11, You code will be faster without changing a thing
        - this is because all the unnecessary copy construction of STL containers 
        will be automatically replace the ways move construction
    b. Passing-by-value can be used for STL containers

vector<int> foo(){
    //...
    return myVector;
}

void hoo(string s);

bool goo(vector<int> arg); // Pass by reference if you use arg to carry 
                           // data back from goo()


Summary:
Move Constructor/Mode Assignment Operator
Purpose: Conveniently avoid constly and unnecessary deep copying.

1. They are particularly powerful where passing by reference and passing by value
are oth used
2. They give you finer control of which part of your object to be moved.


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