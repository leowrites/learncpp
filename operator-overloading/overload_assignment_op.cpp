// operator= or copy assignment operator copies value from one object to another
#include "Date.h"
// Copy assignment vs Copy constructor
// if a new object has to be created before copying, then copy constructor is used

// see Date.h
// if new object does not have to be created before copying occur, assignment operator is used
int main()
{
    Date date{};
    Date d;
    d = date;           // calls assignment op
    
}