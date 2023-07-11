## Object composition, aggregation, association, and dependency

composition: an object is a part of something else but is unaware.
aggregation: an object is a part of multiple other objects. The aggregation class is not responsible for the creation/destruction of the object it holds (array)

When an aggregator needs to hold reference to multiple other objects, the std vector can't hold references, so something like this is illegal:
```
std::vector<const Item&> items{}
```
Instead, we need to use `std::reference_wrapper`. It's a class that acts like reference but allows assignment and copying
```
std::string tom{ "Tom" };
std::string berta{ "Berta" };std::vector<std::reference_wrapper<std::string>> names{ tom, berta };
```
To get an object from reference wrapper, use `get()`
```
names[0].get()  // will return the string
```

## std::initializer_list
If you have a container class and you want to initialize with a list of items, you need to define a constructor that would take in std::initializer_list

```
#include <initializer_list>
class IntArray
{
private:
    int m_length {};
    int* m_data {};
public:
    IntArray() = default;
    IntArray(int length): m_length { length }, m_data { new int[length]{} } { };
    // using initializer list to allow initializing with the syntax
    // IntArray arr { 1, 2, 3, 4 };
    // when using std::initializer_list, you need to denote the type
    IntArray(std::initializer_list<int>list): IntArray(static_cast<int>(list.size()))
    {
        int count { 0 };
        for(auto element: list)
        {
            m_data[count] = element;
            ++count;
        }
    }
}
```

Adding a list initializer could be dangerous --
Since list constructor is preferred, if the class originally had a constructor `Foo(int, int)` and we define a new `Foo(std::initializer_list<int>)`, then trying to initialize `Foo{ 1, 2 }` will use the list initializer instad of the other constructor

Best practice for initializing containers with a list:
- Use { } initialization o call list constructor
- Use ( ) initialization to call non-list constructor
