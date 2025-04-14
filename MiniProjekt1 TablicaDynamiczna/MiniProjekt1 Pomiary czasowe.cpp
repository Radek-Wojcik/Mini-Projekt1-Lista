#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <fstream>
#include<string>
#include <vector>
#include "ArrayList.h"
#include "DoubleConnectedList.h"
#include "LinkedList.h"

using namespace std;
using namespace std::chrono;

void testArrayList();
void testSingleLinkedList();
void testDoubleLinkedList();
void TimetestArrayList();
void TimetestSingleLinkedList();
void TimetestDoubleLinkedList();
void testAllStructures();
void generateRandomFile(const string& filename, int count);

int main() {
    int choice = 0;
    int capacity;

        cout << "======== MENU TESTOWANIA ========\n";
        cout << "1. Test tablicy dynamicznej\n";
        cout << "2. Test listy jednokierunkowej\n";
        cout << "3. Test listy dwukierunkowej\n";
        cout << "4. Pomiary czasowe wszystkich struktur\n";
        cout << "5. Generowanie pliku z liczbami losowymi do testowania wydajnosci\n";
        cout << "0. Wyjscie\n";
        cout << "Wybierz opcje: ";
        cin >> choice;

        switch (choice) {
        case 1: testArrayList(); break;
        case 2: testSingleLinkedList(); break;
        case 3: testDoubleLinkedList(); break;
        case 4: testAllStructures(); break;
        case 5: {
            cout << "Podaj wielkosc generowanego pliku: ";
            cin >> capacity;
            generateRandomFile("Liczby.txt", capacity);
            break; }
        case 0: cout << "Zamykanie programu." << endl; break;
        default: cout << "Nieprawidlowa opcja." << endl; break;
        }

    return 0;
}

// ======= TEST TABLICY DYNAMICZNEJ =======
void testArrayList() {
    srand(static_cast<unsigned int>(time(nullptr)));
    ArrayList list;
    int choice;

    do {
        cout << "\n===== TEST TABLICY DYNAMICZNEJ =====\n";
        cout << "1. Zbuduj z pliku\n";
        cout << "2. Usun wybrany element\n";
        cout << "3. Dodaj element\n";
        cout << "4. Znajdz element\n";
        cout << "5. Wypelnij tablice losowo\n";
        cout << "6. Wyswietl tablice\n";
        cout << "0. Wyjdz\n";
        cout << "Twoj wybor: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            // Budowanie listy z pliku
            string filename = "Liczby.txt";
            
            ifstream file(filename);
            if (!file) {
                cout << "Blad przy otwieraniu pliku \n";
                break;
            }
            ArrayList tempList;
            int value;
            while (file >> value) {
                tempList.push_back(value);
            }
            file.close();
            list = tempList;
            cout << "Tablica zbudowana pomyslnie!\n";
            break;
        }
        case 2: {
            // Usuwanie wybranego elementu
            if (list.size() == 0) {
                cout << "Tablica jest pusta\n";
                break;
            }
            int index;
            cout << "Podaj indeks elementu do usuniecia (0 - " << list.size() - 1 << "): ";
            cin >> index;
            if (index < 0 || index >= list.size()) {
                cout << "Niepoprawny indeks\n";
                break;
            }
            list.remove(index);
            cout << "Element na indeksie " << index << " zostal usuniety\n";
            break;
        }
        case 3: {
            // Dodawanie elementu
            int value;
            cout << "Jaka wartosc dodac: ";
            cin >> value;
            cout << "Gdzie wstawic element?\n";
            cout << "1. Na poczatku\n";
            cout << "2. Na koncu\n";
            cout << "3. W losowej pozycji\n";
            cout << "Twoj wybor: ";
            int posChoice;
            cin >> posChoice;
            switch (posChoice) {
            case 1:
                list.push_front(value);
                cout << "Dodano " << value << " na poczatku\n";
                break;
            case 2:
                list.push_back(value);
                cout << "Dodano " << value << " na koncu\n";
                break;
            case 3:
                list.insert_random(value);
                cout << "Dodano " << value << " w losowej pozycji\n";
                break;
            default:
                cout << "Niepoprawny wybor \n";
            }
            break;
        }
        case 4: {
            // Wyszukiwanie elementu
            if (list.size() == 0) {
                cout << "Tablica jest pusta\n";
                break;
            }
            int value;
            cout << "Podaj wartosc do wyszukania: ";
            cin >> value;
            int index = list.find(value);
            if (index != -1)
                cout << "Wartosc " << value << " znaleziona na indeksie nr: " << index << "\n";
            else
                cout << "Wartosc " << value << " nie zostaala znaleziona\n";
            break;
        }
        case 5: {
            // Tworzenie losowej listy
            int size;
            cout << "Podaj rozmiar losowej tablicy: ";
            cin >> size;
            if (size <= 0) {
                cout << "Rozmiar musi byc dodatni \n";
                break;
            }
            ArrayList newList(size);
            for (int i = 0; i < size; i++) {
                int randomValue = rand() % 100; // wartości od 0 do 99
                newList.push_back(randomValue);
            }
            list = newList;
            cout << "Losowa tablica wygenerowana \n";
            break;
        }
        case 6: {
            // Wyświetlanie listy
            cout << "\nZawartosc tablicy:\n";
            cout << "Rozmiar: " << list.size() << " | Pojemnosc: " << list.getCapacity() << endl;
            if (list.size() == 0)
                cout << "Lista jest pusta.\n";
            else {
                cout << "Elementy: ";
                for (int i = 0; i < list.size(); i++)
                    cout << list[i] << " ";
                cout << endl;
            }
            break;
        }
        case 0:
            cout << "Wychodze...\n";
            break;
        default:
            cout << "Zly wybor \n";
        }
    } while (choice != 0);
}

