// arrays
#include <iostream>

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

// multi-dimensional arrays
int marr[][]
{
    {1, 2, 3, 4, 5},
    {6, 7, 8, 9, 10}
};