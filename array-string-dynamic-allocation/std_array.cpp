// std::array
// better alternative for C-style fixed size array
#include <iostream>
#include <array>
#include <algorithm>

std::array<int, 3> array{ 1, 2, 3 };       // array with 3 integers
// since c++ 17, you can ommit type and size
std::array array1{ 1, 2, 3 };
// array1.at checks for out-of-bound and will throw an exception, which is safer but slower

// std::array will also work in a function, and you need to pass by reference
void takeInArray(std::array<int, 3>& arr)
{
    // sort the array
    std::array(arr.begin(), arr.end());
}

// to take in array of dynamic size with templates
template <typename T, std::size_t size>
void printArray(std::array<T, size>& arr)
{
    for (auto el: arr)
        std::cout << el << ' ';
    std::cout << '\n';
}

// arr.size() return a special type size_type, which is a unsigned integral type
// if we try to compare it against an integer, we will get type mismatch
// so we need to make sure our variable is th esame type as size_type
int main()
{
    std::array arr{ 1, 2, 3 };
    for (std::size_t i{0}; i < arr.size(); ++i)
    {
        std::cout << arr[i];
    }
}

struct House
{
    int stories;
    int rooms;
};
// initializing array with structs
std::array<House, 3> houses{
    {   // initialize a C-style array first
        { 1, 2 },
        { 3, 4 }
    }
};