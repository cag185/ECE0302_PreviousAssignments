#include "bitset.hpp"

//include headers
#include <iostream>

  //Defualt Constructor-- Bitset of width 8, all bits are set to 0
  Bitset::Bitset()
  {
      bit1 = new intmax_t [8];
      for (int i = 0; i <8; i++)
      {
          bit1[i] = 0;
      }
      sizeArr = 8;
  }

  //Constructor that sets a bitset to be intmax_t units large, all bits set to 0, N must be larger than 0
  Bitset::Bitset(intmax_t size)
  {
      if(size > 0)
      {
          sizeArr = size;
      bit1 = new intmax_t[size];
      for(int i = 0; i<size;i++)
      {
          bit1[i] = 0;
      }
      }
      else
      {
          //invalid
        validity = false;
      }
  }

  //Constructor that sets bitset based on string, only 1/0 allowed
  Bitset::Bitset(const std::string & value)
  {
      //variable to store string as integer
      int length = value.length();
      sizeArr = length;
      bit1 = new intmax_t[length];

      //check for validity
      for (int i = 0; i < length;i++)
      {
          //check for 1
          if(value[i] == '1')
          {
            bit1[i] = 1;
          }
          else if (value[i]== '0')
          {
              bit1[i] = 0;
          }
          else
          {
              //invalid
              validity = false;
          }
      }
  }

  //destructor that frees allocated storage in array
  Bitset::~Bitset()
  {
      delete bit1;
  }

  //Method to determine size of bitset
  intmax_t Bitset:: size() const
  {
      return sizeArr;
  }

  //Method to determine if bitset is valid
  bool Bitset::good() const
  {
      //bitset is valid when validity = true
    if(validity == true)
        return true;
    else
        return false;
  }

  //Method to set nth bit to 1, if 0<n<size-1
  //Invalid if n is out of range
  void Bitset:: set(intmax_t index)
  {
      //check for range
      if(0 <= index && index < size())
      {
          validity = true;
          //set the bit
          bit1[index] = 1;
      }
      else
        validity = false;
  }

  //Method to reset nth bit to 0 if 0<n<size-1
  //Invalid if n is out of range
  void Bitset::reset(intmax_t index)
  {
      //check for range
      if(0 <= index && index < size())
      {
          validity = true;
          //set the bit
          bit1[index] = 0;
      }
      else
        validity = false;
  }

  //Method to toggle the nth bit, if 0<n<size-1
  //Invalid if n is out of range
  void Bitset::toggle(intmax_t index)
  {
      //check for range
      if(0 <= index && index < size())
      {
          validity = true;
          //toggle bit
          if(bit1[index]==1)
            {bit1[index] = 0;}
          else
            {bit1[index] = 1;}
      }
      else
        validity = false;
  }

  //Method to see if nth bit is set or reset (1 or 0) -- true is returned for set
  //false is return if bit is reset or bit is out of range
  bool Bitset:: test(intmax_t index)
  {
      //test for range
      if(0 <= index && index < size())
      {
          //valid range
        if(bit1[index]==1)
        {
            return true;
        }
        else if (bit1[index]==0)
        {
            return false;
        }
      }
      else
      {
          //false is returned, and validity = false
          validity = false;
          return false;
      }
      return false;
  }

  //function to return the bitset as a string of numbers
  std::string Bitset::asString() const
  {
      //make a string 
      std::string ans = "";
      for (int i= 0; i< size() ;i++)
      {
          //check each index for 0 or 1
        if(bit1[i] == 1)
            ans.append("1");
        else
            ans.append("0");
      }
      //return string
      return ans;
  }