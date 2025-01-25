#include <iostream>
#include <string>

int main()
{
	std::string str;
	while (getline(std::cin, str))
	{
		std::string* tstr = new std::string();
		int* max = new int(0);
		for (int i = 0; i < str.size(); i++)
			if (str[i] > *max) *max = str[i];

		for (int i = 0; i < str.size(); i++)
		{
			tstr->push_back(str[i]);
			if (str[i] == *max) {
				tstr->append("(max)");
			}
		}

		std::cout << *tstr << std::endl;
		delete max;
		delete tstr;
	}
	return 0;
}