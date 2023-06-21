#include <string_view>
// use string_view over string for const strings
// string makes a copy when initialized, whereas string_view does not, so it's much faster

// when passing string to parameters, use std::string_view over const std::string&
void doSomething(std::string_view);
// std::string_view is not guaranteed to be null-terminated

// ownership issue:
// since a string_view can have a longer life than the string it's observing, we need
// to make sure the string being observed lives as long as the string_view
// to access the underlying C-style string, use std::string_view::data.
// Note: Make sure the C-style string is null terminated!
// Best practice: convert std::string_view to std::string first, which is guaranteed to be 
// null terminated. Then do std::string::data