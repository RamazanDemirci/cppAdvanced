/*
3. foreach

#1: C++03
we traverse a vector

#2: C++11
- I can do the same thing with a much simplified coding like this what 
- this mean is for each item of v assign 'it' to 'i' and do something with 'i'
- this kind of coding can work on any class of v that has begin() and end() function 

#3:
- if you remember I can change the int to Auto
- if I want to change the value of v all I need to do is adding a reference sign(&) 
in front of 'i'
    - in this case I'm incrementing each member of v by 1
*/

#include <vector>
#include <string>
#include <iostream>

int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5};
    //#1
    for (std::vector<int>::iterator itr = v.begin(); itr != v.end(); ++itr)
        std::cout << (*itr);

    //#2
    for (int i : v)
    {
        std::cout << i;
    }
    //#3
    for (auto &i : v)
    {
        i++;
    }

    return 0;
}