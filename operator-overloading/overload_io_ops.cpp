#include <iostream>

class Point
{
private:
    double m_x{};
    double m_y{};
    double m_z{};

public:
    Point(double x=0.0, double y=0.0, double z=0.0)
      : m_x{x}, m_y{y}, m_z{z}
    {
    }
    // when you use <<, the operand is std::cout, which has type std::ostream&, so overloading has header like this:
    friend std::ostream& operator<<(std::ostream& out, const Point& point);
    friend std::istream& operator>>(std::istream& in, const Point& point);

    double getX() const { return m_x; }
    double getY() const { return m_y; }
    double getZ() const { return m_z; }
};

// tricky part is we need to return by reference here, std::ostream& cannot be copied
std::ostream& operator<<(std::ostream& out, const Point& point)
{
    out << "Point(" << point.m_x << "," << point.m_y << "," << point.m_z << ")";
    return out;
}

// overriding std::cin
std::istream& operator>>(std::istream& in, const Point& point)
{
    in >> point.m_x;
    in >> point.m_y;
    in >> point.m_z;
    return in;
}

int main()
{
    Point point { 0.1, 0.2, 0.3 };
    std::cout << point << std::endl;
    Point point2;
    std::cin >> point2;
    std::cout << point2;
}