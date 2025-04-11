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