// ======= TEST LISTY JEDNOKIERUNKOWEJ  =======
void testSingleLinkedList() {
    LinkedList List;
    int choice;
    do {
        cout << "\n===== TEST TABLICY DYNAMICZNEJ =====\n";
        cout << "1. Zbuduj z pliku\n";
        cout << "2. Usun wybrany element\n";
        cout << "3. Dodaj element\n";
        cout << "4. Znajdz element\n";
        cout << "5. Wypelnij tablice losowo\n";
        cout << "6. Wyswietl tablice\n";
        cout << "0. Wyjdz\n";
        cout << "Twoj wybor: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            List.build_from_file("Lista.txt");
            break;
        }
        case 2: {
            // Usuwanie wybranego elementu
            if (List.get_size() == 0) {
                cout << "Tablica jest pusta\n";
                break;
            }
            int index;
            cout << "Podaj indeks elementu do usuniecia (0 - " << List.get_size() - 1 << "): ";
            cin >> index;
            if (index < 0 || index >= List.get_size()) {
                cout << "Niepoprawny indeks\n";
                break;
            }
            List.pop_index(index);
            cout << "Element na indeksie " << index << " zostal usuniety\n";
            break;
        }
        case 3: {
            // Dodawanie elementu
            int value;
            cout << "Jaka wartosc dodac: ";
            cin >> value;
            cout << "Gdzie wstawic element?\n";
            cout << "1. Na poczatku\n";
            cout << "2. Na koncu\n";
            cout << "3. W wybranej pozycji\n";
            cout << "Twoj wybor: ";
            int posChoice;
            int index;
            cin >> posChoice;
            switch (posChoice) {
            case 1:
                List.push_front(value);
                cout << "Dodano " << value << " na poczatku\n";
                break;
            case 2:
                List.push_back(value);
                cout << "Dodano " << value << " na koncu\n";
                break;
            case 3:
                cout << "Podaj index na ktorym chcesz umiescic element: ";
                cin >> index;
                List.push_index(value, index);
                cout << "Dodano " << value << " na indeksie: "<<index<<endl;
                break;
            default:
                cout << "Niepoprawny wybor \n";
            }
            break;
        }
        case 4: {
            // Wyszukiwanie elementu
            if (List.get_size() == 0) {
                cout << "Tablica jest pusta\n";
                break;
            }
            int value;
            cout << "Podaj wartosc do wyszukania: ";
            cin >> value;
            vector<int> indices = List.search(value);
            std::cout << "Indices: [";
            for (size_t i = 0; i < indices.size(); i++) {
                std::cout << indices[i];
                if (i < indices.size() - 1) {
                    std::cout << ", ";
                }
            }
            std::cout << "]" << std::endl;
            break;
        }
        case 5: {
            // Tworzenie losowej listy
            int size, min, max;
            cout << "Podaj rozmiar losowej tablicy: ";
            cin >> size;
            if (size <= 0) {
                cout << "Rozmiar musi byc dodatni \n";
                break;
            }
            cout << "Podaj minimalna wartosc zakresu: ";
            cin >> min;
            cout << "Podaj maksymalna wartosc zakresu: ";
            cin >> max;
            List.generate_random(size, min, max);
            cout << "Losowa tablica wygenerowana \n";
            break;
        }
        case 6: {
            // Wyświetlanie listy
            cout << "\nZawartosc tablicy:\n";
            cout << "Rozmiar: " << List.get_size() << endl;
            if (List.get_size() == 0)
                cout << "Lista jest pusta.\n";
            else {
                cout << "Elementy: ";
                List.show();
            }
            break;
        }
        case 0:
            cout << "Wychodze...\n";
            break;
        default:
            cout << "Zly wybor \n";
        }
    } while (choice != 0);
}

