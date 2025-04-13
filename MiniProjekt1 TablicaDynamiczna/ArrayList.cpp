#include <iostream>
#include <cstdlib>
#include <ctime>

#include "ArrayList.h"

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

// Konstruktor do budowy pliku 
ArrayList::ArrayList(const ArrayList& other)
    : capacity(other.capacity), length(other.length)
{
    array = new int[capacity];
    for (int i = 0; i < length; i++) {
        array[i] = other.array[i];
    }
}

// Operator przypisania 
ArrayList& ArrayList::operator=(const ArrayList& other) {
    if (this != &other) { 
        delete[] array;                                 // Usuñ star¹ tablicê 

        capacity = other.capacity;
        length = other.length;
        array = new int[capacity];

        for (int i = 0; i < length; i++) {
            array[i] = other.array[i];
        }
    }
    return *this;
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
    
    for (int i = length; i > 0; --i) {                  // Przesuwamy wszystkie elementy o jeden indeks do przodu
        array[i] = array[i - 1];
    }
    array[0] = value;                                   // Wstawiamy nowy element na pocz¹tek
    ++length;                                           // Zwiêkszamy licznik elementów
}

// Metoda dodaj¹ca element w losowe miejsce tablicy
void ArrayList::insert_random(const int& value) {
    if (length == capacity) {                          // Sprawdzenie pojemnoœci
        resize();
    }

    int index = rand() % (length + 1);                 // Losowy index

    for (int i = length; i > index; --i) {             // Przesuniêcie elementów w górê aby zrobiæ miejsce na nowy 
        array[i] = array[i - 1];
    }
    array[index] = value;                              // Wstaw nowy element na losowej pozycji
    ++length;
}

// Metoda do usuwania elementu o podanym indeksie
void ArrayList::remove(int index) {
    if (index < 0 || index >= length) {
        cerr << "Indeks poza zakresem!" << endl;
        return;
    }

    for (int i = index; i < length - 1; ++i) {         // Przesuniêcie elementów w dó³, aby nadpisaæ usuwany element
        array[i] = array[i + 1];
    }

    --length;                                          // Zmniejszenie licznika elementów
}

// Metoda do wyszukiwania elementu
int ArrayList::find(int value) const {
    for (int i = 0; i < length; ++i) {
        if (array[i] == value) {
            return i;                                   // Zwraca indeks znalezionego elementu
        }
    }
    return -1; 
}

// Zabezpieczenie przed odow³aniem do elementu spoza zakresu
int& ArrayList::operator[](int index) const {             
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

