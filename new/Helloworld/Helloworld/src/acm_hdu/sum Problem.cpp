#include <iostream>

long long sum(long long nums)
{
	auto num = new long long();
	*num = nums + 1;
	return (nums * *num) / 2;
}

int main()
{
	long long num;
	while (std::cin >> num)
	{
		std::cout << sum(num) << std::endl;
		std::cout << std::endl;
	}
	return 0;
}