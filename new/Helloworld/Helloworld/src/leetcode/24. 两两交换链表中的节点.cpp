#include <iostream>

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		// 设置一个最初的节点指针
		ListNode* init = new ListNode(0);
		// 该节点指针的下一个指向 head 头指针
		init->next = head;
		// 创建一个临时指针用于交换节点
		ListNode* temp = init;
		// 当临时指针的下一个元素和下下个元素不为空
		while (temp->next != nullptr && temp->next->next != nullptr)
		{
			// 分别定义两个节点存储下一个和下下一个节点的信息
			ListNode* node1 = temp->next;
			ListNode* node2 = temp->next->next;
			// 交换节点
			temp->next = node2;
			node1->next = node2->next;
			node2->next = node1;
			temp = node1;
		}
		// 返回节点
		return init->next;
	}

	void PrintListNode(ListNode* head)
	{
		while (head)
		{
			std::cout << head->val << " ";
			head = head->next;
		}
	}
};

