#include <iostream>

struct Node
{
	int val;
	Node* left;
	Node* right;
	Node* next;
	Node() :val(0), left(nullptr), right(nullptr), next(nullptr) {}
	Node(int x) :val(x), left(nullptr), right(nullptr), next(nullptr) {}
	Node(int x, Node* let, Node* right, Node* next)
		:val(x), left(left), right(right), next(next) {}
};

class Solution
{
public:
	Node* connect(Node* root) {
		if (root == nullptr) {
			return root;
		}
			
		// 从根节点开始
		Node* leftmost = root;
			
		while (leftmost->left != nullptr) {
			
			// 遍历这一层节点组织成的链表，为下一层的节点更新 next 指针
			Node* head = leftmost;
			
			while (head != nullptr) {
			
			    // CONNECTION 1
			    head->left->next = head->right;
			
			    // CONNECTION 2
			    if (head->next != nullptr) {
			        head->right->next = head->next->left;
			    }
			
			    // 指针向后移动
			    head = head->next;
			}
			
			// 去下一层的最左的节点
			leftmost = leftmost->left;
		}
			
		return root;
	}
};