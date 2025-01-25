#include <iostream>

long Fact(long n)
{
	if (n == 0) return 1; // 递归终止的条件
	else return n * Fact(n - 1); // 递归步骤
}

long Fib(long n)
{
	if (n == 1 || n == 2) return 1; // 递归终止的条件
	else return Fib(n - 1) + Fib(n - 2); //递归步骤
}

typedef struct LNode
{
	int data; // 节点的数据域
	struct LNode* next; // 节点的指针域
}LNode, * LinkList; // LinkList为指向结构体LNode的指针类型

void TraverseList(LinkList p)
{
	if (p) 
	{
		std::cout << p->data << std::endl; // 输出当前节点的数据域
		TraverseList(p->next);
	}
}

int m = 0;
void move(char A, int n, char C)
{
	std::cout << ++m << "," << n << "," << C << std::endl;
}

void Hanoi(int n, char A, char B, char C)
{
	// 将塔座A上的n个圆盘按规则搬到塔座C上，塔座B作为辅助塔座
	if (n == 1) move(A, 1, C); // 将编号为1的圆盘从塔座A移到塔座C
	else
	{
		Hanoi(n - 1, A, C, B); // 将A上编号为1至n-1的圆盘移到塔底B，塔座C作为辅助塔座
		move(A, n, C); // 将编号为n的圆盘从塔座A移到塔座C
		Hanoi(n - 1, B, A, C); // 将B上编号为1至n-1的圆盘移到塔底C，塔座A作为辅助塔座
	}
}