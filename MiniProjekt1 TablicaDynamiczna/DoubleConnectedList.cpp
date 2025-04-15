#include"DoubleConnectedList.h"
#include<iostream>
#include<vector>
#include<algorithm>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include<string>

DoubleConnectedList::DoubleConnectedList():head(nullptr), tail(nullptr), size(0) {}

int DoubleConnectedList::get_size() const{
	return size;
}

//Funkcja dodajaca element na poczatek
void DoubleConnectedList::push_front(int value) {
	DNode* newNode = new DNode(value, nullptr, head);
	if (head) head->prev = newNode;
	else tail = newNode; //jezeli lista jest pusta
	head = newNode;
	size++;
}

//Funkcja dodajaca element na koniec
void DoubleConnectedList::push_back(int value) {
	DNode* newNode = new DNode(value, tail, nullptr);
	if (tail) tail->next = newNode;
	else head = newNode; //jezeli lista by³a pusta
	tail = newNode;
	size++;
}

//funkcja dodajca element na zadany indeks
void DoubleConnectedList::push_index(int value, int index) {
	if (index == 0) {
		push_front(value);
		return;
	}
	else if (index == size) {
		push_back(value);
		return;
	}
	else {
		if (index < size / 2) {  //jezeli indeksowi jest blizej do poczatku listy iterujemy od heada
			DNode* current = head;
			for (int i = 0; i < index; i++) {
				current = current->next;
			}
			DNode* newNode = new DNode(value, current->prev, current);
			current->prev->next = newNode;
			current->prev = newNode;
		}
		else {  //jezeli indeksowi jest blizej do konca listy iterujemy od taila
			DNode* current = tail;
			for (int i = size-1; i >= index; i--) {
				current = current->prev;
			}
			DNode* newNode = new DNode(value, current, current->next);
			current->next->prev = newNode;
			current->next = newNode;
		}
		size++;
	}
}

//funkcja usuwajaca pierwszy element
void DoubleConnectedList::pop_front() {
	if (!head) return;
	DNode* temp = head;
	head = head->next;
	if (head) { 
		head->prev = nullptr;
	}
	else { //jezeli po usunieciu pierwszego jest pusta
		tail = nullptr;
	}
	delete temp;
	size--;
}

//funkcja usuwajaca ostatni element
void DoubleConnectedList::pop_back() {
	if (!tail) return;
	DNode* temp = tail;
	tail = tail->prev;
	if (tail) {
		tail->next = nullptr;
	}
	else { //jezeli po usunieciu ostatniego jest pusta
		head = nullptr;
	}
	delete temp;
	size--;
}

//funkcja usuwajaca element na zadanym indeksie
void DoubleConnectedList::pop_index(int index) {
	if (index == 0) pop_front();
	else if (index == size - 1) pop_back();
	else {
		if (index < size / 2) {
			DNode* current = head;
			for (int i = 0; i < index; i++) {
				current = current->next;
			}
			current->prev->next = current->next;
			current->next->prev = current->prev;
			delete current;
		}
		else {
			DNode* current = tail;
			for (int i = size-1; i > index; i--) {
				current = current->prev;
			}
			current->prev->next = current->next;
			current->next->prev = current->prev;
			delete current;
		}
		size--;
	}
}

//funkcja zwracajaca wektor z indeksami na ktorych znajdziemy zadana wartosc, jezeli nie ma w liscie zwraca -1
std::vector<int> DoubleConnectedList::search(int value) {
	std::vector<int> indices;
	int i = 0;
	int j = size - 1;
	DNode* left = head;
	DNode* right = tail;

	// Przeszukujemy listê od obu koñców
	while (i <= j && left && right) {
		if (left->data == value) {
			indices.push_back(i);
		}
		// Jeœli oba wskaŸniki wskazuj¹ ten sam element, unikamy podwójnego dodania
		if (i != j && right->data == value) {
			indices.push_back(j);
		}
		left = left->next;
		right = right->prev;
		i++;
		j--;
	}

	// uporz¹dkowanie indeksów
	std::sort(indices.begin(), indices.end());
	if (indices.empty()) {
		indices.push_back(-1);
	}
	return indices;
}


//funkcje do menu
void DoubleConnectedList::show() const {
	DNode* temp = head;
	while (temp) {
		std::cout << temp->data << " -> ";
		temp = temp->next;
	}
	std::cout << std::endl;
}


void DoubleConnectedList::show_reverse() const {
	DNode* temp = tail;
	while (temp) {
		std::cout << temp->data << " -> ";
		temp = temp->prev;
	}
	std::cout << std::endl;
}

// Funkcja czyszcz¹ca listê – usuwa wszystkie elementy
void DoubleConnectedList::clear() {
	while (head) {
		DNode* temp = head;
		head = head->next;
		delete temp;
	}
	tail = nullptr;
	size = 0;
}

// Funkcja buduj¹ca listê z pliku (wczytuje wartoœci ca³kowite z pliku)
// Najpierw czyœci dotychczasow¹ listê, a nastêpnie dodaje kolejne elementy na koñcu
void DoubleConnectedList::build_from_file(const std::string& filename) {
	clear(); // Usuwamy istniej¹ce dane

	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Nie mozna otworzyc pliku: " << filename << std::endl;
		return;
	}

	int value;
	while (file >> value) {
		push_back(value); // Dodajemy elementy na koñcu, zachowuj¹c kolejnoœæ z pliku
	}

	file.close();
}

// Funkcja tworz¹ca losow¹ strukturê – generuje listê o podanej liczbie elementów
// Elementy maj¹ losowe wartoœci w przedziale [minVal, maxVal]
void DoubleConnectedList::generate_random(int count, int minVal, int maxVal) {
	clear(); // Usuwamy istniej¹ce dane

	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	for (int i = 0; i < count; i++) {
		int randomValue = minVal + (std::rand() % (maxVal - minVal + 1));
		push_back(randomValue);
	}
}

DoubleConnectedList::~DoubleConnectedList() {
	while (head) pop_front();
}