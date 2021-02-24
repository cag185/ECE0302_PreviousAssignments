#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "array_list.hpp"

//force class expansion
template class ArrayList<int>;

//create a defualt constructor
TEST_CASE( "Defualt Constructor", "[ArrayList]" ) {

  ArrayList<int> list; // creates an integer list
  //usedSpace should be 0 at this point
  REQUIRE(list.getLength() == 0);
}

TEST_CASE( "Copy Constructor", "[ArrayList]" ) {

  ArrayList<int> list; // creates an integer list
  //add some values to list
  REQUIRE(list.insert(1, 10) == true);
  REQUIRE(list.insert(2, 2) == true);
  REQUIRE(list.insert(3, 3) == true);
  //arrSize should be = 4, used space = 3
  //test to make sure that items have been inserted in list
  REQUIRE(list.getEntry(1) == 10);
  REQUIRE(list.getEntry(2) == 2);
  REQUIRE(list.getEntry(3) == 3);

  ArrayList<int> list2(list); // creates a new list that is a copy of the old list
  REQUIRE(list2.getLength() == 3); //verify that num of elements copied over

  //require that the elements copied over as well -- COPY CONSTRUCTOR MAKING MEMORY ISSUES
  REQUIRE(list.getEntry(1) == 10);
  REQUIRE(list.getEntry(2) == 2);
 // REQUIRE(list.getEntry(1) == 3);
}

TEST_CASE( "Copy Assignment", "[ArrayList]" ) {

  ArrayList<int> list; // creates an integer list
}

TEST_CASE( "isEmpty", "[ArrayList]" ) {

  ArrayList<int> list; // creates an integer list
}

TEST_CASE( "getLength", "[ArrayList]" ) {

  ArrayList<int> list; // creates an integer list
}

TEST_CASE( "Insert", "[ArrayList]" ) {

  ArrayList<int> list; // creates an integer list
}

TEST_CASE( "Remove", "[ArrayList]" ) {

  ArrayList<int> list; // creates an integer list
}

TEST_CASE( "clear", "[ArrayList]" ) {

  ArrayList<int> list; // creates an integer list
}

TEST_CASE( "getEntry", "[ArrayList]" ) {

  ArrayList<int> list; // creates an integer list
}

TEST_CASE( "setEntry", "[ArrayList]" ) {

  ArrayList<int> list; // creates an integer list
}

TEST_CASE( "resizeArray", "[ArrayList]" ) {

  ArrayList<int> list; // creates an integer list
}