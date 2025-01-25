#include <iostream>

typedef enum { atom, list } elemtag; // atom = 0:原子，list=1：子表

typedef int atomtype;

typedef struct glnode
{
	elemtag tag; // 公共部分，用于区分原子节点和表节点
	union // 原子节点和表节点的连个部分
	{
		atomtype tag; // atom是原子节点的值域，atomtype由用户定义
		struct { struct glnode* hp, * tp; } ptr; // ptr是表节点的指针域，ptr.hp和ptr.tp分别指向表头和表尾
	};
}*glist; // 广义表类型

// 病毒感染检测
void virus_detction()
{
	// 利用bf算法实现病毒检测
	std::ifstream infile("病毒感染检测输入数据.txt");
	std::ofstream outfile("病毒感染检测输出结果.txt");
	infile >> num; // 读取待检测的任务数
	while (num--) // 依次检测每对病毒dna和人的dna是否匹配 
	{
		infile >> virus.ch + 1; // 读取病毒dna序列，字符串从下标1开始存储
		infile >> person.ch + 1; // 读取人的dna序列
		vir = virus.ch; // 将病毒dna临时暂存在vir中，以备输出
		flag = 0; // 用来标识是否匹配，初始为0，匹配后为非0
		m = virus.length; // 病毒dna序列的长度是m
		for (i = m + 1, j = 1; j <= m; j++)
			virus.ch[i++] = virus.ch[j]; // 将病毒字符串的长度扩大2倍
		virus.ch[2 * m + 1] = '\0'; // 添加结束符号
		for (i = 0; i < m; i++) // 依次取得每个长度为m的病毒dna环状字符串temp
		{
			for (j = 1; j < m; j++)
				temp.ch[j] = virus.ch[i + j];
			temp.ch[m + 1] = '\0';  // 添加结束符号
			flag = index_bf(person, temp, 1); // 模式匹配
			if (flag) break; // 匹配即可退出循环
		} // for
		if (flag) outfile << vir + 1 << "  " << person.ch + 1 << "  " << "yes" << std::endl;
		else outfile << vir + 1 << "  " << person.ch + 1 << "  " << "no" << std::endl;
	} // while
}