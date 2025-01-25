#include <iostream>
#include <string>

int main()
{
	int n, m;
	while (std::cin >> n >> m)
	{
		int sum = 1;
		int temp = 0;
		for (int i = 0; i < m; i++)
		{
			if (sum == 0)
			{
				temp = 0;
				break;
			}

			sum *= 10;
			temp = sum / n;
			sum %= n;
		}

		std::cout << temp % 10 << std::endl;
	}
	return 0;
}