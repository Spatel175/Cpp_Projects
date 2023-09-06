//Sujad Patel
// Assigment 1 Van Eck Sequence

#include <iomanip>
#include <iostream>
int main ()
{
	int A[10] = {};
	for (int i = 0; i < 10; i++)
	{	
		int counter = 0;

		if (i == 0) {
			A[i] = 0;
		}
		else
		{
			for (int j = i; j > 0; j--) {
				if (A[i - 1] == A[j -1]) {
					A[i + 1] = j;
					counter++;
					break;
				}
			}
			if (!counter) {
				A[i + 1] = 0;
				counter--;
			}
		}
		
		
	}

	for (int k = 0; k < 10; k++)
	{
		std::cout << A[k] << std::endl;
	}
	

	system("PAUSE");
	return 0;

}

