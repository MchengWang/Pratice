#include <iostream>

int getMajory(int* nums, int size)
{
	// 定义一个临时变量存储当前元素值
	int temp = nums[0];
	// 定义一个计数变量，存储当前元素出现的次数
	int count = 1;
	for (int i = 1; i < size; i++)
	{
		if (nums[i] == temp)
			count++;
		else
			count--;

		if (!count)
		{
			temp = nums[i];
			count = 1;
		}
	}

	count = 0;
	for (int i = 0; i < size; i++)
		if (nums[i] == temp) count++;

	return count >= size / 2 ? temp : 0;
}

int main()
{
	std::cout << getMajory(new int[] { 0, 5, 5, 3, 5, 1, 5, 7 }, 8);
	return 0;
}