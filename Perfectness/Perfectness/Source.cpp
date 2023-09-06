#include <iomanip>
#include <iostream>

bool Perfectness(int n)
{
	int sum = 0;
	for (int i = 1; i < n; ++i)
	{
		if (n% i == 0)
		{
			sum += i;
		}
	}
	if (sum == n)
	{
		return true;
	}
	return false;
}

int main()
{
	for (int i = 1; i <= 10000; ++i)
	{
		bool result = Perfectness(i);
		if (result == true)
		{
			std::cout << i << std::endl;
		}
	}

	system("PAUSE");
	return 0;
}

