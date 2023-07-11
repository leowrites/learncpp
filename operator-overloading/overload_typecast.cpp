// overloading type cast allows you to convert primitive types to a 
// user defined type
#include <iostream>

class Cents
{
private:
    int m_cents;

public:
    Cents(int cents=0) : m_cents{ cents }
    {
    }

    // allow static cast to int
    // syntax: 
    // operator type() const { return ... }
    operator int() const { return m_cents; }
    std::ostream& operator<<(std::ostream& out);

    int getCents() const { return m_cents; }
    void setCents(int cents) { m_cents = cents; }
};

std::ostream& Cents::operator<<(std::ostream& out)
{
    out << m_cents;
    return out;
}

// this means we can also cast between user defined types
class Dollar
{
private:
    int m_dollars;

public:
    Dollar(int dollars=0): m_dollars { dollars } { };
    operator Cents() const { return Cents{ m_dollars * 100 }; };
};

void printCents(Cents& cent)
{
    std::cout << cent;
}

int main()
{
    Cents cents{ 7 };
    // using the custom static cast
    int c{ static_cast<int>(cents) };
    std::cout << c;
    Dollar dollar { 1 };
    Cents dollar_to_cent{ static_cast<Cents>(dollar) };
}