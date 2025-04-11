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

// Metoda powiêkszaj¹ca tablice
void ArrayList::resize() {
    capacity *= 2;                                      // Podwojenie pojemnoœci
    int* newArray = new int[capacity];                  // Nowa tablica o zwiêkszonej pojemnoœci
    
    for (int i = 0; i < length; ++i) {                  // Kopiowanie elementów do nowej tablicy
        newArray[i] = array[i];
    }
    delete[] array;
    array = newArray;
}

// Metoda dodaj¹ca element na koniec
void ArrayList::push_back(const int& value) {           
    if (length == capacity) {                           // Sprawdzenie, czy tablica jest pe³na
        resize();
    }
    array[length++] = value;                            // Dodanie elementu i zwiêkszenie licznika
}

// Metoda dodaj¹ca element na pocz¹tek
void ArrayList::push_front(const int& value) {
    if (length == capacity) {                           // Je¿eli tablica jest pe³na, zwiêkszamy pojemnoœæ
        resize();
    }
    // Przesuwamy wszystkie elementy o jeden indeks do przodu
    for (int i = length; i > 0; --i) {
        array[i] = array[i - 1];
    }
    array[0] = value;                                  // Wstawiamy nowy element na pocz¹tek
    ++length;                                          // Zwiêkszamy licznik elementów
}

// Zabezpieczenie przed odow³aniem do elementu spoza zakresu
int& ArrayList::operator[](int index) {             
    if (index < 0 || index >= length) {                 // Sprawdzenie, czy indeks mieœci siê w zakresie
        cerr << "Indeks poza zakresem!" << endl;        // B³¹d krytyczny, zakoñczenie progrsamu
        exit(EXIT_FAILURE); 
    }
    return array[index];
}

int ArrayList::size() const {                           // Metoda zwracaj¹ca liczbê dodanych elementów
    return length;
}

int ArrayList::getCapacity() const {                    // Metoda zwracaj¹ca aktualn¹ pojemnoœæ tablicy
    return capacity;
}