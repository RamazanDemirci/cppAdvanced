/*
3. Auto Type

//#1:C++03
we typically do to traverse a vector. 
I don't know about you but for me it is always vaccine to have to type a long type 
name like this

#2:C++11
I'm thrilled to see C++ 11 introduced auto-type with Auto type 
it can also automatically infer the type for it from its R-value the right hand side 
value in this case vector 
became this will save me a lot of typing and that the less typing I do the less 
typo I will make


a side effect of this is IDE becomes more important because you want to hover your 
mouse over all variable and see what type it is otherwise you have to fumble around 
to find the type because all you see is Auto
*/

#include <vector>
#include <string>
#include <iostream>

int main()
{
    std::vector<int> vec = {2, 3, 4, 5};
    //#1
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
        vec.push_back(*it);

    //#2
    for (auto it = vec.begin(); it != vec.end(); ++it)
        vec.push_back(*it);

    auto a = 6;   // a is a integer
    auto b = 9.6; //b is a double
    auto c = a;   //c is an integer. because a is an integer

    return 0;
}