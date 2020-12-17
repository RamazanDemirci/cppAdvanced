/*
2. Uniform Initialization

#1:
in C++ 03 allows me to initialize an aggregate class or struct with curly brace 
enclose the list this is called aggregate initialization

#2:
C++11 extended the scope of curly brace initialization to any classes 
so as long as the dog2 class has a constructor that takes an integer and string 

it can also be initialized with the same format of curly braces enclosed list 

regular constructor initialization (#1)
aggregate initialization plus (#2)
the initializer list initialization(we covered prev bkz: C++11_1.cpp)

they all take on the same format of curly brace enclose the list that is why they 
are called 'uniform initialization'

-- however in the eyes of the compiler the three kind of initialization are not seen 
as equal. they have different priorities.

uniform initialization Search order;
first ;  initializer list constructor 
second; regular constructor that takes appropriate parameters
third; aggregate initializer



*/

#include <vector>
#include <string>
#include <iostream>

//#1
class dog
{ //Aggregate class or struct
public:
    int age;
    std::string name;
};

class dog2
{
public:
    dog2(int age, std::string name)
    {
        std::cout << "age : " << age << "name : " << name << std::endl;
    };
};

int main()
{
    //#1
    dog d1 = {5, "Henry"}; // Aggregate Initialization

    //#2
    dog2 d2 = {5, "Henry"};

    return 0;
}