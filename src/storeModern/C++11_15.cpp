/*
9. New String Literals

#1: C++03
this is usually how you define a string literal in C++03

#2:
C++11 provides a better support for Unicode 

in raw string define, the '\\' will be interpreted as two slashes instead of one 
slash because the first slash is not seen as escape character anymore beacuse of
raw string identifier

you have to define the raw string delimereter. you are free defining this delimereter
whatever you want you can define.
    format : R"delimiter(raw_characters)delimeter"


*/

#include <iostream>

int main()
{
    //#1
    char *a = "string";

    //#2
    char *a2 = u8"string";            //to define an UTF-8 string
    char16_t *b = u"string";          //to define an UTF-16 string
    char32_t *c = U"string";          //to define an UTF-32 string
    char *d = R"###("string \\")###"; //to define a raw string

    std::cout << "d: " << d << std::endl;

    return 0;
}