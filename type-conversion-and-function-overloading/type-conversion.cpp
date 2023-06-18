// Implicit type conversion
#include <iostream>
// Integer 3 and float 3.0 are represented differently in binary, so when casting we can't directly copy the bits representing 3 to be a float
// instead, a copy is made

// implicit type conversion
// integer implicitly converted to double
// compiler will determine if value of current type can be converted, if so, compiler decides how and a new value is created
// for example, casting 3.5 to int will depend on how compiler decides to cast it
double d { 3 };
double result { 5.0 / 2 };

// floating point and integral promotion
// values can be promoted, for example a char can be promoted to a wider data type like int. It's value will be preserved so the promotion is safe

// floating point promotions
// float -> double, so we can write a function that takes a double and treat it as float or double

void printDouble(double d)
{

}

void callPrintDouble()
{
    printDouble(2.5);
    printDouble(2.5f);  // float promotion to double
}

// integral promotion
// signed char/signed short can be converted to int
// unsigned char/shorst, char8_t can be converted if int can hold entire range of type, or they can be converted to unsigned_int
// bool can be converted to int
// this means that we can write a function with type int and pass in different integral types

void printInt(int x)
{
    std::cout << x;
}

void callPrintInt()
{
    printInt('c');
    printInt(true);
    short s { 3 };
    printInt(s);
}

// numeric conversion
// not always safe -- for example, converting unsigned <-> signed, or double -> int will result in data loss
// best practice is to avoid premature optimization and build a working program, then optimize data types later
// 5 types:
// 1. integral type -> integral type
// 2. floating -> floating
// 3. floating -> integral
// 4. integral -> floating
// 5. integral/floating -> bool

// narrow conversion (from wider data type to smaller)
// always explicitly cast with static_cast
// with brace ionitialization, narrow conversion is not allowed
int z { 3.5 };  // won't compile
int c { static_cast<int>(3.5) }; // explicitly cast instead
void callPrintIntWithDouble()
{
    printInt(static_cast<int>(3.5));
}

// when source value of narrow conversion isn't known until run time, result of conversion can't be determined until runtime, should be avoided
// when source value of narrowing conversion is constexpr, source value must be known to the compiler, so the compiler
// can perform the conversion and check if the value is preserved. 
//      If value is not preserved, compilation is halted with error.
//      If value is preserved, then it is not considered narrow conversion

void print(unsigned int n)
{
    std::cout << n << '\n';
}
void callPrint()
{
    int u_in{};
    std::cin >> u_in; // user may input negative values
    print(u_in);
}

// arithmetic converison
// what happpens when you add 2 and 2.5? what is the result type?
// the following operators require operands to be same type:
// +- */%
// < > <= >= == !=
// & ^ |
// ? :
// the usual arithmetic conversion rules will be followed:
// if one of the operand has a wider type, then the operand with narrower type will be converted
// to the wider type
// so 2 + 2.5 will promote 2 to a double, and result will be 4.5
// #include<typeinfo>
// typeid() can be used to check the result type of an expression

// explicit type conversion
// avoid c-style casts, const casts and reinterpret casts
// best practice is to use static_cast