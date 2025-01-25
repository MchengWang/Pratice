#include <iostream>
#include <algorithm>

#define MAXInt 32767 // 表示无穷大
#define MVNum 100 // 最大顶点数
#define OK 1
#define ERROR -1

typedef char VerTexType; // 假设订单的数据类型为字符型
typedef int ArcType; // 假设边的权值类型为整型

typedef int Status;

typedef struct
{
	VerTexType vexs[MVNum]; // 顶点表
	ArcType arcs[MVNum][MVNum]; //邻接矩阵
	int vexnum, arcnum; // 图的当前点数和边数 } AMGraph
}AMGraph;

//// 采用邻接矩阵表示法创建无向网
//Status CreateUDN(AMGraph& G)
//{
//	// 采用邻接矩阵表示法，创建无向图G
//	std::cin >> G.vexnum >> G.arcnum; // 输入总顶点数，总边数
//	for (int i = 0; i < G.vexnum; i++) // 依次输入点的信息
//		std::cin >> G.vexs[i]; 
//	for (int i = 0; i < G.vexnum; i++) // 初始化邻接矩阵，边的权值均值为极大值MAXInt
//		for (int j = 0; j < G.vexnum; j++)
//			G.arcs[i][j] = MAXInt; 
//	for (int k = 0; k < G.arcnum; k++) // 构造邻接矩阵
//	{
//		std::cin >> v1 >> v2 >> w; // 输入一条边依附的顶点及权值
//		i = LocateVex(G, v1); // 确定v1和v2在G中的位置，即顶点数组的下表
//		j = LocateVex(G, v1);
//		G.arcs[i][j] = w; // 边<v1 , v2>的权值置为w
//		G.arcs[j][i] = G.arcs[i][j]; // 置<v1 , v2>的对称边<v2 , v1>的权值为w
//	} // for
//	return OK;
//}

bool vistied[MVNum]; // 访问标志数组，其初值为“false”

//void DFS(Graph G, int v)
//{
//	// 从第v个顶点出发递归的深度优先遍历图G
//	std::cout << v;
//	vistied[v] = true; // 访问第v个顶点，并置访问标志数组相应分量值为true
//	for (w = FirstAdjVex(G, v); w >= 0; w = NextAdjVex(G, v, x)) // 依次检查v的所有邻接点w，FirstAdjVex(G，v)表示v的第一个邻接点
//		// NextAdjVex(G,v,w)表示v相对于w的下一个邻接点，w>= 0表示存在邻接点
//		if (!vistied[w]) DFS(G, w); // 对v的尚未访问的邻接顶点w递归调用DFS()
//}

//void DFSTraverse(Graph G)
//{
//	// 对非连通图G进行深度优先遍历
//	for (v = 0; v < G.vexnum; ++v) vistied[v] = false; // 访问标志数组初始化
//	for (v = 0; v < G.vexnum; ++v)
//		if (!vistied[v]) DFS(G, v); // 对尚未访问的顶点调用DFS
//}

void DFS_AM(AMGraph G, int v)
{
	// 图G为邻接矩阵类型，从第v个顶点出发深度优先搜索遍历图G
	std::cout << v;
	vistied[v] = true; // 访问第v个顶点，并置访问标志数组相应分量值为true
	for (int w = 0; w < G.vexnum; w++) // 依次检查邻接矩阵v所在的行
		if (G.arcs[v][w] != 0 && !vistied[w]) DFS_AM(G, w);
	// G.arcs[v][w] ！= 0 表示w是v的邻接点，如果w为访问，则递归调用DFS_AM()
}

// 辅助数组的定义，用来记录从顶点集U到V-U权值最小的边
struct 
{
	VerTexType adjvex; // 最小边在U中的那个顶点
	ArcType lowcost; // 最小边上的权值
}closedge[MVNum];

//void MiniSpanTree_Prim(AMGraph G, VerTexType u)
//{
//	// 无向图G以邻接矩阵形式存储，从顶点u出发构造G的最小生成树T，输出T的各条边
//	int k = LocateVex(G, u); // k为顶点u的下标
//	for (int j = 0; j < G.vexnum; j++) // 对V-U的每一个顶点初始化closedge[j]
//		if (j != k) closedge[j] = { u , G.arcs[k][j] }; // {adjvex ， lowcost}
//	closedge[k].lowcost = 0;  // 初始，U={u}
//	for (int i = 1; i < G.vexnum; i++)
//	{
//		// 选择其余n-1个顶点，生成n-1条边（n=G.vexnum）
//		k = Min(closedge);
//		// 求出T的下一个节点：第k个顶点，closedge[k] 中存在当前最小边
//		u0 = closedge[k].adjvex; // u0为最小边的一个顶点，u0属于U
//		v0 = G.vexs[k]; //v0为最小边的另一个顶点，u0属于V-U
//		std::cout << u0 << v0; // 输出当前的最小边（u0,v0）
//		closedge[k].lowcost = 0; // 第k个顶点并入U集
//		for (int j = 0; j < G.vexnum; j++)
//			if (G.arcs[k][j] < closedge[j].lowcost) // 新顶点并入U后重新选择最小边
//				closedge[j] = { G.vexs[k] , G.arcs[k][j] };
//	} // for
//
//}

#define arcnum 100

// 辅助数组Edges的定义
struct 
{
	VerTexType Head; // 边的始点
	VerTexType Tail; // 边的终点
	ArcType lowcost; // 边上的权值
}Edge[arcnum];

