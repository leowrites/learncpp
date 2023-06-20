// class templates
#include <iostream>
#include <string>

// multiple template works in a similar way
// template <typename T, typename U>
template <typename T>
struct Pair
{
    T first{};
    T second{};
};

// now we can define type dynamically
Pair<int> p1 { 1, 2 };
Pair<double> p2 { 1.2, 1.3 };

// now if we want a function that can take in a Pair
template <typename T>
constexpr T max(Pair<T> pair)
{
    return (pair.first < pair.second) ? pair.second : pair.first;
}

// C++ 17 class template argument deduction
// for instance, we don't need to explicitly specify the type and the type will be deduced
// all template types from standard library will have deduction guide
std::pair p3 { 1, 2 };

// for aggregate classes (like Pair that we defined), we need to provide a deduction guide
// deduction guide
// this means that objects initialized with arg of type T should deduce to Pair<T>
template <typename T>
Pair(T, T) -> Pair<T>;
Pair p4 { 1, 2 };

int main()
{
    std::cout << max(p1) << '\n';
    std::cout << max(p2) << '\n';
    std::string str { "Hello World" };
    std::cout << str.length();
}