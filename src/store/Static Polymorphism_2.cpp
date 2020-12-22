
/*
Static Polymorphism:

we can actually simulate the behavior of polymorphism and by simulating it we are 
getting its benefit and not paying price before going to the solution let's take 
a look what are the things that we want to simulate
1. is-a relationship between base class and derived class
2. Base class defines a "generic" algorithm that's used by derived class
3. The "generic" algorithm is customized by the derived class

#1:
the first thing you might notice is the base class Generic_Parse 
so now has become a template class of type T
parse_preorder function is the same as before

however the process_node function is changed instead of doing nothing like before 
it will statically cast this object into the type of T and invoke the process_node 
function of the type T.

the tricky part the EmployeeChart_Parser is publicly derived from Generic_Parser 
and the Generic_Parser is a template class with a template type of 
EmployeeChart_Parser

-- the rest of the code is the same

note that the process_node function is no longer a virtual function. so the 
Generic_Parser will call itself the process_node function not the 
EmployeeChart_Parser process_node function

however the Generic_Parser process_node function will cast this object into type 
of T and invoke this process_node function


- the type T is actually EmployeeChart_Parser 
so eventually it is the EmployeeChart_Parser process_node function that's got 
invoked thus the polymorphism is achieved.

---now let's review the three elements that we want to simulate---
1. is a relationship between the base class and the derived class
    -- that is still true
2. Base class defines a "generic" algorithm that's used by derived class
    -- which is also true. look at ->Generic_Parser::parse_preorder()
3. The "generic" algorithm is customized by the derived class
    -- it s also true. here is done by EmployeeChart_Parser::process_node()

-- so we are getting all the benefits of polymorphism but we are not paying any 
price for it 


Note:
from our kind point of view they can use our class as if it is a true polymorphism 
- they don't even care whether it's real or simulated polymorphism 
- this technique is called 'curiously recurring template pattern'
    - also static polymorphism
    - also simulated polymorphism


it is very fairly popular in the library code because in most of the application 
code you don't really care about the cost of the virtual table and the dynamic 
binding unless the your profiler tells you that this is important but in the 
library code often time you want to squeeze every bit of performance out of your 
code

----------

so we are getting all the benefits of polymorphism but we are not paying in price 
for it. it's like free lunch! right?
-- No! nothing is free in this world! everything comes in with the price

what is the price we are paying here?

suppose I create another parser, which is called MilitaryChartParser, 
and that the MilitaryChartParser will be derived from the Generic_Parser
- EmployeeChart_Parser and MilitaryChartParser are two different classes.
they're distinguished classes that occupies their own space in the program image

- now you would realize that the launch is not free this is a typical trade-off 
between a program image size and program performance

- whether the trade-off is worth it it totally depends on your application

another thing I want to point out is this is also a small demo of TMP
- TMP: Template Metaprogramming
- the idea of temporary meta programming is it moves part of the computation which 
typically happens during a long time up front to the compile time therefore 
improve the efficiency of your program and that is exactly our static polymorphism
does although static polymorphism only improves the efficiency a little bit some 
time by using the TMP technique you can make much bigger improvements to your 
program


----------

when some people talk about static polymorphism they are actually referring to the 
template itself in this

#2:

I have a template function Max() which goes through every element of the vector v 
and find the largest one and return it.

and when function max is materialized with any different type of T
or the operators such as large then and copy assignmend will be invoked with 
different version of the operator large then and copy assignment and because that 
happens in the compiler time they call it 'static polymorphism'

there's nothing wrong with it it's just a different definition. I just want to 
clear up with the concepts so next time you hear other people talking about static 
polymorphism you know which one they are talking about

*/

#include <iostream>
#include <vector>
//#1
struct TreeNode
{
    TreeNode *left;
    TreeNode *right;
};

template <typename T>
class Generic_Parser
{
public:
    void parse_preorder(TreeNode *node)
    {
        if (node)
        {
            process_node(node);
            parse_preorder(node->left);
            parse_preorder(node->right);
        }
    }
    void process_node(TreeNode *node)
    {
        static_cast<T *>(this)->process_node(node);
    }
};

class EmployeeChart_Parser : public Generic_Parser<EmployeeChart_Parser>
{
public:
    void process_node(TreeNode *node)
    {
        std::cout << "Customized process_node() for EmployeeChart." << std::endl;
    }
};

//#2
//Generalized Static Polymorphism
template <typename T>
T Max(std::vector<T> v)
{
    T max = v[0];
    for (typename std::vector<T>::iterator it = v.begin(); it != v.end(); ++it)
    {
        if (*it > max)
        {
            ret = *it;
        }
    }
    return max;
}

int main()
{
    EmployeeChart_Parser ep;
    ep.parse_preorder(root);

    return 0;
}