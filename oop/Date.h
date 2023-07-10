// for best practice, you should put the declarations in the header file

// some rules:
// for classes not only used once and not re-usable, declare AND define in cpp
// for classes used in multiple files, define in .h
// trivial member functions (accessing attributes) can be defined inside class
// non-trivial member functions should be placed inside .cpp with same name as class

// default params for member functions should be declared in the class definition

#ifndef DATE_H
#define DATE_H

class Date
{
private:
    int m_year;
    int m_month;
    int m_day;
    // static member functions
    // when you have a private static variable, you need a static member function
    static inline int s_private{ 2 };

public:
    // static member variable is shared by all objects of the same class
    // you don't need to instantiate an object to use this static variable
    // declare in class but not initializing. If you do this
    // you must define it outside of the class
    // prefix with s_
    static int number;

    // In c++ 17 you can do inline initialization which is preferred
    static inline int s_num{ 4 };

    static int getValue() { return s_private; };

    Date(int year, int month, int day);
    void SetDate(int year, int month, int day);
    int getYear() { return m_year; }
    int getMonth() { return m_month; }
    int getDay()  { return m_day; }
};

#endif