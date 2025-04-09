#include "ArrayList.h"

ArrayList::ArrayList(int initCapacity)
    : capacity(initCapacity), length(0)                
{
    array = new int[capacity];                         
}

ArrayList::~ArrayList() {
    delete[] array;                                    
}

void ArrayList::resize() {
    capacity *= 2;
    int* newArray = new int[capacity];
    for (int i = 0; i < length; ++i) {
        newArray[i] = array[i];
    }
    delete[] array;
    array = newArray;
}

void ArrayList::push_back(const int& value) {           
    if (length == capacity) {
        resize();
    }
    array[length++] = value;
}