#include<stdio.h>
#include<iostream>


void Merge(int A[], int const Start, int const middle, int const Size)
{

	int* L = new int[middle - Start + 1];
	int* R = new int[Size - middle];

	for (int i = 0; i < middle - Start + 1; i++)
		L[i] = A[Start + i];
	for (int j = 0; j < Size - middle; j++)
		R[j] = A[middle + 1 + j];

	
	int i = 0;
	int j = 0;
	int k = Start;
	while (i < middle - Start + 1 && j < Size - middle)
	{
		if (L[i] <= R[j])
		{
			A[k] = L[i];
			i++;
		}
		else
		{
			A[k] = R[i];
			j++;
		}
		k++;
	}
	while (i < middle - Start + 1)
	{
		A[k] = L[i];
		i++;
		k++;
	}
	while (j < Size - middle)
	{
		A[k] = R[j];
		j++;
		k++;
	}
}
void Merge_sort(int A[], int const Start , int const Size)
{
	
	if (Start >= Size)
	{
		return;
	}
	int middle = Start + ((Size - Start) / 2);
	Merge_sort(A, Start, middle);
	Merge_sort(A, middle + 1, Size);
	Merge(A, Start, middle, Size);
}


int main() {

	int Arr[6] = {9,4,3,5,8,2};
	Merge_sort(Arr, 0, 5);
	for (int i = 0; i < 6; i++)
	{
		std::cout << Arr[i] << std::endl;
	}

	return 0;
}