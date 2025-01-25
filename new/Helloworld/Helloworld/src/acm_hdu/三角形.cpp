#include <iostream>
#include <string>

int main()
{
	int n;
	std::cin >> n;
	while (n--)
	{
		int *a = new int(), * b = new int(), * c = new int();
		std::cin >> *a >> *b >> *c;
		int* temp = new int();
		if (*a > *b)
		{
			*temp = *a;
			*a = *b;
			*b = *temp;
		}
		if (*b > *c)
		{
			*temp = *b;
			*b = *c;
			*c = *temp;
		}
		if (*a > *c)
		{
			*temp = *a;
			*a = *c;
			*c = *temp;
		}

		if ((*a * *a) * (*b * *b) == (*c * *c) || *a == *b && *b == *c) std::cout << "YES" << std::endl;
		else std::cout << "NO" << std::endl;
	}
	return 0;
}

#include<iostream>

int main()
{
	int m;
	std::cin >> m;
	while (m--)
	{
		double a, b, c;
		std::cin >> a >> b >> c;
		if ((a + b) > c && (a + c) > b && (b + c) > a)
		{
			std::cout << "YES" << std::endl;
		}
		else
			std::cout << "NO" << std::endl;
	}
	return 0;
}