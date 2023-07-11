#include <iostream>

class Base
{
private:
    int m_private {};
public:
    int m_public {};
    void func()
    {

    }
    void func2()
    {

    }
};

class Derived: public Base
{
public:
    Derived(): Base{}
    {

    }
    // redefining func from base
    void func()
    {

    }
    // if instead you still want the behavior from the base, but add on additional,
    // you can call the function in base first
    void func2()
    {
        Base::func2();
        std::cout << "Do something else";
    }
};

// the protected specifier: 
// can be accessed by the member functions, friends and derived class, but not 
// from out side of the class. You should favor private over protected

// when you call a function in the derived class, it will go up the derived chain until
// it finds a match. This means you can redefine the function in the derived class