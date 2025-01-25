#include "structs.h"

void ShellInsert(SqList& L, int dk)
{
	// 对顺序表L进行一趟增量是dk的希尔插入排序
	for(int i = dk + 1; i <= L.length; i ++)
		if (L.r[i].key < L.r[i - dk].key) // 需将L.r[i]插入有序增量子表
		{
			L.r[0] = L.r[i]; // 暂存在r[0]中
			int j = 0;
			for (j = i - dk; j > 0 && L.r[0].key < L.r[j].key; j -= dk)
				L.r[j + dk] = L.r[j]; // 记录后移，直到找到插入位置
			L.r[j + dk] = L.r[0]; // 将r[0]即原r[i]，插入正确位置
		} // if
}