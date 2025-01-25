#include <iostream>

int peach(int n)
{
	int sum = 1;
	for (int i = 1; i < n; i++)
		sum = (sum + 1) * 2;
	return sum;
}

int main()
{
	int n;
	while (std::cin >> n)
		std::cout << peach(n) << std::endl;
	return 0;
}