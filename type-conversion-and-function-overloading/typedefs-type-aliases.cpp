// typedefs and type aliases
// conventionall,y type aliases have a suffix _t
// best practice - in modern C++, start alias with a capital letter
// the using keyword creates an alias for an existing type
using Distance = double;    // Distance is now an alias for type double
Distance z = { 5.0 };       // compiler will sub Distance with the actual type
void printDistance(Distance distance);
// type aliases are not type safe
// typedefs is the old way to create alias for a type
// don't use typedefs

// when to use type aliases
// 1. it can hide platform dependent details, for example int on one machine will have different size compare to the other
//    but if you define an alias int8_t, you can make the assumption that you are working with an integer of at least 8 bits 
// 2. it can make complex types easier to read
// 3. document the meaning of value to reduce magic numbers
// 4. better code maintenance - if you decide to change from short -> long, with a type aliases you can simply do using Alias = long
//    instead of having to change every instance of short

// type deduction
// use auto to define variables unless you need to commit to a type for operations

// function type deduction
// best practice - use explicit return types over auto for functions
// you cannot use auto for funciton parameters