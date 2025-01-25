#include "structs.h"

void BubbleSort(SqList& L)
{
	int m = L.length - 1, flag = 1; // flag用来标记某一趟排序是否发生交换
	while (m > 0 && flag == 1)
	{
		flag= 0; //flag置为0，如果本趟排序没有发生交换，则不会执行下一趟排序
		int j = 0;
		for(j = 1;j<= m; j ++)
			if (L.r[j].key > L.r[j + 1].key)
			{
				flag = 1; // flag置为1，表示本趟排序发生了交换
				RedType t = L.r[j];
				L.r[j] = L.r[j + 1];
				L.r[j + 1] = t; // 交换前后两个记录
			} // if
		--m;
	} // while
} // BubbleSort