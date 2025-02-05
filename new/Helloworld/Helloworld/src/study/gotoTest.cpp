#include <iostream>

int main()
{
	int a = 0;

	if (a == 0)
		goto B;

	std::cout << " shshs " << std::endl;

B:
	a = 3;

	std::cout << a << std::endl;

	return 0;
}