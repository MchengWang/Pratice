#include <iostream>
#include "assert.h"

template <typename T>
struct ThreadTree
{
	T data;
	ThreadTree<T>* lchild, * rchild;
	int ltag, rtag;
};

// 通过中序遍历实现二叉树线索化
template <typename T>
void inThread(ThreadTree<T>* root, ThreadTree<T>* pre)
{
	if (root)
	{
		inThread(root->lchild, pre); // 递归，线索化左子树
		if (root->lchild == nullptr) // 当前节点的左子树为空
		{
			root->lchild = pre; // 建立当前节点的前驱线索
			root->ltag = 1;
		}
		if (pre != nullptr && pre->rchild == nullptr) // 前驱结点非空且其右子树为空
		{
			pre->rchild = root; // 建立前驱节点的后继线索
			pre->rtag = 1;
		}
		pre = root; // 标记当前结点成为刚刚访问多的结点
		inThread(root->rchild, pre); // 递归，线索化右子树
	}
}

template <typename T>
void createInThread(ThreadTree<T> tree)
{
	ThreadTree<T> pre = nullptr;
	if (tree != nullptr) // 非空二叉树，线索化
	{
		inThread(tree, pre); // 线索化二叉树
		pre->rchild = nullptr; // 处理遍历的最后一个结点
		pre->rtag = 1;
	}
}

// 求中序序列下的第一个结点
template <typename T>
ThreadTree<T>* firstNode(ThreadTree<T>* root)
{
	while (root->ltag == 0) root = root->lchild; // 最左下结点（不一定是叶节点）
	return root;
}

// 中序线索二叉树中结点 root 在中序序列下的后继
template <typename T>
ThreadTree<T>* nextNode(ThreadTree<T>* root)
{
	if (root->rtag == 0) return firstNode(root->rchild); // 右子树中最左下结点
	else return root->rchild; // 若 tag == 1 则直接返回后继线索
}

// 利用上述两个算法，可以写出不含头结点的中序线索二叉树的中序遍历的算法
template <typename T>
void inOrder(ThreadTree<T>* root)
{
	for (ThreadTree<T>* p = firstNode(root); p != nullptr; p = nextNode(root))
		std::cout << p->data << std::endl;
}