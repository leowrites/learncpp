// compound data types
#include <string>
#include <iostream>
// data types constructed from fundamental data types or other compound
// lvalue and rvalue
// all expressions in C++ have two properties - type and value
// value category - indicates if an expression resolves to a value, function or object
// lvalue: an expression that evaluates to an identifiable object or function
// lvalue can be modifiable or non-modifiable
// example: 
int x { 5 };    // x is an identifier
int y { x };    // x is an lvalue expression because it evaluates to variable x
// r value: literals and the return value of functions and operators, not identifiable!! and need to be used immediately
int return5()
{
    return 5;
}

int main()
{
    return5();   // rvalue expression
    int x { 5 };    // 5 is a rvalue
}

// lvalue to rvalue
// lvalue can be implicitly converted to rvalues, so x = y is legal

// lvalue reference - alias of a variable
// examples:
// int& - lvalue reference to an int object
// lvalue reference variable is a variable that can refer to an lvalue
int& ref { x }; // will contain the value of x
// this allows you to modify the value of the object being referred
// x = 5; x and ref will both print 5
// ref = 10; x and ref will both print 10

// lvalue references must be initialized, we say the reference is bound to the object it is referring to
// this bounding processing is called reference binding. lvalue references must be bound to a modifiable value

// references cannot be changed to refer to another object
// since ref and referent can have different life time, if referent is destroyed before the ref, the ref is dangling (same as dangling pointer)

// ref to ref
int& ref1 { x };
int& ref2 { ref1 };
// in this case, ref1 will resolve to x, so ref2 is bounded to x, instead of referencing ref1

// lvalue ref to const
// normal lvalue ref is not allowed to be bounded to constants, but a const lvalue ref can
const int z { 5 };
const int& ref { z };
// best practice: you can use const ref to non-const variable as well and you won't be able to modify the value of the variable

// passing param by reference
// classes are expensive to copy, so we want to avoid making unecessary copies
// thsi also allows us to modify the original variable
void printValue(std::string& y)
{
    std::cout << y << '\n';
}
// pass by const ref works the same way, guarantees y cannot be changed by printValue
void printValue(const std::string& y)
{
    std::cout << y << '\n';
}
void callPrintValue()
{
    std::string x  { "Hello World" };
    printValue(x);      // passing by reference
    const std::string y {"Hello World"};
    printValue(y);
}