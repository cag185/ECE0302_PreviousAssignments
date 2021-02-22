#include "bag.hpp"
#include <iostream>

// empty implementation   
//variables           
int size = 0;                                                                                        
int MAXSIZE = 64; 
template <typename T> Bag<T>::Bag() 
{
    size = 0;
}

template <typename T> Bag<T>::~Bag() 
{

}

template <typename T> std::size_t Bag<T>::getCurrentSize() const 
{ 
    return size; 
    }

template <typename T> bool Bag<T>::isEmpty() const 
{ 
    if(size == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
    
    }

template <typename T> bool Bag<T>::add(const T& entry) 
{ 
    if(size >= MAXSIZE)
    {
        return false; 
    }
    else
    {
    
    size++;
    return true;
    }
}

template <typename T> bool Bag<T>::remove(const T& entry) 
{ 
    if(size <= 0)
    {
    return false; 
    }
    else
    {
        size--;
        return true;
    }
    

template <typename T> void Bag<T>::clear() 
{
    size = 0;
}

template <typename T> std::size_t Bag<T>::getFrequencyOf(const T& entry) const 
{ 
    return 0; 
    }

template <typename T> bool Bag<T>::contains(const T& entry) const 
{ 
    return false; 
    }

