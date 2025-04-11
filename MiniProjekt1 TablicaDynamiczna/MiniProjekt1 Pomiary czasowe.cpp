#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <fstream>
#include <vector>
#include "ArrayList.h"

using namespace std;
using namespace std::chrono;

void testArrayList();
void testSingleLinkedList();
void testDoubleLinkedList();
void testAllStructures();
void generateRandomFile(const string& filename, int count);

int main() {
    int choice = 0;

        cout << "======== MENU TESTOWANIA ========\n";
        cout << "1. Test tablicy dynamicznej\n";
        cout << "2. Test listy jednokierunkowej\n";
        cout << "3. Test listy dwukierunkowej\n";
        cout << "4. Test wszystkich struktur\n";
        cout << "5. Generowanie pliku z liczbami losowymi\n";
        cout << "0. Wyjscie\n";
        cout << "Wybierz opcje: ";
        cin >> choice;

        switch (choice) {
        case 1: testArrayList(); break;
        case 2: testSingleLinkedList(); break;
        case 3: testDoubleLinkedList(); break;
        case 4: testAllStructures(); break;
        case 5: generateRandomFile("Liczby.txt", 1000000); break;
        case 0: cout << "Zamykanie programu." << endl; break;
        default: cout << "Nieprawidlowa opcja." << endl; break;
        }

    return 0;
}

// ======= TEST TABLICY DYNAMICZNEJ =======
void testArrayList() {
    int iterations = 10;

    // Wczytanie danych z pliku "Liczby.txt"
    ifstream file("Liczby.txt");
    if (!file) {
        cerr << "Nie mozna otworzyc pliku Liczby.txt!" << endl;
        return;
    }
    vector<int> dane;
    int liczba;
    while (file >> liczba) {
        dane.push_back(liczba);
    }
    file.close();

    long  SumPushFront = 0;
    long  SumPushBack = 0;
    long  SumInsertRandom = 0;

    for (int i = 0; i < iterations; ++i) {
        
        // --- Test push_front ---
        ArrayList listaPushFront(dane.size());      // Stworzenie kopii struktury ArrayList z danymi
        for (size_t j = 0; j < dane.size(); ++j) {
            listaPushFront.push_back(dane[j]);
        }
        auto start = high_resolution_clock::now();  // Mierzenie czasu
        listaPushFront.push_front(1);  
        auto stop = high_resolution_clock::now();
        SumPushFront += duration_cast<microseconds>(stop - start).count();

        // --- Test push_back ---
        ArrayList listaPushBack(dane.size());
        for (size_t j = 0; j < dane.size(); ++j) {
            listaPushBack.push_back(dane[j]);
        }
        start = high_resolution_clock::now();
        listaPushBack.push_back(1);  
        stop = high_resolution_clock::now();
        SumPushBack += duration_cast<microseconds>(stop - start).count();

        // --- Test insert_random ---
        ArrayList listaInsertRandom(dane.size());
        for (size_t j = 0; j < dane.size(); ++j) {
            listaInsertRandom.push_back(dane[j]);
        }
        start = high_resolution_clock::now();
        listaInsertRandom.insert_random(1);  
        stop = high_resolution_clock::now();
        SumInsertRandom += duration_cast<microseconds>(stop - start).count();
    }

    // Obliczenie i wyświetlenie średnich czasów wykonania dla poszczególnych operacji
    cout << "Sredni czas push_front: " << SumPushFront / iterations << " mikrosekund" << endl;
    cout << "Sredni czas push_back: " << SumPushBack / iterations << " mikrosekund" << endl;
    cout << "Sredni czas insert_random: " << SumInsertRandom / iterations << " mikrosekund" << endl;
}

// ======= TEST LISTY JEDNOKIERUNKOWEJ  =======
void testSingleLinkedList() {
    // TODO
}

// ======= TEST LISTY DWUKIERUNKOWEJ  =======
void testDoubleLinkedList() {
    // TODO
}

// ======= TEST WSZYSTKICH STRUKTUR PO KOLEI =======
void testAllStructures() {
    cout << "=== Test tablicy dynamicznej ===" << endl;
    testArrayList();
    cout << "\n=== Test listy jednokierunkowej ===" << endl;
    testSingleLinkedList();
    cout << "\n=== Test listy dwukierunkowej ===" << endl;
    testDoubleLinkedList();
}

// ======= GENEROWANIE PLIKU Z LOSOWYMI LICZBAMI =======
void generateRandomFile(const string& filename, int count) {
    ofstream file(filename);
    if (!file) {
        cerr << "Nie można otworzyć pliku!" << endl;
        return;
    }

    srand(time(nullptr)); // Inicjalizacja generatora

    for (int i = 0; i < count; ++i) {
        int num = ((rand() & 0x7FFF) << 15) | (rand() & 0x7FFF); // Generowanie liczb z pełnego zakresu int
        file << num << "\n";
    }

    file.close();
    cout << "Wygenerowano plik " << filename << " z " << count << " liczbami losowymi." << endl;
}