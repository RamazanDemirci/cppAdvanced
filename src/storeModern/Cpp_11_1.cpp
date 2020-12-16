/*
1. Initializer List

#1 : C++03 initilizer list
initializer list this is nice however if you have a vector
- the only way to initialize the vector is pushing every value into the vector which 
is not convenient

#2:
C++ 11 extends the support of initializer list to many other classes
so you can initialize a vector the same way you initialize array 
what this does is at calling initialize a list constructor 

note: that all the relevant STL container has been updated to accept initializer 
list; like map or list

#3:
beyond that you can define your own initializer list_constructor and for your own 
class
- I have a class boVector and the boVector has initially the list constructor 
defined
- this constructor takes up a parameter of initializer_list type and in the 
constructor I go through each item in the initializer_list and push the item into my 
own private data member m_vec having that I can initialize a boVector the same way
*/

//#3
class boVector
{
    std::vector<int> m_vec;

public:
    boVector(const std::initializer_list<int> &v)
    {
        for (std::initializer_list<int>::iterator itr = v.begin(); itr != v.end(); ++itr)
            m_vec.push_back(*itr);
    }
};

#include <vector>

int main()
{
    //#1
    int arr[4] = {3, 2, 4, 5};

    std::vector<int> v;
    v.push_back(3);
    v.push_back(2);
    v.push_back(4);
    v.push_back(5);

    //#2
    std::vector<int> v = {3, 4, 1, 9}; //calling initializer_list ctor

    //#3
    boVector v = {0, 2, 3, 4};
    boVector v2{0, 2, 3, 4}; //effectively the same

    return 0;
}