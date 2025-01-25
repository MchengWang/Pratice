struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* reverseList(ListNode* head) 
	{
		// 定义一个空节点用于前插构造链表
		ListNode* prev = nullptr;
		// 定义一个节点使用 head 的链表信息
		ListNode* curr = head;
		// 若当前节点不为空
		while (curr)
		{
			// 定义一个节点存储当前节点的下一个节点的地址
			ListNode* next = curr->next;
			// 将当前节点的下一个指针指向前插构造空指针
			curr->next = prev;
			// 将前插构造头节点指针移动到当前节点上
			prev = curr;
			// 指向当前节点的指针移动到下一个节点上
			curr = next;
		}
		// 返回前插构造好的链表中
		return prev;
	}
};