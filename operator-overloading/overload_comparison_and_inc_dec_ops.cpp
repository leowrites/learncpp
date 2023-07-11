// they follow similiar patterns as before
#include <string>

using namespace std;

class SomeClass
{
private:
    std::string m_attr;

public:
    SomeClass(std::string str);
    friend bool operator==(const SomeClass& c1, const SomeClass& c2);
};

SomeClass::SomeClass(std::string str): m_attr { str } { };
bool operator==(const SomeClass& c1, const SomeClass& c2)
{
    return c1.m_attr == c2.m_attr;
}

// increment/decrement opreator
// since we can do prefix ++ and postfix ++, to distinguish the difference, the compiler will
// look at the overloaded operator to see if there is an int parameter

class Cents
{
private:
    int m_cents {};

public:
    Cents(int cents)
        : m_cents { cents } { }
    Cents& operator++();
    // int param indicates postfix 
    Cents& operator++(int);

    int getCents() const { return m_cents; }
};

// no int, prefix
Cents& Cents::operator++()
{
    ++m_cents;
    return *this;
}

// remember in postfix, we return value BEFORE ++, THEN apply ++ to old value
// since we need to make a copy of the original value and return by value,
// this is usually less efficent than prefix ++
Cents& Cents::operator++(int)
{
    Cents temp{*this};
    ++(*this);
    return temp;
}


int main()
{
	return 0;
}