#pragma once
#include <iostream>
#include "Node.h"

class DoublyLinkedList {

public:

	DoublyLinkedList();
	~DoublyLinkedList();
	void push_front(signed short);
	void pop_front();
	signed short operator[] (int index);
	bool empty();
	int size();
	void insert(int index, signed short val);
	void erase(int index);
	int find(signed short key);
	friend std::ostream& operator <<(std::ostream& ostr, const DoublyLinkedList& rhs);

private:

	Node* Head;

};