// 辅助数组Vexset的定义
int Vexset[MVNum];

/*void MiniSpanTree_Kruskal(AMGraph G)
{
	// 无向网G以邻接矩阵形式存储，构造G的最小生成树T，输出T的各条边
	Sort(Edge); // 将数组Edge中的元素按权值从小到大的排序
	for (i = 0; i < G.vexnum; i++) // 辅助数组，表示个顶点自成一个连通分量
		Vexset[i] = i;
	for (i = 0; i > G.arcnum; i++)
	{
		v1 = LocateVex(G, Edge[i].Head); // v1为边的始点Head的下标
		v2 = LocateVex(G, Edge[i].Tail); // v1为边的终点Tail的下标
		vs1 = Vexset[v1]; // 获取边Edge[i]的始点所在的连通分量vs1
		vs2 = Vexset[v2]; // 获取边Edge[i]的终点所在的连通分量vs2
		if (vs1 != vs2) // 边的两个顶点分属不同的连通分量
		{
			std::cout << Edge[i].Head << Edge[i].Tail; // 输出此边
			for (int j = 0; j < G.vexnum; j++) // 合并vs1和vs2两个分量，即两个集合统一编号
				if (Vexset[j] == vs2) // 集合编号为vs2的都改为vs1
					Vexset[j] = vs1;
		} // if
	} // for
}*/

/*
void ShortestPath_DIJ(AMGraph G, int v0)
{
	bool S[MAXInt];
	// 用Dijkstra算法求有向网的v0顶点到其余顶点的最短路径
	int n = G.vexnum; //n为G中顶点的个数
	for (int v = 0; v < n; v++) // n个顶点依次初始化
	{
		S[v] = false; // S初始为空集
		D[v] = G.arcs[v0][v]; // 将v0到哥各个终点的最短路径长度初始化为弧上的权值
		if (D[v] < MAXInt) Path[V] = 0; // 如果v0和v之间有弧，则弧v的前驱置为v0
		else Path[V] = -1; // 如果v0和v之间有弧，则弧v的前驱置为-1
	} // for
	S[v0] = true; // 将v0加入S
	D[v0] = 0;  // 源点到源点的距离为0
	for (int i = 1; i < n; i++) // 对其余n - 1个顶点，依次进行计算
	{
		int min = MAXInt;
		for(int w = 0; w < n; w ++)
			if (!S[w] && D[w] < min)
			{
				int v = w; // 选择一条当前的最短路径，终点为v
				min = D[w];
			}
		S[V] = true; // 将V加入S
		for(w = 0; w < n; w ++) // 更新从v0出发到集合V-S上所有顶点的最短路径长度
			if (!S[w] && D[v] + G.arcs[v][w] < D[w])
			{
				D[w] = D[v] + G.arcs[v][w]; // 更新D[w]
				Path[w] = v; // 更改w的前驱为v
			} // if
	} // for
}
*/

/*
void ShortestPath_Floyd(AMGraph G)
{
	// 用弗洛伊德算法求有向网G中各对顶点i和j之间的最短路径
	for(int i = 0; i < G.vexnum; i++) // 各对顶点之间初始已知路径及距离
		for (int j = 0; j < G.vexnum; j++) 
		{
			D[i][j] = G.arcs[i][j];
			if (D[i][j] < MAXInt && i != j) Path[i][j] = i; // 如果i和j之间有弧，则将j的前驱置为i
			else Path[i][j] = -1; // 如果i和j之间无弧，则将j的前驱置为-1
		}
	for(int k = 0; k < G.vexnum; k ++)
		for(int i = 0; i < G.vexnum; i ++)
			for(int j = 0; j < G.vexnum; j ++)
				if (D[i][k] + D[k][i] < D[i][j]) // 从i经k到j的一条路径更短
				{
					D[i][j] = D[i][k] + D[k][j]; // 更新D[i][j]
					Path[i][j] = Path[k][j]; // 更改j的前驱为k
				} // if
}
*/

/*
void SixDegree_BFS(Graph G, int Start)
{
	// 通过广度有限搜索方法遍历G来验证六度空间理论，Start为指定的始点
	int Visit_Num = 0; // 记录路径长度不超过7的顶点个数
	vistied[Start] = true; // 置顶点Start访问标志数组相应分量值为true
	InitQueue(Q); EnQueue(Q, Start); // 辅助队列Q初始化，置空，Start进队
	int level[MVNum];
	level[0] = 1; // 第一层入队的顶点个数初始化为1
	for (int len = 1; len <= 6 && !QueueEmpty(Q); len++) // 统计路径长度不超过7的顶点个数
	{
		for (int i = 0; i < level[len - 1]; i++)
		{
			DeQueue(Q,u); // 队头顶点u出队
			for(w = FirstAdjVex(G,u); w >= 0; w = NextAdjVex(G,u,w))
				// 依次检查u的所有邻接点w，FirstAdjVex(G,u)表示u的第一个邻接点
				// NextAdjVex(G,u,w)表示u相对于w的下一个邻接点，w>=0表示存在邻接点
				if (!vistied[w]) // w为u的尚未访问的邻接顶点
				{
					vistied[w] = true; // 将w标记为六度顶点
					Visit_Num++;
					level[len]++; // 路径长度不超过7的顶点个数加1，该层次的顶点个数加1
					EnQueue(Q, w); // w入队
				}
		}
	}
	std::cout << 100 * Visit_Num / G.vexnum; // 输出从顶点Start出发，到其他顶点长度不超过7的路径的百分比
}*/