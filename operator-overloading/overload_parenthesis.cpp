// parenthesis operator must be implemented as a member function
#include <iostream>
#include <cassert>

// one example why we might use this is to access a 2d matrix
class Matrix
{
private:
    double m_data[4][4];

public:
    double& operator()(int row, int col);
    double  operator()(int row, int col) const;
};

double& Matrix::operator()(int row, int col)
{
    assert(0 <= row && row < 4);
    assert(0 <= col && row < 4);
    return m_data[row][col];
}

double Matrix::operator()(int row, int col) const
{
    assert(0 <= row && row < 4);
    assert(0 <= col && row < 4);
    return m_data[row][col];
}

// now we can access the 2d matrix
int main()
{
    Matrix matrix {};
    double num = matrix(1, 2);
}