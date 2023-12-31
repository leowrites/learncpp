// arrays
#include <iostream>
#include <string_view>

// defining an array
int testScore[30]{};

// you can make array from any type
struct MyType
{
    int attr1{};
    int attr2{};
};

// these kinds of array must be fixed length -- length must be a compile time constant
MyType arr[10]{};   // initialize all element to MyType with default initialization
MyType arr2[5]{ MyType{1, 2}, MyType{2, 3} };       // note you don't need the lenght, you can let compiler deduce it
MyType arr3[]{ MyType{1}, MyType{2} };

// passing array to function
void takeInArray(int num[5])
{
    // do something
}

int main()
{
    int num[5]{ 1, 2, 3, 4, 5 };
    takeInArray(num);
}

// c++ 17+ - use std::size to get length of an array (note: this will not work for array passed into a function)
int size = std::size(arr3);

// looping array
void loopArray()
{
    for (int item{ 0 }; item < std::size(arr3); ++item)
    {
        // do something       
    }
}

// multi-dimensional arrays, you can only ommit the inner most array
int marr[][5]
{
    {1, 2, 3, 4, 5},
    {6, 7, 8, 9, 10}
};

// array vs integer pointer
// diff:
// when using sizeof(), passing in a fixed sized array returns the size of entire array
// whereas passing in a pointer will return the pointer size

// passing fixed array to functions
// array is passed as a pointer to the first element because copying is expensive
// pointer arithmetic
// if ptr is a pointer to the first element in the array,
// then ptr + 1 will return the address of the next ELEMENT
// so if array contains integers, ptr + 1 will return the address of the next integer
// if it's an array of chars, then it will return address of next char...

// dynamically allocate array
int main()
{
    int length{};
    std::cin >> length;
    int* arr { new int[length] };
    // must have [] to de-allocate arrays
    delete[] arr;
}

// using for each loops
std::string_view str_arr[] = {"Hello", "World"};

// loop through the strings
void loop()
{
    for (const auto& string: str_arr)
    {
        // this allows us to loop through by value, but each string is copied
        // so we should use reference, this will grealy improve performance
        std::cout << string << std::endl;
    }
}

