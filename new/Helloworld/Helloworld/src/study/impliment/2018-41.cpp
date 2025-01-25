#include <iostream>

#define ABS(x) x > 0 ? x : -x

// 其实可以用空间换时间的算法求解
int getNotHave(int* nums)
{
	// 计算数组长度
	int size = (sizeof(nums) / sizeof(nums[0]));

	// 定义一个临时变量用于存储数组中最大元素
	int max = 0;
	for (int i = 0; i < size; i++)
		if (max < ABS(nums[i])) max = ABS(nums[i]);

	// 创建数组，长度设置为 max 并将数组中元素默认赋值为 0
	int* temp = new int[max + 1] {0};

	// 遍历数组，然后将对应下标的值变为 1
	for (int i = 0; i < size; i++)
	{
		if (!temp[ABS(nums[i])]) temp[ABS(nums[i])] = 1;
	}

	int t = 0;

	// 遍历 temp 数组，并获取最开始出现不为 1 的数值
	for (int i = 1; i < max + 1; i++)
	{
		if (!temp[i])
		{
			t = i;
			return i;
		}
			
	}


	if (t == 0) return max + 1;

	return 0;
}

int main()
{
	//int* nums = new int[4] { -5, 3, 2, 3 };
	int* nums = new int[3] { 1, 2, 3 };

	std::cout << getNotHave(nums) << std::endl;
	return 0;
}