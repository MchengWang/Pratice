#include <iostream>

int setPartition(int* nums, int n)
{
	int pivotkey = 0, flag = 1, low = 0, high = n - 1, low0 = 0, high0 = n - 1;
	int s1 = 0, s2 = 0;
	while (flag)
	{
		pivotkey = nums[low]; // 选择枢轴
		while (low < high) // 基于枢轴对数据进行划分
		{
			while (low <= high && nums[high] >= pivotkey) --high;
			if (low != high) nums[low] = nums[high];
			while (low < high && nums[low] <= pivotkey) ++low;
			if (low != high) nums[high] = nums[low];
		}
		nums[low] = pivotkey;
		if (low == n / 2 - 1)
			flag = 0;
		else
		{
			if (low < n / 2 - 1)
			{
				low0 = ++low;
				high = high0;
			}
			else
			{
				high0 = --high;
				low = low0;
			}
		}
	}

	for (int i = 0; i < n / 2; i++)
		s1 += nums[i];
	for (int i = n / 2; i < n; i++)
		s2 += nums[i];

	return s2 - s1;
}

int main()
{
	return 0;
}