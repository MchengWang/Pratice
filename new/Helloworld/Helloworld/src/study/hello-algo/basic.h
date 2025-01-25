#pragma once

#include <iostream>

#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_set>
#include <unordered_map>

#include <algorithm>
#include <functional>

#include <exception>

typedef int Vertex;

/* 链表节点结构体 */
struct ListNode
{
	int val;								   // 节点值
	ListNode* next;							   // 指向下一节点的指针
	ListNode(int x) : val(x), next(nullptr) {} // 构造函数
};

/* 双向链表节点 */
struct DoublyListNode
{
	int val; // 节点值 
	DoublyListNode* next; // 后继节点指针
	DoublyListNode* prev; // 前驱节点指针
	DoublyListNode(int val) : val(val), prev(nullptr), next(nullptr) {}
};

/* 键值对 */
struct Pair
{
public:
	int key;
	std::string val;
	Pair(int key, std::string val)
	{
		this->key = key;
		this->val = val;
	}
};

/* 二叉树节点结构体 */
struct TreeNode
{
	int val; // 节点值
	TreeNode* left, * right; // 左右子节点指针
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/* AVL 树节点类 */
struct AVLTreeNode
{
	int val{}; // 节点值
	int height = 0; // 节点高度
	AVLTreeNode* left{}; // 左子节点
	AVLTreeNode* right{}; // 右子节点
	AVLTreeNode() = default;
	explicit AVLTreeNode(int x) : val(x) {}
};

inline void freeMemoryLinkedList(ListNode* node)
{
	while (node)
	{
		ListNode* temp = node;
		node = node->next;
		delete temp;
	}
}