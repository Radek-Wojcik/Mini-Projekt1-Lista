#include "LinkedList.h"
#include "DoubleConnectedList.h"
#include<iostream>

int main() {
	//LinkedList List;
	DoubleConnectedList List;
	List.push_front(5);
	List.push_front(7);
	List.show();
	List.push_back(3);
	List.push_back(1);
	List.push_back(8);
	List.show();
	List.show_reverse();
	List.push_index(11, 1);
	List.show();
	List.push_index(15, 4);
	List.show();
	List.push_back(20);
	List.push_back(9);
	List.show();
	/*List.pop_front();
	List.show();
	List.pop_back();
	List.show();
	List.pop_index(2);
	List.show();
	List.push_back(11);
	List.show();
	List.search(11);
	List.search(0);*/
	std::cout << "size: "<<List.get_size() << std::endl;
	
}