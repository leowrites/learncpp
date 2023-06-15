// the extraction operator >>
// for std::cin, user input is stored in a buffer waiting to be extracted
// >> does the following things:
// 1. If there is data for input buffer, use that data for extraction
// 2. If there is no data, wait until a \n is detected
// 3. >> extract as much data from the input as it can put into the variable
// 4. Data not extracted is left in the input buffer for next extraction
// input validation
#include <iostream>
#include <limits>
#include <cassert>
#include <cmath>
void example()
{
    // types of errors and how to handle them
    // 1. meaningless symbols - wrap whole function in loop
    while (true) {
        std::cout << 'Enter something\n';
        char op {};
        std::cin >> op;
        switch(op)
        {
            case '*':
            case '+':
            case '-':
            case '/':
            default:
                // handle meaningless case
        }
        // 2. when there are multiple std::cin on different types, and user enters them in one line
        // for example, user inputs a7 in the first std::cin. The extraction operator extracts a and leaves 7,
        // the second std::cin just reads 7 instead of asking for input again
        // to fix this, we can call ignoreLine to ignore all characters up until the next \n, which indicates
        // user typed enter
        ignoreLine();
        // 3. user inputs incorrect type causing failed extraction, the prev input is not extracted and thus causing infinite loop
        // we must check if the previous input failed
        if (std::cin.fail())
        {
            // handle error by clearing cin
            std::cin.clear();
            ignoreLine();
        } else 
        {
            ignoreLine();
        }
        // 4. success extraction but overflow value, handle same way as above

        double num {};
        std::cout << 'Enter somethign else\n';
        std::cin >> num;
    }
}

// assertion
// assertion comes at a cost of performance and should only be used in debug build. For production, define a macro NDEBUG to disable assertion
void assertionExample(double gravity)
{
    // similar to python (and CSC110), we can use assert statements to check for pre-conditions
    // the && allow you to add some message to why the assertion failed
    assert(gravity == 9.8 && "Gravity is not 9.8");
}

// static_assert
// static_assert is run during compile time and can be used in the form of static_assert(condition, message)
void staticAssert()
{
    static_assert(sizeof(int) == 4, "Integer must be at least 4 bytes");
}

// take away
// this function will clear extraneous input
void ignoreLine()
{
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// this function will test if the extraction failed, and clear it if so
void didExtractionFail()
{
    // same as std::cin.fail()
    if (std::cin)
        std::cin.clear();
    ignoreLine();
}