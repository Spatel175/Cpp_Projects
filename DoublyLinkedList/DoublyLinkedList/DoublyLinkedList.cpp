#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList()
	:Head(nullptr)
{
	//Nothing here
}

DoublyLinkedList::~DoublyLinkedList()
{
	Node* Current = Head;
	while (Current != nullptr)
	{
		Node* Next = Current->next;
		delete Current;
		Current = Next;
	}
	Head = nullptr;
}

void DoublyLinkedList::push_front(signed short Val)
{
	if (Head != nullptr)
	{	
		//use constructor and new to create node with arg and pointers attched 
		Node* Temp = new Node(Val, nullptr, Head);
		Head->previous = Temp;
		Head = Temp;
		//swap 
	}
	else
	{
		//else start a new list.
		Head = new Node(Val);
	}
}


void DoublyLinkedList::pop_front()
{
	if (Head == nullptr)
	{
		throw std::out_of_range("CANNOT POP THE VOID");
	}
	if (Head->next == nullptr)
	{
		//if only one element delete head
		delete Head;
		Head = nullptr;
	}
	else
	{
		Node * Current = Head->next;
		//swap and then delete.
		delete Head;
		Head = Current;
	}
}

signed short DoublyLinkedList::operator[](int index)
{
	int i = 0;
	Node* Current = Head;
	while (Current != nullptr)
	{
		if (i == index)
		{
			return Current->data;
		}
		Current = Current->next;
		++i;
	}
	return std::numeric_limits<short>::min(); 
}

bool DoublyLinkedList::empty()
{
	return Head == nullptr;
}

int DoublyLinkedList::size()
{
	int Size = 0;
	Node* Current = Head;
	if (Head == nullptr)
	{
		return 0;
	}
	while (Current->next != nullptr)
	{
		Current = Current->next;
		++Size;
	}
	++Size;
	return Size;
}

void DoublyLinkedList::insert(int index, signed short val)
{
	Node* Current = Head;
	int currSize = (int)this->size();

	if (index <= 0)
	{
		//if index is <= 0 then assign the new node as head and copy head's prev ptr Ref.
		Head = new Node(val, nullptr, Current);
		Current->previous = Head;
	}
	if (index >= currSize)
	{
		for (int i = 0; i < currSize - 1; ++i)
		{
			//Traversing
			Current = Current->next;
		}		
		Node* node = new Node(val, Current, nullptr);
		Current->next = node;
		//point current next ptr to the new node
	}
	if (index > 0 && index < currSize)
	{
		for (int i = 0; i < index; ++i)
		{
			Current = Current->next;
		}
		Node* node = new Node(val, Current->previous, Current);
		/*Constrctuor assignes new node's prev ptr to current node's prev ptr 
		and the node's next ptr to Current's address*/
		Current->previous->next = node;
		//change the next ptr of prev node's to the NEW node.
		Current->previous = node;
		//point current prev ptr to the new node

	}

}

void DoublyLinkedList::erase(int index)
{
	int currSize = (int)this->size();

	if (index <= 0)
	{
		Node* Temp = Head->next;
		Head->previous = nullptr;
		delete Head;
		Head = Temp;
	}
	
	if (index > 0 && index < currSize)
	{
		Node* Temp = Head;
		for (int i = 0; i < index-1; ++i)
		{
			Temp = Temp->next;
		}
		//Switch Temp's neigbors ptr's to each other to delete Temp w/o breaking links
		Temp->next->previous = Temp->previous;
		Temp->previous->next = Temp->next;
		delete Temp;
	}
}

int DoublyLinkedList::find(signed short key)
{
	int currSize = (int)this->size();

	Node* Temp = Head;
	for (int i = 0; i < currSize ; ++i)
	{
		if (Temp->data == key)
		{
			//i corresponds with "index" of the KEY
			return i;
		}
		Temp = Temp->next;
	}
	return -1;
}

std::ostream& operator<<(std::ostream& ostr, const DoublyLinkedList& rhs)
{
	Node* Current = rhs.Head;
	ostr << "X ";
	while (Current != nullptr)
	{
		ostr << Current->data << " ";
		Current = Current->next;
	}
	ostr << "X";
	return ostr;
}

