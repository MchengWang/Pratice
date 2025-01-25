#include <iostream>

int main()
{
	int a, b;
	while (std::cin >> a >> b)
		std::cout << (((a + b) % 86 == 0) ? "yes" : "no") << std::endl;
	return 0;
}