#include <iostream>

struct Node
{
	int data;
	Node* next;
	Node() :data(0), next(nullptr) {}
	Node(int x) :data(x), next(nullptr) {}
	Node(int x, Node* next) :data(x), next(next) {}
};

Node* change_list(Node* h)
{
	Node* hear = h;
	Node* fear = h;

	while (fear->next != nullptr) // 寻找中间节点
	{
		hear = hear->next; // hear 走一步
		fear = fear->next;
		if (fear->next != nullptr) fear = fear->next; // fear 走两步
	}

	fear = hear->next; // hear 所指向节点为中间节点，fear 为后半段链表的首节点
	hear->next = nullptr;
	while (fear != nullptr) // 将链表后半段逆置
	{
		Node* temp = fear->next;
		fear->next = hear->next;
		hear->next = fear;
		fear = temp;
	}

	Node* dd = h->next; // dd 指向前半段的第一个数据节点 即 插入点
	fear = hear->next; // fear 指向后半段的第一个数据节点
	hear->next = nullptr; 
	while (fear != nullptr) // 将链表后半段的节点插入指定位置
	{
		Node* temp = fear->next; // temp 指向后半段的下一个节点
		fear->next = dd->next; // 将 fear 所指节点插入 dd 所指节点之后
		dd->next = fear;
		dd = fear->next; // dd 指向前半段的下一个插入点
		fear = temp;
	}

	return h->next;
}

int main()
{
	return 0;
}