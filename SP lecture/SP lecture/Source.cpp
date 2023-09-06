#include <stdlib.h>
#include<iostream>
int main()
{
	int iarr[100];
	void* p = iarr;
	int q = *(int*)((char*)p + 50 * sizeof(int*));
	std::cout << q << std::endl;
	return 0;
}