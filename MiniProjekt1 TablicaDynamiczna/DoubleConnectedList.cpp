#include"DoubleConnectedList.h"
#include<iostream>
#include<vector>

DoubleConnectedList::DoubleConnectedList():head(nullptr), tail(nullptr), size(0) {}

int DoubleConnectedList::get_size() const{
	return size;
}

void DoubleConnectedList::push_front(int value) {
	Node* newNode = new Node(value, nullptr, head);
	if (head) head->prev = newNode;
	else tail = newNode; //jezeli lista jest pusta
	head = newNode;
	size++;
}

void DoubleConnectedList::push_back(int value) {
	Node* newNode = new Node(value, tail, nullptr);
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
			Node* current = head;
			for (int i = 0; i < index; i++) {
				current = current->next;
			}
			Node* newNode = new Node(value, current->prev, current);
			current->prev->next = newNode;
			current->prev = newNode;
		}
		else {  //jezeli indeksowi jest blizej do konca listy iterujemy od taila
			Node* current = tail;
			for (int i = size-1; i > index; i--) {
				current = current->prev;
			}
			Node* newNode = new Node(value, current, current->next);
			current->next->prev = newNode;
			current->next = newNode;
		}
		size++;
	}
}

DoubleConnectedList::~DoubleConnectedList() {
	while (head) pop_front();
}