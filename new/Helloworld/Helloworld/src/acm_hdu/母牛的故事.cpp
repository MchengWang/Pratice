#include <iostream>

int cow(int year)
{
	if (year == 1 || year == 2 || year == 3 || year == 4) return year;
	
	return cow(year - 1) + cow(year - 3);
}

int main()
{
	int num;
	
	while (std::cin >> num && num != 0)
	{
		std::cout << cow(num) << std::endl;
	}

	return 0;
}