#include "ArrayList.h"

ArrayList::ArrayList(int initCapacity)
    : capacity(initCapacity), length(0)                
{
    array = new int[capacity];                         
}

ArrayList::~ArrayList() {
    delete[] array;                                    
}