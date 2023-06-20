// pointers
#include <iostream>
int* ptr;
int x { 5 };
int* ptr2 { &x };

// nullptr is a keyword you can use to initialize a pointer or assigning a pointer
// you should not de-reference a null pointer
int* null { nullptr };

int* nullp {};  // a null pointer and not holding an address
// best practice - initialize pointers to be null if not initializing with an address

int main()
{
    ptr = &x;
    *ptr = 10;
    // to check for null pointer, we can do
    if (ptr == nullptr)
    {
        std::cout << "null pointer\n";
    }
}
// pretty much the same like C pointers
// use reference over pointer when possible

// pointer to const value -- pointer is not const itself, which means ptr can be changed to point to other things
// it cannot change the value of x
// const int* ptr { &x }
// to make the pointer itself constant, we put const after int*
// int* const constptr { &x }

// to test if the pointer is null in a function, we can have it as a precondition and use assert(ptr)

// something we can do is return by reference/address
// similar to C, we need to make sure the referent exist after function exits, one way to acheive this is making the variable static
// so it will exist until the end of the program -- DO NOT return non-constant static variables unless it's intended
// static variable will persist over the entirety of the program, so if you call getProgramName multiple times and change it, it will produce undefined behavior

// there are certain cases where i's safe to return by reference
// 1. if param is pased into a function by ref, then we can return the param by ref
// 2. non-constant ref params can be modified

// you can also return by address like in C, but prefer return by reference
const std::string& getProgramName()
{
    static const std::string s_programName { "Calculator" };
    return s_programName;
}

//type deduction with pointers and references
