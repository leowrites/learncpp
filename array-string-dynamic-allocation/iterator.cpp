// iterators
#include <array>
#include <iostream>
#include <algorithm>
#include <string_view>

using namespace std;

bool containsNut(std::string_view str)
{
    // note: std::string_view::npos represents end of view indicator
    // so if no "nut" is found, str.find will equal to npos
    return (str.find("nut") != std::string_view::npos);
}

bool greater(int a, int b)
{
    return a > b;
}

void doubleNumber(int& i)
{
    i *= 2;
}

int main()
{
    std::array<int, 3> arr{ 1, 2, 3 };
    // arr.begin() arr.end() gives pointers to the first and last element in the array
    
    auto begin{ arr.begin() };
    auto end { arr.end() };
    for (auto p{ begin }; p != end; ++p)
    {
        std::cout << *p << ' ';
    }
    return 0;
    // range based for loops like
    for (int i: arr)
    {
        // use iterator behind the scene
    }

    // standard library algos
    // find elememt by value
    // std::find(first, last, value) -> pointer to element
    int search{ 1 };
    auto found{ std::find(arr.begin(), arr.end(), search) };
    std::cout << *found;
    // find_if
    array<string_view, 4> strings{"Hello", "Nuts", "nut", "world"};
    auto found{ std::find_if(arr.begin(), arr.end(), containsNut) };
    // there are similiar functions for count and count_if
    // std::sort can take in a function to compare objects
    // array for each will do something in place for all elements
    std::for_each(arr.begin(), arr.end(), doubleNumber);
    // since c++20, we can just do
    // std::for_each(arr, doubleNumber);

}