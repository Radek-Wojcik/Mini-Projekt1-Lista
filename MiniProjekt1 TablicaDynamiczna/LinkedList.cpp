#include"LinkedList.h"
#include<iostream>


LinkedList::LinkedList() : head(nullptr), tail(nullptr) {}

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
		int i = 0;
		for (i; i < index; i++) {    //dobieramy si� do indeksu na kt�ry chcecmy doda� warto��
			current = current->next;
		}
		newNode->next = current;
		current->next = newNode;
		size++;
	}
}