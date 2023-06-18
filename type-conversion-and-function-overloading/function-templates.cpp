// function templates
#include <iostream>
// say we have the function
// there are multiple types we want this to work with -- float, double, long,... and we don't want to re-write
// it for every type
int max(int x, int y)
{
    return (x > y) ? x : y;
}
// C++ support 3 types of tempalte params:
// 1. type template, where template param represents a type
// 2. non-type template, where templare param represents a constexpr value
// 3. tempalte template, wherre template param represents a template
// most common is type template param

// first, define T to be a type template parameter
template <typename T>
// to use function template...
T max(T x, T y)
{
    return (x > y) ? x : y;
}

// now, to use the function, we use the syntax max<actual_type>(arg1, arg2)
int main()
{
    std::cout << max<int>(1, 2) << '\n';
    std::cout << max<double>(1.2, 1.3) << '\n';

    // template argument deduction
    // we can let the compiler deduce the actual type which should be used, so we don't have to provide a type
    std::cout << max<>(1, 2) << '\n';
    std::cout << max(1,2) << '\n';  // <- this is the preferred syntax
}

// if you want to have template function across different files, you need to put the template definition!!
// in a header file with the definition

// multiple template types -- we can define another template type if we want to allow two different generic types
template <typename T, typename U>
auto max(T x, U y)
{
    return (x > y) ? x : y
}

// non-type template params
// a template param with a dixed type that serves as a placeholder for a constexpr passed as a template argument
template <int N>
void print()
{
    std::cout << N
}

// we can now call print<5>(), passing 5 in as N
// useful when you want to assert certain inputs at compile time