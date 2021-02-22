#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "bitset.hpp"

// THIS IS JUST AN EXAMPLE
// There should be at least one test per Bitset method

//--TEST EACH TYPE OF CONSTRUCTOR--//
//defualt constructor//
TEST_CASE( "Test bitset construction", "[bitset]" ) {

    Bitset b;  
    REQUIRE(b.size() == 8);
    REQUIRE(b.good());
}
//constructor with parameter
TEST_CASE( "Test bitset construction with paramter", "[bitset]") {
    //give bitset a starting size of 16
    Bitset a(16);
    //require validity to be true and for all numbers to be 8.
    //check that the size matches the paramter we input
    REQUIRE(a.good());
    REQUIRE(a.size() == 16);

}
//constructor with string paramater
TEST_CASE( "Test bitset construction with a string parameter", "[bitset]"){
    //give bitset a starting value from a string
    Bitset c("0101");
    //require validity to be true
    REQUIRE(c.good());
    REQUIRE(c.size() == 4);

    //again
    Bitset alpha ("101011110000");
    //require validity to be true
    REQUIRE(alpha.good());
    REQUIRE(alpha.size()==12);

    //again
    Bitset beta("302");
    //require validity to be false
    REQUIRE(beta.good() == false);
}

//test method to return size of bitset
TEST_CASE("Test bitset size", "[bitset]"){
    //give initial constructor
    Bitset a;
    REQUIRE(a.size() == 8);
    Bitset b(256);
    REQUIRE(b.size()==256);
    Bitset c("11110000");
    REQUIRE(c.size()== 8);
}

//test method for validity
TEST_CASE("Test validity", "[bitset]"){
    //create something to be valid
    Bitset a(65);
    REQUIRE(a.good());
    //create something to be invalid
    Bitset b("Hello");
    REQUIRE(b.good()== false);
    //create something to be valid
    REQUIRE(a.test(30)==false);
    //create something to be out of bounds//invalid
    REQUIRE(a.test(100) == false);
}

//test for set member function
TEST_CASE("Test Setting capability", "[bitset]"){
    //create bitset
    Bitset a(10);
    a.set(1);
    REQUIRE(a.good());

    a.set(12);
    REQUIRE(a.good()==false);
}

//test for reset member function
TEST_CASE("Test reset capability", "[bitset]"){
    Bitset b("1111");
    REQUIRE(b.good());
    b.reset(1);
    REQUIRE(b.asString() == "1011");
    REQUIRE(b.good());
}

//test for toggle
TEST_CASE("Test toggle capability", "[bitset]"){
    Bitset a("1010");
    REQUIRE(a.good());
    //toggle all bits to 1
    a.toggle(1);
    a.toggle(3);
    REQUIRE(a.asString() == "1111");
    //check for validity
    REQUIRE(a.good());
}

//Test for test function
TEST_CASE("Test the testing function", "[bitset]"){
    Bitset g("101011");
    REQUIRE(g.asString() == "101011");
    REQUIRE(g.test(0) == true);
    REQUIRE(g.test(2)== true);
    REQUIRE(g.test(4)== true);
    REQUIRE(g.test(5)== true);
    REQUIRE(g.test(1) == false);
    REQUIRE(g.test(3)== false);
    //also test for validity
    REQUIRE(g.good());
}

//Test for the bitset to string function
TEST_CASE("Test for bitset to String", "[bitset]"){
    Bitset y("101");
    y.set(1);
    //should have '111'
    //test
    REQUIRE(y.asString() == "111");
    //check validity
    REQUIRE(y.good());

    //try different way
    Bitset alpha(8); //8 bits all set to 0
    //set a few bits
    alpha.set(0);
    alpha.set(7);
    alpha.set(3);
    //should have 10010001
    REQUIRE(alpha.good());
    REQUIRE(alpha.asString() == "10010001");

}