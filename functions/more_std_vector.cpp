// std::vector contains two additional attributes length and capacity
// length - # of elements in the array  .size()
// capacity - # of elments the array can hold   .capacity()
#include <vector>
#include <iostream>

std::vector array{1, 2, 3, 4};
int main()
{
    array.resize(10);
    // length - 10 (elements after 4 will be zero-intialized), capacity - 10
    //std::vector can be used like a stack with push and pop
    // this will resize std::vector 
    array.push_back(5);     // push to back(top)
    array.back();       // return last element
    array.pop_back();
}