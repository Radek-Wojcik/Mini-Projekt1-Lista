#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H


struct Node {
	int data;
	Node* next;
	Node(int value = 0) : data(value), next(nullptr) {}
	Node(int value, Node* tempNext) : data(value), next(tempNext) {}
};

class LinkedList {
private:
	Node* head;
	Node* tail;
public:
	LinkedList() {}
	void push_front(int value);
	void push_back(int value);
	void push_index(int value, int index);
	void pop_front();
	void pop_back();
	void pop_index(int index);
	Node search(int value);
	~LinkedList() {}
};

#endif //LINKEDLIST_H
