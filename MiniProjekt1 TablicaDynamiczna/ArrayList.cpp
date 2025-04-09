#include "ArrayList.h"
#include <iostream>
#include <cstdlib>

using namespace std;

// Konstruktor
ArrayList::ArrayList(int initCapacity)
    : capacity(initCapacity), length(0)                
{
    array = new int[capacity];                         
}

// Destruktor
ArrayList::~ArrayList() {
    delete[] array;                                    
}

// Metoda powi�kszaj�ca tablice
void ArrayList::resize() {
    capacity *= 2;                                      // Podwojenie pojemno�ci
    int* newArray = new int[capacity];                  // Nowa tablica o zwi�kszonej pojemno�ci
    
    for (int i = 0; i < length; ++i) {                  // Kopiowanie element�w do nowej tablicy
        newArray[i] = array[i];
    }
    delete[] array;
    array = newArray;
}

// Metoda dodaj�ca element
void ArrayList::push_back(const int& value) {           
    if (length == capacity) {                           // Sprawdzenie, czy tablica jest pe�na
        resize();
    }
    array[length++] = value;                            // Dodanie elementu i zwi�kszenie licznika
}

// Zabezpieczenie przed odow�aniem do elementu spoza zakresu
int& ArrayList::operator[](int index) {             
    if (index < 0 || index >= length) {                 // Sprawdzenie, czy indeks mie�ci si� w zakresie
        cerr << "Indeks poza zakresem!" << endl;        // B��d krytyczny, zako�czenie progrsamu
        exit(EXIT_FAILURE); 
    }
    return array[index];
}

int ArrayList::size() const {                           // Metoda zwracaj�ca liczb� dodanych element�w
    return length;
}

int ArrayList::getCapacity() const {                    // Metoda zwracaj�ca aktualn� pojemno�� tablicy
    return capacity;
}