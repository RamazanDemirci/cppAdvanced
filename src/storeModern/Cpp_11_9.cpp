/*
3. delegating constructor

#1:
delegating constructor it is very common for the constructors to share the same code 
so sometimes it is desirable to have this kind of code I've defined a first 
constructor and as I define a second constructor which reuse the code of the first 
constructor and then do something else
-- however this code can only work in Java

you won't work in C++ at least not work as you expected it typically will create
two dogs instead of one

#2: C++03

in C++ we often come ends up having code like this I define a unit function and the 
init function will be invoked at different constructors 

Cons:

- the downside of this kind of implementation is first of all it's cumbersome 
comparing to this code
    - I have to define add additional function and this additional function will be 
    duplicated in each constructor 

- secondly the init() function is a regular function it could be invoked by any other 
functions which means the init() function needs to take care of the additional 
complexity of be invoked as a different life stage of the object not just the 
construction stage of the object

#3:
C++11 provides a new way to
- share the code of the Constructors
- first constructor can be called at the initialization list section of the second 
constructor
- this allows the first constructor to be invoked before the second constructor 
starts

- The Limitation: here is the first constructor cannot be invoked in the middle of 
the second constructor or in the end of the second constructor


#4:
C++ 11 also allows in class data member initialization

- so for example if the dog has a data member age I can initialize over here with 9 
and as a result age will be initialized at every constructor.









*/

#include <vector>
#include <string>
#include <iostream>
#include <cassert>

//#1
class dog
{
public:
    dog()
    {
        std::cout << "dog ctor" << std::endl;
    }
    dog(int a)
    {
        dog();
        //doOtherThings(a);
        std::cout << "a :" << a << std::endl;
    }
};
//#2
class dog2
{
    void init()
    {
        std::cout << "init" << std::endl;
    }

public:
    dog2()
    {
        init();
    }
    dog2(int a)
    {
        init();
        //doOtherThings(a);
        std::cout << "a : " << a << std::endl;
    }
};

//#3
class dog3
{
    int age = 9; //9
public:
    dog3()
    {
        std::cout << "dog3 ctor" << std::endl;
    }

    dog3(int a) : dog3()
    {
        //doOtherThings
        std::cout << "a : " << a << std::endl;
    }
};

int main()
{

    return 0;
}