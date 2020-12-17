/*
9. override (for virtual function)
To avoid inadvertently create new function in derived classes

#1:C++03
say we have a class dog and Dog has a virtual function A(int) and B()
YellowDog is derived from Dog, and in YellowDog I want to override the function A 
and B of Dog
    - I accidentally give a different parameter a float for A()
    - I accidentally lost the const keyword for B()
        -- in this case both A() and B() will not override the Dog's A() and B()
        they will becamoe functions of their own class(YellowDog)
        -- this is really bad because the runtime when you expect the polymorphism
        to happen it doesn't

#2:
C++11 gives you a new keyword 'override' which allows you to specifically tell the 
compiler that this function is our override function of its base class 
- if the function has a different signature from the base function compiler will 
error out
- so both function A() and B() will error out 
C() alson error out because its not a virtual function at all
*/

//#1
class Dog
{
    virtual void A(int);
    virtual void B() const;
};

class YellowDog : public Dog
{
    virtual void A(float); // create a new function
    virtual void B();      // create a new function
};

class YellowDog2 : public Dog
{
    virtual void A(float) override; // Error: no function to override
    virtual void B() override;      // Error: no function to override
    void C() override;              // Error: no function to override
};

int main()
{
    return 0;
}