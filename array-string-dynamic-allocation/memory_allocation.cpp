// dynamic memory allocation
#include <iostream>

// use the new keyword, which is similar to malloc and will return a pointer
// if memory cannot be allocated, an exception is thrown.
// to avoid the exception and assign ptr to be nullptr, do
int* ptr { new(std::nothrow) int };
// always check if memory allocation is successful

// you can initialize the new variable like so:
int* ptr { new int{5} };
// use the delete keyword to free memory
int main()
{
    delete ptr;
    ptr = nullptr;
    // dynamically allocate array
    int length{};
    std::cin >> length;
    int* array{ new int[length]{} };
    delete[] array;     // deallocate
    // since C++11, you can now initialize dynamic array with initializer list
    auto* array1{ new int[length] {1, 2, 3, 4} };

    constexpr int fibonacci[]{ 0, 1, 2, 3 }; 
    std::string strings[]{ "string1", "string2" };
    // for-each loop is like loop by element
    // for-each doesn't work with array pointers and dynamically allocated arrays
    // since each array element iterated will be copied into "number", it can be expensive
    // so it's more efficient to use reference
    // if you want to use "number" as read-only, add const too
    for (const auto& number: strings)
    {
        std::cout << number;
    }

    // void pointers
    // special type that can be pointed at any data type
    void* ptr;
    // de-referencing a void pointer is illegal and needs to be first casted to another type

    // allocating multi-dimensional arrays
    auto marr { new int[8][5] };
    // if the inner array is not constant length, then we need to initialize the outer and inner arrays separately
    int **oarr { new int*[10] };    // 10 elements, each element is a a pointer to an integer
    for (int i{ 0 }; i < 10; ++i)
        oarr[i] = new int[5];
    // freeing
    for (int i{ 0 }; i < 10; ++i)
        delete[] oarr[i];
    delete[] oarr;
    
}

