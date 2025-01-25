#include <iostream>

template <typename T>
void Reverse(T R[], int from, int to)
{
	int i, temp;
	for (i = 0; i < (to - form) / 2; i++)
	{
		temp = R[i];
		R[form + i] = R[to - i];
		R[to - i] = temp;
	}
}
 
template <typename T>
void Converse(T R[], int n, int p)
{
	Reverse(R, 0, p - 1);
	Reverse(R, p, n - 1);
	Reverse(R, 0, n - 1);
}

template <typename T>
int M_search(T A[], T B[], int n)
{
	int s1, d1, m1, s2, d2, m2;
	s1 = 0;
	d1 = n - 1;
	s2 = 1;
	d2 = n - 1;
	while (s1 != d1 || s2 != d2)
	{
		m1 = (s1 + d1) / 2;
		m2 = (s2 + d2) / 2;
		// 满足条件:若 a = b ，则 a 或 b即为所求中位数，算法结束
		if (A[m1] == B[m2]) 
			return A[m1];
		// 满足条件: 若 a < b ，则舍弃序列 A 中较小的一半，同时舍弃序列 B 中较大的一半，要求两次舍弃的长度相同
		if (A[m1] < B[m2])
		{
			// 若元素个数为奇数
			if ((s1 + d1) % 2 == 0)
			{
				s1 = m1; // 舍弃 A 中间点以后的部分，且保留中间点
				d2 = m2; // 舍弃 B 中间点以后的部分，且保留中间点
			}
			// 若元素个数为偶数
			else
			{
				s1 = m1 + 1; // 舍弃 A 的前半部分
				d2 = m2; // 舍弃 B 的后半部分
			}
		}
		// 满足条件: 若 a > b ，则舍弃序列 A 中间较大的一半，同时舍弃序列 B 中较小的一半，要求两次舍弃的长度相等
		else 
		{
			// 满足元素个数为奇数
			if ((s1 + d1) % 2 == 0)
			{
				d1 = m1; // 舍弃 A 中间点以后的部分，且保留中间点
				s2 = m2; // 舍弃 B 中间点以前的部分，且保留中间点
			}
			// 元素个数为偶数
			else
			{
				d1 = m1; // 舍弃 A 的后半部分
				s2 = m2 + 1; // 舍弃 B 的前半部分
			}
		}
		return A[s1] < B[s2] ? A[s1] : B[s2];
	}
}

template <typename T>
int Majority(T A[], int n)
{
	T c = A[0]; // c 用来保存候选主元素
	int count = 1; // count 用来计数
	// 查找候选主元素
	for (int i = 0; i < n; i++)
	{
		if (A[i] == c)
			count++; // 对 A 中的候选元素计数
		else
		{
			if (count > 0) // 处理不是候选主元素的情况
				count--;
			else // 更换候选主元素，重新计数
			{
				c = A[i];
				count = 1;
			}
		}
	}
	if (count > 0)
		for (int i = 0; i < n; i++) // 统计候选主元素的实际出现次数
			if (A[i] == c)
				count++;
	if (count > (n / 2)) return c; // 确认候选主元素
	else return -1; // 不存在主元素
}

template <typename T>
int findMissMin(T A[], int n)
{
	T* B = new T[n]; // 创建标记数组
	memset(B, 0, sizeof(T) * n); // 赋初值为 0
	for (int i = 0; i < n; i++)
		if (A[i] > 0 && A[i] <= n) // 若 A[i] 的值介于 1 ~ n，则标记数组 B
			B[A[i] - 1] = 1;
	for (int i = 0; i < n; i++) // 扫描数组 B，找到目标值
		if (B[i] == 0) break;
	return i + 1; // 返回结果
}