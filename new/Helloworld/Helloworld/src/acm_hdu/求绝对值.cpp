#include <iostream>
#include <iomanip>

int main()
{
	double num;
	while (std::cin >> num)
	{
		num = num > 0 ? num : -num;
		std::cout << std::fixed << std::setprecision(2) <<  num << std::endl;
	}
	return 0;
}