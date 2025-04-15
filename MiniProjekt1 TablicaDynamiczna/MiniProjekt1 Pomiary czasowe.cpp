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

        std::cout << "======== MENU TESTOWANIA ========\n";
        std::cout << "1. Test tablicy dynamicznej\n";
        std::cout << "2. Test listy jednokierunkowej\n";
        std::cout << "3. Test listy dwukierunkowej\n";
        std::cout << "4. Pomiary czasowe wszystkich struktur\n";
        std::cout << "5. Generowanie pliku z liczbami losowymi do testowania wydajnosci\n";
        std::cout << "0. Wyjscie\n";
        std::cout << "Wybierz opcje: ";
        cin >> choice;

        switch (choice) {
        case 1: testArrayList(); break;
        case 2: testSingleLinkedList(); break;
        case 3: testDoubleLinkedList(); break;
        case 4: testAllStructures(); break;
        case 5: {
            std::cout << "Podaj wielkosc generowanego pliku: ";
            cin >> capacity;
            generateRandomFile("Liczby.txt", capacity);
            break; }
        case 0: std::cout << "Zamykanie programu." << endl; break;
        default: std::cout << "Nieprawidlowa opcja." << endl; break;
        }

    return 0;
}

// ======= TEST TABLICY DYNAMICZNEJ =======
void testArrayList() {
    srand(static_cast<unsigned int>(time(nullptr)));
    ArrayList list;
    int choice;

    do {
        std::cout << "\n===== TEST TABLICY DYNAMICZNEJ =====\n";
        std::cout << "1. Zbuduj z pliku\n";
        std::cout << "2. Usun wybrany element\n";
        std::cout << "3. Dodaj element\n";
        std::cout << "4. Znajdz element\n";
        std::cout << "5. Wypelnij tablice losowo\n";
        std::cout << "6. Wyswietl tablice\n";
        std::cout << "0. Wyjdz\n";
        std::cout << "Twoj wybor: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            // Budowanie listy z pliku
            string filename = "Liczby.txt";
            
            ifstream file(filename);
            if (!file) {
                std::cout << "Blad przy otwieraniu pliku \n";
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
                std::cout << "Tablica jest pusta\n";
                break;
            }
            int index;
            std::cout << "Podaj indeks elementu do usuniecia (0 - " << list.size() - 1 << "): ";
            cin >> index;
            if (index < 0 || index >= list.size()) {
                std::cout << "Niepoprawny indeks\n";
                break;
            }
            list.remove(index);
            std::cout << "Element na indeksie " << index << " zostal usuniety\n";
            break;
        }
        case 3: {
            // Dodawanie elementu
            int value;
            std::cout << "Jaka wartosc dodac: ";
            cin >> value;
            std::cout << "Gdzie wstawic element?\n";
            std::cout << "1. Na poczatku\n";
            std::cout << "2. Na koncu\n";
            std::cout << "3. W wybranej pozycji\n";
            std::cout << "Twoj wybor: ";
            int posChoice;
            cin >> posChoice;
            switch (posChoice) {
            case 1:
                list.push_front(value);
                std::cout << "Dodano " << value << " na poczatku\n";
                break;
            case 2:
                list.push_back(value);
                std::cout << "Dodano " << value << " na koncu\n";
                break;
            case 3:
                int num;
                std::cout << "Podaj index: ";
                std::cin >> num;
                list.insert_random(value, num);
                std::cout << "Dodano " << value << " w pozycji: "<<num<<std::endl;
                break;
            default:
                std::cout << "Niepoprawny wybor \n";
            }
            break;
        }
        case 4: {
            // Wyszukiwanie elementu
            if (list.size() == 0) {
                std::cout << "Tablica jest pusta\n";
                break;
            }
            int value;
            std::cout << "Podaj wartosc do wyszukania: ";
            cin >> value;
            int index = list.find(value);
            if (index != -1)
                std::cout << "Wartosc " << value << " znaleziona na indeksie nr: " << index << "\n";
            else
                std::cout << "Wartosc " << value << " nie zostaala znaleziona\n";
            break;
        }
        case 5: {
            // Tworzenie losowej listy
            int size;
            std::cout << "Podaj rozmiar losowej tablicy: ";
            cin >> size;
            if (size <= 0) {
                std::cout << "Rozmiar musi byc dodatni \n";
                break;
            }
            ArrayList newList(size);
            for (int i = 0; i < size; i++) {
                int randomValue = rand() % 100; // wartości od 0 do 99
                newList.push_back(randomValue);
            }
            list = newList;
            std::cout << "Losowa tablica wygenerowana \n";
            break;
        }
        case 6: {
            // Wyświetlanie listy
            std::cout << "\nZawartosc tablicy:\n";
            std::cout << "Rozmiar: " << list.size() << " | Pojemnosc: " << list.getCapacity() << endl;
            if (list.size() == 0)
                std::cout << "Lista jest pusta.\n";
            else {
                std::cout << "Elementy: ";
                for (int i = 0; i < list.size(); i++)
                    std::cout << list[i] << " ";
                std::cout << endl;
            }
            break;
        }
        case 0:
            std::cout << "Wychodze...\n";
            break;
        default:
            std::cout << "Zly wybor \n";
        }
    } while (choice != 0);
}

