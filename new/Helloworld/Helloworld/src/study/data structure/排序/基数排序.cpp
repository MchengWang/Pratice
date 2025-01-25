#include <iostream>
#include "structs.h"

#define MAXNUM_KEY 8 // 关键字项数的最大值
#define RADIX 10 // 关键字基数，此时基数是十进制整数
#define MAX_SPACE 10000

typedef struct
{
	KeyType keys[MAXNUM_KEY]; // 关键字
	InfoType otherinfo; // 其他数据域
	int next;
}SLCell;

typedef struct // 静态链表的节点类型
{
	SLCell r[MAX_SPACE]; // 静态链表的可利用空间，r[0]为头节点
	int keynum; // 记录的当前关键字个数
	int recnum; // 静态链表的当前长度
}SLList; // 静态链表类型

typedef int ArrType[RADIX]; // 数组类型

void Distribute(SLCell& r, int i, ArrType& f, ArrType& e)
{
	// 静态链表L的r域中记录已按（keys[0], .. keys[i - 1]有序）
	// 按第i个关键字keys[i]建立RADIX个子表，使同一个子表中记录的keys[i]相同
	// f[0..RADIX-1] 和e[0..RADIX-1]分别指向各子表中第一个和最后一个记录
	for (int j = 0; j < RADIX; j++) f[j] = 0; // 各子表初始化为空表
	for (int p = r[0].next; p; p = r[p].next)
	{
		int j = ord(r[p].keys[i]); // ord将记录中第i个关键字映射到[o..RADIX-1]
		if (!f[j]) f[j] = p;
		else r[e[j]].next = p;
		e[j] = p; // 将p所指的节点插入第j个子表中
	} // for
}

void Collect(SLCell& r, int i, ArrType f, ArrType e)
{
	// 按keys[i] 自小到大的将f[0..RADIX-1]所指各子表依次链接成一个链表
	// e[0.。RADIX-1]为各子表的尾指针
	int j = 0;
	for (; !f[j]; j++) j = succ(j); // 找第一个非空子表,succ()为求后继函数
	r[0].next = f[j]; t = e[j]; //r[0].next指向第一个非空子表中第一个节点
	while (j < RADIX)
	{
		for (j = succ(j); j < RADIX - 1 && !f[j]; j = succ(j)); // 找到希望一个非空子表
		if (f[j]) { // 链接两个非空子表
			r[t].next = f[j];
			t = e[j];
		}
	}// while
	r[t].next = 0; // t指向最后一个非空子表中的最后一个节点
}

void RadixSort(SLList& L)
{
	// L是采用静态链表表示的顺序表
	// 对L进行基数排序，使得L成为按关键字自小到大的有序静态链表，L.r[0]为头节点
	for (int i = 0; i < L.recnum; i++) L.r[i].next = i + 1; 
	L.r[L.recnum].next = 0; // 将L改造为静态链表
	for (int i = 0; i < L.keynum; i++) // 按最低位优先对各关键字进行分配和收集
	{
		Distribute(L, r, i, f, e); // 第i趟分配
		Collect(L, r, i, f, e); // 第i趟收集
	} // for
}

