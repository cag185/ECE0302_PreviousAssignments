#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "linked_list.hpp"

//force class expansion
template class LinkedList<int>;

//test case for constructor -- DONE
TEST_CASE( "Constructor", "[LinkedList]" ) {
  //create a linked list
  LinkedList<int> list;
  //test size
  REQUIRE(list.getLength() == 0); 
}

//test case for copy constructor
TEST_CASE( "Copy constructor", "[LinkedList]" ) {
  //create a linked list
  LinkedList<int> list;
}

//copy assignment
TEST_CASE( "Copy assignment", "[LinkedList]" ) {
  //create a linked list
  LinkedList<int> list;
}

//swap two lists
TEST_CASE( "Swap", "[LinkedList]" ) {
  //create a linked list
  LinkedList<int> list;
}

//determine if a list is empty
TEST_CASE( "isEmpty", "[LinkedList]" ) {
  //create a linked list
  LinkedList<int> list;
}

//get length
TEST_CASE( "getLength", "[LinkedList]" ) {
  //create a linked list
  LinkedList<int> list;
}

//insert
TEST_CASE( "insert", "[LinkedList]" ) {
  //create a linked list
  LinkedList<int> list;
  //test case 1
  REQUIRE(list.insert(1,1)==true); // works 
  REQUIRE(list.getEntry(1) == 1);
  REQUIRE(list.getLength() == 1);
  //test case 1 again
  REQUIRE(list.insert(1,2)== true);
  REQUIRE(list.getEntry(1) == 2);
  REQUIRE(list.getLength() == 2);  // also works
  //test case 1 again
  REQUIRE(list.insert(1,3) == true);
  REQUIRE(list.getEntry(1) == 3);
  REQUIRE(list.getLength() == 3); // also works

  //test case 2
  REQUIRE(list.insert(2,4) == true); //order should be 1 4 2 3
  REQUIRE(list.getLength() == 4);
}

//remove an item
TEST_CASE( "remove", "[LinkedList]" ) {
  //create a linked list
  LinkedList<int> list;
}

//clear
TEST_CASE( "clear", "[LinkedList]" ) {
  //create a linked list
  LinkedList<int> list;
}

//get entry
TEST_CASE( "getEntry", "[LinkedList]" ) {
  //create a linked list
  LinkedList<int> list;
}

//set entry
TEST_CASE( "setEntry", "[LinkedList]" ) {
  //create a linked list
  LinkedList<int> list;
  
}
