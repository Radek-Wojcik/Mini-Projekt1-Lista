#include <iostream>
#include <cstdlib>
#include <ctime>
#include "ArrayList.h"

using namespace std;

//Test
int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    ArrayList list(5);
    for (int i = 0; i < 10000; ++i) {
        list.insert_random(i);;
        cout << "Rozmiar: " << list.size() << "|| Pojemnosc: " << list.getCapacity() << endl;
    }
    cout << "Zawartosc tablicy: ";
    for (int i = 0; i < list.size(); ++i) {
        cout << list[i] << " ";
    }
    cout << endl;
    return 0;
}