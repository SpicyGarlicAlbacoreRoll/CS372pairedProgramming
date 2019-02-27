#include <iostream>
#include <string>
#include <sstream>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
//#include "kimStringCalc.hpp"


int Add(std::string numbers)
{
    std::stringstream stringInt;

    stringInt << numbers;

    std::string tempString;

    int sum = 0;

    while(!stringInt.eof())
    {
        stringInt >> tempString;
        
        if(tempString == ",")
        {
            stringInt >> tempString;
            std::stringstream(tempString) >> sum;
        }
        std::stringstream(tempString) >> sum;

        //tempString = "";
    }

    return sum;
}

TEST_CASE ("An Empty String returns zero")
    {

    REQUIRE( Add("Hello") == 0);
    
    }

TEST_CASE ("String with argument of string 'a' returns int 'a'")
    {
        REQUIRE(Add("20") == 20);
    }

TEST_CASE ("String with two numbers")
    {
        REQUIRE(Add("21,22") == 43);
    }

//TEST_CASE ("A single number")
