#include <iostream>
#include <string>

#define MVNum 100 //最大顶点数

#define OK 1
#define ERROR -1

typedef int VerTexType;
typedef int Status;
typedef std::string OtherInfo;

typedef struct ArcNode // 边节点
{
	int adjevx; // 该边所指向的顶点的位置
	struct ArcNode* nextarc; // 指向下一条边的指针
	OtherInfo infor; // 和边相关的信息
}ArcNode;

typedef struct VNode
{
	VerTexType data;
	ArcNode* firstarc; // 指向第一条依附该顶点的边的指针
}VNode , AdjList[MVNum]; // AdjList表示邻接表类型

typedef struct
{
	AdjList vertices;
	int vexnum, arcnum; // 图的当前顶点数和边数
}ALGraph;

//Status CreateUDG(ALGraph& G)
//{
//	// 采用邻接表表示法，创建无向图G
//	std::cin >> G.vexnum >> G.arcnum; // 输入总顶点数，总边数
//	for (int i = 0; i < G.vexnum; i++) // 输入各点，构造表头节点表
//	{
//		std::cin >> G.vertices[i].data; // 输入顶点值
//		G.vertices[i].firstarc = NULL; // 初始化表头节点的指针域为NULL
//	} // for
//	for (int k = 0; k < G.arcnum; k++) // 输入各边，构造边表
//	{
//		std::cin >> v1 >> v2; // 输入一条边依附的两个顶点
//		i = LocateVex(G, v1); j = LocateVex(G, v2); // 确定v1和v2在G中的位置，即顶点在G.vertices中的序号
//		ArcNode* p1 = new ArcNode; // 生成一个新的边节点*p1
//		p1->adjevx = j; // 邻接点序号为j
//		p1->nextarc = G.vertices[i].firstarc; // 将新节点*p1插入顶点v1的边表头部
//		G.vertices[i].firstarc = p1;
//		ArcNode* p2 = new ArcNode; // 生成另一个对称的新的边节点*p2
//		p2->adjevx = i; // 邻接点序号为i
//		p2->nextarc = G.vertices[j].firstarc; // 将新节点*p2插入顶点v2的边表头部
//		G.vertices[j].firstarc = p2;
//	} // for
//	return OK;
//}

bool vistied[MVNum]; // 访问标志数组，其初值为“false”

void DFS_AL(ALGraph G, int v)
{
	// 图G为邻接表类型，从第v个顶点出发深度优先搜索遍历图G
	std::cout << v;
	vistied[v] = true; // 访问第v个顶点，并置访问标志数组相应分量值为true
	ArcNode* p = G.vertices[v].firstarc; // p指向v的边链表的第一个边节点
	while (p != NULL) // 边节点非空
	{
		int w = p->adjevx; // 表示w是v的邻接点
		if (!vistied[w]) DFS_AL(G, w); //如果w为访问，则递归调用DFS_AL()
		p = p->nextarc; // p指向下一个边节点
	} // while
}

