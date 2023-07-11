## When to use member/friend/normal operator overload?
- Member functions:
  - When overloading `=,` `[]`, `()` or `->`
  - When overloading unary operator like `!`
  - When overloading binary operator that modify left operand, and you have access to modify the class
- Normal function:
  - When overloading binary operator that does not modify left operand
  - When overloading binary operator that modify left and you cannot add members to the class definition of the left operand (you don't have access to class)

Notice how normal function is preferred over friend functions, only use friend if you need access to private attributes