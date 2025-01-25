#include <iostream>
#include <iomanip>

int main()
{
	int n;
	while (std::cin >> n)
	{
		while (n--)
		{
			int* count = new int();
			double* max = new double(0.00);

			std::cin >> *count;
			double* nums = new double[*count];

			for (int i = 0; i < *count; i++)
			{
				std::cin >> nums[i];
				if (nums[i] > *max) *max = nums[i];
			}

			std::cout << std::fixed << std::setprecision(2) << *max << std::endl;

			delete max , count;
			delete[] nums;
		}
	}
	return 0;
}