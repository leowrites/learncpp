// iterators
#include <array>
#include <iostream>

int main()
{
    std::array arr{ 1, 2, 3 };
    // arr.begin() arr.end() gives pointers to the first and last element in the array
    auto begin{ arr.begin() };
    auto end { arr.end() };
    for (auto p{ begin }; p != end; ++p)
    {
        std::cout << *p << ' ';
    }
    return 0;

}