#include <iostream>
#include <string>

// 初始定义阶乘数组 0-9
int* nums = new int[10] {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

// 定义一个宏 用于计算字符转数字 0 的字符编码为48
#define CHAR_TO_INT(x) (int)x - 48

// 定义整数的最大值
#define INT_MAX 51201

bool isJudge(int num)
{
	// 设置每一位数字的阶乘累加值
	int temp = 0;
	// 将数字转换为字符串
	std::string strs = std::to_string(num);
	// 遍历字符串的每一位
	for (int i = 0; i < strs.size(); i++)
		// 先将字符串中每一位的字符进行数值转换
		// 在将数值转换后的整数放到数组中去获取对应的阶乘
		// 最后使用累加，计算每一位的阶乘和
		temp += nums[CHAR_TO_INT(strs[i])];
	return temp == num; // 返回累加值是否与原数相同
}

int main()
{
	for (int i = 0; i < INT_MAX; i++)
		if (isJudge(i)) std::cout << i << std::endl;
	return 0;
}