#include"DoubleConnectedList.h"
#include<iostream>
#include<vector>

DoubleConnectedList::DoubleConnectedList():head(nullptr), tail(nullptr), size(0) {}

int DoubleConnectedList::get_size() const{
	return size;
}

void DoubleConnectedList::push_front(int value) {
	DNode* newNode = new DNode(value, nullptr, head);
	if (head) head->prev = newNode;
	else tail = newNode; //jezeli lista jest pusta
	head = newNode;
	size++;
}

void DoubleConnectedList::push_back(int value) {
	DNode* newNode = new DNode(value, tail, nullptr);
	if (tail) tail->next = newNode;
	else head = newNode; //jezeli lista by³a pusta
	tail = newNode;
	size++;
}

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

void DoubleConnectedList::pop_index(int index) {
	if (index == 0) pop_front();
	else if (index == size - 1) pop_back;
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
				current = current->next;
			}
			current->prev->next = current->next;
			current->next->prev = current->prev;
			delete current;
		}
		size--;
	}
}

//funkcja do testow
void DoubleConnectedList::show() const {
	DNode* temp = head;
	while (temp) {
		std::cout << temp->data << " -> ";
		temp = temp->next;
	}
	std::cout << std::endl;
}

//funkcja do testow
void DoubleConnectedList::show_reverse() const {
	DNode* temp = tail;
	while (temp) {
		std::cout << temp->data << " -> ";
		temp = temp->prev;
	}
	std::cout << std::endl;
}



DoubleConnectedList::~DoubleConnectedList() {
	while (head) pop_front();
}