// ======= TEST LISTY JEDNOKIERUNKOWEJ  =======
void testSingleLinkedList() {
    LinkedList List;
    int choice;
    do {
        std::cout << "\n===== TEST TABLICY DYNAMICZNEJ =====\n";
        std::cout << "1. Zbuduj z pliku\n";
        std::cout << "2. Usun wybrany element\n";
        std::cout << "3. Dodaj element\n";
        std::cout << "4. Znajdz element\n";
        std::cout << "5. Wypelnij tablice losowo\n";
        std::cout << "6. Wyswietl tablice\n";
        std::cout << "0. Wyjdz\n";
        std::cout << "Twoj wybor: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            List.build_from_file("Lista.txt");
            break;
        }
        case 2: {
            // Usuwanie wybranego elementu
            if (List.get_size() == 0) {
                std::cout << "Tablica jest pusta\n";
                break;
            }
            int index;
            std::cout << "Podaj indeks elementu do usuniecia (0 - " << List.get_size() - 1 << "): ";
            cin >> index;
            if (index < 0 || index >= List.get_size()) {
                std::cout << "Niepoprawny indeks\n";
                break;
            }
            List.pop_index(index);
            std::cout << "Element na indeksie " << index << " zostal usuniety\n";
            break;
        }
        case 3: {
            // Dodawanie elementu
            int value;
            std::cout << "Jaka wartosc dodac: ";
            cin >> value;
            std::cout << "Gdzie wstawic element?\n";
            std::cout << "1. Na poczatku\n";
            std::cout << "2. Na koncu\n";
            std::cout << "3. W wybranej pozycji\n";
            std::cout << "Twoj wybor: ";
            int posChoice;
            int index;
            cin >> posChoice;
            switch (posChoice) {
            case 1:
                List.push_front(value);
                std::cout << "Dodano " << value << " na poczatku\n";
                break;
            case 2:
                List.push_back(value);
                std::cout << "Dodano " << value << " na koncu\n";
                break;
            case 3:
                std::cout << "Podaj index na ktorym chcesz umiescic element: ";
                cin >> index;
                List.push_index(value, index);
                std::cout << "Dodano " << value << " na indeksie: "<<index<<endl;
                break;
            default:
                std::cout << "Niepoprawny wybor \n";
            }
            break;
        }
        case 4: {
            // Wyszukiwanie elementu
            if (List.get_size() == 0) {
                std::cout << "Tablica jest pusta\n";
                break;
            }
            int value;
            std::cout << "Podaj wartosc do wyszukania: ";
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
            std::cout << "Podaj rozmiar losowej tablicy: ";
            cin >> size;
            if (size <= 0) {
                std::cout << "Rozmiar musi byc dodatni \n";
                break;
            }
            std::cout << "Podaj minimalna wartosc zakresu: ";
            cin >> min;
            std::cout << "Podaj maksymalna wartosc zakresu: ";
            cin >> max;
            List.generate_random(size, min, max);
            std::cout << "Losowa tablica wygenerowana \n";
            break;
        }
        case 6: {
            // Wyświetlanie listy
            std::cout << "\nZawartosc tablicy:\n";
            std::cout << "Rozmiar: " << List.get_size() << endl;
            if (List.get_size() == 0)
                std::cout << "Lista jest pusta.\n";
            else {
                std::cout << "Elementy: ";
                List.show();
            }
            break;
        }
        case 0:
            std::cout << "Wychodze...\n";
            break;
        default:
            std::cout << "Zly wybor \n";
        }
    } while (choice != 0);
}

