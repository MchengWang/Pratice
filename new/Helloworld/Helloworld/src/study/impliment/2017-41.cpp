#include <iostream>

struct BTree
{
	char data[10];
	BTree* left, * right;
};

void BTreeToE(BTree* root)
{
	BtreeToExp(root, 1); // 根的高度为 1
}

void BtreeToExp(BTree* root, int deep)
{
	// 空节点返回
	if (!root) return;
	else if (!root->left && !root->right) // 若为叶节点
		std::cout << root->data; // 输出操作数
	else
	{
		if (deep > 1) std::cout << "("; // 若有子表达式则加一层括号
		BtreeToExp(root->left, deep + 1);
		std::cout << root->data; // 输出操作数
		BtreeToExp(root->right, deep + 1);
		if (deep > 1) std::cout << ")"; // 若有子表达式则加一层括号
	}
}

int main()
{
	return 0;
}