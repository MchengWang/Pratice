#include <iostream>

// 其实，可以想成两个数组进行数值判断，因为是升序，则肯定可以说明，他的中位数就是第 i 个元素。
class Solution
{
public:
	int getMedium(int* num1, int* num2, int size)
	{
		// 定义两个指针用于分别指向两个数组
		int p1 = 0, p2 = 0;
		// 定义一个临时变量用存储当前值
		int temp = num1[p1];
		// size - 1；
		while (size)
		{
			// 比对两个数组中的元素的大小
			if (num1[p1] < num2[p2])
			{
				// 存储当前 p1 指针指向的数组元素
				temp = num1[p1];
				// 将指针向后移动
				p1++;
			}
			else
			{
				// 存储当前 p2 所指向的数组元素
				temp = num2[p2];
				// 指针向后移动
				p2++;
			}

			// 可以查找的次数减一
			size--;
		}

		return temp;
	}
};

int main()
{

	Solution sol;
	int* num1 = new int[] { 11, 13, 15, 17, 19 };
	int* num2 = new int[] { 2, 4, 6, 8, 20};

	std::cout << sol.getMedium(num1, num2, 5);
	return 0;
}