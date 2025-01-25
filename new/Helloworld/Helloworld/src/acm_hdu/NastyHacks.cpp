#include <iostream>
#include <string>

int main()
{
	int n;
	while (std::cin >> n)
	{
		while (n--)
		{
			int r, e, c;
			std::cin >> r >> e >> c;
			if (r == (e - c)) std::cout << "does not matter" << std::endl;
			else if (r > (e - c)) std::cout << "do not advertise" << std::endl;
			else std::cout << "advertise" << std::endl;
		}
	}
	return 0;
}