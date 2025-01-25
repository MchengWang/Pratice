#include <iostream>
#include <string>
#include <cmath>

int main()
{
	int n, m;
	while (std::cin >> n >> m &&( n != 0 || m != 0))
	{
		if (n >= -10000 && n <= 10000 && m >= -10000 && m <= 10000)
		{
			int a = n * n - 4 * m;
			int temp = (int) sqrt(a);
			if (temp * temp == a) std::cout << "Yes" << std::endl;
			else std::cout << "No" << std::endl;
		}
	}
	return 0;
}