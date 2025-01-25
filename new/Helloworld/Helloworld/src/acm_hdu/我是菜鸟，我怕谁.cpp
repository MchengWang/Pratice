#include <iostream>

int main()
{
	int t;
	while (std::cin >> t)
	{
		while (t--)
		{
			int n, volecity = 1 , distance = 1;
			std::cin >> n;

			if (n != 1)
			{
				for (int i = 2; i <= n; i++)
				{
					volecity += 2;
					distance += volecity;
				}
			}
				

			std::cout << (distance % 10000) << std::endl;
		}
	}
	return 0;
}