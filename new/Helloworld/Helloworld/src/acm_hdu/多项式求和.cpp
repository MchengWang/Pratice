#include<iostream>

int main()
{
	int m, n;
	int i, count;
	double sum;
	int f;
	std::cin >> m;
	while (m--)
	{
		f = 1;
		sum = 0;
		std::cin >> n;
		for (i = 1, count = 1; count <= n; count++, i++)
		{
			sum += 1.0 / i * f;
			f = -f;
		}
		printf("%.2f\n", sum);
	}
	return 0;
}

