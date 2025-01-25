#include <iostream>

#define OK 1
#define ERROR -1

typedef int ElemType;
typedef int Status;

typedef struct LNode
{
	ElemType data; // 节点的数据域
	struct LNode* next; // 节点的指针域
}LNode , *LinkList; // LinkList为指向结构体LNode的指针类型

// 初始化
Status InitList(LinkList& L)
{
	// 构造一个空的单链表L
	L = new LNode; // 生成新节点作为头节点，用头指针L指向头节点
	L->next = NULL; // 头节点的指针域置空
	return OK;
}

// 取值
Status GetElem(LinkList L, int i, ElemType& e)
{
	// 在带头结点的单链表L中根据序号i获取元素的值，用e返回L中第i个数据元素的值
	LinkList p = L->next;  // 初始化，p只想首元节点
	int j = 1; // 计数器j初值赋为1；
	while (p && j < i)  // 顺链域向后查找，直到p为空或p指向第i个元素
	{
		p = p->next; // p指向下一个节点
		++j; // 计数器j相应加1
	}
	if (!p || j > i) return ERROR; // i值不合法 i>n或i<0
	e = p->data; // 取第i个结点的数据域
	return OK;
}

// 查找
LNode* LocateElem(LinkList L, ElemType e)
{
	// 在带头结点的单链表L中查找值为e的元素
	LinkList p = L->next; // 初始化，p指向首元节点
	while (p && p->data != e) // 顺链表向后查找，直到p为空或p所指向节点的数据域等于e
		p = p->next; // p 指向下一个节点
	return p; // 查找成功返回值为e的节点地址p，查找失败p为NULL
}

// 插入
Status LisiInsert(LinkList& L, int i, ElemType e)
{
	// 在带头结点的单链表L中第i个位置插入值为e的新节点
	LinkList p = L;
	int j = 0;
	while (p && j < i - 1)
	{
		p = p->next; // 查找第i-1个节点，p指向该节点
		++j;
	}
	if (!p || j > i - 1) return ERROR; // i > n + 1 或者 i << 1
	LinkList s = new LNode; // 生成新节点 *S
	s->data = e; // 将节点*s的数据域置为e
	s->next = p->next; // 将节点*s的指针域置为e
	p->next = s; // 将节点*p的指针域指向节点*s
	return OK;
}

// 删除
Status ListDelete(LinkList& L, int i)
{
	// 在带头结点的单链表L中，删除第i个元素
	LinkList p = L; 
	int j = 0;
	while (p->next && j < i - 1) // 查找第i-1个节点，p指向该节点
	{
		p = p->next;
		++j;
	}
	if (!p->next || j > i - 1) return ERROR; // 当i>n或i<1时，删除位置不合理
	LinkList q = p->next; // 临时保存被删节点的地址以备释放
	p->next = q->next; // 改变删除节点前驱节点的指针域
	delete q; // 释放删除节点的空间
	return OK;
}

// 前插法 创建单链表
void CreateList_H(LinkList& L, int n)
{
	// 逆位序输入n个元素的值，建立带头结点的单链表L
	L = new LNode;
	L->next = NULL; // 先建立一个带头节点的空链表
	for (int i = 0; i < n; i++)
	{
		LinkList p = new LNode; // 生成新节点*p
		std::cin >> p->data; // 输入元素值赋给新节点*p的数据域
		p->next = L->next; // 将新节点*p插入到头节点之后
		L->next = p; 
	}
}

// 创建单链表 后插法
void CreateList_R(LinkList& L, int n)
{
	// 正位序输入n个元素的值，建立带头节点的单链表L
	L = new LNode; // 先建立一个带头结点的空链表
	L->next = NULL;
	LinkList r = L; // 尾指针r指向头节点
	for (int i = 0; i < n; i++)
	{
		LinkList p = new LNode; // 生成新节点
		std::cin >> p->data; // 输入元素值赋给新节点*p的数据域
		p->next = NULL;
		r->next = p; // 将新节点*p插入尾节点*r之后
		r = p; // r指向新的尾节点*p
	}
}

// 链表有序表的合并
void MergeList_L(LinkList& LA, LinkList& LB, LinkList& LC)
{
	// 已知单链表LA和LB的元素按值非递减的排列
	// 归并LA和LB得到新的单链表LC，LC的元素也按值非递减排列
	LinkList pa = LA->next; // pa和pb的初值分别指向两个表的第一个节点
	LinkList pb = LB->next;
	LC = LA; // 用LA的头节点作为LC的头节点
	LinkList pc = LC; //pc的初值指向LC的头节点
	while (pa && pb)
	{
		// LA和LB均未到达表尾，依次“摘取”两表中值较小的节点插入到LC的最后
		if (pa->data <= pb->data) // 摘取pa所指向节点
		{
			pc->next = pa; // 将pa所值节点链接到pc所指节点之后
			pc = pa; // 将pc指向pa
			pa = pa->next; // pa指向下一个节点
		}
		else // 摘取pb所指节点
		{
			pc->next = pb; // 将pb所指节点链接到pc所指节点之后
			pc = pb; // pc指向pb
			pb = pb->next; // pb指向下一节点
		}
	} // while
	pc->next = pa ? pa : pb; // 将非空表的剩余段插入到pc所指结点之后
	delete LB; // 释放LB的头节点
}