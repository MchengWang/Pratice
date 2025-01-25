#include <iostream>
#include <string>

int main()
{
	int n , count;
	std::string strs;

	std::cin >> n;
	while (n--)
	{
		count = 0;
		std::cin >> strs;
		for (int i = 0; i < strs.length(); i++)
		{
			if (isdigit(strs[i])) count++;
		}
		std::cout << count << std::endl;
	}
	return 0;
}