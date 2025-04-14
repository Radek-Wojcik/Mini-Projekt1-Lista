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
	
	void push_back(int value);
	void push_index(int value, int index);
	void pop_front();
	void pop_back();
	void pop_index(int index);
	std::vector<int> search(int value);
	//funkcje do menu
	void show() const; 
	void show_reverse() const; 
	void push_front(int value);
	void clear();
	void build_from_file(const std::string& filename);
	void generate_random(int count, int minVal = 0, int maxVal = 100);
	~DoubleConnectedList();
};

#endif // DOUBLECONNECTEDLIST_H

