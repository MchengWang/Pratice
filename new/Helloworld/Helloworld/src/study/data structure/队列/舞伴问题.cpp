#include <iostream>

typedef struct
{
	char name[20]; // 姓名
	char sex; // 性别，F表示女性，M表示男性
}Person;

#define MAXQSIZE 100 // 队列可能达到的最大长度
typedef struct
{
	Person* base; // 队列中数据元素类型为Person
	int front; //头指针
	int rear; //尾指针
}SqQueue;

SqQueue Mdancers, Fdancers; // 分别存储男士和女士入队者队列

void DancePartner(Person dancer[], int num)
{
	// 结果数组dancer中存放跳舞的男女姓名，num是跳舞的人数
	InitQueue(Mdancers); // 男士队列初始化
	InitQueue(Fdancers); // 女士队列初始化
	for (int i = 0; i < num; i++) // 依次将跳舞者根据其性别入队
	{
		Person p = dancer[i]; 
		if (p.sex == 'F') EnQueue(Fdancers, p); // 插入女队
		else EnQueue(Mdancers, p); // 插入男队
	}
	std::cout << "The dancing partners are : \n";
	while (!QueueEmpty(Fdancers) && !QueueEmpty(Mdancers))
	{
		// 依次输出男女舞伴的姓名
		DeQueue(Fdancers, p); // 女士出队
		std::cout << p.name << " "; // 输出出队女士姓名
		DeQueue(Mdancers, p); // 男士出队
		std::cout << p.name << " "; // 输出出队男士姓名
	}
	if (!QueueEmpty(Fdancers)) // 女士队列非空，输出队头女士的姓名
	{
		p = GetHead(Fdancers); // 取女士队头
		std::cout << "The first woman to get a partner is :" << p.name << std::endl;
	}
	else if (!QueueEmpty(Mdancers)) // 男士队列非空，输出队头男士的姓名
	{
		p = GetHead(Fdancers); // 取男士队头
		std::cout << "The first man to get a partner is :" << p.name << std::endl;
	}
}