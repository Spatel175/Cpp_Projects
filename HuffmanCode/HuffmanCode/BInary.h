#pragma once
#include "Node.h"
#include <iostream>

class Node;
class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();
	void insert(int i);
	void Clear();
	void erase(int val);
	Node* Find(int i);
	void Print();
private:
	void Clear(Node* curr);
	Node* FindParent(Node* node);
	Node* root;
	void Print(Node* p);
};
BinaryTree::BinaryTree()
	:root(nullptr)
{
}
inline BinaryTree::~BinaryTree()
{
	Clear(root);
}

void BinaryTree::insert(int i)
{
	if (root == nullptr)
	{
		root = new Node(i);
	}
	else
	{
		Node* Curr = root;
		while (true)
		{


			if (i < Curr->val)
			{
				if (Curr->left != nullptr)
				{
					Curr = Curr->left;
				}
				else
				{
					Curr->left = new Node(i);
					break;
				}

			}
			else if (i > Curr->val)
			{
				if (Curr->right != nullptr)
				{
					Curr = Curr->right;
				}
				else
				{
					Curr->right = new Node(i);
					break;
				}

			}
			else
			{
				break;
			}
		}
	}
}

void BinaryTree::Clear()
{
	Clear(root);
	root = nullptr;

}

void BinaryTree::erase(int val)
{
	Node* Curr = Find(val);
	if (Curr != nullptr)
	{
		int child = (Curr->left != nullptr) + (Curr->right != nullptr);
		if (child == 0)
		{
			Node* parent = FindParent(root);
			if (Curr->val < parent->val)
			{
				parent->left = nullptr;
			}
			else
			{
				parent->right = nullptr;
			}
		}
		else if (child == 1)
		{
			int f = 0;
		}
		else if (child == 2)
		{
			int f = 0;
		}
	}
}

void BinaryTree::Clear(Node* Curr)
{
	if (Curr != nullptr)
	{
		Print(Curr->left);
		Print(Curr->right);
		delete Curr;
	}

}

Node* BinaryTree::FindParent(Node* node)
{
	if (root->val == node->val)
	{
		return root;
	}
	Node* current = root;

	while (current != nullptr)
	{
		if (current->left->val == node->val)
		{
			return current;
		}
		else if (current->right->val == node->val)
		{
			return current;
		}
		else if (node->val < current->val)
		{
			current = current->left;
		}
		else
		{
			current = current->right;
		}
	}
	return NULL;
}


Node* BinaryTree::Find(int i)
{
	Node* Curr = root;
	while (Curr != nullptr)
	{

		if (i == Curr->val)
		{
			return Curr;
		}
		else if (i < Curr->val)
		{
			Curr = Curr->left;
		}
		else
		{
			Curr = Curr->right;
		}
	}
	return nullptr;
}

void BinaryTree::Print()
{
	Print(root);

}

void BinaryTree::Print(Node* p)
{
	if (p != nullptr)
	{
		Print(p->left);
		std::cout << p->val << " ";
		Print(p->right);
	}

}
