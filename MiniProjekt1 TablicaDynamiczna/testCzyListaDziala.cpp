#include "LinkedList.h"
#include<iostream>

int main() {
	LinkedList List;
	List.push_front(5);
	List.push_front(7);
	List.push_back(3);
	List.push_back(1);
	List.push_index(11, 2);
	List.show();
	std::cout << List.get_size() << std::endl;
}