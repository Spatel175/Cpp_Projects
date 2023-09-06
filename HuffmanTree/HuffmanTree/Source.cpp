#include<iostream>
#include<stdlib.h>
#include <fstream>
#include <list>
#include <map>
#include "Node.h"

#define len 54                                           
using namespace std;
using std::ifstream;
map<char, string> codes;

bool cmp(const Node* a, const Node* b)
{
	return (a->val < b->val);
}

int findChar(char c, char arr[], int count[])
{
	for (int i = 0; i < len - 1; i++)
	{
		if (arr[i] == c)
		{
			count[i]++;
			return 1;
		}
	}
	return 0;
}

void printcodes(Node* p, string str)
{
	if (!p)
	{
		return;
	}
	if (p->character != '*')
	{
		cout << p->character << ':' << str << endl;
	}
	printcodes(p->left, str + "0");
	printcodes(p->right, str + "1");
}

void storeCodes(string c, Node* N)
{
	if (N == nullptr)
	{
		return;
	}
	if (N->left == nullptr && N->right == nullptr)
	{
		N->code = c;
		return;
	}
	storeCodes(c + "0", N->left);
	storeCodes(c + "1", N->right);
}

void printTree(int level, Node* N)
{
	if (N == nullptr)
	{
		return;
	}
	for (int i = 0; i < level; i++)
	{
		std::cout << "\t";
	}
	
	
	std::cout << N->character << ' ' << N->code << std::endl;;
	
	
	printTree(level + 1, N->right);
	printTree(level + 1, N->left);
}
void Encode(Node* root, char c, FILE* stream)
{
	if (root == NULL)
	{
		return;
	}
	if (root->left == NULL &&root->right == NULL)
	{
		if (root->character == c)
		{
			fputs(root->code.c_str(), stream);
			return;
		}
	}
	Encode(root->left, c, stream);
	Encode(root->right, c, stream);
}
void output(Node* curr)
{
	FILE* stream1;
	errno_t err = fopen_s(&stream1, "Decoded.txt", "a");
	
	fputc(curr->character, stream1);


	fclose(stream1);
}
void Decode(Node* root, string str)
{
	string infile("Endoded.txt");
	FILE* stream2;
	errno_t err = fopen_s(&stream2,infile.c_str(), "r");
	
	if (err != 0)
	{
		cout << "Could not open file" << endl;
		return;
	}
	char i;
	Node* curr = root;
	while ((i = fgetc(stream2)) != EOF)
	{
		if (i == '0')
		{
			curr = curr->left;
		}
		else if (i == '1')
		{
			curr = curr->right;
		}
		else if (curr->left == NULL and curr->right == NULL)
		{
			output(curr);
			curr = root;
		}
	}
	fclose(stream2);
;
}
void getData()
{
	string myfile("Test.txt");
	char arr[len] = { NULL };
	int count[len] = { };
	FILE* stream;
	errno_t err = fopen_s(&stream, myfile.c_str(), "r");
	if (err != 0)
	{
		cout << "Could not open file" << endl;
		return;
	}
	char c;
	int k = 0;
	while ((c = fgetc(stream)) != EOF)
	{
		if (!findChar(c, arr, count))
		{
			arr[k] = c;
			count[k] = 1;
			k++;
		}
	}
	fclose(stream);
	Node* left, *right, *parent;
	list<Node*> NL;

	for (int i = 0; i < len ;i++)
	{
		if (count[i] != 0)
		{
			NL.push_back(new Node(arr[i], count[i]));
		}
		
	}
	while (NL.size() != 1)
	{
		NL.sort(cmp);
		list<Node*>::iterator it = NL.begin();
		left = *it;
		NL.pop_front();
		it = NL.begin();
		right = *it;
		NL.pop_front();
		parent = new Node('*', left->val + right->val);
		parent->left = left;
		parent->right = right;
		NL.push_back(parent);
	}
	list<Node*>::iterator it = NL.begin();
	Node* root = *it;
	storeCodes(" ",root);
	printTree(0, root);
	printcodes(root, "");
	

	FILE* stream3;
	errno_t err3 = fopen_s(&stream3, "Endoded.txt", "w+");

	for (int i = 0; i < len; i++)						//find code from nodes and print them out
	{
		Encode(root, arr[i],stream3);
	}
	fclose(stream3);

	Decode(root, "Encoded.txt");
	
}



int main()
{
	
	getData();
	
	return 0;
}