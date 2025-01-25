#include <iostream>
#include <string>

int main()
{
	int n;
	while (std::cin >> n)
	{
		while (n--)
		{
			char* chs = new char[11];
			std::string* strs = new std::string();
			getchar();
			strs->push_back('6');
			std::cin >> chs;
			for (int i = 6; i < strlen(chs); i++)
			{
				strs->push_back(chs[i]);
			}

			std::cout << *strs << std::endl;
		}
	}
	return 0;
}