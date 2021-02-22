#include "limited_size_bag.hpp"

template<typename T>
LimitedSizeBag<T>::LimitedSizeBag() {
   //intialize the bag size to 0
  bagSize = 0; 
}

template<typename T>
LimitedSizeBag<T>::LimitedSizeBag(const LimitedSizeBag& x){
//Copies a second Bag with all of its contents
//get the bag size
bagSize = x.getCurrentSize();
//copy each node from the second bag to the new one
Node * a = x.head;
while (a != NULL)
{
  //loop through and copy contents of x into node using add
  add(a->data);
  //move to next node
  a = a->next;
}
}

//destructor
template<typename T>
LimitedSizeBag<T>::~LimitedSizeBag(){
  //call clear
  clear();
}

//copies a bag into an existing bag and changes size
template<typename T>
LimitedSizeBag<T>& LimitedSizeBag<T>::operator=(LimitedSizeBag<T>& x)
{  
  Node * alpha = x.head;
  while (alpha != NULL)
  {
    //loop through and copy
    this->add(alpha->data);
    //move to next node
    alpha = alpha->next;
  }
  return *this;
}

template<typename T>
bool LimitedSizeBag<T>::add(const T& item)
{
  if(bagSize ==maxSize)
  {
    return false;
  }
  //create a temp node
  Node *temp = new Node;
  //assign the value of data to be item
  temp->data = item;
  //point the next pointer to null. States that this is the last entry until 'add' is ran again
  temp->next = NULL;

  //check to see if the head is null (first entry)
  if(head == NULL)
  {
    //both head and tail are assigned to temp
    head = temp;
    tail = temp;
    temp = NULL; // nothing is in temp -- might need to comment this out
    //increase bag size to 1
    bagSize = 1;
  }
  else
  {
    tail-> next = temp; // assign the next pointer to the next temporary 
    tail = temp;
    //increase bagsize
    bagSize++;
  }
  return true; //only way to return false is if computer has no more memory to make nodes
  
}

template<typename T>
bool LimitedSizeBag<T>::remove(const T& item)
{
  //need to make sure item is contained in linked list
  if(contains(item)== false)
  {
    return false;
  }
  else
  {
    //run through the linked list
    //reassign previous node to = post node, skipping entry we want to delete
    //assign a new node to the head
    Node *priorNode = head;
    Node *postNode  = head->next;
    //check if the prior node data == item
    if(priorNode->data == item)
    {
      if(getCurrentSize() == 1)
      {
        //delete all nodes
        head = NULL;
        tail = NULL;
        bagSize = 0;
        return true;
      }
      else{
        //increase all nodes
        priorNode = priorNode->next;
        postNode = postNode ->next;
        head= priorNode; // moves head along one, removes first value
        bagSize --;
        return true;
      }
    }

    while(postNode->data != NULL)
    {
      if(postNode->data == item)
      {
          if(postNode->next == NULL) // at the end of the linked list
          {
            tail = priorNode; // elimimates the last link
            bagSize--;
            return true;
          }
        postNode = postNode->next; //creates a gap
        priorNode->next = postNode;
        //now priorNode and postNode are connected skipping the gap
        bagSize--;
        return true;
      }
      else{
        //increase both pointers
        postNode = postNode->next;
        priorNode = priorNode->next;
      }
    }
  }
  return true;
}
template<typename T>
bool LimitedSizeBag<T>::isEmpty() const
{
  //check to see if bag size is empty or not
  if(getCurrentSize() == 0)
  {
    return true;
  }
  else
    return false;
}

template<typename T>
std::size_t LimitedSizeBag<T>::getCurrentSize() const
{
  return bagSize;
}

template<typename T>
bool LimitedSizeBag<T>::contains(const T& item) const
{  //go to head of linked list, follow the path to the tail and stop 
//when the contents of the node == the item
//create a new node
Node * search;
search = head; //sets the address at search = head
while(search != NULL) // while search hasnt gotten to tail
{
  if(search -> data == item)
    return true;
  else
    search= search->next; 
}
  return false;
}

template<typename T>
void LimitedSizeBag<T>::clear(){
//remove all nodes from the bag
Node *clear = head;
//remove all contents
head = NULL;
tail = NULL;
bagSize = 0;
}

template<typename T>
std::size_t LimitedSizeBag<T>::getFrequencyOf(const T & item) const
{
   //count how many nodes have the item being searched for
  //create node
  Node * search = head;
  //create counting variable
  std::size_t counter = 0;
  while(search != NULL)
  {
    //search for contents
    if(search->data == item)
    {
      counter++;
    }
    search = search->next;
    
  }
  return counter;
};
