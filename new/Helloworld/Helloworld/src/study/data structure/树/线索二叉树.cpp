#include <iostream>

typedef int TElemType;

typedef struct BiThrNode
{
	TElemType data;
	struct BiThrNode* lchild, * rchild; // 左右孩子指针
	int LTag, RTag; // 左右标志
}BiThrNode , *BiThrTree;

// 以节点p为根的子树中序线索化
void InThreading(BiThrTree p)
{
	BiThrTree pre = 0;
	// pre是全局变量，初始化时其右孩子指针为空，便于在树的最左点开始建线索
	if (p)
	{
		InThreading(p->lchild); // 左子树递归线索化
		if (!p->lchild) // p的左孩子为空
		{
			p->LTag = 1; // 给p加上左线索
			p->lchild = pre; // p的左孩子指针指向pre（前驱）
		}
		else p->LTag = 0;
		if (!pre->rchild) // pre的右孩子为空
		{
			pre->RTag = 1; // 给pre加上右线索
			pre->rchild = p; // pre的右孩子指针指向p（后驱）
		}
		else pre->RTag = 0;
		pre = p; // 保持pre指向p
		InThreading(p->rchild); // 右子树递归线索化
	}
}

// 带头结点的二叉树中序线索化
void InOrderThreading(BiThrTree& Thrt, BiThrTree T)
{
	BiThrTree pre;
	// 中序遍历二叉树T，并将其中序线索化，Thr指向头节点
	Thrt = new BiThrNode; // 建头节点
	Thrt->LTag = 0; // 头节点有左孩子，若树非空，则其左孩子为树根
	Thrt->RTag = 1; // 头节点的右孩子指针为右线索
	Thrt->rchild = Thrt; // 初始化时右指针指向自己
	if (!T) Thrt->lchild = Thrt; // 若树为空，则左指针也指向自己
	else
	{
		Thrt->lchild = T;
		pre = Thrt; // 头节点的左孩子指向根，pre初值指向头节点
		InThreading(T); // 对以T为根的二叉树进行中序线索化
		pre->rchild = Thrt; // pre为最右节点，pre的右线索指向头节点
		pre->RTag = 1;
		Thrt->rchild = pre; // 头节点的右线索指向pre
	}
}

// 遍历中序线索二叉树
void InOrderTraverse_Thr(BiThrTree T)
{
	// T指向头节点，头节点的左链lchild指向根节点
	// 中序遍历二叉线索树T的非递归算法，对每个数据元素直接输出
	BiThrTree p = T->lchild; // p指向根节点
	while (p != T) // 空树或遍历结束时，p=T
	{
		while (p->LTag == 0) p = p->lchild; // 沿左孩子向下
		std::cout << p->data; // 访问其左子树为空的节点
		while (p->RTag == 1 && p->rchild != T)
		{
			p = p->rchild;
			std::cout << p->data; // 沿右线索访问后继节点
		}
		p = p->rchild; // 转向p的右子树
	}
}