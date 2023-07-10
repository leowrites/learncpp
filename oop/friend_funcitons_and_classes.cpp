// imagine there is a display class and a storage class that stores the data to display
// friend classes allow you to give private access from a specified class, so the other class and directly use private members/functions
class Accumulator
{
    private:
        int m_value{ 0 };

    public:
        void add(int value) { m_value = value; };
        // friend function
        friend void reset(Accumulator& accumulator);
};

void reset(Accumulator& accumulator)
{
    // now you can access the private attributes
    accumulator.m_value = 0;
}

// a friend function can be friend to multiple classes, therefore accessing private data from both classes

// a member function that belongs to a class can be friend to another class, the best approach is to put each class definition in a 
// separate header file and member functions in .cpp files.