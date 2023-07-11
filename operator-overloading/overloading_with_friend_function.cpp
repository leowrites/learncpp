// demo overloading the + operator to add two Cents

#include <iostream>

class Cents
{
private:
    int m_cents {};
public:
    Cents(int cents);
    int getCents() const { return m_cents; };
    friend Cents operator+(const Cents& c1, const Cents& c2);
    friend Cents operator-(const Cents& c1, const Cents& c2);
    ~Cents();
};

Cents::Cents(int cents): m_cents { cents }
{
}
Cents::~Cents()
{
}
Cents operator+(const Cents& c1, const Cents& c2)
{
    return c1.m_cents + c2.m_cents;
}
Cents operator-(const Cents& c1, const Cents& c2)
{
    return c1.m_cents - c2.m_cents;
}

// obviously, you shouldn't use friend functions if the operator doesn't require private attributes
// if you need to add additional functions to access private attributes, just use friend
// Cents operator+(const Cents& c1, const Cents& c2)
// {
//     return Cents{ c1.getCents() + c2.getCents() ;
// }

int main()
{
    std::cout << "I have " << (Cents{ 2 } + Cents{ 2 }).getCents() << "cents" << std::endl;
}