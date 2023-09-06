#include <iostream>
#include <iomanip>

void  Insertion_sort(int a[], int x)
{
	int key, j;
	for (int i = 1; i < x; ++i)
	{
		key = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > key)
		{
			a[j + 1] = a[j];
			--j;
		}
		a[j + 1] = key;
	}
	

}

int main()
{
	const int  SIZE = 4;
	int a[SIZE] = {5,4,3,6};
	Insertion_sort(a, SIZE);

	
	std::cout << a[0] << a[1]<< a[2] << a[3] << std::endl;
	

	system("PAUSE");
	return 0;
}