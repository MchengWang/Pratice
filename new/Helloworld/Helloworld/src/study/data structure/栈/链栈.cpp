#include <iostream>
#define OK 1
//#define ERROR -1

typedef int ElemType;
typedef int SElemType;
typedef int Status;

typedef struct StackNode
{
	ElemType data;
	struct StackNode* next;
}StackNode , *LinkStack;

// 初始化
Status InitStack(LinkStack& S)
{
	// 构造一个空栈S，栈顶指针置空
	S = NULL;
	return OK;
}

// 入栈
Status Push(LinkStack& S, SElemType e)
{
	// 在栈顶插入元素e
	LinkStack p = new StackNode; // 生成新节点
	p->data = e; // 将新节点数据域置为e
	p->next = S; // 将新节点插入栈顶
	S = p; // 修改栈顶指针为p
	return OK;
}

// 出栈
Status Pop(LinkStack& S, SElemType& e)
{
	// 删除S的栈顶元素，用e返回其值
	if (S == NULL) return ERROR; // 栈空
	e = S->data; // 将栈顶元素赋给e
	LinkStack p = S; // 用p临时保存栈顶元素空间，以备释放
	S = S->next; // 修改栈顶指针
	delete p; //释放原栈顶元素的空间
	return OK;
}

// 取栈顶元素
SElemType GetTop(LinkStack S)
{
	// 返回S的栈顶元素，不修改栈顶指针
	if (S != NULL) // 栈非空
		return S->data; // 返回栈顶元素的值，栈顶指针不变
}