## Operator Overloading

When you see `x + y`, it is equivalent to `operator+(x, y)`

Operator overloading allows you to use `+` on different data types, such as int or double.

If you have user-defined types and use `+` like so:

```
Mystring string1 { "Hello, " };
Mystring string2 { "World!" };
std::cout << string1 + string2 << std::endl;
```
Unless you have overloaded the operator, it will give an error.

Best practices:
1. When you overload the operators, at least one type must be user defined
2. When overloading operators, keep function of operators close to original intent
3. If meaning of overloaded operator is not clear, use a named function
4. Operands don't modify the operands should return by value
5. Operators that modify the operand should return by reference