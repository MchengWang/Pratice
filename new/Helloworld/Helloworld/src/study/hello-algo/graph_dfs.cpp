#include "basic.h"
#include "graph_adjacency_list.cpp"

// 深度优先遍历辅助函数
void dfs(GraphAdjList& graph, std::unordered_set<Vertex*>& visitied, std::vector<Vertex*>& res, Vertex* vet)
{
	res.push_back(vet); // 记录访问顶点
	visitied.emplace(vet); // 标记该顶点已被访问
	// 遍历该顶点的所有邻接顶点
	for (Vertex* adjVet : graph.adjList[vet])
	{
		if (visitied.count(adjVet))
			continue; // 跳过已被访问的顶点
		// 递归访问邻接顶点
		dfs(graph, visitied, res, adjVet);
	}
}

// 深度优先遍历
// 使用邻接表来表示图，以便获取指定顶点的所有邻接顶点
std::vector<Vertex*> graphDFS(GraphAdjList& graph, Vertex* startVet)
{
	// 顶点遍历序列
	std::vector<Vertex*> res;
	// 哈希表，用于记录已被访问的顶点
	std::unordered_set<Vertex*> visitied;
	dfs(graph, visitied, res, startVet);
	return res;
}