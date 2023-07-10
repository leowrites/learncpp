// you can use const before initializing an object
// once initialized, you cannot change the member variable
#include "Date.h"

// now you cannot modify any fields
const Date date1;

// const objects can only call const member functions
// const member function is a function that guarantees the function
// will not modify the object
// to mark a function const, do
// int getValue() const { //body };
