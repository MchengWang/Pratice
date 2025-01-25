#include <iostream>

struct Node
{
	int weight;
	Node* left, * right;
	Node() :weight(0), left(nullptr), right(nullptr) {}
	Node(int x) :weight(x), left(nullptr), right(nullptr) {}
	Node(int x, Node* left) :weight(x), left(left), right(nullptr) {}
	Node(int x, Node* right) :weight(x), left(nullptr), right(right) {}
	Node(int x, Node* left, Node* right) :weight(x), left(left), right(right) {}
};

int WPL(Node* root)
{
	return WPL1(root, 0);
}

int WPL1(Node* root, int d)
{
	if (root->left == nullptr && root->right == nullptr)
		return (root->weight * d);
	else
		return (WPL1(root->left, d + 1) + WPL1(root->right, d + 1));
}

int main()
{
	return 0;
}