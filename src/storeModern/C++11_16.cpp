/*
9. Lambda Function

love it or hate it it's there int C++11

lambda function basically is an annonymous function 
you can think of it as a function that is not defined as a regular function 
#1
this lambda function takes two parameters and return the sum of these parameters
3 and 4 are passed as parameter to the lambda function

#2: you can also save the lambda function to a valuable f and invoke the function 
with f

#3:
lambda function is very useful in functional programming 
#3.1:
for example i have function filter which takes a parameter of function f and a 
parameter of vector array then i perform the function f on each item of the array
if the function returns true i will print out the item 

#3.2:
i create a vector v 
then i invoke the filter function with a lambda function this lambda function will
check if X is greater than 3  and this lambda function will be performed on each item
of the vector v if the function returns true the item will be printed out 

this is called functional programming. it is completely different the programming 
model than the traditional programming model that we are used to

#4:
Note: [&] tells compiler that we want variable capture. 

lambda funciton can even access local variables
say i have a y=4 and in this inside the lmbda function i can check if x is greater 
than y. 
all i need to do is edit the reference sign inside the square brackets which tells 
compiler that we want valuable capture 
this is a very powerful technique think how you can do the same kind of thing in 
c++03 it's very very difficult 



*/

#include <iostream>
#include <vector>

//#3.1
template <typename func>
void filter(func f, std::vector<int> arr)
{
    for (auto i : arr)
    {
        if (f(i))
            std::cout << i << " ";
    }
}

int main()
{
    //#1
    std::cout << [](int x, int y) { return x + y; }(3, 4) << std::endl;
    //#2
    auto f = [](int x, int y) { return x + y; };
    std::cout << f(3, 4) << std::endl;

    //#3.2
    std::vector<int> v = {1, 2, 3, 4, 5, 6};
    filter([](int x) { return (x > 3); }, v); //output: 4 5 6
    //...
    filter([](int x) { return (x > 2 & x < 5); }, v); //output: 3 4

    //#4
    int y = 4;
    filter([&](int x) { return (x > y); }, v); //output: 5 6

    return 0;
}