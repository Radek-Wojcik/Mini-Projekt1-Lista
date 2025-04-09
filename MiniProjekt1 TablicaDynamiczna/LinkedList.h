#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <typename T>
struct Node {
	T data;
	Node<T>* next;
	Node(T value = 0) : data(value), next(nullptr) {}
	Node(T value, Node<T>* tempNext) : data(value), next(tempNext) {}
};

template <typename T>
class LinkedList {
private:
	Node<T>* head;
	Node<T>* tail;
public:
	LinkedList() {}
	void push_front(T value);
	void push_back(T value);
	void push_index(T value, int index);
	void pop_front();
	void pop_back();
	void pop_index(int index);
	Node<T> search(T value);
	~LinkedList() {}
};

#endif //LINKEDLIST_H
