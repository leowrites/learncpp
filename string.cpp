//
// Created by Siqi Liu on 2023-06-08.
//

#include <string>
#include <string_view>
#include <iostream>

int main() {
    std::string name { "Hello" };
    name = "Leo";      // wtf you can do this?
    // outputing string
    std::cout << "Hello" << name << '\n';

    // taking in string inputs
    std::string age {};
    std::cin >> age;

    // note: >> will only extract upto the first white space, need to use std::getline()
    std::cout << "Enter your full name";
    std::string username{};
    // read a full line
    // std::ws is a manipulator that tells std::cin to ignore leading whitespace
    // best practice is to use std::ws
    std::getline(std::cin >> std::ws, username);
    std::cout << "Enter your age";
    std::string user_age{};
    std::getline(std::cin >> std::ws, user_age);
    std::cout << "You name is " << username << " and your age is " << user_age;
    // std::String is an object and contains props like string length
    std::cout << username.length();
    // cast to an integer
    int length { static_cast<int> (username.length()) };

    // an easier to initialize string instead of std::string - use literal
    using namespace std::literals;
    std::cout << "foo\n"s;  // s is std::string literal
    std::cout << "foo\n"sv; // sv is std::string_view literal

    // string_view
    // this is heap allocated
    std::string s { "Hello " };
    // this is like the global read-only string in C
    constexpr std::string_view read_only { "Hello World" };
    // we can convert between string and string_view
    std::string conv{ static_cast<std::string_view>("Cast to string_view") };
    std::string_view conv2 { static_cast<std::string>("Casting to string") };

    // operations
    int x{ 5 };
    int y{ --x };
    // don't ever have x and x with side effect applied to it in the same statement, for example
    int z { x + --x };
    return 0;

    // c++ has similar conditional shorthand as js x ? y : z
    // best practice is to always parenthesize the conditional part
    // only use it for simple conditionals

    // don't use == or != to compare floating point values
    // it is only safe for these cases:
    // literal
    // return val from function

    // boolean: ! && ||
}