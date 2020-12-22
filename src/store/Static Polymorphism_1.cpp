
/*
Static Polymorphism:

when we talk about polymorphism by default we are talking about dynamic 
polymorphism because dynamic polymorphism is such an important part of 
object-oriented programming.

#1:
here I'm giving you an example of dynamic polymorphism this is an example of tree 
parsing.

we have a class Generic_Parser and the Generic_Parser has a member function past 
pre-order which does the pre-order parsing of the tree and the while parsing the 
tree it invoke a function process_node() which it has certain specific thing to 
this particular node

however the Generic_Parser's process_node() function is an empty function which 
does nothing


the EmployeeChart_Parser is a specialized parser and it's derived from the 
Generic_Parser. it overrides the process_node() function and it does some 
customized thing for the employee chart

in the main function that employee chart parser is created and that the employee 
chart parser will call the parse_preorder() function from its base class

the parse_preorder function will call process_node because the process_node 
function is a virtual function so it will actually call the EmployeeChart_Parser's 
process_node() function

so the generic algorithm of parse_preorder is customized by the 
EmployeeChart_Parser's own process_node function this is a typical example of 
polymorphism

- we like polymorphism because it makes your code more clean and elegant
- it helps you to write more generic code that is more decoupled from other code

-- however polymorphism is not for free it comes with a small price to pay
1. the memory cost of the virtual table
2. the runtime cost of dynamic binding which is basically the code that creates 
and uses the virtual table 

this costs us more however what if my profiler tells me that this is a critical 
part of my algorithm and it needs to run as fast as it can
... and I don't want to give up on the benefit of polymorphism what can I do?

..-> next page
*/

#include <iostream>

struct TreeNode
{
    TreeNode *left;
    TreeNode *right;
};

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

private:
    virtual void process_node(TreeNode *node) {}
};

class EmployeeChart_Parser : public Generic_Parser
{
private:
    virtual void process_node(TreeNode *node) override
    {
        std::cout << "Customized process_node() for EmployeeChart" << std::endl;
    }
};

int main()
{
    EmployeeChart_Parser ep;
    ep.parse_preorder(root);
    return 0;
}