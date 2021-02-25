#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "linked_list.hpp"

//force class expansion
template class LinkedList<int>;

//test case for constructor
TEST_CASE( "Constructor", "[LinkedList]" ) {
  //create a linked list
  LinkedList<int> list;
  //test size
  REQUIRE(list.getLength() == 0); //works
}
