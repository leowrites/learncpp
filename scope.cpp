//
// Created by Siqi Liu on 2023-06-12.
//

// defining namespace (define in header files)
// you are also allowed to have the same namespace in different files
// when to use namespace:
// use to separate application-specific code that might be reused later (like math or physics)
// if you are writing a library, always put code inside a namespace

// global variables
// convention: prefix global variable with g or g_
// avoid non-constant global variables if possible, constant are ok
int g_x {};
// all constant global variables are internal
// To make a non-constant global variable internal, we use internal linkage -- we can define global
// variables with the static keyword so that it's only accessible within scope.cpp internal linkage does not violate
// one-definition rule
static int g_y { 4 };
// static can also be used on functions to make them internal

namespace scope1
{
    int someFunc()
    {

    }
    // you can nest namespace too, you would call it like scope1::nested::func
    namespace nested
    {
        int func()
        {

        }
    }
}

namespace scope2
{
    int someFunc()
    {

    }
}

int main() {
    // now the function can be referred to as
    scope1::someFunc();
    scope2::someFunc();
    // and other libraries are free to define a function with the same name
    // to use the namespace scope, we can do scope::, or with keyword using
}