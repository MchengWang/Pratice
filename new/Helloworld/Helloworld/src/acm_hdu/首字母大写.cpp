#include <iostream>
#include <string>

void change(char& ch)
{
	ch -= 32;
}

int main()
{
	char* chs = new char[101];
	while (std::cin.getline(chs, 101))
	{
		change(chs[0]);
		for (int i = 0; i < strlen(chs); i++)
			if (chs[i - 1] == ' ') change(chs[i]);
		for (int i = 0; i < strlen(chs); i++)
			std::cout << chs[i];
		std::cout << std::endl;
	}
	delete[] chs;
	return 0;
}