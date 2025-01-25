#include <iostream>

int main()
{
	int n;

	while (std::cin >> n && n != 0)
	{
		int* nums = new int[n]();
		int imin = 0;
		for (int i = 0; i < n; i++)
			std::cin >> nums[i];

		for (int i = 1; i < n; i++)
		{
			if (nums[imin] > nums[i]) imin = i;
		}

		int* temp = new int;
		*temp = nums[0];
		nums[0] = nums[imin];
		nums[imin] = *temp;

		std::cout << nums[0];
		for (int i = 1; i < n; i++)
			std::cout << " " << nums[i];
		std::cout << std::endl;

		delete[] nums;
		delete temp;
	}
	return 0;
}