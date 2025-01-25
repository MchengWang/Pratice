#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	/* 初始化列表 */
	// 需注意， C++ 中 vector 即是文本描述的 nums
	// 无初始值
	std::vector<int> nums1;
	// 有初始值
	std::vector<int> nums = { 1, 3, 2, 5, 4 };

	/* 访问元素 */
	int num = nums[1]; // 访问索引 1 处的元素
	
	/* 更新元素 */
	nums[1] = 0; // 索引 1 处的元素更新为0

	/* 清空列表 */
	nums.clear();

	/* 在尾部添加元素 */
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(5);
	nums.push_back(4);

	/* 在中间插入元素 */
	nums.insert(nums.begin() + 3, 6); // 在索引 3 处插入数字 6

	/* 删除元素 */
	nums.erase(nums.begin() + 3); // 删除索引 3 处的元素

	/* 通过索引遍历列表 */
	int count = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		count += nums[i];
	}

	/* 直接遍历列表元素 */
	count = 0;
	for (int num : nums)
	{
		count += num;
	}

	/* 拼接两个列表 */
	std::vector<int> nums1 = { 6, 8, 7, 10, 9 };
	// 将列表 nums1 拼接到 nums 之后
	nums.insert(nums.end(), nums1.begin(), nums1.end());

	/* 排序列表 */
	std::sort(nums.begin(), nums.end()); // 排序后，列表元素从小到大排列
	return 0;
}

