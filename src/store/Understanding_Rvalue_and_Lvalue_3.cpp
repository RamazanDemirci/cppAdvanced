/*
Understanding Rvalue and Lvalue

what confuses most of the people in the transforming between the L value?

lvalue can be used to create an rvalue

#1.1
I have a lvalue i and I can create rvalue with i+2
what is i?  is it rvalue or lvalue?
- i is obviously lvalue because it has address and the address is identifiable.

#1.2
what is i?  is it rvalue or lvalue?
- however in this context i is implicitly transformed into rvalue.
so lvalue can be implicitly transformed into rvalue.
-- however the other way around is not valid and rvalue cannot be implicitly 
transformed into a lvalue
-- and rvalue should be explicitly used to create lvalue

#2.1
rvalue can be used to create an lvalue

I have an integer array V and the v+2 is  rvalue.
however the (dereference) *(v+2) is a lvalue which can be assigned with a different 
value


*/

int main()
{
    //#1.1
    int i = 1;
    int x = i + 2;

    //#1.2
    int x = i;

    //#2.1
    int v[3];
    *(v + 2) = 4;
}