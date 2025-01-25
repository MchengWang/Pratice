#include <iostream>
#include <string>
#include <iomanip>

int main()
{
	int n;
	while (std::cin >> n)
	{
		while (n--)
		{
			int count;
			while (std::cin >> count)
			{
				double* c = new double(), * s = new double(),*temp = new double(), *ci = new double() ,*result = new double();
				std::string* strs = new std::string();
				int* flag = new int();
				while (count--)
				{
					std::cin >> *strs >> *c >> *s;
					if (*s >= 0 && *s <= 60)
					{
						*flag = 1;
					}
					else
					{
						*temp += ((*c) * (*s));
						*ci += *c;
					}
				}

				*result = *temp / *ci;
				if (*flag) std::cout << "Sorry!" << std::endl;
				else std::cout << std::fixed << std::setprecision(2) << *result << std::endl;

				if(n != 0) std::cout << std::endl;

				delete c, s, temp, ci, result;
			}
		}
	}
	return 0;
}