// ======= TEST LISTY DWUKIERUNKOWEJ  =======
void testDoubleLinkedList() {
    DoubleConnectedList List;
    int choice;
    do {
        std::cout << "\n===== TEST TABLICY DYNAMICZNEJ =====\n";
        std::cout << "1. Zbuduj z pliku\n";
        std::cout << "2. Usun wybrany element\n";
        std::cout << "3. Dodaj element\n";
        std::cout << "4. Znajdz element\n";
        std::cout << "5. Wypelnij tablice losowo\n";
        std::cout << "6. Wyswietl tablice\n";
        std::cout << "7. Wyswietl tablice w odwrotnej kolejnosci\n";
        std::cout << "0. Wyjdz\n";
        std::cout << "Twoj wybor: ";
        std::cin >> choice;
        switch (choice) {
        case 1: {
            List.build_from_file("Lista.txt");
            break;
        }
        case 2: {
            // Usuwanie wybranego elementu
            if (List.get_size() == 0) {
                std::cout << "Tablica jest pusta\n";
                break;
            }
            int index;
            std::cout << "Podaj indeks elementu do usuniecia (0 - " << List.get_size() - 1 << "): ";
            std::cin >> index;
            if (index < 0 || index >= List.get_size()) {
                std::cout << "Niepoprawny indeks\n";
                break;
            }
            List.pop_index(index);
            std::cout << "Element na indeksie " << index << " zostal usuniety\n";
            break;
        }
        case 3: {
            // Dodawanie elementu
            int value;
            std::cout << "Jaka wartosc dodac: ";
            std::cin >> value;
            std::cout << "Gdzie wstawic element?\n";
            std::cout << "1. Na poczatku\n";
            std::cout << "2. Na koncu\n";
            std::cout << "3. W wybranej pozycji\n";
            std::cout << "Twoj wybor: ";
            int posChoice;
            int index;
            cin >> posChoice;
            switch (posChoice) {
            case 1:
                List.push_front(value);
                std::cout << "Dodano " << value << " na poczatku\n";
                break;
            case 2:
                List.push_back(value);
                std::cout << "Dodano " << value << " na koncu\n";
                break;
            case 3:
                std::cout << "Podaj index na ktorym chcesz umiescic element: ";
                cin >> index;
                List.push_index(value, index);
                std::cout << "Dodano " << value << " na indeksie: " << index << endl;
                break;
            default:
                std::cout << "Niepoprawny wybor \n";
            }
            break;
        }
        case 4: {
            // Wyszukiwanie elementu
            if (List.get_size() == 0) {
                std::cout << "Tablica jest pusta\n";
                break;
            }
            int value;
            std::cout << "Podaj wartosc do wyszukania: ";
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
            std::cout << "Podaj rozmiar losowej tablicy: ";
            std::cin >> size;
            if (size <= 0) {
                std::cout << "Rozmiar musi byc dodatni \n";
                break;
            }
            std::cout << "Podaj minimalna wartosc zakresu: ";
            std::cin >> min;
            std::cout << "Podaj maksymalna wartosc zakresu: ";
            std::cin >> max;
            List.generate_random(size, min, max);
            std::cout << "Losowa tablica wygenerowana \n";
            break;
        }
        case 6: {
            // Wyświetlanie listy
            std::cout << "\nZawartosc tablicy:\n";
            std::cout << "Rozmiar: " << List.get_size() << endl;
            if (List.get_size() == 0)
                std::cout << "Lista jest pusta.\n";
            else {
                std::cout << "Elementy: ";
                List.show();
            }
            break;
        }
        case 7: {
            // Wyswietlanie listy w odwrotnej kolejnosci
            std::cout << "\nZawartosc tablicy:\n";
            std::cout << "Rozmiar: " << List.get_size() << endl;
            if (List.get_size() == 0)
                std::cout << "Lista jest pusta.\n";
            else {
                std::cout << "Elementy: ";
                List.show_reverse();
            }
            break;
        }
        case 0:
            std::cout << "Wychodze...\n";
            break;
        default:
            std::cout << "Zly wybor \n";
        }
    } while (choice != 0);
}


