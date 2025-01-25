#include "basic.h"

/* 基于链表实现的队列 */
class linkedListQueue
{
public:
	linkedListQueue()
		: queSize(0), front(nullptr), rear(nullptr)
	{
	}

	~linkedListQueue()
	{
		// 遍历链表删除节点，释放内存
		freeMemoryLinkedList(front);
	}

	/* 获取队列的长度 */
	int size()
	{
		return queSize;
	}

	/* 判断队列是否为空 */
	bool isEmpty()
	{
		return queSize == 0;
	}

	/* 入队 */
	void push(int num)
	{
		// 在尾节点后添加 num
		ListNode* node = new ListNode(num);
		// 如果队列为空，则令头尾节点都指向该节点
		if (!front)
		{
			front = node;
			rear = node;
		}
		// 如果队列不为空，则将该节点添加到尾节点后
		else
		{
			rear->next = node;
			rear = node;
		}
		queSize++;
	}

	/* 出队 */
	int pop()
	{
		int num = peek();
		// 删除头节点
		ListNode* tmp = front;
		front = front->next;
		// 释放内存
		delete tmp;
		queSize--;
		return num;
	}

	/* 访问队首元素 */
	int peek()
	{
		if (size() == 0)
			std::cout << "队列为空" << std::endl;
		return front->val;
	}

	/* 将链表转化为 vector 并返回 */
	std::vector<int> toVector()
	{
		ListNode* node = front;
		std::vector<int> res(size());
		for (int i = 0; i < res.size(); i++)
		{
			res[i] = node->val;
			node = node->next;
		}
		return res;
	}
private:
	ListNode* front, *rear; // 头节点 front， 尾节点 rear
	int queSize;
};