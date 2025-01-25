#include <iostream>

struct Node
{
	int data;
	Node* next;
	Node() :data(0), next(nullptr) {}
	Node(int x) :data(x), next(nullptr) {}
	Node(int x, Node* next) :data(x), next(next) {}
};

// 用空间换时间
Node* func(Node* node, int n)
{
	// 创建一个大小为 n 的数组 因为数组下表是从 0 开始的，为了方便直接让数组从 下标 1 开始存储
	int* nums = new int[n + 1] { 0 };
	
	// 创建工作节点，存储当前节点信息
	Node* cur = node;

	// 循环，当当前节点的下一个节点不存在，则退出
	while (cur->next)
	{
		// 定义一个临时存储数据变量
		int temp = cur->next->data > 0 ? cur->next->data : -(cur->next->data);
		if (nums[temp])
		{
			Node* t = cur->next;
			cur->next = t->next;
			delete t;
		}
		else
		{
			nums[temp] = 1;
			cur = cur->next;
		}
	}

	return node->next;
}

int main()
{
	Node* node = new Node(0, new Node(21, new Node(-15, new Node(-15, new Node(-7, new Node(15, nullptr))))));
	Node* s = func(node, 21);
	while (s)
	{
		std::cout << s->data << " ";
		s = s->next;
	}
	return 0;
}