// ======= TEST CZASOWY TABLICY DYNAMICZNEJ =======
void TimetestArrayList(ofstream& resultsFile, int dataSize, int randomSearch, int randomIndex) {
    int iterations = 50;
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
    long  SumPopFront = 0;
    long  SumPopBack = 0;
    long  SumPopRandom = 0;
    long  SumSearch = 0;

    for (int i = 0; i < iterations; ++i) {

        // --- Test push_front ---
        ArrayList listaPushFront(dane.size());      // Stworzenie kopii struktury ArrayList z danymi
        for (size_t j = 0; j < dane.size(); ++j) {
            listaPushFront.push_back(dane[j]);
        }
        auto start = high_resolution_clock::now();  // Mierzenie czasu
        listaPushFront.push_front(1);
        auto stop = high_resolution_clock::now();
        SumPushFront += duration_cast<nanoseconds>(stop - start).count();

        // --- Test push_back ---
        ArrayList listaPushBack(dane.size());
        for (size_t j = 0; j < dane.size(); ++j) {
            listaPushBack.push_back(dane[j]);
        }
        start = high_resolution_clock::now();
        listaPushBack.push_back(1);
        stop = high_resolution_clock::now();
        SumPushBack += duration_cast<nanoseconds>(stop - start).count();

        // --- Test insert_random ---
        ArrayList listaInsertRandom(dane.size());
        for (size_t j = 0; j < dane.size(); ++j) {
            listaInsertRandom.push_back(dane[j]);
        }
        start = high_resolution_clock::now();
        listaInsertRandom.insert_random(1, randomIndex);
        stop = high_resolution_clock::now();
        SumInsertRandom += duration_cast<nanoseconds>(stop - start).count();

        // --- Test pop_front ---
        ArrayList listaPopFront(dane.size());      // Stworzenie kopii struktury z danymi
        for (size_t j = 0; j < dane.size(); ++j) {
            listaPopFront.push_front(dane[j]);
        }
        start = high_resolution_clock::now();  // Mierzenie czasu
        listaPopFront.remove(0);
        stop = high_resolution_clock::now();
        SumPopFront += duration_cast<nanoseconds>(stop - start).count();

        // --- Test pop_back ---
        ArrayList listaPopBack(dane.size());      // Stworzenie kopii struktury z danymi
        for (size_t j = 0; j < dane.size(); ++j) {
            listaPopBack.push_front(dane[j]);
        }
        start = high_resolution_clock::now();  // Mierzenie czasu
        listaPopBack.remove(listaPopBack.size() - 1);
        stop = high_resolution_clock::now();
        SumPopBack += duration_cast<nanoseconds>(stop - start).count();

        // --- Test pop_index ---
        ArrayList listaPopRandom(dane.size());
        for (size_t j = 0; j < dane.size(); ++j) {
            listaPopRandom.push_front(dane[j]);
        }
        start = high_resolution_clock::now();
        listaPopRandom.remove(randomIndex);
        stop = high_resolution_clock::now();
        SumPopRandom += duration_cast<nanoseconds>(stop - start).count();

        // --- Test search ---
        ArrayList listaSearch(dane.size());
        for (size_t j = 0; j < dane.size(); ++j) {
            listaSearch.push_front(dane[j]);
        }
        start = high_resolution_clock::now();
        listaInsertRandom.find(randomSearch);
        stop = high_resolution_clock::now();
        SumSearch += duration_cast<nanoseconds>(stop - start).count();

    }

    // Obliczenie i wyświetlenie średnich czasów wykonania dla poszczególnych operacji
    std::cout << "Sredni czas push_front: " << SumPushFront / iterations << " nanosekund" << endl;
    std::cout << "Sredni czas push_back: " << SumPushBack / iterations << " nanosekund" << endl;
    std::cout << "Sredni czas push_index: " << SumInsertRandom / iterations << " nanosekund" << endl;
    std::cout << "Sredni czas pop_front: " << SumPopFront / iterations << " nanosekund" << endl;
    std::cout << "Sredni czas pop_back: " << SumPopBack / iterations << " nanosekund" << endl;
    std::cout << "Sredni czas pop_random: " << SumPopRandom / iterations << " nanosekund" << endl;
    std::cout << "Sredni czas search: " << SumSearch / iterations << " nanosekund" << endl;

    // Zapisanie wyników do pliku
    resultsFile << "ArrayList\t" << dataSize << "\t"
        << SumPushFront / iterations << "\t"
        << SumPushBack / iterations << "\t"
        << SumInsertRandom / iterations << "\t"
        << SumPopFront / iterations << "\t"
        << SumPopBack / iterations << "\t"
        << SumPopRandom / iterations << "\t"
        << SumSearch / iterations << endl;
}

