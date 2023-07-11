## All about initialization

#### Direct initialization:
`int x(5);`

#### Uniform initialization:
`int x { 5 };`

#### Copy initialization:
`int x = 6;`
`Fraction six = Fraction(6)`

```
#include <cassert>
#include <iostream>

class Fraction
{
private:
    int m_numerator{};
    int m_denominator{};

public:
    // Default constructor
    Fraction(int numerator=0, int denominator=1)
        : m_numerator{numerator}, m_denominator{denominator}
    {
        assert(denominator != 0);
    }

    friend std::ostream& operator<<(std::ostream& out, const Fraction& f1);
};

std::ostream& operator<<(std::ostream& out, const Fraction& f1)
{
	out << f1.m_numerator << '/' << f1.m_denominator;
	return out;
}

int main()
{
	Fraction fiveThirds { 5, 3 }; // Brace initialize a Fraction, calls Fraction(int, int) constructor
	Fraction fCopy { fiveThirds }; // Brace initialize a Fraction -- with what constructor?
	std::cout << fCopy << '\n';
}
```

There is no constructor for `fCopy`, the line is calling Fractions' copy constructor.

*A copy constructor* is a constructor that copies the existing object. If you don't provide one, C++ will make a default one. Each member in the existing is copied to the new object

To define a new copy constructor:
```
(Inside Fraction)
// The copy constructor's parameter must be a reference
Fraction(const Fraction& fraction): ...
{
    std::cout << "copy constructor called"
}
```

If you wanttto prevent copies to be made publicly, you can make the copy constructor private

#### Rule of three and rule of zero

Rule of three - if a class requires user-defined destructor, copy constructor, or copy assignment operator, then it requires all three

Rule of zero - classes with custom destructors, copy constructors or assignment operator should have deal exclusively with ownership

#### Copy initialization
Avoid using copy initialization due to performance issues, for example

`Fraction fraction = Fraction(1);`

This performs two times the work

