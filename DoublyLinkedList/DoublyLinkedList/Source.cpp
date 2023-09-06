#include "DoublyLinkedList.h"


int main()
{

	DoublyLinkedList First;
	First.push_front(1);
	First.push_front(2);
	First.push_front(3);	
	First.insert(0, 4);
	First.insert(5, 5);	
	std::cout << First << std::endl;
	std::cout << std::endl;
	First.pop_front();
	First.erase(15);
	First.erase(2);
	std::cout << First << std::endl;
	std::cout << std::endl;

	std::cout << "at 0 = " << First[0] << ", at 2 = " << First[2] << std::endl;
	std::cout << "This list is EMPTY : " << (First.empty() ? "TRUE" : "FALSE") << std::endl;
	std::cout << "# data 7 is at index " << First.find(7) << std::endl;
	std::cout << "# data 5 is at index " << First.find(5) << std::endl;
	std::cout << "Size is " << First.size() << std::endl;
	First.~DoublyLinkedList();

	//Second TEST for all possible cases.
	std::cout << std::endl;
	std::cout << "Second TEST"<< std::endl;
	std::cout << std::endl;

	DoublyLinkedList Second;
	Second.push_front(2);
	Second.insert(15, 6);
	std::cout << Second << std::endl;
	std::cout << std::endl;
	Second.pop_front();
	Second.erase(0);

	std::cout << Second << std::endl;
	std::cout << std::endl;

	std::cout << "at 1 = " << Second[1] << ", at 2 = " << Second[2] << std::endl;
	std::cout << "Is the list Empty? " << (Second.empty() ? "TRUE" : "FALSE") << std::endl;
	std::cout << "Size is " << Second.size() << std::endl;




}
