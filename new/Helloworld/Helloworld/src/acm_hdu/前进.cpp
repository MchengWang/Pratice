#include <iostream>

int main()
{
	int c;
	while (std::cin >> c)
	{
		while (c--)
		{
			int n , B = 0;
			std::cin >> n;
			while (n != 0)
			{
				if (n % 2 != 0)
				{
					n -= 1;
					B++;
				}
				else
				{
					n -= 2;
				}
			}

			std::cout << B << std::endl;
		}
	}
	return 0;
}