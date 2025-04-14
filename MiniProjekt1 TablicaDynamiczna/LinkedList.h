#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include<vector>

struct Node {
	int data;
	Node* next;
	Node(int value, Node* tempNext) : data(value), next(tempNext) {}
};

class LinkedList {
private:
	Node* head;
	Node* tail;
	int size;
public:
	LinkedList();
	int get_size() const;
	void push_front(int value);
	void push_back(int value);
	void push_index(int value, int index);
	void pop_front();
	void pop_back();
	void pop_index(int index);
	std::vector<int> search(int value);
	//funkcje do menu
	void show() const; 
	void clear();
	void build_from_file(const std::string& filename);
	void generate_random(int count, int minVal = 0, int maxVal = 100);
	~LinkedList();
};

#endif //LINKEDLIST_H
