#include <iostream>
#include <string>

int main()
{
	std::string strs;
	int flag = 0;
	while (std::cin >> strs)
	{
		int result = 0;
		for (int i = 0; i < strs.length(); i++)
		{
			if (strs.at(i) % 2 == 0) result += (strs.at(i) - 48);
		}
		std::cout << result << std::endl;
		if (!flag)
		{
			std::cout << std::endl;
			flag = 1;
		}
		if (!flag) flag = 1;
	}
	return 0;
}

int main1()
{
	std::cout << (int) '0' << std::endl; // 48
	std::cout << (int) '1' << std::endl; // 49
	std::cout << (int) '2' << std::endl; // 50
	std::cout << (int) '3' << std::endl; // 51
	std::cout << (int) '4' << std::endl; // 52
	std::cout << (int) '5' << std::endl; // 53
	std::cout << (int) '6' << std::endl; // 54
	std::cout << (int) '7' << std::endl; // 55
	std::cout << (int) '8' << std::endl; // 56
	std::cout << (int) '9' << std::endl; // 57
}