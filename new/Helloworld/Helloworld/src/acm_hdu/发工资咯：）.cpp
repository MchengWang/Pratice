#include <iostream>

int money[6] = { 100,50,10,5,2,1 };

int main()
{
	int n;
	while (std::cin >> n && n != 0)
	{
		int wage , x = 0;
		while (n--)
		{
			std::cin >> wage;
			for (int i = 0; i < 6; i++)
			{
				if (wage >= money[i])
				{
					x += (wage / money[i]);
					wage %= money[i];
				}
			}
		}
		std::cout << x << std::endl;
	}
	return 0;
}