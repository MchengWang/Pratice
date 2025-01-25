#include <iostream>
#include <string>

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

long long* nums = new long long[12] {0,1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,10000000000};

#define GET_JINZHI(x) nums[x]

#define STRING_TRANSMIT_INT(x) (((int)x) - 48)

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		getVal(l1, 1 , num1);
		getVal(l2, 1 , num2);

		unsigned long long numss = num2 + num1;
		std::string strs = std::to_string(numss);
		int numtemp = STRING_TRANSMIT_INT(strs.at(strs.size() - 1));
		ListNode* l3 = new ListNode(numtemp), *l = l3;

		for (int i = strs.size() - 2; i >= 0; i--)
		{
			l3->next = new ListNode(STRING_TRANSMIT_INT(strs.at(i)));
			l3 = l3->next;
		}

		return l;
	}

	void getVal(ListNode* l1 , int depth, unsigned long long &num)
	{
		if (!l1) return;
		
		num += (l1->val) * GET_JINZHI(depth);

		getVal(l1->next, depth + 1 , num);
	}

	ListNode* preHead(ListNode* head)
	{
		ListNode* new_head = NULL;
		ListNode* temp = NULL;
		if (head == NULL || head->next == NULL) {
			return head;
		}
		while (head != NULL)
		{
			temp = head;
			//将 temp 从 head 中摘除
			head = head->next;
			//将 temp 插入到 new_head 的头部
			temp->next = new_head;
			new_head = temp;
		}
		return new_head;
	}
private:
	unsigned long long num1 = 0l;
	unsigned long long num2 = 0l;
};

int main()
{
	//ListNode* l1 = new ListNode(2,new ListNode(4 , new ListNode(9)));
	//ListNode* l2 = new ListNode(5,new ListNode(6 , new ListNode(4,new ListNode(9))));

	/*ListNode* l1 = new ListNode(2,new ListNode(4 , new ListNode(3)));
	ListNode* l2 = new ListNode(5,new ListNode(6 , new ListNode(4)));*/

	ListNode* l1 = new ListNode(9);
	ListNode* l2 = new ListNode(1,new ListNode(9 , new ListNode(9,new ListNode(9 ,
		new ListNode(9 , new ListNode(9 , new ListNode(9 , new ListNode(9 ,
			new ListNode(9 , new ListNode(9))))))))));

	Solution sol;

	ListNode *l3 = sol.addTwoNumbers(l1, l2);

	while (l3)
	{
		std::cout << l3->val << " ";
		l3 = l3->next;
	}
	return 0;

	//std::cout << (int)'0' << std::endl; // 48
	//std::cout << (int)'9' << std::endl; // 57
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode temp; 
	ListNode* p = &temp;
	int sign = 0; // 标志 是否有进位
	while (l1 || l2 || sign) { 
		int sum = sign + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
		p = p->next = new ListNode(sum % 10); 
		sign = sum / 10; 
		if (l1) l1 = l1->next; 
		if (l2) l2 = l2->next; 
	}
	return temp.next; 
}