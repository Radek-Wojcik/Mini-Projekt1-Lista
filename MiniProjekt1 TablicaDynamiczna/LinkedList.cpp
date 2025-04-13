#include"LinkedList.h"
#include<iostream>
#include<vector>

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

//Funkcja dodaj¹ca element z przodu listy, nie zwraca nic
void LinkedList::push_front(int value) {
	Node* newNode = new Node(value, head);
	head = newNode;
	//sprawdzamy czy lista nie by³a pusta
	if (tail == nullptr) tail = newNode;
	size++;
}

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
		for (int i = 0; i < index-1; i++) {    //dobieramy siê do indeksu na który chcecmy dodaæ wartoœæ
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
		size++;
	}
}

void LinkedList::pop_front() {
	if (head == nullptr) return; //jeœli lista jest pusta
	Node* temp;
	temp = head;
	head = head->next;
	delete temp;
	size--;
	if (head == nullptr) tail = nullptr; //je¿eli lista po usuniêciu pusta, zerujemy tail
}

void LinkedList::pop_back() {
	if (head == nullptr) return; //jeœli lista jest pusta
	if (head->next == nullptr) { //jeœli lista zawiera jeden element pop_back = pop_front
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
	for (int i = 0; i < index - 1; i++) {    //dobieramy siê do indeksu na który chcecmy dodaæ wartoœæ
		current = current->next;
	}
	Node* temp = current->next;
	current->next = temp->next;
	delete temp;
	size--;
}

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

	// Do testow wyswietl wektor
	std::cout << "Indices: [";
	for (size_t i = 0; i < indices.size(); i++) {
		std::cout << indices[i];
		if (i < indices.size() - 1) {
			std::cout << ", ";
		}
	}
	std::cout << "]" << std::endl;

	return indices;
}

//funkcja do testów
void LinkedList::show() const {
	Node* temp = head;
	while (temp) {
		std::cout << temp->data << " -> ";
		temp = temp->next;
	}
	std::cout << std::endl;
}