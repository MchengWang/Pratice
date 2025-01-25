#include <iostream>

int main()
{
	int n;
	while (std::cin >> n)
	{
		while (n--)
		{
			double y, q, e, f, g;
			std::cin >> y >> q >> e >> f >> g;
			std::cout << (y * (1 + e / 100 * q / 365)) * (1 + g / 100) << std::endl;
			std::cout << y * (1 + f / 100 * (q + 365) / 365) << std::endl;
		}
	}
	return 0;
}