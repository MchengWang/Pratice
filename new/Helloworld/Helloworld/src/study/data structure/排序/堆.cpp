#include "structs.h"

void HeapAdjust(SqList& L, int s, int m)
{
	// 假设r[s+1 .. m]已经是堆，将r[s..m]调整为r[s]为根的大根堆
	RedType rc = L.r[s]; 
	int j = 0;
	for (j = 2 * s; j <= m; j *= 2) // 沿key较大的孩子节点向下筛选
	{
		if (j < m && L.r[j].key < L.r[j + 1].key) ++j; // j为key较大的记录的下表
		if (rc.key >= L.r[j].key) break; // rc应插入在位置s上
		L.r[s] = L.r[j];
		s = j;
	} // for
	L.r[s] = rc; // 插入
} 

void CreateHeap(SqList &L)
{
	// 把无序序列L.r[1..n]建成大根堆
	int n = L.length;
	for (int i = n / 2; i > 0; i--) // 反复调用HeapAdjust
		HeapAdjust(L, i, n);
}

void HeapSort(SqList& L)
{
	// 对顺序表L进行堆排序
	CreateHeap(L); // 把无序序列L.r[1..L.length]建成大根堆
	for (int i = L.length; i > 1; i--)
	{
		RedType x = L.r[1]; // 将堆顶记录和当前未经排序子序列L.r[1..i]中最后一个记录互换
		L.r[1] = L.r[i];
		L.r[i] = x;
		HeapAdjust(L, 1, i - 1); // 将L.r[1..i - 1]重新调整为大根堆
	} // for
}