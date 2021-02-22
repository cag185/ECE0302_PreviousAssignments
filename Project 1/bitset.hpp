#ifndef BITSET_HPP
#define BITSET_HPP
#include <cstdint>
#include <string>

class Bitset{
public:

  //Defualt Constructor-- Bitset of width 8, all bits are set to 0
  Bitset();

  //Constructor that sets a bitset to be intmax_t units large, all bits set to 0, N must be larger than 0
  Bitset(intmax_t size);

  //Constructor that sets bitset based on string, only 1/0 allowed
  Bitset(const std::string & value);

  //destructor that frees allocated storage in array
  ~Bitset();

  Bitset(const Bitset & ) = delete;
  Bitset & operator=(const Bitset &) = delete;

  //Method to determine size of bitset
  intmax_t size() const;

  //Method to determine if bitset is valid
  bool good() const;

  //Method to set nth bit to 1, if 0<n<size-1
  //Invalid if n is out of range
  void set(intmax_t index);

  //Method to reset nth bit to 0 if 0<n<size-1
  //Invalid if n is out of range
  void reset(intmax_t index);

  //Method to toggle the nth bit, if 0<n<size-1
  //Invalid if n is out of range
  void toggle(intmax_t index);

  //Method to see if nth bit is set or reset (1 or 0) -- true is returned for set
  //false is return if bit is reset or bit is out of range
  bool test(intmax_t index);

  //function to return the bitset as a string of numbers
  std::string asString() const;

private:

  //create a pointer to an array of type intmax_t
  intmax_t * bit1;
  //boolean to keep track of validity
  bool validity = true;
  //size of the bitset
  intmax_t sizeArr = 0;

};

#endif
