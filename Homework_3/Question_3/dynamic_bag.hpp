#ifndef _DYNAMIC_BAG_HPP_
#define _DYNAMIC_BAG_HPP_

#include "abstract_bag.hpp"

template <typename T>
class DynamicBag: public AbstractBag<T>
{
public:
  // default constructor
  DynamicBag();
  
  // copy constructor
  DynamicBag(const DynamicBag& x);
    
  // destructor
  ~DynamicBag();
  
  // copy assignment
  DynamicBag& operator=(DynamicBag& x);

  // add an item to the bag
  bool add(const T & item);
  
  // remove an item
  bool remove(const T & item);

  // check is the bag is empty
  bool isEmpty() const;

  // get number of items in the bag
  std::size_t getCurrentSize() const;

  // clear the bag contents
  void clear();

  // count how many time item occurs in bag
  std::size_t getFrequencyOf(const T & item) const;

  // check if item is in the bag
  bool contains(const T& item) const;

private:
  //create a variable for bag size
  std:: size_t bagSize = 0;

  // CREATE a node class
  
  class Node {
    public:
      //create a data type and variable
      //Creates a pointer that points to the next node
      T data;
      Node * next = NULL;
  };
   Node * head = NULL;
   Node * tail = NULL;
};

#include "dynamic_bag.tpp"

#endif
