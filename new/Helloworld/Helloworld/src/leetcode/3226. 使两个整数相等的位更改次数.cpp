#include <iostream>
#include <bit>

class Solution
{
public:
	int minChanges(int n, int k)
	{
		return (n & k) == k ? std::popcount(1u * n ^ k) : -1;
	}
};

int main()
{
	Solution sol;
	std::cout << sol.minChanges(13, 4) << std::endl;
	std::cin.get();
}