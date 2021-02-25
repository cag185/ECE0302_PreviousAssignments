#include "linked_list.hpp"

template <typename T>
LinkedList<T>::LinkedList()
{
  //initialize head pointer
  head = NULL;

  //initialize length variable
  listLength = 0;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
  //free all memory allocated
 
}

//copy constructor
template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& x)
{
  //TODO
}

//swap values
template <typename T>
void LinkedList<T>::swap(LinkedList<T>& x, LinkedList<T>& y)
{
  //TODO
}

//copy assignment
template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& x)
{
  //TODO
  return *this;
}

//check to see if the list is empty
template <typename T>
bool LinkedList<T>::isEmpty() const
{
  //check if the head pointer is null
  if(head == NULL)
  {
    return true;
  }
  return false;
}

//return the length of the list
template <typename T>
std::size_t LinkedList<T>::getLength() const
{
  //listLength
  return listLength;
}

//insert a value and shift list
template <typename T>
bool LinkedList<T>::insert(std::size_t position, const T& item)
{
  ///Cases for insertion
    //1. insert at the beginning (index 1)
    //2. insert in the middle
    //3. insert at the end

    //create a temp node
    Node <T>* newNodePtr = new Node<T>;

    //case 1
    if(position == 1)
    {
      //set value
      newNodePtr->setItem(item);
      //set next
      newNodePtr->setNext(head);
      //replace head with newNodePtr so that the pointer is the start and the head becomes the tail, which is null
      head = newNodePtr;
      //increase size
      listLength++;
      //return
      return true;
    }
  return false;
}

//remove a value and shift list
template <typename T>
bool LinkedList<T>::remove(std::size_t position)
{
  //TODO
  return true;
}

//clear all data from the list
template <typename T>
void LinkedList<T>::clear()
{
  //TODO
}

//get a specific entry -- works
template <typename T>
T LinkedList<T>::getEntry(std::size_t position) const
{
  //create temp pointer
  Node<T>* newNodePointer = new Node<T>;
  newNodePointer = head;
  //create a loop that starts at head and for Position times, returns the value of data
  for(std::size_t i = 1; i < position; i++ )
  {
    newNodePointer = newNodePointer->getNext();
  }
  //return the value at index postion
  return newNodePointer->getItem();
}

//set a specific position to a value
template <typename T>
void LinkedList<T>::setEntry(std::size_t position, const T& newValue)
{
  //TODO
}
