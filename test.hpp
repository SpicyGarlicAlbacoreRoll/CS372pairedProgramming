#define CATCH_TEST
#ifndef CATCH_TEST
#include "catch.hpp"
#include <string>
#include "StringCalc.cpp"

TEST_CASE ("An Empty String returns zero" , "[Add]")
    REQUIRE( Add("") == 0);
TEST_CASE ("A single number returns the value")
    REQUIRE(Add("1") == 1 );

//TEST_CASE("Two numbers, comma delimited, returns the sum")
//    REQUIRE(Add(a, b) == a+b );
//
//TEST_CASE("Two numbers, newline delimited, returns the sum")
//    REQUIRE( );
//
//TEST_CASE("Three numbers, delimited either way, returns the sum")
//    REQUIRE( );
//
//TEST_CASE("Negative numbers throw an exception")
//    REQUIRE( );
//
//TEST_CASE("Numbers greater than 1000 are ignored")
//    REQUIRE( );
//
//TEST_CASE("A single char delimiter can be defined on the first line (e.g. //# for a ‘#’ as the delimiter)")
//    REQUIRE( );
//
//TEST_CASE("A multi char delimiter can be defined on the first line (e.g. //[###] for ‘###’ as the delimiter)")
//    REQUIRE
//
//TEST_CASE("Many single or multi-char delimiters can be defined (each wrapped in square brackets)")
//    REQUIRE

#endif