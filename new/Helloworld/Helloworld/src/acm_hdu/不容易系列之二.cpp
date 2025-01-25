#include <iostream>

int main()
{
	int n;
	while (std::cin >> n)
	{
		while (n--)
		{
			int* a = new int();
			std::cin >> *a;

			int* count = new int(3);
			for (int i = *a; i > 0; i--)
			{
				*count = ((*count - 1) * 2);
			}

			std::cout << *count << std::endl;

			delete a, count;
		}
	}
	return 0;
}