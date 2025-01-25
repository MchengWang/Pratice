#include <iostream>

/* 链表节点结构体 */
struct ListNode
{
	int val;								   // 节点值
	ListNode* next;							   // 指向下一节点的指针
	ListNode(int x) : val(x), next(nullptr) {} // 构造函数
};

/* 双向链表节点结构体 */
struct douListNode
{
	int val;                // 节点值
	douListNode* next;      // 指向后继节点的指针
	douListNode* prev;      // 指向前驱节点的指针
	douListNode(int x) : val(x), next(nullptr), prev(nullptr) {} // 构造函数
};

/* 在链表的节点 n0 之后插入节点 p */
void insert(ListNode* n0, ListNode* p)
{
	ListNode* n1 = n0->next;
	p->next = n1;
	n0->next = p;
}

/* 删除链表的节点 n0 之后的首个节点 */
void remove(ListNode* n0)
{
	if (n0->next == nullptr) return;
	// n0 -> p -> n1
	ListNode* p = n0->next;
	ListNode* n1 = p->next;
	n0->next = n1;
	// 释放内存
	delete p;
}

/* 访问链表中索引为 index 的节点 */
ListNode* access(ListNode* head, int index)
{
	for (int i = 0; i < index; i++)
	{
		if (head == nullptr) return nullptr;
		head = head->next;
	}
	return head;
}

/* 在链表中查找值为 target 的首个节点 */
int find(ListNode* head, int target)
{
	int index = 0;
	while (head != nullptr)
	{
		if (head->val == target) return index;
		head = head->next;
		index++;
	}
	return -1;
}

int main1()
{
	/* 初始化链表 1 -> 3 -> 2 -> 5 -> 4 */
// 初始化各个节点
	ListNode* n0 = new ListNode(1);
	ListNode* n1 = new ListNode(3);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(5);
	ListNode* n4 = new ListNode(4);
	// 构建节点之间的引用
	n0->next = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	return 0;
}