// ======= TEST CZASOWY LISTY JEDNOKIERUNKOWEJ  =======
void TimetestSingleLinkedList(ofstream& resultsFile, int dataSize, int randomSearch, int randomIndex) {
    int iterations = 50;
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
    long  SumPopFront = 0;
    long  SumPopBack = 0;
    long  SumPopRandom = 0;
    long  SumSearch = 0;

    for (int i = 0; i < iterations; ++i) {

        // --- Test push_front ---
        LinkedList listaPushFront;      // Stworzenie kopii struktury z danymi
        for (size_t j = 0; j < dane.size(); ++j) {
            listaPushFront.push_front(dane[j]);
        }
        auto start = high_resolution_clock::now();  // Mierzenie czasu
        listaPushFront.push_front(1);
        auto stop = high_resolution_clock::now();
        SumPushFront += duration_cast<nanoseconds>(stop - start).count();

        // --- Test push_back ---
        LinkedList listaPushBack;
        for (size_t j = 0; j < dane.size(); ++j) {
            listaPushBack.push_front(dane[j]);
        }
        start = high_resolution_clock::now();
        listaPushBack.push_back(1);
        stop = high_resolution_clock::now();
        SumPushBack += duration_cast<nanoseconds>(stop - start).count();

        // --- Test push_index ---
        LinkedList listaInsertRandom;
        for (size_t j = 0; j < dane.size(); ++j) {
            listaInsertRandom.push_front(dane[j]);
        }
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        listaInsertRandom.push_index(1, randomIndex);
        stop = high_resolution_clock::now();
        SumInsertRandom += duration_cast<nanoseconds>(stop - start).count();

        // --- Test pop_front ---
        LinkedList listaPopFront;      // Stworzenie kopii struktury z danymi
        for (size_t j = 0; j < dane.size(); ++j) {
            listaPopFront.push_front(dane[j]);
        }
        start = high_resolution_clock::now();  // Mierzenie czasu
        listaPopFront.pop_front();
        stop = high_resolution_clock::now();
        SumPopFront += duration_cast<nanoseconds>(stop - start).count();

        // --- Test pop_back ---
        LinkedList listaPopBack;      // Stworzenie kopii struktury z danymi
        for (size_t j = 0; j < dane.size(); ++j) {
            listaPopBack.push_front(dane[j]);
        }
        start = high_resolution_clock::now();  // Mierzenie czasu
        listaPopBack.pop_back();
        stop = high_resolution_clock::now();
        SumPopBack += duration_cast<nanoseconds>(stop - start).count();

        // --- Test pop_index ---
        LinkedList listaPopRandom;
        for (size_t j = 0; j < dane.size(); ++j) {
            listaPopRandom.push_front(dane[j]);
        }
        start = high_resolution_clock::now();
        listaPopRandom.pop_index(randomIndex);
        stop = high_resolution_clock::now();
        SumPopRandom += duration_cast<nanoseconds>(stop - start).count();

        // --- Test search ---
        LinkedList listaSearch;
        for (size_t j = 0; j < dane.size(); ++j) {
            listaSearch.push_front(dane[j]);
        }
        start = high_resolution_clock::now();
        listaSearch.search(randomSearch);
        stop = high_resolution_clock::now();
        SumSearch += duration_cast<nanoseconds>(stop - start).count();
    }

    // Obliczenie i wyświetlenie średnich czasów wykonania dla poszczególnych operacji
    std::cout << "Sredni czas push_front: " << SumPushFront / iterations << " nanosekund" << endl;
    std::cout << "Sredni czas push_back: " << SumPushBack / iterations << " nanosekund" << endl;
    std::cout << "Sredni czas push_index: " << SumInsertRandom / iterations << " nanosekund" << endl;
    std::cout << "Sredni czas pop_front: " << SumPopFront / iterations << " nanosekund" << endl;
    std::cout << "Sredni czas pop_back: " << SumPopBack / iterations << " nanosekund" << endl;
    std::cout << "Sredni czas pop_random: " << SumPopRandom / iterations << " nanosekund" << endl;
    std::cout << "Sredni czas search: " << SumSearch / iterations << " nanosekund" << endl;

    // Zapisanie wyników do pliku
    resultsFile << "LinkedList\t" << dataSize << "\t"
        << SumPushFront / iterations << "\t"
        << SumPushBack / iterations << "\t"
        << SumInsertRandom / iterations << "\t"
        << SumPopFront / iterations << "\t"
        << SumPopBack / iterations << "\t"
        << SumPopRandom / iterations << "\t"
        << SumSearch / iterations << endl;
}

