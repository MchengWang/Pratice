#include <iostream>

#define MAX_SIZE 10

#define false 0
#define true 1

struct SqBitree
{
	int SqBiTNode[MAX_SIZE]; // 保存二叉树结点值的数组
	int ElemNum; // 实际占用的数组元素个数
};

int judgeInOrderBST(SqBitree bt, int k, int* val)
{
	if (k < bt.ElemNum && bt.SqBiTNode[k] != -1)
	{
		if (!judgeInOrderBST(bt, 2 * k + 1, val)) return false;
		if (bt.SqBiTNode[k] < *val) return false;
		*val = bt.SqBiTNode[k];
		if (!judgeInOrderBST(bt, 2 * k + 2, val)) return false;
	}

	return true;
}