#include <iostream>
// dynamic memory allocation with new and delete
// dynamically allocate an int
int* ptr { new int };

int main()
{
    *ptr = 8;
    // initialize it with a value directly
    int *ptr2 { new int {1} };
    // free the memeory
    delete ptr;
    delete ptr2;
    // new operator could fail and a bad_alloc exception is thrown,
    // if we don't want the exception and symply want a null pointer,
    // we can use std::nothrow
    // if os cannot allocate, null will be returned
    int *ptr3 { new(std::nothrow) int };
    if (!ptr3) 
    {
        std::cerr << "Couldn't allocate";
    }
    delete ptr3; 
}

