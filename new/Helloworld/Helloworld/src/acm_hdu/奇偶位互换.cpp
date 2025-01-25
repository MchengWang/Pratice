#include <iostream>
#include <string>

int main()
{
	int n;
	while (std::cin >> n)
	{
		while (n--)
		{
			std::string strs;
			std::cin >> strs;

			std::string str;
			for (int i = 0; i < strs.length(); i+=2)
			{
				if (i % 2 == 0 || i == strs.length())
				{
					if(i + 1 < strs.length())str.push_back(strs.at(i + 1));
					str.push_back(strs.at(i));
				}
			}

			std::cout << str << std::endl;
		}
	}
	return 0;
}