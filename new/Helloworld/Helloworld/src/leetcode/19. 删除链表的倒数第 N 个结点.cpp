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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
		// 使用两个指针分别 用于存储以及中间运算
		ListNode* result = new ListNode(0);
		result->next = head;
		ListNode* temp = result;
		// 存储 head 的链表长度
		int length = 0;
		// 从头往后循环，获得链表长度
		while (head != nullptr)
		{
			length++;
			head = head->next;
		}

		// 计算多少位后的链表需要删掉
		length -= n;
		while (length--)
		{
			temp = temp->next;
		}

		// 将当前节点的下一个指针 换成 当前节点的下一个的下一个的节点
		temp->next = temp->next->next;

		return result->next;
    }
};

int main()
{
	Solution sol;
	ListNode* t = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
	ListNode* TT = sol.removeNthFromEnd(t, 2);
	while (TT != NULL)
	{
		std::cout << TT->val << " ";
		TT = TT->next;
	}
	return 0;
}#include <iostream>

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
		// 使用两个指针分别 用于存储以及中间运算
		ListNode* result = new ListNode(0);
		result->next = head;
		ListNode* temp = result;
		// 存储 head 的链表长度
		int length = 0;
		// 从头往后循环，获得链表长度
		while (head != nullptr)
		{
			length++;
			head = head->next;
		}

		// 计算多少位后的链表需要删掉
		length -= n;
		while (length--)
		{
			temp = temp->next;
		}

		// 将当前节点的下一个指针 换成 当前节点的下一个的下一个的节点
		temp->next = temp->next->next;

		return result->next;
    }
};

int main()
{
	Solution sol;
	ListNode* t = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
	ListNode* TT = sol.removeNthFromEnd(t, 2);
	while (TT != NULL)
	{
		std::cout << TT->val << " ";
		TT = TT->next;
	}
	return 0;
}