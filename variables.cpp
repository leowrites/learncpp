//
// Created by Siqi Liu on 2023-06-06.
//

// similar to C, you can do sizeof(type) to find the # of bytes
// required for that type
// be careful with integer overflow, or don't assign 129 to an 8 bit integer
//  / means integer division
// use signed over unsigned, and do not mix them
// only use unsigned if you are doing bit manipulation, or array indexing...
// if done correctly, unsigned can represent larger positive number than signed (embedded)

// history on fixed-width integers
// since different machines have different sizes of integers, C99 defines a fixed-width integers in std namespace
#include <cstdint>
#include <iostream>
#include <bitset>
// it's best to avoid std::int8_t
std::int16_t i{5};
// best practices
// use int when size of integer doesn't matter
// use std::int#_t when need guarantee on a range
// when you do sizeof(type), a std::size_t is returned, which is unsigned

// floating point numbers
// float: float z{5.0f}
// double: double y:{5.0}
// use double over float unless space is limited
// rounding errors
// double d2{ 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 }; should equal 1.0
// but actually outputs 0.99999..., because double truncates approximation
// Inf - infinity
// Nan - not a number

// boolean 1 = true, 0 = false
bool isTrue {true};
bool isFalse {false};
// print boolean as true/false
int main() {
    std::cout << std::boolalpha;
    std::cout << isTrue;
    // chars
    char ch{'a'};
    std::cout << ch;
    return 0;

    // casting
    // static_cast<new_type>(expression) allows type to be explicitly converted
    // static_cast<int>(5.5)
    double d { static_cast<int>(5) };

    // constant
    // don't use for func params and return values
    // prepend with k in cammel case
    // variable cannot change value
    const int kAge {20};

    // runtime const vs compile time
    // best practice: declare compile time constants to be constexpr
    // declare runtime constants to be const

    // things like numbers int x{3} are compile time constants
    // constants that needs evaluation at runtime are runtime constants
    // we want to use compile time constants because they will be faster than runtime constants
    // and have little downside

    // constexpr ensures we get a compile-time constant
    // example:
    constexpr int sum { 4 + 5 };
    constexpr double gravity { 9.8 };

    // literals are values, you can change the type of the value with suffixes
    // for example: 5.0f
    // magic numbers - numbers like 5.0 that are double but have no suffix
    // if you use a number without giving any context, it will cause confusion, so assign it a variable to give name

    // number systems
    // octal (base 8) int x{ 012 }
    // hexa int x{ 0xF }
    // binary int x{ 0b01 }
    // you can use ' as digit separators
    int b{ 0b0111'000 };
    std::cout << std::oct;
    std::cout << 012 << '\n';
    // tell bitset to store 8 bits
    std::bitset<8> bin1 {0b1100'0011};
    // now it will output bin1 in binary
    std::cout << bin1 << '\n';
}