#include <iostream>
#include <iomanip>

#define pi 3.1415927

int main()
{
	double num;
	while (std::cin >> num)
	{
		num = (4 * num * num * num * pi) / 3;
		std::cout << std::fixed << std::setprecision(3) << num << std::endl;
	}
	return 0;
}