//void BFS(Graph G, int v)
//{
//	// 按广度优先非递归遍历连通图G
//	std::cout << v;
//	vistied[v] = true; // 访问第v个顶点，并置访问数组相应分量值为true
//	InitQueue(Q); // 辅助队列Q初始化，置空
//	EnQueue(Q, v); // v入队
//	while (!QueueEmpty(Q)) // 队列非空
//	{
//		DeQueue(Q, u); // 队头元素出队并置为u
//		for(w = FirstAdjVex(G , u); w > 0; w= NextAdjVex(G , u , w))
//			// 依次检查u的所有邻接点w，FirstAdjVex(G,u)表示u的第一个邻接点
//			// NextAdjVex(G,u,w)表示u相对于w的下一个邻接点，w>=0表示存在邻接点
//			if (!vistied[w]) // w为u的尚未访问的邻接顶点
//			{
//				std::cout << w;
//				vistied[w] = true; // 访问w，并置访问标志数组相应分量为true
//				EnQueue(Q, w); // w入队
//			} // if
//	} // while
//}
/*
Status TopologicalSort(ALGraph G, int top[])
{
	// 有向图G采用邻接表作为存储结构
	// 若G无回路，则生成G的一份拓扑序列topo并返回OK，否则ERROR
	FindInDegree(G, indegree); // 求出各顶点的入度并存入数组indegree中
	InitStack(S); // 栈S初始化为空
	for (int i = 0; i < G.vexnum; i++)
		if (!indegree[i]) Push(S, i); // 入度为0者进栈
	int m = 0; // 对输出顶点计数，初始为0
	while (!StackEmpty(S)) // 栈S非空
	{
		Pop(S, i); //使栈顶顶点Vi出栈
		topo[m] = i; // 将顶点vi保存在拓扑序列数组topo中
		m++; // 对输出顶点计数
		p = G.vertices[i].firstarc;
		while (p != NULL)
		{
			int k = p->adjvex;  // vk为vi的邻接点
			--indegree[k]; // vi的每个邻接点的入度减1
			if (indegree[k] == 0) Push(S, k); // 若入度减为0，则入栈
			p = p->nextarc; // p指向顶点vi，下一个邻接节点
		} // while
	} // while
	if (m < G.vexnum) return ERROR; // 该有向图有回路
	else return OK;
}*/
/*
Status CriticalPath(ALGraph G)
{
	// G为邻接表存储的有向网，输出G的各项关键活动
	if (!TopologicalSort(G, topo)) return ERROR; // 调用拓扑排序算法，使拓扑排序保存在topo中，若调用失败，则存在有向环，返回ERROR
	int n = G.vexnum; // n为顶点个数
	for (int i = 0; i < n; i++)
		ve[i] = 0; // 给每个时间的最早发生时间置初值0
	for (int i = 0; i < n; i++)
	{
		int k = topo[i]; // 取得拓扑序列中的顶点序号k
		ArcNode* p = G.vertices[k].firstarc; // p指向k的第一个邻接顶点
		while (p != NULL)
		{	// 依次更新k的所有邻接顶点的最早发生时间
			int j = p->adjevx;  // j为邻接顶点的序号
			if (ve[j] < ve[k] + p->weight) // 更新顶点j的最早发生时间ve[j]
				ve[j] = ve[k] + p->weight;
			p = p->nextarc; // p指向k的下一个邻接顶点
		} // while
	} // for
	for (int i = 0; i < n; i++) // 为每个时间的最迟发生时间置初值ve[n - 1]
		v1[i] = ve[n - 1]; 
	for (int i = n - 1; i >= 0; i--)
	{
		k = topo[i]; // 取得拓扑序列中的顶点序号k
		p = G.vertices[k].firstarc; // p指向k的第一个邻接顶点
		while (p != NULL) // 根据k的邻接点，更新k的最次发生时间
		{
			j = p->adjvex; // j为邻接顶点的序号
			if (v1[k] > v1[j] - p->weight) // 更新顶点k的最迟发生时间v1[k]
				v1[k] = v1[j] - p->weight;
			p = p->nextarc; // p指向k的下一个邻接顶点
		} // while
	} // for
	for (int i = 0; i < n; i++) // 每次循环针对vi为活动开始点的所有活动
	{
		p = G.vertices[i].firstarc; // p指向i的第一个邻接顶点
		while (p != NULL)
		{
			j = p->adjvex; // j为i的邻接顶点的序号
			e = ve[i]; // 计算活动<v1 , v2>的最早开始时间
			l = v1[j] - p->weight; // 计算活动<v1,v2>的最迟开始时间
			if (e == 1) // 若为关键活动，则输出<vi , vi>
				std::cout << G.vertices[i].data << G.vertices[j].data; 
			p = p->nextarc; // p指向i的下一个邻接顶点
		} // while
	} // for
}*/