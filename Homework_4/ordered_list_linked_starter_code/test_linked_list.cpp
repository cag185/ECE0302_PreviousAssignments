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
  //add a few values
  REQUIRE(list.insert(1,1) == true);
  REQUIRE(list.insert(2,1) == true);
  REQUIRE(list.insert(3,1) == true);

  //create new list -- copied from og
  LinkedList<int> list2(list);
  REQUIRE(list2.getLength() == 3);
  REQUIRE(list2.getEntry(1) == 1);
  REQUIRE(list2.getEntry(2) == 1);
  REQUIRE(list2.getEntry(3) == 1);
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
  REQUIRE(list.getEntry(2) == 2);
  REQUIRE(list.getEntry(3) == 1);
  REQUIRE(list.getLength() == 3); // also works

  //test case 2
  REQUIRE(list.insert(2,4) == true); //order should be 3 4 2 1
  REQUIRE(list.getEntry(1) == 3);
  REQUIRE(list.getEntry(2) == 4); 
  REQUIRE(list.getEntry(3) == 2); 
  REQUIRE(list.getEntry(4) == 1);
  REQUIRE(list.getLength() == 4);

  //test case 2 again
  LinkedList<int> listTest;
  REQUIRE(listTest.insert(1,50) == true);
  REQUIRE(listTest.insert(1,40) == true);
  REQUIRE(listTest.insert(1,30) == true);
  REQUIRE(listTest.insert(1,20) == true);
  REQUIRE(listTest.insert(1,10) == true);

  //insert value at position 4
  REQUIRE(listTest.insert(4,400) == true);
  //report values
  REQUIRE(listTest.getLength() == 6);
  REQUIRE(listTest.getEntry(1) == 10);
  REQUIRE(listTest.getEntry(2) == 20);
  REQUIRE(listTest.getEntry(3) == 30);
  REQUIRE(listTest.getEntry(4) == 400);
  REQUIRE(listTest.getEntry(5) == 40);
  REQUIRE(listTest.getEntry(6) == 50);


  //Test case 3 // all cases work
  //create a new linked list
  LinkedList<int> list2;
  REQUIRE(list2.insert(1,1)== true);
  REQUIRE(list2.getEntry(1) == 1);
  REQUIRE(list2.insert(2,2)== true);
  REQUIRE(list2.getEntry(2) == 2);
  REQUIRE(list2.insert(3,3)== true);
  REQUIRE(list2.getEntry(3) == 3); 
}


//remove an item
TEST_CASE( "remove", "[LinkedList]" ) {
  //create a linked list
  LinkedList<int> list;
  //add a few values -- test case 1
  REQUIRE(list.insert(1,1) == true);
  REQUIRE(list.remove(1) == true);
  REQUIRE(list.getLength()==0);

  //add a few more values -- test case 2
  REQUIRE(list.insert(1,1) == true);
  REQUIRE(list.insert(2,2) == true);
  REQUIRE(list.insert(3,3) == true);
  REQUIRE(list.remove(2) == true);
  REQUIRE(list.getEntry(1) == 1);
  REQUIRE(list.getEntry(2) == 3);
  REQUIRE(list.getLength() == 2);

  //remove value at the end -- test case 3
  REQUIRE(list.remove(2) == true);
  REQUIRE(list.getLength() == 1);
  REQUIRE(list.getEntry(1) == 1);
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
