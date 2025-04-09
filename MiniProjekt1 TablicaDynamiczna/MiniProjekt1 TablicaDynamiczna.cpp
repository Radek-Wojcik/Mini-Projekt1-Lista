#include <iostream>
#include "ArrayList.h"

using namespace std;

int main() {
    ArrayList list(5);
    for (int i = 0; i < 10000; ++i) {
        list.push_back(i);
        cout << "Rozmiar: " << list.size() << "|| Pojemnosc: " << list.getCapacity() << endl;
    }
    cout << "Zawartosc tablicy: ";
    for (int i = 0; i < list.size(); ++i) {
        cout << list[i] << " ";
    }
    cout << endl;
    return 0;
}