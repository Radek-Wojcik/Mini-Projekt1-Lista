#pragma once
#ifndef DOUBLECONNECTEDLIST_H
#define DOUBLECONNECTEDLIST_H
#include<vector>

struct DNode {
	int data;
	DNode* prev;
	DNode* next;
	DNode(int value, DNode* tempPrev, DNode* tempNext) :data(value), prev(tempPrev), next(tempNext) {}
};

class DoubleConnectedList {
private:
	DNode* head;
	DNode* tail;
	int size;
public:
	DoubleConnectedList();
	int get_size() const;
	void show() const; //funkcja do testów czy lista dzia³a
	void show_reverse() const; //funkcja do testów czy lista dzia³a
	void push_front(int value);
	void push_back(int value);
	void push_index(int value, int index);
	void pop_front();
	void pop_back();
	void pop_index(int index);
	//std::vector<int> search(int value);
	~DoubleConnectedList();
};

#endif // DOUBLECONNECTEDLIST_H

