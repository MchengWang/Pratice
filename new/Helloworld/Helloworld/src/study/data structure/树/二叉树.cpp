#include <iostream>

// 二叉树的顺序存储表示
#define MAXSIZE 100 // 二叉树的最大节点数
typedef int TElemType;

typedef TElemType SqBitree[MAXSIZE]; // 0号单元存储根节点
SqBitree bt;

// 二叉树的二叉链表存储表示
typedef struct BitNode
{
	TElemType data; // 节点数据域
	struct BitNode* lchild, * rchild; //左右孩子指针
}BitNode , *BiTree;

 //中序遍历 递归
void InOrderTraverseD(BiTree T)
{
	 中序遍历二叉树T的递归算法
	if (T) // 若二叉树非空
	{
		InOrderTraverseD(T->lchild); // 中序遍历左子树
		std::cout << T->data << std::endl; // 访问根节点
		InOrderTraverseD(T->rchild); // 中序遍历右子树
	}
}

 //中序便利 非递归
void InOrderTraverse(BiTree T)
{
	// 中序遍历二叉树T的非递归泛
	InitStack(S); p = T;
	q = new BitNode;
	while (p || !StackEmpty(S))
	{
		if (p) // p非空
		{
			Push(S, p); // 跟指针进栈
			p = p->next; // 跟指针进栈，遍历左子树
		}
		else // p为空
		{
			Pop(S, p); // 退栈
			std::cout << q->data; // 访问根节点
			p = q->rchild; // 遍历右子树
		}
	} // while
}

 //先序遍历的栓徐建立二叉链表
void CreateBiTree(BiTree T)
{
	 //按先序次序输入二叉树中节点的值（单字符），拆功能键二叉链表表示的二叉树T
	char ch;
	std::cin >> ch;
	if (ch == '#') T = NULL; // 递归结束，建空树
	else // 递归创建二叉树
	{
		T = new BitNode; // 生成根节点
		T->data = ch; // 根节点数据域置为ch
		CreateBiTree(T->lchild); // 递归创建左子树
		CreateBiTree(T->rchild); // 递归创建右子树
	} // else
}

// 计算二叉树的深度
int Depth(BiTree T)
{
	// 计算二叉树的深度
	if (T == NULL) return 0; // 如果是空树，深度为0，递归结束
	else
	{
		int m = Depth(T->lchild); // 递归计算左子树的深度为m
		int n = Depth(T->rchild); // 递归计算右子树的深度为n
		if (m > n) return m + 1; // 二叉树的深度为m与n的较大者加1
		else return n + 1;
	}
}

// 统计二叉树中节点的个数
int NodeCount(BiTree T)
{
	 //统计二叉树T中节点的个数
	if (T == NULL) return 0; // 如果是空树，则节点个数为0，递归结束
	else return NodeCount(T->lchild) + NodeCount(T->rchild) + 1; // 否则节点个数为左子树的节点个数+右子树的节点个数+1
}

 //表达式的求值
int EvaluateExpTree(BiTree T)
{
	int lvalue = rvalue = 0; // 初始为0
	if (T->lchild == NULL && T->rchild == NULL)
		return T->data - '0'; // 如果节点为操作数，则返回该节点的数值
	else // 如果节点为运算符
	{
		lvalue = EvaluateExpTree(T->lchild); // 递归计算左子树的值，记为lvalue
		rvalue = EvaluateExpTree(T->rchild); // 递归计算右子树的值，记为rvalue
		return GetValue(T->data, lvalue, rvalue); // 根据当前节点运算符的类型进行相应运算
	}
}