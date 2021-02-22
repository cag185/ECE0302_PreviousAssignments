#include "bag.hpp"
                                                                                                  

template <typename T> Bag<T>::Bag() 
{
    bagSize = 0;
    maxSize = 64;
}

template <typename T> Bag<T>::~Bag() 
{}

template <typename T> std::size_t Bag<T>::getCurrentSize() const 
{ 
    return bagSize; 
}

template <typename T> bool Bag<T>::isEmpty() const 
{ 
    if((int)bagSize == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename T> bool Bag<T>::add(const T& entry) 
{ if(bagSize < maxSize)
{
   bag1.push_back(entry);
   bagSize++;
   return true;
}
else
{
    return false;
}
}

template <typename T> bool Bag<T>::remove(const T& entry) 
{ 
    int pos = 0;
    int sizeBefore = 0;
    int sizeAfter = 0;

    sizeBefore = bag1.size() ;
    for (int i = 0; i <(int)bagSize;i++)
    {
        if(bag1.at(i) == entry)
        {
            pos = i;
            //erase the value at pos
            bag1.erase(bag1.begin()+pos);
            //check for size of vec
            sizeAfter = bag1.size();
            //check for removal
            if(sizeAfter < sizeBefore)
            {
                return true;
            }
            else
            {
                return false;
            }
            
        }
    }
}

template <typename T> void Bag<T>::clear() 
{
    bagSize = 0;
}

template <typename T> std::size_t Bag<T>::getFrequencyOf(const T& entry) const 
{ //check how many times a entry shows in the bag
int count = 0;
    for (int i = 0; i <(int)bagSize; i++)
    {
        if (bag1.at(i)==entry)
        {
            count ++;
        }
    }
    std::size_t count1 = count;
    return count1;
}

template <typename T> bool Bag<T>::contains(const T& entry) const 
{ 
    //check if bag contains the element
    int count = 0;
    for(int i = 0; i<maxSize; i++)
    {
        if(bag1.at(i) == entry)
        {
            return true;
        }

        else if(bag1.at(maxSize-1) != entry)
        {
            return false;
        }
    }
}

