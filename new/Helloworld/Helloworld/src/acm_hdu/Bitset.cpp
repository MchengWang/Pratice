 Give you a number on base ten,you should output it on base two.(0 < n < 1000)

#include <iostream>
#include <string>

#define TO_STRING(x) std::to_string(x)

// 二进制每位上的数组
int* bit = new int[2] { 0, 1 };

std::string tenToTwo(int num)
{
	std::string strs;
	while (true)
	{
		// 当数值除于 2 等于 0 的时候，结束循环
		if (num / 2 == 0)
		{
			// 当数值除于 2 等于 0 的时候，需要将最后的余数放到字符串中
			if (num % 2 != 0) strs.insert(0, TO_STRING(bit[num % 2]));
			break;
		}
		// 将转换的数对 2 进行取余,然后将其添加进字符串首位
		strs.insert(0, TO_STRING(bit[num % 2]));
		// 十进制 -> 二进制 模2取余法
		num /= 2;
	}
	return strs;
}

int main()
{
	
	// 用于接收输入的十进制数
	int num;
	while (std::cin >> num)
		std::cout << tenToTwo(num) << std::endl;
	return 0;
}