// ======= TEST CZASOWY LISTY DWUKIERUNKOWEJ  =======
void TimetestDoubleLinkedList(ofstream& resultsFile, int dataSize, int randomSearch, int randomIndex) {
    int iterations = 50;
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
    long  SumPopFront = 0;
    long  SumPopBack = 0;
    long  SumPopRandom = 0;
    long  SumSearch = 0;

    for (int i = 0; i < iterations; ++i) {

        // --- Test push_front ---
        DoubleConnectedList listaPushFront;      // Stworzenie kopii struktury z danymi
        for (size_t j = 0; j < dane.size(); ++j) {
            listaPushFront.push_front(dane[j]);
        }
        auto start = high_resolution_clock::now();  // Mierzenie czasu
        listaPushFront.push_front(1);
        auto stop = high_resolution_clock::now();
        SumPushFront += duration_cast<nanoseconds>(stop - start).count();

        // --- Test push_back ---
        DoubleConnectedList listaPushBack;
        for (size_t j = 0; j < dane.size(); ++j) {
            listaPushBack.push_front(dane[j]);
        }
        start = high_resolution_clock::now();
        listaPushBack.push_back(1);
        stop = high_resolution_clock::now();
        SumPushBack += duration_cast<nanoseconds>(stop - start).count();

        // --- Test push_index ---
        DoubleConnectedList listaInsertRandom;
        for (size_t j = 0; j < dane.size(); ++j) {
            listaInsertRandom.push_front(dane[j]);
        }
        start = high_resolution_clock::now();
        listaInsertRandom.push_index(1, randomIndex);
        stop = high_resolution_clock::now();
        SumInsertRandom += duration_cast<nanoseconds>(stop - start).count();

        // --- Test pop_front ---
        DoubleConnectedList listaPopFront;      // Stworzenie kopii struktury z danymi
        for (size_t j = 0; j < dane.size(); ++j) {
            listaPopFront.push_front(dane[j]);
        }
        start = high_resolution_clock::now();  // Mierzenie czasu
        listaPopFront.pop_front();
        stop = high_resolution_clock::now();
        SumPopFront += duration_cast<nanoseconds>(stop - start).count();

        // --- Test pop_back ---
        DoubleConnectedList listaPopBack;      // Stworzenie kopii struktury z danymi
        for (size_t j = 0; j < dane.size(); ++j) {
            listaPopBack.push_front(dane[j]);
        }
        start = high_resolution_clock::now();  // Mierzenie czasu
        listaPopBack.pop_back();
        stop = high_resolution_clock::now();
        SumPopBack += duration_cast<nanoseconds>(stop - start).count();

        // --- Test pop_index ---
        DoubleConnectedList listaPopRandom;
        for (size_t j = 0; j < dane.size(); ++j) {
            listaPopRandom.push_front(dane[j]);
        }
        start = high_resolution_clock::now();
        listaPopRandom.pop_index(randomIndex);
        stop = high_resolution_clock::now();
        SumPopRandom += duration_cast<nanoseconds>(stop - start).count();

        // --- Test search ---
        DoubleConnectedList listaSearch;
        for (size_t j = 0; j < dane.size(); ++j) {
            listaSearch.push_front(dane[j]);
        }
        start = high_resolution_clock::now();
        listaSearch.search(randomSearch);
        stop = high_resolution_clock::now();
        SumSearch += duration_cast<nanoseconds>(stop - start).count();
    }

    // Obliczenie i wyświetlenie średnich czasów wykonania dla poszczególnych operacji
    cout << "Sredni czas push_front: " << SumPushFront / iterations << " nanosekund" << endl;
    cout << "Sredni czas push_back: " << SumPushBack / iterations << " nanosekund" << endl;
    cout << "Sredni czas push_index: " << SumInsertRandom / iterations << " nanosekund" << endl;
    cout << "Sredni czas pop_front: " << SumPopFront / iterations << " nanosekund" << endl;
    cout << "Sredni czas pop_back: " << SumPopBack / iterations << " nanosekund" << endl;
    cout << "Sredni czas pop_random: " << SumPopRandom / iterations << " nanosekund" << endl;
    cout << "Sredni czas search: " << SumSearch / iterations << " nanosekund" << endl;

    // Zapisanie wyników do pliku
    resultsFile << "DoubleConnectedList\t" << dataSize << "\t"
        << SumPushFront / iterations << "\t"
        << SumPushBack / iterations << "\t"
        << SumInsertRandom / iterations << "\t"
        << SumPopFront / iterations << "\t"
        << SumPopBack / iterations << "\t"
        << SumPopRandom / iterations << "\t"
        << SumSearch / iterations << endl;
}

