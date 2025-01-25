#include <iostream>
#include <vector>

/* 链表节点结构体 */
struct ListNode
{
	int val;								   // 节点值
	ListNode* next;							   // 指向下一节点的指针
	ListNode(int x) : val(x), next(nullptr) {} // 构造函数
};

/* 基于链表实现的栈 */
class LinkedListStack
{
public:
	LinkedListStack()
	{
		stackTop = nullptr;
		stkSize = 0;
	}

	~LinkedListStack()
	{
		// 遍历链表删除节点，释放内存
		freeMemoryLinkedList(stackTop);
	}

	/* 获取栈的长度 */
	int size()
	{
		return stkSize;
	}

	/* 判断栈是否为空 */
	bool isEmpty()
	{
		return size() == 0;
	}

	/* 入栈 */
	void push(int num)
	{
		ListNode* node = new ListNode(num);
		node->next = stackTop;
		stackTop = node;
		stkSize++;
	}

	/* 出栈 */
	int pop()
	{
		int num = top();
		ListNode* tmp = stackTop;
		stackTop = stackTop->next;
		// 释放内存
		delete tmp;
		stkSize--;
		return num;
	}

	/* 访问栈顶元素 */
	int top()
	{
		if (isEmpty())
			std::cout << "栈为空" << std::endl;
		return stackTop->val;
	}

	/* 将 List 转换为 Array 并返回 */
	std::vector<int> toVector()
	{
		ListNode* node = stackTop;
		std::vector<int> res(size());
		for (int i = res.size() - 1; i >= 0; i--)
		{
			res[i] = node->val;
			node = node->next;
		}
		return res;
	}
private:
	ListNode* stackTop; // 将头节点作为栈顶
	int stkSize; // 栈的长度

	inline void freeMemoryLinkedList(ListNode* node)
	{
		while (node)
		{
			ListNode* temp = node;
			node = node->next;
			delete temp;
		}
	}
};