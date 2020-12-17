/*
9. final (for virtual function and for class)

#1: 
- by making a class final it means no class can be derived this class anymore
- similarly by making Dog2's virtual function bark() a final virtual function
means no child of Dog2 can override the bark() function

*/

class Dog final
{ // no class can be derived from Dog
public:
    void bark();
};

class Dog2
{
    virtual void bark() final; // No class can override bark()
};

int main()
{
    return 0;
}