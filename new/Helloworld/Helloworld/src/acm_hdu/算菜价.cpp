#include <iostream>
#include <string>
#include <iomanip>

int main()
{
	std::string strs;
	double count, price, sum = 0;
	while (std::cin >> strs >> count >> price)
		sum += count * price;
	std::cout << std::fixed << std::setprecision(1) << sum << std::endl;
	return 0;
}