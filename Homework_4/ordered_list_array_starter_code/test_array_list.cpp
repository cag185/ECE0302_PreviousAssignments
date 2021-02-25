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

  //require that the elements copied over as well 
  REQUIRE(list.getEntry(1) == 10);
  REQUIRE(list.getEntry(2) == 2);
  REQUIRE(list.getEntry(3) == 3);
}

TEST_CASE( "Copy Assignment", "[ArrayList]" ) {

  ArrayList<int> list; // creates an integer list
  //assign a few values
  REQUIRE(list.insert(1,10) == true);
  REQUIRE(list.insert(2,20) == true);
  REQUIRE(list.insert(3,30) == true);

  //create a second list
  ArrayList<int> list2;// empty so far
  list2 = list; //copy assignment
  //make sure values copied over and that the size is correct
  REQUIRE(list2.getLength() ==3);
  REQUIRE(list2.getEntry(1) == 10);
  REQUIRE(list2.getEntry(2) == 20);
  REQUIRE(list2.getEntry(3) == 30);
}

TEST_CASE( "isEmpty", "[ArrayList]" ) {

  ArrayList<int> list; // creates an integer list // empty so far
  REQUIRE(list.isEmpty() == true);
}

TEST_CASE( "getLength", "[ArrayList]" ) {

  ArrayList<int> list; // creates an integer list
  REQUIRE(list.getLength()== 0);
  //add some entries
  REQUIRE(list.insert(1,1)== true);
  REQUIRE(list.getLength() == 1);
  REQUIRE(list.insert(2,2) == true);
  REQUIRE(list.getLength() == 2);
}

TEST_CASE( "Insert", "[ArrayList]" ) {

  ArrayList<int> list; // creates an integer list
  //insert a few values
  REQUIRE(list.insert(1,100) == true);
  REQUIRE(list.insert(2,200) == true);
  //make sure size increased
  REQUIRE(list.getLength() == 2);
}

TEST_CASE( "Remove", "[ArrayList]" ) {

  ArrayList<int> list; // creates an integer list
  //add a value
  REQUIRE(list.insert(1,1) == true);
  //make sure it removes
  REQUIRE(list.remove(1) == true); // works
  //test for an array that has more than 1 element, remove from beginning
  REQUIRE(list.insert(1,1) == true);
  REQUIRE(list.insert(2,2) == true);
  REQUIRE(list.insert(3,3) == true);
  //remove first element
  REQUIRE(list.remove(1) == true);
  REQUIRE(list.getLength() == 2);
  REQUIRE(list.getEntry(1) == 2);
  REQUIRE(list.getEntry(2) == 3); //works

  //remove all elements
  REQUIRE(list.remove(1) == true);
  REQUIRE(list.remove(1) == true);
  REQUIRE(list.getLength() == 0); // make sure array is clear

  REQUIRE(list.insert(1, 1) == true);
  REQUIRE(list.insert(2, 5) == true);
  REQUIRE(list.insert(3, 100) == true);
  REQUIRE(list.insert(4, 3) == true);
  REQUIRE(list.insert(5, 2)== true); // added some values

  REQUIRE(list.remove(3) == true);
  REQUIRE(list.getLength() == 4);
  REQUIRE(list.getEntry(3) != 100);
  REQUIRE(list.getEntry(3) == 3); // all works, test case 3 good

  //test case 4
  //create new array
  ArrayList<int> list2; 
  //add a few values
  REQUIRE(list2.insert(1,1) == true);
  REQUIRE(list2.insert(2,2) == true);
  REQUIRE(list2.insert(3,3) == true);
  //remove last item
  REQUIRE(list2.remove(3) == true);
  REQUIRE(list2.getLength() == 2);
  REQUIRE(list2.getEntry(3) != 3); // all remove cases work

}

TEST_CASE( "clear", "[ArrayList]" ) {

  ArrayList<int> list2; // creates an integer list
  //add a few values
  REQUIRE(list2.insert(1,5)== true);
  REQUIRE(list2.insert(2,6)== true);
  REQUIRE(list2.insert(3,7)== true);
  REQUIRE(list2.insert(4,8)== true);
  //clear
  list2.clear();
  //make sure used space == 0
  REQUIRE(list2.getLength() == 0); // works
}

TEST_CASE( "getEntry", "[ArrayList]" ) {

  ArrayList<int> list; // creates an integer list
  //insert some items
  REQUIRE(list.insert(1, 100) == true);
  REQUIRE(list.insert(2,200) == true);
  
  //make sure values are right
  REQUIRE(list.getEntry(1) == 100);
  REQUIRE(list.getEntry(2) == 200); // works
}

TEST_CASE( "setEntry", "[ArrayList]" ) {

  ArrayList<int> list; // creates an integer list
  //create some entries
  REQUIRE(list.insert(1,1) == true);
  REQUIRE(list.insert(2,2) == true);
  REQUIRE(list.insert(3,2) == true);
  REQUIRE(list.insert(4,3) == true);
  REQUIRE(list.insert(5,4) == true);

  //reset a few
  list.setEntry(3,3);
  list.setEntry(4,4);
  list.setEntry(5,5);

  //check
  REQUIRE(list.getEntry(3) == 3);
  REQUIRE(list.getEntry(4) == 4);
  REQUIRE(list.getEntry(5) == 5);// WORKS
}

TEST_CASE( "resizeArray", "[ArrayList]" ) {

  ArrayList<int> list; // creates an integer list
  //list starts at getArraySize = 1
  REQUIRE(list.getArraySize() == 1);
  list.resizeArray();
  //make sure the size doubles
  REQUIRE(list.getArraySize() == 2);
  //repeat
  list.resizeArray();
  REQUIRE(list.getArraySize() == 4);
}