// std::vector
// better alternative for dynamically allocated array
// memory is managed, so no new/delete is necessary

#include <vector>
// when initializing vector:
// use {} if initializing with specific values
// use () to initialize with specific size
std::vector<int> v;
std::vector<int> v2(10);    // vector of size 10 
std::vector v1 { 1, 2, 3, 4 };

// array is cleaned up when the variable is out of scope
// getting size
std::size_t size { v1.size() };
// to resize
int main()
{
    v1.resize(1); // this will keep the first N element
}

