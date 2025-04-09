#include "ArrayList.h"
#include <iostream>
#include <cstdlib>

using namespace std;

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

int& ArrayList::operator[](int index) {        
    if (index < 0 || index >= length) {
        cerr << "Indeks poza zakresem!" << endl;
        exit(EXIT_FAILURE);
    }
    return array[index];
}

int ArrayList::size() const {                  
    return length;
}

int ArrayList::getCapacity() const {           
    return capacity;
}