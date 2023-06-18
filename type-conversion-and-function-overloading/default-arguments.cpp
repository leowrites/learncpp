// default arguments
// you can provide default args like so
#include <iostream>
// note: don't use paranthesis or brace initialization
// default params should always the rightmost params

// when you declare a declare a function, default arguments needs to be in either definition or declaration and not both
// best practice is always to declare in forward declaration

// declare default in forward declaration
void print(int x, int y=10);
void print(int x, int y)
{
    std::cout << x;
    std::cout << y;
}
// works just like default args in python
int main()
{
    print(1, 2);
    print (1);
}