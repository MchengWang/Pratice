#include <iostream>

int main()
{
	int n;
	while (std::cin >> n && n != 0)
	{
		__int32* a = new __int32() , *max = new __int32();
		while (n--)
		{
			std::cin >> *a;
			if (*a > *max)
			{
				*max = *a;
			}
		}
		std::cout << *max << std::endl;

		delete a, max;
	}
	return 0;
}