
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include <string>
using std::string;

//to_number
//Converts string to number of base ten.
int to_number(const string num)
{
    char* end;
    return std::strtol(num.c_str(), &end, 10);
}
//next_Delimiter function
//Will mark , and new lines as delimiters and handle them appropriately
size_t next_Delimiter(const string& num, size_t start)
{
    return num.find_first_of(",\n", start);
}
//next_Number function
//Moves on to the next number in the string.
string next_Number(const string &num, size_t start)
{
    return num.substr(start+1);
}

int Add(const std::string &num)
{
    if (num == "")
    {
        return 0;
    }
    if (num == "1")
    {
        return 1;
    }

    size_t delimiter = next_Delimiter(num, 0);
    int result = to_number(num);
    while(delimiter != string::npos)
    {
        result += to_number(next_Number(num, delimiter));
        delimiter = next_Delimiter(num, delimiter+1);
    }

    return result;


}

//Test Cases


TEST_CASE ("An Empty String returns zero" , "[Add]")
{
    REQUIRE( Add("") == 0);
}
TEST_CASE ("A single number returns the value")
{
    REQUIRE(Add("1") == 1);
}

TEST_CASE("Two numbers, comma delimited, returns the sum")
{
    REQUIRE(Add("1, 2") == 1 + 2);
}

TEST_CASE("Two numbers, newline delimited, returns the sum")
{
    REQUIRE(Add("1\n2, 3") == 6);
}
//TEST_CASE("Three numbers, delimited either way, returns the sum")
//    REQUIRE( );
//
//TEST_CASE("Negative numbers throw an exception")
//    REQUIRE( );
//
//TEST_CASE("Numbers greater than 1000 are ignored")
//{
//    REQUIRE(Add("1000") == 0);
//}

//TEST_CASE("A single char delimiter can be defined on the first line (e.g. //# for a ‘#’ as the delimiter)")
//    REQUIRE( );
//
//TEST_CASE("A multi char delimiter can be defined on the first line (e.g. //[###] for ‘###’ as the delimiter)")
//    REQUIRE
//
//TEST_CASE("Many single or multi-char delimiters can be defined (each wrapped in square brackets)")
//    REQUIRE
