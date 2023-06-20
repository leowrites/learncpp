// user defined types
#include <string_view>
#include <iostream>
// when using program-defined types, include them in the header file and include them

// enum - compound data type where every possible value is defined as a symbolic constant
// this is an unscoped enum, Color is defined in the global scope. This is bad because
// there could be naming collisions

// problem with unscoped enum -- since they are treated as integers, they will be implicitly casted to integer
// this means even if they are scoped, you can compare two enum in two different namespace and they will equal
// for example, color::red == fruit::orange will return true
// solution is use scoped enum/ enum class -- see below

// we can also specify the base type of an enum
namespace color
{
    enum Color : std::int8_t
    {
        red,
        green,
        blue,
        orange
    };
}

// orange collides in two enum classes
// to avoid this, we should put them in their own namespace
namespace fruit
{
    enum Fruit
    {
        orange
    };
}

// each value in the enum is implicitly an integer, where the value is the index
// so when you print them, it will print an integer value
// overload the << operator so that it prints the color
std::ostream& operator<<(std::ostream& out, color::Color color)
{
    switch (color)
    {
        case color::red: return out << "red";
        case color::blue: return out << "blue";
        case color::green: return out << "green";
        default: return out << "???";
    }
}

std::istream& operator>> (std::istream& in, color::Color& color)
{
    int input {};
    in >> input;
    // cast to enum
    color = static_cast<color::Color> (input);
    return in;
}

int main()
{
    color::Color apple { color::red };
    fruit::Fruit orange { fruit::orange };
    // you can compare enum
    color::Color shirt_color { color::blue };
    if (shirt_color == color::blue) {
        // do something
    }
    std::cout << "Color is " << shirt_color << '\n';

    // taking in an enum
    std::cout << "Enter a color: 0=red, 1=green, 2=blue";

    // we can overload >> so we don't have to write this every time
    int input {};
    std::cin >> input;
    // cast to enum
    color::Color color_in { static_cast<color::Color> (input) };

    // scoped enum with enum class
    // enum class is strongly typed, so they won't be converted to integers, and they are strongly scoped
    enum class Color // defines a sope enum
    {
        red,
        blue
    };
    Color color { Color::red };

    // using enum will import all of the enumerators from an enum into the current scope
    using fruit::Fruit;
    // now we can access orange
    
}