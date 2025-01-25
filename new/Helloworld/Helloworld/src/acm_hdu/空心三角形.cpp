#include <iostream>

int main()
{
	char x;
	int n;
	while (std::cin >> x && x != '@')
	{
		std::cin >> n;
		for (int i = 1; i <= n; i++)
		{
			int length = 2 * n - 1;
			if (i != n)
			{
				for (int j = 1; j <= length; j++)
				{
					if (j == n - i + 1 || j == length - (n - i)) std::cout << x;
					else std::cout << ' ';
				}
			}
			else
			{
				for (int j = 1; j <= length; j++)
				{
					std::cout << x;
				}
			}
			std::cout << std::endl;
		}
	}
	return 0;
}