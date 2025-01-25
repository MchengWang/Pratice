#include <iostream>

struct Node
{
	char data;
	Node* next;
	Node() :data('0'), next(nullptr) {}
	Node(char ch) :data(ch), next(nullptr) {}
	Node(char ch, Node* next) :data(ch), next(next) {}
};

Node* Solution(Node* n1, Node* n2)
{
	// 先判断单链表的长度并且将长的指针移动到跟短的长度相同的位置上
	Node* temp1 = n1, * temp2 = n2;
	int c1 = 0 ,c2 = 0;
	while (temp1)
	{
		temp1 = temp1->next;
		c1++;
	}

	while (temp2)
	{
		temp2 = temp2->next;
		c2++;
	}

	for (; c1 > c2; c1--)
		n1 = n1->next;
	for (; c1 < c2; c2--)
		n2 = n2->next;
	while (n1->next != nullptr && n1->next != n2->next)
	{
		n1 = n1->next;
		n2 = n2->next;
	}

	return n1->next;
}

int main()
{
	Node* n1 = new Node('l', new Node('o', new Node('a', new Node('d', new Node('i', new Node('n', new Node('g', nullptr)))))));
	Node* n2 = new Node('b', new Node('2', new Node('i', new Node('n', new Node('g', nullptr)))));
	Node* result = Solution(n1, n2);
	std::cout << result->data << std::endl;
	return 0;
}