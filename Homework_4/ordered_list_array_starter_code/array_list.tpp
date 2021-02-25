#include "array_list.hpp"

template <typename T>
ArrayList<T>::ArrayList() {
  //constructor
  //allocate memory
  arrSize = 1;
  arrPoint = new T [arrSize]; // creates a new array, dynamically allocated, size arrSize
  usedSpace = 0;
}

template <typename T>
ArrayList<T>::~ArrayList() { 
  //destructor, free memory
  delete [] arrPoint; // frees memory
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList & rhs){
  //copy constructor, copies data from one array into another
  usedSpace = rhs.getLength();
  arrSize = rhs.getArraySize();
  arrPoint = new T [arrSize]; // makes arrPoint the correct size

  //copy all values
  for(std::size_t i = 1; i <= arrSize; i++)
  {
    arrPoint[i] = rhs.getEntry(i);
  }

}

//assign all values of the old D.A.A to the new
template <typename T>
ArrayList<T> & ArrayList<T>::operator=(const ArrayList & rhs){
  //copy assignment, copies one array to another existing array
  //make arrays the same size
  while(arrSize < rhs.getArraySize())
  {
    resizeArray();
  }
  //update used space
  usedSpace = rhs.getLength();

  //copy all values
  for(std::size_t i = 1; i <= arrSize; i++)
  {
    arrPoint[i] = rhs.getEntry(i);
  }

  return *this;
}

//determine if list is empty, return T/F -- WORKS
template <typename T>
bool ArrayList<T>::isEmpty() const{
  if(usedSpace ==0)
  {return true;}
  else
  {return false;};
}

//return size of arrSize -- WORKS
template <typename T>
std::size_t ArrayList<T>::getLength() const{
  return usedSpace;
}

 // return the size of the actual array
template <typename T>
std::size_t ArrayList<T>::getArraySize() const
  {
    return arrSize;

  }

//insert an item into the list array at index positon -- WORKS
template <typename T>
bool ArrayList<T>::insert(std::size_t position, const T& item){
  //check for special cases
    //1. insert at the very beggining and array empty
    //2. insert at beggining, not empty
    //3. insert at the very end
    //4. insert any place in the middle

    //check for out of bounds
    if(position > arrSize + 1)
    {
      return false;
    }
    //Case 1
    if(arrSize == 1 && isEmpty() == true)
    {
      arrPoint[1] = item;
      usedSpace++;
      return true;
    }
    //use the second pointer to copy all values of the original after 1
    //create second pointer
    T *tempPoint;
    tempPoint = new T [arrSize];

    //Case 2
    if(position == 1 && usedSpace >= 1)
    {
      //check if the array needs to be resized
      if(usedSpace == arrSize)
      {
       resizeArray();
      }

      tempPoint[1] = item;
      for(std::size_t i = 2; i <= arrSize; i++)
      {
        //copy all values
        tempPoint[i] = arrPoint[i-1];
      }
      //copy all values back into arrayPoint
      for(std::size_t j = 1; j<=arrSize;j++)
      {
        //copy all values back
        arrPoint[j] = tempPoint[j];
      }
      //free memory
      delete [] tempPoint;
      //increase size
      usedSpace++;
      return true;
    } 

    //Case 3
    if(position > 1 && position == usedSpace+1) // at the end of the used space in the array
    {
      //check if we need to resize
      if(usedSpace == arrSize)
      {
        resizeArray();
      }
      //copy everything from arrPoint to tempPoint
      for(std::size_t i = 1; i<=usedSpace; i++)
      {
        tempPoint[i] = arrPoint[i];
      }
      tempPoint[position] = item; // last item is tacked on
      //loop through and recopy all values
      for(std::size_t a = 1; a<= arrSize; a++)
      {
        arrPoint[a] = tempPoint[a];
      }
      //increase used space
      usedSpace++;
      //release memory
      delete [] tempPoint;
      //return
      return true;
    }

    //Case 4
    if (position > 1 && position < usedSpace) // in the middle
    {
      //check if the array needs to be resized
      if(usedSpace == arrSize)
      {
       resizeArray();
      }
      for(std::size_t i = 1; i < position; i++)
      {
        tempPoint[i] = arrPoint[i];
      }
      tempPoint[position] = item;
      for(std::size_t j = position + 1; j<arrSize; j++)
      {
        tempPoint[j] = arrPoint[j-1];
      }
      //now copy everything from temp pointer to array pointer
      for(std::size_t a = 1; a< arrSize; a++)
      {
        arrPoint[a] = tempPoint[a];
      }
      //increase size
      usedSpace++;
      //delete temp point
      delete [] tempPoint;
      //return
      return true;
    }
  return false;
}

// remove item at position in the list using 1-based indexing
template <typename T>
bool ArrayList<T>::remove(std::size_t position){
  //check for an out of bound position
  if(position < 1 || position > usedSpace)  //check if the position is too small for array OR position is not included in the used space
  {
    return false;
  }
  //if position is within range
  //CASES
    //1. the item is at the beggining of array where size = 1
    //2. the item is at the beggining of array where size > 1
    //3. the item is in a random spot in the middle
    //4. the item is at the end

    //create a temp pointer
    T *tempPoint;
    tempPoint= new T [arrSize];
  //1. 
  if(arrSize == 1 && position == 1)
  {
    delete [] arrPoint; //removes all elements
    arrSize = 1;
    arrPoint = new T [arrSize]; // resets array size to 1
    usedSpace--; // decriment usedSpace
    return true;
  }
  //2.
  if(arrSize > 1 && position == 1)
  {
    //need to remove first element and shift everything back by one
    //copy all elements of OG array minus the beggining
    for(std::size_t i = 1; i <= arrSize; i++)
    {
      tempPoint[i] = arrPoint[i+1]; // tempPoint holds values 2-n
    }
    //copy all back to array
    for(std::size_t a = 1; a <= arrSize; a++)
    {
      arrPoint[a] = tempPoint[a]; // array holds shifted values
    }
    //reduce size
    usedSpace--;
    //free memory
    delete [] tempPoint;
    //return
    return true;
  }
  return false;
}

template <typename T>
void ArrayList<T>::clear() {
//deallocate the memory
delete [] arrPoint;
arrPoint = new T [arrSize]; // same size array as before, but intiialized to 0
usedSpace = 0;
}

//gets an entry from the array at a specific index
template <typename T>
T ArrayList<T>::getEntry(std::size_t position) const {
  return arrPoint[position];
  //return *(arrPoint + position+ 1);
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
for(std::size_t i = 1; i <= arrSize; i++)
  {
    arrPoint2[i] = arrPoint[i];
  }

//delete old array
delete [] arrPoint;
arrSize = arrSize * 2; //update arrSize
//reassign arrPoint from arrPoint 2;
arrPoint = new T [arrSize];
for(std::size_t x = 1; x< arrSize; x++) //assign all values of point2 to arraypoint
{
  arrPoint[x] = arrPoint2[x];
}
//release arrPoint2 to avoid memory leak
delete [] arrPoint2;
}