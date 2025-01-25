#include <iostream>

int main()
{
	int* num = new int[21];
	num[1] = 1; // 第一天
	num[2] = 2; // 第二天 母猪开始生娃
	num[3] = 3; // 第三天 母猪再次生娃
	for (int i = 4; i < 21; i++)
		// 此后每一天 母猪数量均为头一天的母猪数量的两倍，去掉前三天的母猪数量
		num[i] = num[i - 1] * 2 - num[i - 3];

	int N;
	while (std::cin >> N)
	{
		while (N --)
		{
			int n;
			std::cin >> n;
			std::cout << num[n] << std::endl;
		}
	}
	return 0;
}