// function pointers

// fcnPtr is a pointer to a function with no parameters and returns an integer
int (*fcnPtr)();

int foo(int, int)
{
    return 5;
}

// useful for passing function as arguments to other functions
// you can also set default params for functions
void takeInFunction(int x, int y, int (*exampleFcn)(int, int)=foo)
{
    exampleFcn(1, 2);
}

// to make the type easier to write, we can use type aliasing
using ExampleFunction = int (*)(int, int);


// you can initialize a function pointer like so:
int (*fcn)(int, int){ &foo };
ExampleFunction fcn2 { &foo };

// type for a function that will take in an int:
int (*fcn2)(int){};
// you can call the function with the opinter
int main()
{
    (*fcn)(1, 2);
    fcn(1, 2);      // does the same thing
    if (fcn)
        fcn(1, 2);  // make sure fcn exists
}

