#include <iostream>

int main()
{
    int count { 0 };
    while (count < 10)
    {
        std::cout << count << '\n';
        ++count;
    }
    // do while ensures the statement executes at least once
    do
    {
        --count;
    }
    while (count > 0);
    // for loop
    for (int i { 0 }; i < 10; ++i)
    {
        std::cout << i << '\n';
    }
    // syntax for no init
    int j { 0 };
    for (; j < 10; j++)
    {

    }
}