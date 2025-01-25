#include <iostream>
#include <string>

int main()
{
	int n;
	std::string str = "HDU";
	while (std::cin >> n)
	{
		while (n--)
		{
			int size = 0;
			std::cin >> size;
			int width = str.size() * size;
			for (int i = 0; i < width; i++)
			{
				for (int j = 0; j < size; j++)
					std::cout << str;
				std::cout << std::endl;
			}
		}
	}
	return 0;
}