#include <iostream>
#include <vector>

class Solution {
public:
	int maxUncrossedLines(std::vector<int>& nums1, std::vector<int>& nums2) {
		int linear = 0;
		int index = -1;
		for (int i = 0; i < nums1.size(); i++)
		{
			for (int j = 0; j < nums2.size(); j++)
			{
				if (nums1[i] == nums2[j] && j >= index)
				{
					index = j;
					linear++;
					break;
				}
			}
		}
		return linear;
	}
};

int main()
{
	/*std::vector<int> nums1 = { 1,4,2,4,5,6 };
	std::vector<int> nums2 = { 1,2,4,5,6,4 }; */

	/*std::vector<int> nums1 = { 3,3 };
	std::vector<int> nums2 = { 1,3,1,2,1 };*/

	/*std::vector<int> nums1 = { 1,3,7,1,7,5 };
	std::vector<int> nums2 = { 1,9,2,5,1 };*/

	/*std::vector<int> nums1 = { 2,3,1 };
	std::vector<int> nums2 = { 3,1,3,3,3,3 };*/

	std::vector<int> nums1 = { 1,1,2,1,2 };
	std::vector<int> nums2 = { 1,3,2,3,1 };

	Solution sol;
	printf("%d", sol.maxUncrossedLines(nums1, nums2));
	return 0;
}