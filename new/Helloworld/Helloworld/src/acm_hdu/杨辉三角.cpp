#include <iostream>

int main()
{
	int n;
	while (std::cin >> n)
	{
		int** nums = new int* [n];
		for (int i = 0; i < n; i++)
			nums[i] = new int[n];

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				nums[i][j] = 1;
				if (i > 1 && j > 0 && j < i)
				{
					nums[i][j] = nums[i - 1][j - 1] + nums[i - 1][j];
				}
			}
		}

		for (int i = 0; i < n; i++)
		{
			int* temp = new int{0};
			for (int j = 0; j <= i; j++)
			{
				if (j == *temp) std::cout << nums[i][j];
				else std::cout << " " << nums[i][j];
			}
			std::cout << std::endl;
			delete temp;
			delete[] nums[i];
		}

		delete[] nums;
	}
	return 0;
}