// class
#include <iostream>
#include <array>

// use struct for data-only structures, and class for both data and function

// defining a class, pascal case
class DateClass
{
    // prefix member variables with m_
    // default access is private
    int m_year {};
    int m_month {};
    int m_day {};
    
    // similar to Java, members have access specifiers
    // best practice: make member var private, and member function public
    // like Java, you can have getters/setters too 
    // note: don't return non-const reference, since then the outside function will be able to modify it
    // for getters, return by value or return by const reference
public:
    // constructor
    // if you want a constructor for the class that does nothing, and you have other constructors, use default keyword
    DateClass() = default;
    // notice how this constructor assigns value to the initialized members
    // this is not best practice since some values like const need to be initialized on the line they are declared, like const variables
    // for example, this is not valid:
    // const int m_value;
    // m_value = ...;
    // DateClass(int year, int month, int day)
    // {
    //     m_year = year;
    //     m_month = month;
    //     m_day = day;
    // }
    // instead, we need a constructor that can initialize its memebrs
    DateClass() : m_year{ 1 }, m_month { 2 }, m_day { 3 }
    {
        // no assignments
    }
    // constructor delegation
    // say you have two constructors but there are overlapping initialization code, assuming constructor
    // A is a subset of constructor B, you can delegate constructor
    DateClass(int day) : m_day { day }
    {

    }

    // note you won't be able to intialize month
    DateClass(int day, int month): DateClass{ day }
    {

    }
    // take in some variables:
    DateClass(int day, int month, int year) 
        : m_year { year }, m_day { day }, m_month { month }
    {

    }
    void reset()
    {
        *this = DateClass{};
    }


    // defining member functions/methods
    // similar to java, c++ has a "this" pointer but hidden, de-referencing this will give the object
    const int& getDay()
    {
        // for example, what this actually does is
        // return this->m_day;
        return m_day;
    }
    void print()
    {
        std::cout << m_year << '/' << m_month << '/' << m_day;
    }
    void setDate(int month, int day, int year)
    {
        m_year = year;
        m_day = day;
        m_month = month;
    }
    // although private attributes cannot be accessed outside of the class,
    // objects of the same class can access each other's prvate attributes
    void copyFrom(const DateClass& date)
    {
        m_month = date.m_month;
        m_year = date.m_year;
        m_day = date.m_day;
    }

    // destructor -- executed when object is destroyed (clean up)
    // called when object goes out of scope/ or deleted 
    // should not call destructor explicitly
    ~DateClass()
    {

    }

    // chaining member functions
    // if you let a function return the object it's working with, you can chain funcitons together
    // for example
    DateClass& addDay(){ return *this; }
    DateClass& subDay(){ return *this; }
    // now we can do
    void addSubDay(){
        addDay().subDay();
    }
};

int main()
{
    std::array arr{ 1, 2 };
    DateClass today{};
    today.setDate(6, 21, 2023);
    today.print();
    DateClass yesterday { 1, 2, 3 };
    return 0;
}