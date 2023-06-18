// overload - multiple functions with same name, but different params and return types
double add(double x, double y)
{
    return x + y;
}
int add(int x, int y)
{
    return x + y;
}

// overload resolution
// think about the situation when you pass in char or long into add. Both char and long can be converted into int or double, so
// which function is used? The compiler will give an error that no overloaded function could be found for the function call
// during resolution, the compiler 
// 1. tries to find exact match
// 2. tries to make a trivial conversion, where the type of modified but the value is not (for example int -> const int)
// 3. if no match is found, numeric promotion is applied to the arguments
// 4. if no match is found, numeric conversion is applied to the arguments
// 5. if no match is found, compiler tries user-defined conversions (not learned)
// 6. if no match is found, ellipsis will be used (not learned)
// ambiguous match occurs when compiler finds two or more functions that can ba matched in the same step, compiler will give an error
// ambiguous match resolution:
// 1. create a function that takes param of exactly the type you want to pass in and create an exact match
// 2. cast ambiguous arguments 