// ======= TEST LISTY DWUKIERUNKOWEJ  =======
void testDoubleLinkedList() {
    DoubleConnectedList List;
    int choice;
    do {
        cout << "\n===== TEST TABLICY DYNAMICZNEJ =====\n";
        cout << "1. Zbuduj z pliku\n";
        cout << "2. Usun wybrany element\n";
        cout << "3. Dodaj element\n";
        cout << "4. Znajdz element\n";
        cout << "5. Wypelnij tablice losowo\n";
        cout << "6. Wyswietl tablice\n";
        cout << "7. Wyswietl tablice w odwrotnej kolejnosci\n";
        cout << "0. Wyjdz\n";
        cout << "Twoj wybor: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            List.build_from_file("Lista.txt");
            break;
        }
        case 2: {
            // Usuwanie wybranego elementu
            if (List.get_size() == 0) {
                cout << "Tablica jest pusta\n";
                break;
            }
            int index;
            cout << "Podaj indeks elementu do usuniecia (0 - " << List.get_size() - 1 << "): ";
            cin >> index;
            if (index < 0 || index >= List.get_size()) {
                cout << "Niepoprawny indeks\n";
                break;
            }
            List.pop_index(index);
            cout << "Element na indeksie " << index << " zostal usuniety\n";
            break;
        }
        case 3: {
            // Dodawanie elementu
            int value;
            cout << "Jaka wartosc dodac: ";
            cin >> value;
            cout << "Gdzie wstawic element?\n";
            cout << "1. Na poczatku\n";
            cout << "2. Na koncu\n";
            cout << "3. W wybranej pozycji\n";
            cout << "Twoj wybor: ";
            int posChoice;
            int index;
            cin >> posChoice;
            switch (posChoice) {
            case 1:
                List.push_front(value);
                cout << "Dodano " << value << " na poczatku\n";
                break;
            case 2:
                List.push_back(value);
                cout << "Dodano " << value << " na koncu\n";
                break;
            case 3:
                cout << "Podaj index na ktorym chcesz umiescic element: ";
                cin >> index;
                List.push_index(value, index);
                cout << "Dodano " << value << " na indeksie: " << index << endl;
                break;
            default:
                cout << "Niepoprawny wybor \n";
            }
            break;
        }
        case 4: {
            // Wyszukiwanie elementu
            if (List.get_size() == 0) {
                cout << "Tablica jest pusta\n";
                break;
            }
            int value;
            cout << "Podaj wartosc do wyszukania: ";
            cin >> value;
            vector<int> indices = List.search(value);
            std::cout << "Indices: [";
            for (size_t i = 0; i < indices.size(); i++) {
                std::cout << indices[i];
                if (i < indices.size() - 1) {
                    std::cout << ", ";
                }
            }
            std::cout << "]" << std::endl;
            break;
        }
        case 5: {
            // Tworzenie losowej listy
            int size, min, max;
            cout << "Podaj rozmiar losowej tablicy: ";
            cin >> size;
            if (size <= 0) {
                cout << "Rozmiar musi byc dodatni \n";
                break;
            }
            cout << "Podaj minimalna wartosc zakresu: ";
            cin >> min;
            cout << "Podaj maksymalna wartosc zakresu: ";
            cin >> max;
            List.generate_random(size, min, max);
            cout << "Losowa tablica wygenerowana \n";
            break;
        }
        case 6: {
            // Wyświetlanie listy
            cout << "\nZawartosc tablicy:\n";
            cout << "Rozmiar: " << List.get_size() << endl;
            if (List.get_size() == 0)
                cout << "Lista jest pusta.\n";
            else {
                cout << "Elementy: ";
                List.show();
            }
            break;
        }
        case 7: {
            // Wyswietlanie listy w odwrotnej kolejnosci
            cout << "\nZawartosc tablicy:\n";
            cout << "Rozmiar: " << List.get_size() << endl;
            if (List.get_size() == 0)
                cout << "Lista jest pusta.\n";
            else {
                cout << "Elementy: ";
                List.show_reverse();
            }
            break;
        }
        case 0:
            cout << "Wychodze...\n";
            break;
        default:
            cout << "Zly wybor \n";
        }
    } while (choice != 0);
}


// ======= TEST CZASOWY TABLICY DYNAMICZNEJ =======
void TimetestArrayList() {
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

// ======= TEST CZASOWY LISTY JEDNOKIERUNKOWEJ  =======
void TimetestSingleLinkedList() {
    // TODO
}

// ======= TEST CZASOWY LISTY DWUKIERUNKOWEJ  =======
void TimetestDoubleLinkedList() {
    // TODO
}

// ======= TEST WSZYSTKICH STRUKTUR PO KOLEI =======
void testAllStructures() {
    cout << "=== Test tablicy dynamicznej ===" << endl;
    TimetestArrayList();
    cout << "\n=== Test listy jednokierunkowej ===" << endl;
    TimetestSingleLinkedList();
    cout << "\n=== Test listy dwukierunkowej ===" << endl;
    TimetestDoubleLinkedList();
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