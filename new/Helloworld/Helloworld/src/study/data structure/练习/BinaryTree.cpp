#include <iostream>
#include <queue>
#include <stack>
#include "assert.h"

template <typename T>
struct TreeNode
{
	T data;
	TreeNode<T>* lchild, *rchild;
};

template <typename T>
void preOrder(TreeNode<T>* root)
{
	if (root)
	{
		std::cout << root->data << std::endl;
		preOrder(root->lchild);
		preOrder(root->rchild);
	}
}

template <typename T>
void inOrder(TreeNode<T>* root)
{
	if (root)
	{
		preOrder(root->lchild);
		std::cout << root->data << std::endl;
		preOrder(root->rchild);
	}
}

template <typename T>
void postOrder(TreeNode<T>* root)
{
	if (root)
	{
		preOrder(root->lchild);
		preOrder(root->rchild);
		std::cout << root->data << std::endl;
	}
}

int main()
{
	TreeNode<int>* root = new TreeNode<int>();
	TreeNode<int>* lchild = new TreeNode<int>();
	TreeNode<int>* rchild = new TreeNode<int>();
	TreeNode<int>* llchild = new TreeNode<int>();
	TreeNode<int>* lrchild = new TreeNode<int>();
	TreeNode<int>* rlchild = new TreeNode<int>();
	TreeNode<int>* rrchild = new TreeNode<int>();
	
	root->data = 0;
	lchild->data = 1;
	llchild->data = 2;
	lrchild->data = 3;
	rchild->data = 4;
	rlchild->data = 5;
	rrchild->data = 6;

	root->lchild = lchild;
	root->rchild = rchild;

	lchild->lchild = llchild;
	lchild->rchild = lrchild;

	rchild->lchild = rlchild;
	rchild->rchild = rrchild;

	preOrder(root);
	std::cout << "+++++" << std::endl;
	inOrder(root);
	std::cout << "+++++" << std::endl;
	postOrder(root);
	return 0;
}