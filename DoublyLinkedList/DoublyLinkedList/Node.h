#pragma once
#include<iostream>
class Node {
public:
	
	Node(signed short VALUE,
		Node* PREVIOUS = nullptr,
		Node* NEXT = nullptr);

	Node* previous;
	signed short data;
	Node* next;
	
};