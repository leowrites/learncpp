#include <iostream>

// to convert a friend overload to member overload:
class Cents
{
private:
    int m_cents {};

public:
    Cents(int cents)
        : m_cents { cents } { }

    // overload with member function (this* is implicitly passed in)
    Cents operator+(int value);
    Cents operator-() const;

    int getCents() const { return m_cents; }
};

// overload the operator with a member function
Cents Cents::operator+(int value)
{
    return Cents(m_cents + value);
}

Cents Cents::operator-() const
{
    return -m_cents;
}

int main()
{
	Cents cents1 { 6 };
	Cents cents2 { cents1 + 2 };
	std::cout << "I have " << cents2.getCents() << " cents.\n";

	return 0;
}