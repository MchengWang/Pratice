#include <iostream>

int main()
{
	__int64 nums[51];
	nums[0] = 0;
	nums[1] = 1;

	for (int i = 2; i <= 50; i++)
		nums[i] = nums[i - 1] + nums[i - 2];

	int n;
	while (std::cin >> n && n != -1)
		std::cout << nums[n] << std::endl;
	return 0;
}	