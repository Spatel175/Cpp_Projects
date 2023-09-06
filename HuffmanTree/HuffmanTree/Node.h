#pragma once
#include <string>
using namespace std;
class Node {

public:
	Node();
	Node(char c, int i);
	char character;
	int val;
	std::string code;
	Node* right;
	Node* left;


};
Node::Node() :character('H'), val(1), code(" "), right(nullptr), left(nullptr)
{

}
Node::Node(char c, int i)
{
	character = c;
	val = i;
	code = " ";
	left = right = nullptr;
}

