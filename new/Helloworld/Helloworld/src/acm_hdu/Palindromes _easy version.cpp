#include <iostream>
#include <string>

int main()
{
	int n;
	while (std::cin >> n)
	{
		while (n--)
		{
			getchar();
			std::string str;
			std::cin >> str;
			int flag = 1;
			for (int i = 0; i < str.size() / 2; i++)
			{
				if (str[i] != str[str.size() - i - 1]) {
					std::cout << "no" << std::endl;
					flag = 0;
					break;
				}
			}

			if (flag == 1) std::cout << "yes" << std::endl;
		}
	}
	return 0;
}