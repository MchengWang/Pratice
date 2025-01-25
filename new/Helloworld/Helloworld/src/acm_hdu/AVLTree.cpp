#include <iostream>
#define MAXELEMENT 50

int height[MAXELEMENT];	

int main()
{
	height[0] = 1;
	height[1] = 2;

	for (int i = 2; i < MAXELEMENT; i++)
		height[i] = height[i - 1] + height[i - 2] + 1;
	
	int n;
	while (std::cin >> n && n != 0)
	{
		int depth = 0;
		for (int i = 0; i < MAXELEMENT; i++)
		{
			if (n >= height[i]) depth = i;
			else break;
		}

		std::cout << depth << std::endl;
			
	}
	return 0;
}