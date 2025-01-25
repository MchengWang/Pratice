#include <iostream>
#include <string>

#define ENDFLAG -3

typedef int KeyType;
typedef std::string InfoType;

typedef struct
{
	KeyType key; // 关键字项
	InfoType otherinfo; // 其他数据项
}ElemType; // 每个节点的数据域的类型

typedef struct BSTNode
{
	ElemType data; // 每个结点的数据域包括关键字项和其他项
	struct BSTNode* lchild, * rchild; // 左右孩子指针
}BSTNode , *BSTree;

BSTree SearchBST(BSTree T, KeyType key)
{
	 在根指针T所值二叉排序树中递归地查找某关键字等于key的数据元素
	 若查找成功，则返回指向该数据元素节点的指针，否则返回空指针
	if (!T || key == T->data.key) return T; // 查找结束
	else if (key < T->data.key) return SearchBST(T->lchild, key); // 在左子树中继续查找
	else return SearchBST(T->rchild, key); // 在右子树中继续查找
}

void InsertBST(BSTree& T, ElemType e)
{
	 当二叉排序树T中不存在关键字等于e，key的数据元素时，则插入该元素
	if (!T)
	{ // 找到插入位置，递归结束
		BSTNode* S = new BSTNode; // 生成新节点*S
		S->data = e; // 新节点*S的数据域置为e
		S->lchild = S->rchild = NULL; // 新节点*S作为叶子节点
		T = S; // 把新结点*S链接到已找到的插入位置
	}
	else if (e.key < T->data.key)
		InsertBST(T->lchild, e); // 将*S插入左子树
	else if(e.key > T->data.key)
		InsertBST(T->rchild, e); // 将*S插入右子树
}

void CreateBST(BSTree& T)
{
	 依次读入关键字为key的节点，将相应节点插入二叉排序树T中
	T = NULL; // 将二叉排序树T初始化为空树
	std::cin >> e;
	while (e.key != ENDFLAG)
	{
		InsertBST(T, e); // 将此节点插入二叉排序树T中
		std::cin >> e;
	}
}

void DeleteBST(BSTree& T, KeyType key)
{
	 从二叉排序树T中删除关键字等于key的节点
	BSTree p = T, f = NULL; // 初始化
	while (p)
	{
		if (p->data.key == key) break; // 找到关键字等于key的节点*p，结束循环
		f = p; // *f为*p的双亲节点
		if (p->data.key > key) p = p->lchild; // 在*p的左子树中继续查找
		else p = p->rchild; // 在*p的右子树中继续查找
	} // 找不到被删除节点则返回
	BSTree q = p;
	if (p->lchild && p->rchild) // 被删除节点*p左右子树均不为空
	{
		BSTNode* s = p->lchild;
		while (s->rchild) // 在*p的左子树中继续查找前驱节点，即最右下节点
		{
			q = s; 
			s = s->rchild; // 向右到尽头
		}
		p->data = s->data; // s指向被删除节点的“前驱”
		if (q != p) q->rchild = s->lchild; // 重接*q的右子树
		else q->lchild = s->lchild; // 重接*q的左子树
		delete s;
		return;
	} // if
	else if (!p->rchild) // 被删节点*p无右子树，只需重接其左子树
	{
		p = p->lchild; 
	} // else if
	else if (!p->lchild) // 被删节点*p无左子树，只需重接其右子树
	{
		p = p->rchild;
	}
	if (!f) T = p; // 被删节点为根节点
	else if (q == f->lchild) f->lchild = p; // 挂接到*f的左子树位置
	else f->rchild = p; // 挂接到*f的右子树位置
	delete q;
}