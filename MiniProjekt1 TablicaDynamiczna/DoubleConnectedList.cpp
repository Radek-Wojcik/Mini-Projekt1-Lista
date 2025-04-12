#include"DoubleConnectedList.h"
#include<iostream>
#include<vector>

DoubleConnectedList::DoubleConnectedList():head(nullptr), tail(nullptr), size(0) {}

int DoubleConnectedList::get_size() const{
	return size;
}

DoubleConnectedList::~DoubleConnectedList() {
	while (head) pop_front();
}