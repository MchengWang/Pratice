#include "basic.h"
#include "graph_adjacency_list.cpp"

// 广度优先遍历
// 使用邻接表来表示图，以便获取指定顶点的所有邻接顶点
std::vector<Vertex*> graphBFS(GraphAdjList& graph, Vertex* startVet)
{
	// 顶点遍历序列
	std::vector<Vertex*> res;
	// 哈希表，用于记录已被访问过的顶点
	std::unordered_set<Vertex*> vistied = { startVet };
	// 队列用于实现 BFS
	std::queue<Vertex*> que;
	que.push(startVet);
	// 以顶点 vet 为起点，循环直至访问完所有顶点
	while (!que.empty())
	{
		Vertex* vet = que.front();
		que.pop(); // 队首顶点出队
		res.push_back(vet); // 记录已访问顶点
		// 遍历该顶点的所有邻接顶点
		for (auto adjVet : graph.adjList[vet])
		{
			if (vistied.count(adjVet))
				continue; // 跳过已被访问的顶点
			que.push(adjVet); // 只入队未访问的顶点
			vistied.emplace(adjVet); // 标记该顶点已被访问
		}
	}
	// 返回顶点遍历序列
	return res;
}