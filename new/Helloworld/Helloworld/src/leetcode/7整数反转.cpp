#include <iostream>


class Solution {
public:
	int reverse(int x) {
		long long n = 0;
		if (x == 0) return 0;
		while (x % 10 == 0) 
			x = x / 10;//去掉后缀零
		while (x != 0) { //无论对正数还是负数同样适用
			n = n * 10 + x % 10;//将x的每一次个位数加到n里
			x = x / 10;
		}
		if (n <= -2147483648 || n >= 2147483647) return 0;
		return n;
	}
};

int main()
{
	Solution sol;
	std::cout << sol.reverse(1534236469) << std::endl;
	return 0;
}