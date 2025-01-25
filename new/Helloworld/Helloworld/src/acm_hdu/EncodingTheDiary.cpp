#include <iostream>
#include <string>

void DelSpaceFromString(std::string& str)
{
	for (int i = 0; i < str.size(); i++)
		if (str[i] == ' ') str.erase();
}

int main()
{
	std::string str = "sdfa sss dd aad";
	DelSpaceFromString(str);
	std::cout << str << std::endl;
	std::cin.get();
}