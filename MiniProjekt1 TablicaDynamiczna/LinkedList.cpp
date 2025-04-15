#include"LinkedList.h"
#include<iostream>
#include<vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include<string>

LinkedList::LinkedList() : head(nullptr), tail(nullptr), size(0) {}

int LinkedList::get_size() const {
	return size;
}

LinkedList::~LinkedList() {
	while (head != nullptr) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
	tail = nullptr;
}

//Funkcja dodaj�ca element z przodu listy, nie zwraca nic
void LinkedList::push_front(int value) {
	Node* newNode = new Node(value, head);
	head = newNode;
	//sprawdzamy czy lista nie by�a pusta
	if (tail == nullptr) tail = newNode;
	size++;
}

//Funkcja dodaj�ca element na koncu listy, nie zwraca nic
void LinkedList::push_back(int value) {
	Node* newNode = new Node(value, nullptr);
	if (tail != nullptr) {
		tail->next = newNode;
	} 
	else {
		head = newNode; //kiedy lista jest pusta
	}
	tail = newNode;
	size++;
}

//Funkcja dodaj�ca element na wybrany index, nie zwraca nic
void LinkedList::push_index(int value, int index) {
	if(index==0){  
		push_front(value); 
		return;
	}
	else if (index == size) {
		push_back(value);
		return;
	}
	else {
		Node* newNode = new Node(value, nullptr);
		Node* current = head;
		for (int i = 0; i < index-1; i++) {    //dobieramy si� do indeksu na kt�ry chcecmy doda� warto��
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
		size++;
	}
}

//Funkcja usuwajaca element z przodu listy, nie zwraca nic
void LinkedList::pop_front() {
	if (head == nullptr) return; //je�li lista jest pusta
	Node* temp;
	temp = head;
	head = head->next;
	delete temp;
	size--;
	if (head == nullptr) tail = nullptr; //je�eli lista po usuni�ciu pusta, zerujemy tail
}

//Funkcja usuwajaca element na koncu listy, nie zwraca nic
void LinkedList::pop_back() {
	if (head == nullptr) return; //je�li lista jest pusta
	if (head->next == nullptr) { //je�li lista zawiera jeden element pop_back = pop_front
		pop_front();
		return;
	}
	Node* current=head;
	while (current->next != tail) {
		current = current->next;
	}
	delete tail;
	tail = current;
	tail->next = nullptr;
	size--;
}

//Funkcja usuwajaca element z wybranego indexu, nie zwraca nic
void LinkedList::pop_index(int index) {
	if (index == 0) {
		pop_front();
		return;
	}
	if (index == size - 1) {
		pop_back();
		return;
	}
	Node* current = head;
	for (int i = 0; i < index - 1; i++) {    //dobieramy si� do indeksu na kt�ry chcecmy doda� warto��
		current = current->next;
	}
	Node* temp = current->next;
	current->next = temp->next;
	delete temp;
	size--;
}

//funkcja wyszukujaca zadana wartosc zwraca wektor z wartosciami, jezeli nic nie znajdzie wynik to -1
std::vector<int> LinkedList::search(int value) {
	std::vector<int> indices;
	Node* current = head;

	int index = 0;
	while (current != nullptr) {
		if (current->data == value) {
			indices.push_back(index);
		}
		current = current->next;
		index++;
	}

	if (indices.empty()) {
		indices.push_back(-1);
	}

	return indices;
}

//funkcje do menu
void LinkedList::show() const {
	Node* temp = head;
	while (temp) {
		std::cout << temp->data << " -> ";
		temp = temp->next;
	}
	std::cout << std::endl;
}


// Usuwa wszystkie dane z listy (przydatne przed wczytaniem z pliku)
void LinkedList::clear() {
	while (head != nullptr) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
	tail = nullptr;
	size = 0;
}

// Buduje list� z pliku (czyta warto�ci ca�kowite z pliku)
void LinkedList::build_from_file(const std::string& filename) {
	clear(); // Usuwamy istniej�ce dane

	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Nie mozna otworzyc pliku: " << filename << std::endl;
		return;
	}

	int value;
	while (file >> value) {
		push_back(value); // Dodajemy na koniec listy zachowuj�c kolejno�� z pliku
	}

	file.close();
}

// Tworzy losow� struktur� o podanej wielko�ci
void LinkedList::generate_random(int count, int minVal, int maxVal) {
	clear(); // Usuwamy istniej�ce dane

	std::srand(std::time(nullptr));
	for (int i = 0; i < count; i++) {
		int randomValue = minVal + (std::rand() % (maxVal - minVal + 1));
		push_back(randomValue);
	}
}
