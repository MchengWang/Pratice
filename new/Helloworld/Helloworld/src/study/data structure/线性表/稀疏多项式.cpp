#include <iostream>

typedef struct PNode
{
	float coef; // 系数
	int expn; // 指数
	struct PNode* next; // 指针域
}PNode , *Polynoimal;

// 多项式的创建
void CreatePolyn(Polynoimal& P, int n)
{
	// 输入n项的系数和指数，建立表示多项式的有序链表P
	P = new PNode;
	P->next = NULL; // 先建立一个带头结点的单链表
	for (int i = 1; i <= n; ++i) // 依次输入n个非零项
	{
		Polynoimal s = new PNode; // 生成新节点
		std::cin >> s->coef >> s->expn; // 输入系数和指数
		Polynoimal pre = P; // pre用于保存P的前驱，初值为头节点
		Polynoimal q = P->next; // q初始化，指向首元节点
		while (q && q->expn < s->expn) // 通过比较指数找到第一个大于输入项指数的项*q
		{
			pre = q;
			q = q->next;
		} // while
		s->next = q; // 将输入项s插入*q和其前驱节点pre之间
		pre->next = s;
	} // for
}

// 多项式的相加
void AddPolyn(Polynoimal& Pa, Polynoimal& Pb)
{
	// 多项式加法：Pa=Pa+Pb,利用两个多项式的节点构成“和多项式”
	Polynoimal p1 = Pa->next, p2 = Pb->next; // p1和p2初始时分别指向Pa和Pb的首元节点
	Polynoimal p3 = Pa; // p3指向和多项式的当前节点，初值为Pa
	while (p1 && p2) // p1和p2均非空
	{
		if (p1->expn == p2->expn) // 指数相等
		{
			int sum = p1->coef + p2->coef; // sum保存两项的系数和
			if (sum != 0) // 系数和不为0
			{
				p1->coef = sum; // 修改Pa当前指向节点的系数值为两项系数的和
				p3->next = p1;  // 将修改后的Pa当前指向节点链接在p3之后，p3指向p1
				p3 = p1;
				p1 = p1->next; // p1指向后一项
				Polynoimal r = p2; // 删除Pb当前指向节点，p2指向后一项
				p2 = p2->next;
				delete r;
			}
			else // 系数和为0
			{
				Polynoimal r = p1; // 删除Pa当前所指向节点，p1指向后一项
				p1 = p1->next;
				delete r;

				Polynoimal r = p2; // 删除Pb当前所指向节点，p2指向后一项
				p2 = p2->next;
				delete r;
			}
		}
		else if (p1->expn < p2->expn) // Pa所指向节点的指数值小
		{
			p3->next = p1; // 将p1链接在p3之后
			p3 = p1; // p3指向p1
			p1 = p1->next; // p1指向后一项
		}
		else // Pb当前志向节点的指数值小
		{
			p3->next = p2; // 将p2链接在p3之后
			p3 = p2; // p3指向p2
			p2 = p2->next; // p2指向最后一项
		}
	} // while
	p3->next = p1 ? p1 : p2; // 插入非空多项式的剩余段
	delete Pb; // 释放Pb的头节点
}