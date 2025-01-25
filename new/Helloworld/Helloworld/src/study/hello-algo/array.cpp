#include <iostream>

/* 初始化数组 */
// 存储在栈上
int arr[5];
int nums[5] = { 1, 2, 3, 5, 4 };
// 存储在堆上（需要手动释放空间）
int* arr1 = new int[5];
int* nums1 = new int[5] { 1, 2, 3, 5, 4 };

/* 随机访问元素 */
int randomAccess(int* nums, int size)
{
	// 在区间[0, size)中随机抽取一个数
	int randomIndex = rand() % size;
	// 获取并返回随机元素
	int randomNum = nums[randomIndex];
	return randomNum;
}

/* 在数组的索引 index 处插入元素 num */
void insert(int* nums, int size, int num, int index)
{
	// 把索引 index 以及之后的所有元素向后移动一位
	for (int i = size - 1; i > index; i--)
	{
		nums[i] = nums[i - 1];
	}
	// 将 num 赋值给 index 处的元素
	nums[index] = num;
}

/* 删除索引 index 处的元素 */
void remove(int* nums, int size, int index)
{
	// 把索引 index 之后的所有元素向前移动一位
	for (int i = index; i < size; i++)
	{
		nums[i] = nums[i + 1];
	}
}

/* 遍历数组 */
void traverse(int* nums, int size)
{
	int count = 0;
	// 通过索引遍历数组
	for (int i = 0; i < size; i++) 
	{
		count += nums[i];
	}
}

/* 在数组中查找指定元素 */
int find(int* nums, int size, int target)
{
	for (int i = 0; i < size; i++)
	{
		if (nums[i] == target) return i;
	}
	return -1;
}

/* 拓展数组长度 */
int* extend(int* nums, int size, int enlarge)
{
	// 初始化一个拓展长度后的数组
	int* res = new int[size += enlarge];
	// 将原数组中的所有元素复制到新数组
	for (int i = 0; i < size; i++)
	{
		res[i] = nums[i];
	}
	// 释放内存
	delete[] nums;
	// 返回拓展后的新数组
	return res;
}
