#include <iostream>

#define MAXQSIZE 100 // 队列可能达到的最大长度
#define OK 1
#define ERROR -1

typedef int QElemType;
typedef int Status;

typedef struct
{
	QElemType* base; // 存储空间的基地址
	int front; // 头指针
	int rear; //尾指针
}SqQueue;

//// 初始化
//Status InitQueue(SqQueue& Q)
//{
//	// 构造一个空队列Q
//	Q.base == new QElemType[MAXQSIZE]; // 为队列分配一个最大容量为MAXQSIZE的数组空间
//	if (!Q.base) exit(OVERFLOW); // 存储分配失败
//	Q.front = Q.rear = 0; // 将头指针和尾指针置为0，队列为空
//	return OK;
//}

//// 求队列长度
//int QueueLength(SqQueue Q)
//{
//	// 返回Q的元素个数，即队列的长度
//	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
//}

// 入队
Status EnQueue(SqQueue& Q, QElemType e)
{
	// 插入元素e为Q的新的队尾元素
	if ((Q.rear + 1) % MAXQSIZE == Q.front) // 若尾指针在循环意义上加1后等于头指针，表明队满
		return ERROR;
	Q.base[Q.rear] = e; // 新元素插入队尾
	Q.rear = (Q.rear + 1) % MAXQSIZE; // 队尾指针加1
	return OK;
}

// 出队
Status DeQueue(SqQueue& Q, QElemType& e)
{
	// 删除Q的队头元素，用e返回其值
	if (Q.front == Q.rear) return ERROR; // 队空
	e = Q.base[Q.front]; // 保存队头元素
	Q.front = (Q.front + 1) % MAXQSIZE; // 队头指针加1
	return OK;
}

// 取队头元素
//QElemType GetHead(SqQueue Q)
//{
//	// 返回Q的队头元素，不修改队头指针
//	if (Q.front != Q.rear) // 队列非空
//		return Q.base[Q.front]; // 但会队头元素的值，队头指针不变
//}

