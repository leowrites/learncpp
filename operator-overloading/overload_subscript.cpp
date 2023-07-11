#include <iostream>
#include <cassert>
#include <iterator>

class IntList
{
private:
    int m_list[10]{};

public:
    // if we want to access the list, the most natural way is to overload the subscript operator
    int& operator[] (int index);
    // if IntList is defined as const, then we need a const overload to simply perform accessing the list
    int operator[] (int index) const;
};

// why does operator[] return a int ref?
// if you have m_list[2] = 3, [] has higher precedence than =, so we need a reference to the list
// in order to assign the 3 at that index
int& IntList::operator[] (int index)
{
    // one advantage of overloading is that we can perform error check, i.e. check index
    assert(index >= 0 && index < std::size(m_list));
    return m_list[index];
}

int IntList::operator[] (int index) const
{
    return m_list[index];
}