// ======= TEST WSZYSTKICH STRUKTUR PO KOLEI =======
void testAllStructures() {
    int tab[10] = { 10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000 };
    int capacity;
    int randomSearch, randomIndex;
    // Utworzenie pliku wyniki.txt i dodanie nagłówków
    ofstream resultsFile("wyniki.txt");
    if (!resultsFile) {
        cerr << "Nie mozna utworzyc pliku wyniki.txt!" << endl;
        return;
    }

    // Dodanie nagłówków do pliku
    resultsFile << "Struktura\tRozmiar\tpush_front\tpush_back\tpush_index\tpop_front\tpop_back\tpop_random\tsearch" << endl;

    for (int i = 0; i < 10; i++) {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        capacity = tab[i];
        randomSearch = ((rand() & 0x7FFF) << 15) | (rand() & 0x7FFF);
        randomIndex= (std::rand() % tab[i] + 1);    
        generateRandomFile("Liczby.txt", capacity);
        cout << "Rozmiar: " << tab[i] << endl;
        cout << "=== Test tablicy dynamicznej ===" << endl;
        TimetestArrayList(resultsFile, capacity, randomSearch, randomIndex);
        cout << "\n=== Test listy jednokierunkowej ===" << endl;
        TimetestSingleLinkedList(resultsFile, capacity, randomSearch, randomIndex);
        cout << "\n=== Test listy dwukierunkowej ===" << endl;
        TimetestDoubleLinkedList(resultsFile, capacity, randomSearch, randomIndex);
    }

    resultsFile.close();
    cout << "Wyniki zostaly zapisane do pliku wyniki.txt" << endl;
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