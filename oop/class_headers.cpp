// we can declare and define classes separately, we just need to prefix
// the functions with the class name
#include "Date.h"
// note you need to make sure cpp is compiled into where Date.h is used 
// so compiler knows implementation

// Implements Date constructor
Date::Date(int year, int month, int day)
{
    SetDate(year, month, day);
}

// Implements Date member function
void Date::SetDate(int year, int month, int day)
{
    m_day = day;
    m_month = month;
    m_year = year;
}
