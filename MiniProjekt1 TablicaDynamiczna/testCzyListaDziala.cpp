#include "LinkedList.h"
#include<iostream>

int main() {
	LinkedList List;
	List.push_front(5);
	List.push_front(7);
	List.push_back(3);
	List.push_back(1);
	List.push_index(11, 2);
	List.push_back(20);
	List.push_back(9);
	List.show();
	List.pop_front();
	List.show();
	List.pop_back();
	List.show();
	List.pop_index(2);
	List.show();
	std::cout << "size: "<<List.get_size() << std::endl;
}