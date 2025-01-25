 //输入数据首先包含一个正整数C，表示有C组测试用例，每组测试用例的第一行是两个整数n和m（0 < n <= 1000, 0 < m <= 1000）, 
 //分别表示经费的金额和大米的种类，然后是m行数据，每行包含2个整数p和h(1 <= p <= 25, 1 <= h <= 100)，
 //分别表示单价和对应大米的重量。

#include <iostream>
#include <iomanip>

int main()
{
	// 定义结束测试用例数量
	int num;
	std::cin >> num;
	while (num--)
	{
		// 接收可购买大米经费以及单价和数量的类别
		int total, category;
		std::cin >> total >> category;
		// 计算数组的长度
		int size = category * 2;
		// 定义一个数组用于存储 大米的单价以及数量
		int* nums = new int[size];
		for (int i = 0; i < size; i++)
			std::cin >> nums[i];
	}
	return 0;
}