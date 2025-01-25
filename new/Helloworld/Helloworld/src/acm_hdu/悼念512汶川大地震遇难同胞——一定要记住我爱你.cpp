#include <iostream>

int main()
{
	int c;
	while (std::cin >> c)
	{
		while (c--)
		{
			int n;
			std::cin >> n;
			int* a = new int(), * b = new int(), * c = new int(), * count = new int();
			*a = n / 2;
			*b = ((n - (*a)) * 2) / 3;
			*c = n - *a - *b;

			if (*a % 10 == 0) *count += (*a / 10);
			else *count += ((*a / 10) + 1);
			if (*b % 10 == 0) *count += (*b / 10);
			else *count += ((*b / 10) + 1);
			if (*c % 10 == 0) *count += (*c / 10);
			else *count += ((*c / 10) + 1);

			std::cout << *count << std::endl;
		}
	}
	return 0;
}