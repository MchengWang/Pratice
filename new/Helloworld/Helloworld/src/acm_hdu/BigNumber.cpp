#include <iostream>

int main()
{
	__int64 a , b;
	while (std::cin >> a >> b)
	{
		std::cout << (a % b) << std::endl;
	}
	return 0;
}