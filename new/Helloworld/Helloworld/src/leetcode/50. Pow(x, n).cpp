#include <iostream>
#include <iomanip>

class Solution
{
public:
	double myPow(double x, int n)
	{
		double result = (double)x;
		bool flag = 1;
		if (n < 0)
		{
			flag = 0;
			n = -n;
		}
		if (n == 0) return (double)1;
		if (x == 1 || x == 0) return x;
		if (n > INT_MAX || n < INT_MIN) return 
		for (int i = 1; i < n; i++)
			result *= x;
		if (!flag)
			result = (1 / result);
		return result;
	}
};

int main()
{
	Solution sol;
	std::cout << sol.myPow(2, 10) << std::endl;
	std::cout << sol.myPow(2.1000, 3) << std::endl;
	return 0;
}