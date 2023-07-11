#include <string>
#include <string_view>


class Person
{
private:
    std::string m_name{ };
    int m_age{ };

public:
    Person(std::string_view name = "", int age = 0)
        : m_name { name }, m_age { age }
    {

    }

    const std::string& getName() const { return m_name; }
    int getAge() const { return m_age; }
};

// to inherit person:
class BaseballPlayer : public Person
{
public:
    double m_battingAverage{};
    int m_homeRuns{};

    BaseballPlayer(double battingAverage = 0.0, int homeRunes = 0)
        : m_battingAverage { battingAverage }, m_homeRuns { homeRunes }
        {
            
        }
};

class Employee: public Person
{
public:
    double m_salary{};
    long m_employeeID{};
    // when initializing Employee, if we also want to initialize the parent class with
    // one of the parents constructor, the syntax is as follows:
    Employee(std::string_view name, int age, double salary, long employeeID)
        : Person{ name, age }, m_salary { salary }, m_employeeID { employeeID }
        {

        }
};

// behind the scenes, upon initialization, the base class is constructed first
// then the derived class
// memory is set aside for both the derived class and based, the appropriate derived
// constructor is called. 

int main()
{
    Employee employee { "Leo", 20, 40000, 0 };

}