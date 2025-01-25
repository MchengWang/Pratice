#include <iostream>

typedef int ElemType;

// 树的二叉链表（孩子-兄弟）存储表示
typedef struct CSNode
{
	ElemType data; 
	struct CSNode* firstchild, * nextsibling;
}CSNode , * CSTree;