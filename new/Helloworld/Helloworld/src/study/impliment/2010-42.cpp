#include <iostream>

class Solution
{
public:
	void Reverse(int start, int end, int* nums)
	{
		// 左右指针用于指向要交换数值的数组边界
		while (start < end)
		{
			// 交换元素
			int temp = nums[start];
			nums[start] = nums[end];
			nums[end] = temp;

			start++; // 做指针向后移动
			end--; // 右指针向前移动
		}
	}

	int* getArray(int size, int index, int* nums)
	{
		// 这个是进行范围判断，当旋转中心点超出了数组的长度，是无法进行数组的旋转功能的
		if (index > 0 && index < size)
		{
			// 整体数组颠倒 1 2 3 4 5 6 -> 6 5 4 3 2 1
			Reverse(0, size - 1, nums); 
			// 将数组左半部分的数值颠倒 6 5 4 3 2 1 -> 4 5 6 3 2 1
			Reverse(0, size - index - 1, nums); 
			// 将数组右半部分颠倒 4 5 6 3 2 1 -> 4 5 6 1 2 3
			Reverse(size - index, size - 1, nums); 
		}

		return nums;
	}
};

int main()
{

	int* nums = new int[] { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	Solution sol;
	int* ss = sol.getArray(10, 5, nums);
	for (int i = 0; i < 10; i++)
	{
		std::cout << nums[i] << " ";
	}
	return 0;
}