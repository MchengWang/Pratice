#include <iostream>
#include <iomanip>


int main()
{
	int n;
	while (std::cin >> n && n > 2 && n <= 100)
	{
		int min = 100, max = 0;
		double num , result = 0;
		for (int i = 0; i < n; i++)
		{
			std::cin >> num;
			result += num;
			if (num < min) min = num;
			if (num > max) max = num;
		}

		result = result - min - max;
		result = result * 1.0 / (n - 2);

		std::cout << std::fixed << std::setprecision(2) << result << std::endl;
	}
	return 0;
}