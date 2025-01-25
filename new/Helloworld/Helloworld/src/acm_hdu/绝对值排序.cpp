#include <iostream>

bool max(int A, int B)
{
	A = A > 0 ? A : -A;
	B = B > 0 ? B : -B;
	return A > B;
}

int main()
{
	int n;
	while (std::cin >> n && n != 0)
	{
		int* nums = new int[n];

		for (int i = 0; i < n; i++)
			std::cin >> nums[i];
		for (int i = 0; i < n; i++)
		{
			for (int j = i; j < n; j++)
			{
				if (!max(nums[i], nums[j]))
				{
					int* temp = new int();
					*temp = nums[i];
					nums[i] = nums[j];
					nums[j] = *temp;
					delete temp;
				}
			}
		}

		std::cout << nums[0];
		for (int i = 1; i < n; i++)
			std::cout << " " << nums[i];
		std::cout << std::endl;

		delete[] nums;
	}
	return 0;
}