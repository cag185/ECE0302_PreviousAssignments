#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "dynamic_bag.hpp"

// force template expansion for ints
template class DynamicBag<int>;

TEST_CASE("Calling all public members", "[DynamicBag]"){
  DynamicBag<int> b;
  b.add(0); // test
  b.remove(0); // test
  b.isEmpty(); // test
  b.getCurrentSize(); //test get current size
  b.clear();
  b.getFrequencyOf(0);
  b.contains(0);
}
//TEST CONSTRUCTORS//

//defualt
TEST_CASE("DEFUALT CONSTRUCTOR", "[DynamicBag]"){
  DynamicBag<int> b; // create bag
  REQUIRE(b.add(0) == true);
  REQUIRE(b.getCurrentSize() == 1);
}

//copy constructor
TEST_CASE("COPY CONSTRUCTOR", "[DynamicBag]"){
  DynamicBag<int> a; // create bag
  a.add(100);
  a.add(20);

  //copy the first constructor into the second
  DynamicBag<int> b(a); //creates a copy
  REQUIRE(b.getCurrentSize() == 2);
  REQUIRE(b.contains(100) == true);
  REQUIRE(b.contains(20) == true);
}

//Copy two bags 
TEST_CASE("COPY ASSIGNMENT", "[DynamicBag]")
{
  //create two constructors
  DynamicBag<int> a;
  a.add(1);
  a.add(2);
  a.add(3);

  DynamicBag<int> b;
  b = a;

  REQUIRE(b.getCurrentSize()== 3); //check that size and contents transferred
  REQUIRE(b.contains(1)== true);
  REQUIRE(b.contains(2)== true);
  REQUIRE(b.contains(3)== true);
}

TEST_CASE("Add function", "[DynamicBag]"){
  DynamicBag<int> b; // create bag
  REQUIRE(b.add(1) == true);
  REQUIRE(b.add(2) == true);
  REQUIRE(b.getCurrentSize() == 2);
}

//remove
TEST_CASE("Remove function", "[DynamicBag]")
{
  DynamicBag<int> a;
  a.add(1);
  a.add(57);
  a.add(69);
  REQUIRE(a.getCurrentSize() == 3);
  a.remove(57);
  a.remove(1);
  REQUIRE(a.getCurrentSize() == 1);

}

//isEmpty
TEST_CASE("Empty function", "[DynamicBag]")
{
  DynamicBag<int> a;
  a.add(1);
  REQUIRE(a.getCurrentSize() == 1);
  a.remove(1);
  REQUIRE(a.isEmpty() == true);
}

//getCurrentSize
TEST_CASE("getCurrentSize function", "[DynamicBag]")
{
  DynamicBag<int> b;
  b.add(1);
  b.add(2);
  b.add(2);
  REQUIRE(b.getCurrentSize() == 3);

  DynamicBag<int> c;
  c.add(1);
  c.add(2);
  c.remove(2);
  REQUIRE(c.getCurrentSize() == 1);
}

//clear
TEST_CASE("clear", "[DynamicBag]")
{
  DynamicBag<int> a;
  a.add(1);
  a.add(4);
  a.add(5);
  a.clear();
  REQUIRE(a.getCurrentSize() == 0);
  REQUIRE(a.contains(1)==false);
  REQUIRE(a.contains(4)==false);
  REQUIRE(a.contains(5)==false);
}

//getFrequency
//clear
TEST_CASE("getFrequency", "[DynamicBag]")
{
  DynamicBag<int> a;
  a.add(1);
  a.add(4);
  a.add(5);
  a.add(5);
  a.add(5);
  REQUIRE(a.getCurrentSize() == 5);
  REQUIRE(a.getFrequencyOf(5) == 3);
}

//Contains
//clear
TEST_CASE("Contains", "[DynamicBag]")
{
  DynamicBag<double> a;
  a.add(1.0);
  a.add(4.5);
  a.add(5.1);
  REQUIRE(a.getCurrentSize() == 3);
  REQUIRE(a.contains(1.0)==true);
  REQUIRE(a.contains(4.5)==true);
  REQUIRE(a.contains(5.1)==true);
  REQUIRE(a.contains(0) == false);
  REQUIRE(a.contains(10) == false);
}