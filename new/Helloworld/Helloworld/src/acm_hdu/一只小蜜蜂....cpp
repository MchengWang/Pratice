#include <iostream>
#include <cmath>

int main()
{
	int n;
	while (std::cin >> n)
	{
		while (n--)
		{
			int n, m;
			std::cin >> n >> m;
			int j = 0;
			for (int i = n; i < m; i += 2)
				j++;
			int s = pow(2, j);
			std::cout << s + 1 << std::endl;
		}
	}
	return 0;
}