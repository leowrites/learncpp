#include <iostream>
#include <cstdlib>
void cleanup()
{

}
int main() 
{
    // c++ supports Goto, break, continue, do-while, std::exit()
    bool x {true};
    // best practice - use brackets
    if (x) {

    } else {

    }
    // this works too, but becareful that only statement after the condition will be in the block
    if (x)
        int y { 0 };
    else
        std::cout << "In else";
        std::cout << "Not in else";
    return 0;

    // constexpr if statement
    // at compiler time, if constexpr condition is true, entire if-else will be replaced by the true-statement, and vice-versa
    constexpr double gravity { 9.8 };
    if constexpr (gravity == 9.8) 
    {

    }
    else 
    {

    }
    int val {1};

    // switch statements
    // use when there are more than 3 conditions
    // val must be an integral value
    switch(val) 
    {
        // all variables in the switch belong to the same scope, cases are not individually scoped unless you create a block {}
        case 1:
        {
            // since z is declared in a block, other cases cannot access it
            int z {};
            // do something
            // if you want to return this function, use return
            // if you want to exit switch, use break
            break;
        }
        case 2:
            // do something else
            break;
        // fall through happens when there are no break or return
        // sometimes it's desired, and you have to put [[fallthrough]] at the end of the break
        case 3:
            [[fallthrough]]
        default:
            break;
    }
    // exiting program early
    // note this requires <cstdlib>
    // note, this does not clean up local variables in the stack, so you need to do manual cleaning 
    // we can write the cleaning function and register it with std::atexit(), so that the clean up function will be automatically be called 
    std::atexit(cleanup);
    std::exit(0);
}