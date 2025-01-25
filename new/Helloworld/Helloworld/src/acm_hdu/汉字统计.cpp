#include <iostream>
#include <string>

// 19968 40869
int main()
{
	int n;
	std::string strs;
	std::cin >> n;
	getchar();
	while (n--)
	{
		getline(std::cin, strs);
		int count = 0;
		for (int i = 0; i < strs.size(); i++)
			if (strs[i] < 0) count++;
		// 一个汉字占两个字符
		std::cout << count / 2 << std::endl;
	}
	return 0;
}