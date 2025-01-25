#include "structs.h"

void SelectSort(SqList& L)
{
	// 对顺序表L进行简单选择排序
	int i = 0, k = 0;
	for (i = 1; i < L.length; i++)
	{
		// 在L.r[i..L.length]中选择关键字最小的记录
		k = i;
		int j = 0;
		for (j = i + 1; j <= L.length; j++)
			if (L.r[j].key < L.r[k].key) k = j; // k指向此趟排序中关键字最小的记录
		if (k != i)
		{
			// 交换r[i]与r[k]
			RedType t = L.r[i];
			L.r[i] = L.r[k];
			L.r[k] = t;
		}
	} // for

}