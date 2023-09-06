#include <stdio.h>
#include <iostream>
#include <ctime> 
#include<array>


void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}



int Partition(int A[], int Start, int end)
{
	int x = A[end];
	int i = Start - 1;							// i = partition index, draws the boundry for A[end]; on the left side are values <= pivot and on the right side are values > pivot.
	for (int j = Start; j <= end - 1; j++)
	{
		if (A[j] <= x)// traverse and compare to end element
		{
			i++;
			swap( &A[i], &A[j]); // if end element id greater then swap 
			
		}
	
	}
	swap(&A[i+1], &A[end]);

	return (i+1);
}

void quicksort(int A[], int Start, int end) // p is first index of first element and r is the index of last element
{
	if (Start < end)
	{
		int Pivot = Partition(A, Start, end);  // Pivot
		quicksort(A, Start, Pivot - 1);		// from start to pivot
		quicksort(A, Pivot+1, end);		// from pivot + 1 to end 
	}
}
int main() {

	int Size = 10;													//{ random array intializing
	int array[10] = { 6,4,8,7,1,3,9,2,5,10 }; //Dynamic memmory allocation
	srand((unsigned)time(0));
	/*for (int i = 0; i < Size; i++) {
		array[i] = i;								//}
	}*/

																	//{Print out array before quick-sorting
	for (int i = 0; i < Size; i++)
	{
		std::cout << array[i] << std::endl;
	}
	std::cout << "______________________" << std::endl;				//}
															
	quicksort(array, 0,Size-1);											// Quick-sort
		
	for (int i = 0; i < Size; i++)										//{Print out array before quick-sorting
	{
		std::cout << array[i]<< std::endl;
	}
	
	return 0;//delete  dynamic array!



}