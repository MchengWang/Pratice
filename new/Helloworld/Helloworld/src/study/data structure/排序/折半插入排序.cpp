#include "structs.h"

void BInsertSort(SqList& L)
{
	// 对顺序表L进行折半插入排序
	for (int i = 2; i <= L.length; i++)
	{
		L.r[0] = L.r[i]; // 将待插入的记录暂存到监视哨中
		int low = 1, high = i - 1; // 置查找区间的初值
		while (low <= high) // 在r[low..high]中折半查找插入的位置
		{
			int m = (low + high) / 2; //折半
			if (L.r[0].key < L.r[m].key) high = m - 1; // 插入点在前一子表
			else low = m + 1; // 插入点在后一子表
		} // while
		for (int j = i - 1; j >= high + 1; j--) L.r[j + 1] = L.r[j]; // 记录后移
		L.r[high + 1] = L.r[0];
	}
}