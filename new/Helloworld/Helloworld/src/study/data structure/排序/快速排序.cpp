#include "structs.h"

int Partition(SqList& L, int low, int high)
{
	// 对顺序表L中的子表r[low..high]进行一趟排序，返回枢轴位置
	L.r[0] = L.r[low]; // 用子表的第一个记录作为枢轴记录
	KeyType pivotkey = L.r[low].key; // 枢轴记录关键字保存在pivotkey中
	while (low < high)
	{
		while (low < high && L.r[high].key >= pivotkey) --high;
		L.r[low] = L.r[high]; // 将比枢轴记录小的记录移到低端
		while (low < high && L.r[low].key <= pivotkey) ++low;
		L.r[high] = L.r[low]; // 将比枢轴记录大的记录移到高端
	} // while
	L.r[low] = L.r[0]; // 枢轴记录到位
	return low; // 返回枢轴位置
}

void QSort(SqList& L, int low, int high)
{
	// 调用前置初值：low = 1，high = L.length
	// 对顺序表L中的子表L.r[low..high]进行快速排序
	KeyType pivotkey;
	if (low < high) // 长度大于1
	{
		pivotkey = Partition(L, low, high); // 将L.r[low..high]一分为二，pivotloc是枢轴位置
		QSort(L, low, pivotkey - 1); // 对左子表递归排序
		QSort(L, pivotkey + 1 , high); // 对右子表递归排序
	}
}

void QuickSort(SqList& L)
{
	// 对顺序表L进行快速排序
	QSort(L, 1, L.length);
}