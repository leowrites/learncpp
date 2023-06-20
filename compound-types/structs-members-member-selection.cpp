// structs, members and member selection

struct Employee
{
    // {} is for default value
    int id {};
    int age {};
    // provide a default value for initialization
    // best practice is to always provide default value
    // explicit initialization will take precedence over default
    double wage{ 12.00 };
};

// an aggregate in C++:
// 1. is a struct/class/union or array
// 2. has no private/protected data members
// 3. has no user-declared constructors
// 4. has no base classes
// 5. hase no virutal member functions
// -- structs with only data members are aggregates

// passing struct to function
void printEmployee(const Employee& employee)
{
    // do something
}

// return struct

Employee getEmployee()
{
    // return by value
    return Employee {};
}

// struct can be used in other structs, or nested within other structs

struct Company
{
    struct Employee // Company::Employee
    {

    };
};

// using struct
int main()
{
    Employee joe;
    joe.age = 32;
    // to initialize a struct:
    Employee frank { 1, 20, 45.00 };
    // you can assign them with list assignment
    frank = { frank.id, 23, 41.00 };
}