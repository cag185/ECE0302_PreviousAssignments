#include "array_list.hpp"

template <typename T>
ArrayList<T>::ArrayList() {
  //constructor
  //allocate memory
  
  arrPoint = new T [arrSize]; // creates a new array, dynamically allocated, size arrSize
}

template <typename T>
ArrayList<T>::~ArrayList() {
  //destructor, free memory
  delete [] arrPoint; // frees memory
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList & rhs){
  //copy constructor, copies data from one array into another
  //create dynamically allocated array
 // T * arrPoint;
  arrPoint = new T [arrSize];

  //check for imcompatible array sizes
  while (arrSize < rhs.getLength())
  {
    resizeArray(); // resize array function
  }
  for (std::size_t i = 1; i<arrSize; i++)
  {
    //copy each value of old array into new array
    arrPoint[i] = rhs.getEntry(i); // copies each value from rhs into pointer to D.A.A
  }
}

//assign all values of the old D.A.A to the new
template <typename T>
ArrayList<T> & ArrayList<T>::operator=(const ArrayList & rhs){
  //check for compatible array size
  while(arrSize < rhs.getLength())
  {
    //run the resize function
    resizeArray();
  }
  for(std::size_t i = 1; i<this->arrSize; i++)
  {
    arrPoint[i] = rhs.getEntry(i); // assigns values from rhs into this pointer
  }
  return *this;
}

//determine if list is empty, return T/F
template <typename T>
bool ArrayList<T>::isEmpty() const{
  if(arrSize ==0)
  {return true;}
  else
  {return false;};
}

//return size of arrSize
template <typename T>
std::size_t ArrayList<T>::getLength() const{
  return usedSpace;
}

//insert an item into the list array at index positon
template <typename T>
bool ArrayList<T>::insert(std::size_t position, const T& item){
  //check for special cases
    //1. insert at the very beggining
    //2. insert at the very end
    //3. insert any place in the middle

  //also check for invalid position
  if(position < 1 || position > usedSpace + 1)
  {
    return false;
  }
  //create a new pointer to an array
  T * tempPoint;
  tempPoint = new T [arrSize];

  //check to see if the array needs to be resized before insertion
  if(arrSize == usedSpace)
  {
    resizeArray();
  }

  //case 1
  //position will be 1, first index of the pointer array
  if(position == 1)
  {
    tempPoint[1] = item;
    for(std::size_t i = 2; i< arrSize;i++)
    {
      //assign values from old array into new
      tempPoint[i] = arrPoint[i-1]; // arrPoint[i-1] because we are adding one extra to tempPoint than arrPoint
    }
    //now that tempPoint is copied all over, want to send that back to arrPoint
    for(std::size_t b = 1; b<arrSize; b++)
    {
      arrPoint[b] = tempPoint[b];
    }
    //increase usedSpace
    usedSpace++;
    //free memory
    delete [] tempPoint;
  }

  //case 2
  //position is any middle part
  if(position > 1 && position < usedSpace)
  {
    //copy everything before pos
    for(std::size_t alpha= 1; alpha < position; alpha++ )
    {
      tempPoint[alpha] = arrPoint[alpha];
    }
    //copy value at pos
    tempPoint[position] = item;
    //copy everything after position
    for(std::size_t beta = position+1; beta<arrSize; beta++)
    {
      tempPoint[beta] = arrPoint[beta + 1];
    }

    //copy everything back into arrPoint
    for(std::size_t omega = 1; omega < arrSize; omega++ )
    {
      arrPoint[omega] = arrPoint[omega];
    }
    //increase usedSpace
    usedSpace++;
    //free memory
    delete [] tempPoint;
  }

  //case 3
  //position is at the end of the array
  if(position > usedSpace)
  {
    for(std::size_t w = 1; w<position; w++)
    {
     tempPoint[w] = arrPoint[w]; //copies all values until position
    }
    //add on last value
    tempPoint[position] = item;
    //copy all elements of tempPoint back into arrPoint
    for(std::size_t i = 1; i<usedSpace + 1; i++)
    {
      //copy all values
      arrPoint[i] = tempPoint[i];
    }
    //increase usedSpace
    usedSpace++;
    //free memory
    delete [] tempPoint;
  }
  return true;
}

// remove item at position in the list using 1-based indexing
template <typename T>
bool ArrayList<T>::remove(std::size_t position){
  //check for an out of bound position
  if(position < 1 || position > usedSpace)  //check if the position is too small for array OR position is not included in the used space
  {
    return false;
  }
  else{   //position is within range
  //create a temporary pointer to a D.A.A.
  T * tempPoint;
  tempPoint = new T [arrSize]; // space allocated = space of arrPoint
  //We want to copy everything from before the positoin and store it into the temp array
  for(std::size_t i = 1; i < position; i++)
  {
    tempPoint[i] = arrPoint[i];
  }
  //remove the thing at Position by not inlcuding it
  for(std::size_t j = position; j <usedSpace; j++)
  {
    tempPoint[j] = arrPoint[j+1]; // copies everything AFTER position
  }
  //store everything from temp point back into the array pointer
  for(std::size_t a = 1; a<usedSpace; a++)
  {
    arrPoint[a] = tempPoint[a];
  }
  //free up the temporary pointer
  delete [] tempPoint;
  }
  return true;
}

template <typename T>
void ArrayList<T>::clear() {
//deallocate the memory
delete [] arrPoint;
arrPoint = new T [arrSize];
usedSpace = 0;
}

//gets an entry from the array at a specific index
template <typename T>
T ArrayList<T>::getEntry(std::size_t position) const {
  //return arrPoint[position];
  return *(arrPoint + position+ 1);
}

//set the value of the aray at the listed index
template <typename T>
void ArrayList<T>::setEntry(std::size_t position, const T& newValue) {
arrPoint[position] = newValue; // plugs in newValue at the position of the array
}

// resize the array to one that can suit the needs of the function
template <typename T>
void ArrayList<T>::resizeArray()  
{
T *arrPoint2; //create another pointer
arrPoint2 = new T [2 * arrSize]; //create a new array that is double the size of the old one

//assign all the values from old array into new array - index at 1
for(int i = 1; i < (int)arrSize; i++)
  {
    arrPoint2[i] = arrPoint[i];
  }

//delete old array
delete [] arrPoint;
arrSize = arrSize * 2; //update arrSize
//reassign arrPoint from arrPoint 2;
arrPoint = new T [arrSize];
for(std::size_t x; x< arrSize; x++) //assign all values of point2 to arraypoint
{
  arrPoint[x] = arrPoint2[x];
}
//release arrPoint2 to avoid memory leak
delete [] arrPoint2;
}