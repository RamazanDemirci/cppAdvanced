/*
2. Uniform Initialization



uniform initialization Search order;
first ;  initializer list constructor 
second; regular constructor that takes appropriate parameters
third; aggregate initializer

#1:
so when a compiler see a dog is initialized with {3} 
the first thing we will do is search the class dog for initializer list constructor 
    if that is found it will pass it will take 3 as a single item array and pass it 
    over to the initializer list 
if that is not found it will search for a constructor that takes a single integer 
as a parameter 

if this is not found either it will try to and take dog class as an aggregate class 
and call the aggregate initializer for the age

*/

#include <vector>
#include <string>
#include <iostream>

class dog
{
public:
    int age; //3rd choice
    dog(int a)
    { //2nd choice
        age = a;
    }

    dog(const std::initializer_list<int> &vec)
    { // 1st choice
        age = *(vec.begin());
    }
};

int main()
{
    //#1
    dog d1{3};
    return 0;
}