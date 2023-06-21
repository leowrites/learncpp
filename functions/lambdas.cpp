// lambda functions
#include <array>
#include <algorithm>
#include <iostream>
#include <string_view>
#include <functional>
// syntax
// [ captureClause ] (parameters) -> returnType
// {
//  statements;
//  }

int main()
{
    [] {};
    return 0;

    // example with std::find_if
    const std::array<std::string_view, 4> arr{ "apple", "banana", "lemon" };
    const auto found{ std::find_if(arr.begin(), arr.end(), 
        [](std::string_view str){
            return (str.find("nut") != std::string_view::npos);
        }
    ) };
    auto findNut {
        [](std::string_view str) {
            return (str.find("nut") != std::string_view::npos);
        }
    };
    std::function {
        [](std::string_view str) {
            return (str.find("nut") != std::string_view::npos);
        }
    };
    std::find_if(arr.begin(), arr.end(), findNut);
    // we can store lambda in a variable too
    // if lambda is generic, it will generate a lambda for each tpe it can take in
    // if there is a static variable, the scope of the static will not be shared between different generated lambdas
    // for example, print("string") and print(1) will have different callCount, whereas print("string") and print("type") will have same
    auto print {
        [](auto value) {
            static int callCount{0};
            ++callCount;
            std::cout << value << '\n';
        }
    };

    // lambda captures
    // lambdas can only access global identifiers, entities known at compile time, and static entities
    // capture clause can give access to the other variables
    
    // search for a string
    std::string search{};
    std::cin >> search;
    // notice search is in the capture clause
    // the variables in the capture clause are constant clones, lambda is not allowed to modify them
    // to allow the captured variables to be mutable, use mutable keyword
    // this also means that you cannot modify the variables through passing by value, you need to use
    // pass by reference
    auto found{ std::find_if(arr.begin(), arr.end(), [search](std::string_view str) mutable {
        return (str.find(search) != std::string_view::npos);
    })};

    // default capture
    // pass = to the capture clause to capture all variables by value
    // pass & to the capture clause to capture all variables by reference
    // [&](){}
    // [=](){}
    // dangling captured variables - when passing by ref, make sure the referent lives longer than the lambda, otherwise
    // lambda will refer to undefined variable

    // multiple mutable lambda
    // when passing to a function that internally uses std::function, a copy of the lambda object is made
    // when the lambda is excuted, it's the copy that's executed and not the actual lambda
    // as a part of <functional>, it allows us to pass a lambda as a ref, so that no copies will be made
    // foo(std::ref(bip));
}