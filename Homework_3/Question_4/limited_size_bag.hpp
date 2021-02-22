#ifndef LIMITED_SIZE_BAG_HPP
#define LIMITED_SIZE_BAG_HPP

#include "abstract_bag.hpp"


template <typename T>
class LimitedSizeBag: public AbstractBag<T>
{
public:
  // default constructor
  LimitedSizeBag();
  
  // copy constructor
  LimitedSizeBag(const LimitedSizeBag& x);
    
  // destructor
  ~LimitedSizeBag();
  
  // copy assignment
  LimitedSizeBag& operator=(LimitedSizeBag& x);

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
  std:: size_t maxSize = 10;

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

#include "limited_size_bag.tpp"

#endif
