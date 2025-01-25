#include <iostream>

int main()
{
	int count, num;

	while (std::cin >> count)
	{
		int result = 1;
		for (int i = 0; i < count; i++)
		{
			std::cin >> num;
			if (num % 2 != 0)
			{
				result *= num;
			}
		}
		std::cout << result << std::endl;
	}

	
	return 0;
}