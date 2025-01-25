#include <vector>
#include <iostream>

class Solution {
public:
	double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {

		bool flag1 = nums1.size() % 2 == 0;
		bool flag2 = nums2.size() % 2 == 0;

		if (!nums1.empty() && !nums2.empty())
		{
			std::vector<int> vecs = InsertSort(nums1, nums2);
			if (vecs.size() % 2 == 0) return (double)(vecs[vecs.size() / 2] + vecs[(vecs.size() / 2) - 1]) / 2;
			else return (double)vecs[vecs.size() / 2];
		}
		else
		{
			if (nums1.empty()) return (flag2 ? (double)(nums2[nums2.size() / 2] + nums2[(nums2.size() / 2) - 1]) / 2 : (double)nums2[nums2.size() / 2]);
			if (nums2.empty()) return (flag1 ? (double)(nums1[nums1.size() / 2] + nums1[(nums1.size() / 2) - 1]) / 2 : (double)nums1[nums1.size() / 2]);

			if (nums1.empty() && nums2.empty()) return 0;
		}
		return 0;
	}

	std::vector<int> InsertSort(std::vector<int>& num1, std::vector<int>& num2)
	{
		std::vector<int> vecs = {};
		int i = 0, j = 0; // ±È¿˙±Í÷æ
		while (i < num1.size() && j < num2.size())
		{
			if (num1[i] <= num2[j])
			{
				vecs.push_back(num1[i]);
				i++;
			}
			else if (num1[i] > num2[j])
			{
				vecs.push_back(num2[j]);
				j++;
			}
		}

		if (i < num1.size())
			for (int k = i; k < num1.size(); k++)
				vecs.push_back(num1[k]);

		if (j < num2.size())
			for (int k = j; k < num2.size(); k++)
				vecs.push_back(num2[k]);

		return vecs;
	}
};

int main()
{
	std::vector<int> nums1 = {1,2};
	std::vector<int> nums2 = {};

	/*std::cout << nums1.size() << " " << nums2.size() << std::endl;*/
	Solution sol;
	std::vector<int> test = sol.InsertSort(nums1, nums2);
	for (int i = 0; i < test.size(); i++)
		std::cout << test[i] << " ";
	std::cout << std::endl;
	//std::cout << test.size() << std::endl;
	std::cout << sol.findMedianSortedArrays(nums1, nums2) << std::endl;
	return 0;
}