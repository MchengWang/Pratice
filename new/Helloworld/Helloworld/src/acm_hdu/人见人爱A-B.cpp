#include <iostream>

int main()
{
	int n, m, i, numN[100], numM[100], arr[100], j, k, temp;
	while (std::cin >> n >> m) {
		if (n == 0 && m == 0) 
			break;
		if (n > 100 || m > 100 || n < 0 || m < 0) 
			continue;
		// 输入 numN 集合内容
		for (i = 0; i < n; i++) 
			std::cin >> numN[i];
		// 输入 numM 集合内容
		for (i = 0; i < m; i++) 
			std::cin >> numM[i];
		j = 0;
		for (i = 0; i < n; i++) {
			for (k = 0; k < m; k++)
				if (numN[i] == numM[k])
					break;
			if (k == m) 
				// 把 numN 有 numM 没有的元素插入统计数组中
				arr[j++] = numN[i];
		}
		// 统计数组从小到大排序（冒泡排序）
		for (i = 1; i < j; i++) 
			for (k = 0; k < j - i; k++) 
				if (arr[k] > arr[k + 1]) {
					temp = arr[k];
					arr[k] = arr[k + 1];
					arr[k + 1] = temp;
				}
		// 结果为空集合，则输出 “NULL”
		if (j == 0) 
			std::cout << "NULL";
		// 顺序输出数组中的元素
		else 
			for (i = 0; i < j; i++)
				std::cout << arr[i] << " ";
		std::cout << std::endl;
	}
	return 0;
}
