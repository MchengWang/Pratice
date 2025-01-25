#include <iostream>
#include <string>

#define MAX 1000001

int main()
{
	int* arrs = new int[MAX]();
	long n, m;
	for (long i = 1; i <= MAX; i++)
	{
		long temp = i;
		while (temp > 0)
		{
			if (temp % 10 == 4 || temp % 100 == 62)
				arrs[i] = 1;
			temp /= 10;
		}
	}

	while (std::cin >> n >> m && (n || m))
	{
		int length = m - n + 1;
		for (long i = n; i <= m; i++)
			if (arrs[i] == 1) length--;

		std::cout << length << std::endl;
	}
	return 0;
}