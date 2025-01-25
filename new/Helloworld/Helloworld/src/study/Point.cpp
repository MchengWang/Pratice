#include <iostream>

template <typename T>
struct ListNode
{
	T val;
	ListNode<T>* next;
	ListNode() :val(0), next(nullptr) {}
	ListNode(T t) :val(t), next(nullptr) {}
	ListNode(T t, ListNode<T>* next) :val(t), next(next) {}
};

int main()
{
	ListNode<int>* p0 = new ListNode<int>(0);
	ListNode<int>* p1 = new ListNode<int>(1, p0);
	ListNode<int>* p2 = new ListNode<int>(2, p1);
	ListNode<int>* p3 = new ListNode<int>(3, p2);
	ListNode<int>* p4 = new ListNode<int>(4, p3);

	ListNode<int>* temp = p4;

	/*while (p4)
	{
		std::cout << p4->val << ",";
		p4 = p4->next;
	}*/

	
	while (temp->next)
	{
		temp = temp->next;
	}

	temp->next = p4;
	
	ListNode<int>* p = temp;

	int count = 14;
	while (count--)
	{
		std::cout << temp->val << ",";
		temp = temp->next;
	}

	temp->next = nullptr;

	std::cout << std::endl;

	while (p->next)
	{
		std::cout << p->val << ",";
		p = p->next;
	}


	std::cin.get();
}