#include <iostream>

int main()
{
	int t;
	while (std::cin >> t)
	{
		while (t--)
		{
			int n, k;
			while (std::cin >> n >> k)
			{
				int* nums = new int[n];
				int count = 0;
				for (int i = 0; i < n; i++)
					std::cin >> nums[i];

				for (int i = 0; i < n; i++)
					if (nums[i] > nums[k - 1]) count++;
				std::cout << count << std::endl;
			}
		}
	}
	return 0;
}