#include<iostream>
#include<string>

#define max(a,b) (a>b?a:b)

int main()
{
	std::string s1, s2;
	while (std::cin >> s1 >> s2)
	{
		int i, j;

		for (i = 0; i < s1.length(); i++)
			if (s1[i] == '.')
				break;
		int int_len_1 = i;//s1的整数位长度

		int decimal_len_1 = s1.length() - int_len_1 - 1;//s1的小数位长度

		for (i = 0; i < s2.length(); i++)
			if (s2[i] == '.')
				break;
		int int_len_2 = i;//s2的整数位长度
		int decimal_len_2 = s2.length() - int_len_2 - 1;//s2的小数位长度

		//补齐整数位，使s1和s2的整数位对齐
		if (int_len_1 < int_len_2)
			for (i = 1; i <= int_len_2 - int_len_1; i++)
				s1 = '0' + s1;
		else if (int_len_2 < int_len_1)
			for (i = 1; i <= int_len_1 - int_len_2; i++)
				s2 = '0' + s2;

		//在s1和s2的前面多加1位0，因为例如：2.6+7.5 = 10.1整数位数变多了.
		s1 = '0' + s1;
		s2 = '0' + s2;

		//补齐小数位，使s1和s2小数位对齐
		if (decimal_len_1 < decimal_len_2)
			for (i = 1; i <= decimal_len_2 - decimal_len_1; i++)
				s1 = s1 + '0';
		else if (decimal_len_2 < decimal_len_1)
			for (i = 1; i <= decimal_len_1 - decimal_len_2; i++)
				s2 = s2 + '0';

		int node = max(int_len_1, int_len_2) + 1;//小数点的下标

		//去掉小数点
		s1 = s1.erase(node, 1);
		s2 = s2.erase(node, 1);

		//下面，可以将s1和s2进行整数加法计算.
		//模拟"整数"s1和s2的加法过程，结果存在s1中
		int len = s1.length();
		int c = 0;
		for (i = len - 1; i >= 0; i--)
		{
			int x = s1[i] - '0';//将s1的某个字符转化为字符对应的数字
			int y = s2[i] - '0';

			c += (x + y);
			s1[i] = (c % 10 + '0');//注意 +'0'是将数字 c%10 转化为对应的字符

			c /= 10;
		}

		//至此，计算完毕，下面是输出过程.

		for (i = 0; i < len; i++)
			if (s1[i] != '0')//从非零的整数位开始输出
				break;
		for (j = i; j < node; j++)
			std::cout << s1[j];//输出整数位

		for (j = len - 1; j >= node; j--)//看看小数为是否都为0
			if (s1[j] != '0')
				break;
		if (j >= node)//在这种情况下，小数为不全为0
		{
			std::cout << ".";//输出小数点
			for (i = node; i <= j; i++)
				std::cout << s1[i];//输出小数位
		}

		std::cout << std::endl;
	}

	return 0;
}