#include <iostream>

int main()
{
	char a, b , c , d , t ;

	while (std::cin >> a >> b >> c)
	{
		if (a > b)
		{
			d = a;
			a = b;
			b = d;
		}
		if (a > c)
		{
			d = a;
			a = c;
			c = d;
		}
		if (b > c)
		{
			t = b;
			b = c;
			c = t;
		}
		std::cout << a << " " << b << " " << c << std::endl;
	}
	
	return 0;
}