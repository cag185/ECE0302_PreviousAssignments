#ifndef STUDENT_BAG_HPP
#define STUDENT_BAG_HPP

#include <cstdlib>
#include <vector>

template<typename T> 
class Bag
{
private:
  

public:

  //create a variable for the size
  std::size_t bagSize;
  std::size_t maxSize;
  
  //variable for vector
  std::vector<T> bag1;

  //probaby gets all objects in this bag
  Bag();
  
  ~Bag();
  //Returns the current number of entries in the bag
  std::size_t getCurrentSize() const;

  //returns true if bag is empty
  bool isEmpty() const;

  //adds a new entry to the bag -- boolean tells client if the addition was succesful
  bool add(const T& entry);

  //removes an entry from the bag if possible -- boolean in case not possible
  bool remove(const T& entry);

  //removes all entries from the bag
  void clear();

  //counts the number of times a given entry appears in the bag
  std::size_t getFrequencyOf(const T& entry) const;

  //tests whether the bag contains a given entry -- boolean in case not possible
  bool contains(const T& entry) const;

};

#include "bag.tpp"

#endif
