// C++ will treat constructors as implicit conversion operator
// to prevent a constructor being used as a conversion operator, you can
// use explicit so that the constructor must be explicitly called

#include <string>
#include <iostream>

class MyString
{
private:
	std::string m_string;
public:
    // explicit to prevent implicit conversion
	explicit MyString(int x) // allocate string of size x
	{
		m_string.resize(x);
	}

	MyString(const char* string) // allocate string to hold string value
	{
		m_string = string;
	}

	friend std::ostream& operator<<(std::ostream& out, const MyString& s);

};

std::ostream& operator<<(std::ostream& out, const MyString& s)
{
	out << s.m_string;
	return out;
}

void printString(const MyString& s)
{
	std::cout << s;
}

int main()
{
	// MyString mine = 'x'; // Will compile and use MyString(int)
	// std::cout << mine << '\n';

	// printString('x'); // Will compile and use MyString(int)
	return 0;
}