struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
		ListNode* dummyHead = new ListNode(0); // 设置一个虚拟头结点
		dummyHead->next = head; // 将虚拟头结点指向head，这样方面后面做删除操作
		ListNode* cur = dummyHead;

		while (cur->next) {
			if (cur->next->val == val) {
				ListNode* tmp = cur->next;
				cur->next = cur->next->next;
				delete tmp;
			}
			else {
				cur = cur->next;
			}
		}
		return dummyHead->next;
    }
};