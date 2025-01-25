#include <iostream>

#define OK 1
#define ERROR -1

typedef int QElemType;
typedef int Status;

typedef struct QNode
{
	QElemType data;
	struct QNode* next;
}QNode , *QueuePtr;

typedef struct 
{
	QueuePtr front; // 队头指针
	QueuePtr rear; // 队尾指针
}LinkQueue;

// 初始化
Status InitQueue(LinkQueue& Q)
{
	// 构造一个空队列Q
	Q.front = Q.rear = new QNode; // 生成新节点作为头节点，队头和队尾指针指向此节点
	Q.front->next = NULL; // 头节点的指针域置空
	return OK;
}

// 入队
Status EnQueue(LinkQueue& Q, QElemType e)
{
	// 插入元素e为Q的新的队尾元素
	QNode* p = new QNode; // 为入队元素分配节点空间，用指针p指向
	p->data = e; // 将新节点数据域置为e
	p->next = NULL;
	Q.rear->next = p; // 将新节点插入队尾
	Q.rear = p; // 修改队尾指针
	return OK;
}

// 出队
Status DeQueue(LinkQueue& Q, QElemType& e)
{
	// 删除Q的队头元素，用e返回其值
	if (Q.front == Q.rear) return ERROR; // 若队列为空，则返回ERROR
	QNode* p = Q.front->next; // p指向队头元素
	e = p->data; // e保存队头元素的值
	Q.front->next = p->next; // 修改节点的指针域
	if (Q.rear == p) Q.rear = Q.front; // 最后一个元素被删，队尾指针指向节点
	delete p;
	return OK;
}

// 取队头元素
QElemType GetHead(LinkQueue Q)
{
	// 返回Q的队头元素，不修改队头指针
	if (Q.front != Q.rear) // 队列非空
		return Q.front->next->data; // 返回队头元素的值，队头指针不变
}