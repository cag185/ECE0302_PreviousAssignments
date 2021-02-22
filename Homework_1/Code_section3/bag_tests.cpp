#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "bag.hpp"


// force template expansion
//creates a bag
template class Bag<int>;

//see if the bag starts off empty -- it should -- works
TEST_CASE("Empty Test", "[Bag]")
{
  Bag<int> bag1;
  REQUIRE(bag1.isEmpty());
}

//test to add a new entry -- works
TEST_CASE("Add Test", "[Bag]")
{
  Bag<int> bag1;
  REQUIRE(bag1.add(1)== true);
}

//test to get size
TEST_CASE("Size Test", "[Bag]")
{
  Bag<int> bag1;
  bag1.add(1);
  bag1.add(3);
  REQUIRE(bag1.getCurrentSize()==2);
}

//Test to remove -- works
TEST_CASE("Remove Test", "[Bag]")
{
  Bag<int> bag1;
  bag1.add(2);
  bag1.add(3);
  bag1.add(4);
  REQUIRE(bag1.remove(2)== true);
}

//Test to clear
TEST_CASE("Clear Test","[Bag]")
{
  Bag<int> bag1;
  bag1.add(1);
  bag1.add(2);
  bag1.add(3);
  bag1.clear();
  REQUIRE((int)bag1.getCurrentSize() == 0); //-- need to see if bag is empty
}

//Test to get Frequency
TEST_CASE("Frequency Test", "[Bag]")
{
  Bag<int> bag1;
  bag1.add(1);
  bag1.add(1);
  bag1.add(2);
  REQUIRE(bag1.getFrequencyOf(1)== 2); //-- need to see what the frequency is
}

//Test to see if bag contains a specific thing
TEST_CASE("Contains Test", "[Bag]")
{
  Bag<int> bag1;
  bag1.add(1);
  REQUIRE(bag1.contains(1)); //-- contains a certain thing -- works
}