#include <iostream>

class Solution {
public:
	int getTotal(int num)
	{
		int total = 0;
		int ge = 0;
		while (num)
		{
			ge = num % 10;
			num /= 10;

			total += (ge * ge);
		}
		return total;
	}

	bool isHappy(int n) {
		int total = 0;
		int flag = 0;
		int count = 0;
		while (total != 1 && count <= 100)
		{
			total = getTotal(n);
			if (total != 1)
			{
				n = total;
				count++;
			}

			if (total == 1) flag = 1;
		}
		return flag;
	}
};

int main()
{
	int num;
	Solution sol;
	std::cout << sol.isHappy(19) << std::endl;
	std::cout << sol.isHappy(2) << std::endl;
	return 0;
}