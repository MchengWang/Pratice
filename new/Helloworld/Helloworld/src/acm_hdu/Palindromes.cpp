#include <iostream>
#include <string>

int main()
{
	std::string strs;
	int count = 1;
	while (std::cin >> strs)
	{
		std::string* temp = new std::string();
		*temp = strs;
		std::reverse(strs.begin(), strs.end());
		
		if (!strs.compare(*temp)) std::cout << "#" << count++ << ": " << "YES" << std::endl;
		else std::cout << "#" << count++ << ": " << "NO" << std::endl;

		if (*temp == "STOP") break;

		delete temp;
 	}
	return 0;
}