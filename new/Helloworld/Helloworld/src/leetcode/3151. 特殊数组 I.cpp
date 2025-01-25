#include <iostream>
#include <vector>

class Solution {
public:
	bool isArraySpecial(std::vector<int>& nums) {
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i - 1] % 2 == nums[i] % 2) {
				return 0;
			}
		}
		return 1;
	}
};

int main()
{
	Solution sol;
	//std::vector<int> nums = {4,3,1,6};
	std::vector<int> nums = {2,1,4};
	std::cout << (bool)sol.isArraySpecial(nums) << std::endl;
	return 0;
}