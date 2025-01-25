#include <iostream>

#define m 3 // B-树的阶，暂设为3

#define OK 1
#define ERROR -1

#define FALSE -2
#define TRUE 2

typedef int KeyType;
typedef int Status;

typedef struct BTNode
{
	int keynum; // 节点中关键字的个数，即节点的大小
	struct BTNode* parent; // 指向双亲节点
	KeyType K[m + 1]; // 关键字向量，0号单元未用
	struct BTNode* ptr[m + 1]; // 子树指针向量
	Record* recptr[m + 1]; // 记录指针向量，0号单元未用
}BTNode , *BTree;

typedef BTNode Record;

typedef struct
{
	BTNode* pt; // 指向找到的节点
	int i; // 1~m，在节点中的关键字序号
	int tag; // 1表示查找成功，0表示查找失败
}Result; // B-树的查找结果类型

Result SearchBTree(BTree T, KeyType key)
{
	// 在m阶B-树T上查找关键字key，返回结果(pt , i , tag) 
	// 若找到成功，则特征值tag = 1，指针pt所指节点中第i个关键字等于key
	// 否则特征值tag = 0，等于key的关键字应插入在指针pt所指节点中第i个和第i + 1个关键字之间
	BTree p = T; // 初始化，p指向待查节点，q指向p的双亲
	int found = FALSE, i = 0;
	while (p && found)
	{
		i = Search(p, key); // 在p->K[1..keynum]中查找i，是的p->K[i] <= p->K[i + 1]
		if (i > 0 && p->K[i] == key) found = TRUE; // 找到待查关键字
		else {
			q = p;
			p = p->ptr[i]; // 查找成功
		}
		if (found) return (p, i, 1); // 查找成功
		else return (q, i ,0); // 查找不成功，则返回key的插入位置信息 
	}

}

Status InsertBST(BTree& T, KeyType key, BTree q, int i)
{
	// 在m阶B-树T上节点*q的K[i]与K[i + 1]之间插入关键字key
	// 若引起节点过大，则沿双亲链进行必要的节点分裂调整，使T仍是m阶B-树
	int x = key;  // x表示新插入的关键字，ap为一个空指针
	BTree ap = NULL; 
	int finished = FALSE; 
	while (q && !finished)
	{
		Insert(q, i, x, ap); // 将x和ap分别插入q->key[i + 1]和q->ptr[i + 1]
		if (q->keynum < m) finished = TRUE; // 插入完成
		else // 分裂节点
		{
			s = (m + 1) / 2;  // 将q->K[s+1..m],q->ptr[s..m]和q->recptr[s+1 .. m]移入新节点*ap
			split(q, s, ap);
			x = q->K[s];

			q = q->parent;
			if (q) i = Search(q, x); // 在双亲节点*q中查找x的插入位置
		} // else
	} // while
	if (!finished) // T是空树（参数q为null）或者根节点已分裂为节点*q和*ap
		NewRoot(T, q, x, ap); //生成含信息（T,x,ap）的新的根节点*T，原T和ap为子树指针
	return OK;
}