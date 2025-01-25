#include "structs.h"

void Merge(RedType R[], RedType T[], int low, int mid, int high)
{
	// 将有序表R[low..mid]和R[mid + 1 .. high]归并为有序表T[low .. high]
	int i = low, j = mid + 1, k = low;
	while (i <= mid && j <= high) // 将R中的记录由小到大地并入T中
	{
		if (R[i].key <= R[j].key) T[k++] = R[i++];
		else T[k++] = R[j++];
	} // while
	while (i <= mid) T[k++] = R[i++]; // 将剩余的R[i..mid]复制到T中
	while (j <= high) T[k++] = R[j++]; // 将剩余的R[j..high]复制到T中
}

void MSort(RedType R[], RedType T[], int low, int high)
{
	// R[low..high]归并排序后放入T[low..high]中
	if (low == high) T[low] = R[low];
	else
	{
		int mid = (low + high) / 2; // 将当前序列一分为二，求出分裂点mid
		MSort(R, S, low, mid); // 对子序列R[low..mid]递归进行归并排序，结果放入S[low..mid]
		MSort(R, S, mid + 1, high); // 对子序列R[low + 1 .. high]递归进行归并排序，结果放入S[mid + 1 ..high]
		Merge(S, T, low, mid, high); // 将S[low ..mid]和[mid + 1 .. high]归并到T[low ..high]
	} //else
}

void MergeSort(SqList& L)
{
	// 对顺序表L进行归并排序
	MSort(L.r, L.r, 1, L.length);
}