#include <iostream>
#include <string>

int main()
{
	int n;
	while (std::cin >> n)
	{
		while (n--)
		{
			int *a = new int(), *b = new int(), *c = new int(), *d = new int();
			char* chs = new char[50];
			std::cin >> chs;

			if (strlen(chs) <= 16 && strlen(chs) >= 8)
			{
				for (int i = 0; i < strlen(chs); i++)
				{
					if (chs[i] >= 97 && chs[i] <= 122) (*a)++;
					else if (chs[i] >= 65 && chs[i] <= 90) (*b)++;
					else if (chs[i] >= 48 && chs[i] <= 57) (*c)++;
					else if (chs[i] == 126 || chs[i] == 33 || chs[i] == 64 || chs[i] == 35 || chs[i] == 36 || chs[i] == 37 || chs[i] == 94)
						(*d)++;
				}
			}


			if (*b > 0 && *c > 0 && *d > 0) std::cout << "YES" << std::endl;
			else if (*a > 0 && *c > 0 && *d > 0) std::cout << "YES" << std::endl;
			else if (*a > 0 && *b > 0 && *d > 0) std::cout << "YES" << std::endl;
			else if (*a > 0 && *b > 0 && *c > 0) std::cout << "YES" << std::endl;
			else std::cout << "NO" << std::endl;

			delete a, b, c, d;
			delete[] chs;
		}
	}
	return 0;
}

int main()
{
	std::cout << (int)'a' << " " << (int)'z' << std::endl;
	std::cout << (int)'A' << " " << (int)'Z' << std::endl;
	std::cout << (int)'0' << std::endl;
	std::cout << (int)'1' << std::endl;
	std::cout << (int)'2' << std::endl;
	std::cout << (int)'3' << std::endl;
	std::cout << (int)'4' << std::endl;
	std::cout << (int)'5' << std::endl;
	std::cout << (int)'6' << std::endl;
	std::cout << (int)'7' << std::endl;
	std::cout << (int)'8' << std::endl;
	std::cout << (int)'9' << std::endl;
	std::cout << (int)'~' << std::endl;
	std::cout << (int)'!' << std::endl;
	std::cout << (int)'@' << std::endl;
	std::cout << (int)'#' << std::endl;
	std::cout << (int)'$' << std::endl;
	std::cout << (int)'%' << std::endl;
	std::cout << (int)'^' << std::endl;
}