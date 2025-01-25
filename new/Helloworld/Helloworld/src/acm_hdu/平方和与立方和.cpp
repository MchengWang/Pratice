#include<iostream>
#include<cmath>

int main()
{
	int m, n;
	while (std::cin >> m >> n) 
	{
		if (m > n) std::swap(m, n);
		int odd = 0, even = 0;
		for (int i = m; i <= n; i++) 
		{
			if (i % 2 == 1) odd += pow(i, 3);
			else even += pow(i, 2);
		}
		std::cout << even << " " << odd << std::endl;
	}
	return 0;
}
