#include <iostream>
#include <string>

int main()
{
	int n;
	while (std::cin >> n)
	{
		while (n--)
		{
			std::string str1, str2;
			std::cin >> str1 >> str2;
			int i = str1.size() / 2;
			str1.insert(i, str2);

			std::cout << str1 << std::endl;
		}
	}
	return 0;
}