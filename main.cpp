// with #include, content of the file is inserted here
#include <iostream>
#include "add.h"

// <> vs ""
// <> means it's a header file we didn't write ourselves, so preprocessor only searches for
// certain directories
// "" tells preprocessor that we wrote the header file, so it will search there first

// should be seen as legacy, no longer used
// macros are not available in other files
#define MY_NAME "Leo"

// conditional compilation
#ifdef PRINT_JOE
    //some code
#endif

// namspace you can declare names inside it to make it disamibigious
// so that duplicated names will be distinctive in differen files
// :: is the scope resolution operator, identifier on the left
// is the namespace and to the right is the symbol

// forward declaration
// tells compiler about existence of identifier before defining it

// write function header before main, then you can have add anywhere
// in the program
// there is also no need to specify the name of the params
// int add(int, int) is valid
// declaring/defining functions like this puts in global namespace
//int add(int x, int y);

void function() {
    std::cout << "In founction";
}

int getValueFromStdin() {
    std::cout << "Enter an integer";
    int input{};
    std::cin >> input;
    return input;
}

int funWithParam(int x) {
    std::cout << x;
}

int main() {
    std::cout << "Hello World!";
    // direct initialization
    // maybe_unused tells the compiler this may not be used
    [[maybe_unused]]int width ( 5 );
    // list initialization, modern, recommended way
    int height  = { 6 };
    std::cout << height;
    // value initialization
    int x { };
    // zero initialization, which will set the value to 0
    int y { 0 };
    // insertion operator <<
    std::cout << x << y << std::endl;
    // std::endl prints a newline char, like \n, \n is preferred
    std::cout << "The value of x is " << x << std::endl;
    // std::cout is buffered, output is not displayed immedieately and
    // are stored in a buffer. The buffer is then flushed periodically
    // >> is the extraction operator, and the input must be stored in a variable
    std::cout << "Enter a number: ";
    std::cin >> x;
    std::cout << "You inputed " << x << "\n";
    // don't use unintialized variables

    int num { getValueFromStdin() };
    std::cout << "You inputed" << num;
    int z { add(1, 2) };
    return 0;
}