#include "basic.h"

typedef int Vertex;

class GraphAdjList
{
public:
	friend std::vector<Vertex*> graphBFS(GraphAdjList& graph, Vertex* startVet);
	friend void dfs(GraphAdjList& graph, std::unordered_set<Vertex*>& visitied, std::vector<Vertex*>& res, Vertex* vet);

	GraphAdjList(const std::vector<std::vector<Vertex*>>& edges)
	{
		// 添加所有顶点和边
		for (const std::vector<Vertex*>& edge : edges)
		{
			addVertex(edge[0]);
			addVertex(edge[1]);
			addEdge(edge[0], edge[1]);
		}
	}

	// 在 vector 中删除指定节点
	void remove(std::vector<Vertex*>& vec, Vertex* vet)
	{
		for (int i = 0; i < vec.size(); i++)
		{
			if (vec[i] == vet)
			{
				vec.erase(vec.begin() + i);
				break;
			}
		}
	}

	// 获取顶点数量
	int size()
	{
		return adjList.size();
	}

	// 添加顶点
	void addVertex(Vertex* vet)
	{
		if (adjList.count(vet))
			return;
		// 在邻接表中添加一个新链表
		adjList[vet] = std::vector<Vertex*>();
	}

	// 删除顶点
	void removeVertex(Vertex* vet)
	{
		if (!adjList.count(vet))
			std::cout << "不存在顶点" << std::endl;
		// 在邻接表中删除顶点 vet 对应的链表
		adjList.erase(vet);
		// 遍历其他顶点的链表，删除所有包含 vet 的边
		for (auto& adj : adjList)
			remove(adj.second, vet);
	}

	// 添加边
	void addEdge(Vertex* vet1, Vertex* vet2)
	{
		if (!adjList.count(vet1) || !adjList.count(vet2) || vet1 == vet2)
			throw std::invalid_argument("不存在顶点");
		// 添加边 vet1 - vet2
		adjList[vet1].push_back(vet2);
		adjList[vet2].push_back(vet1);
	}

	// 删除边
	void removeEdge(Vertex* vet1, Vertex* vet2)
	{
		if (!adjList.count(vet1) || !adjList.count(vet2) || vet1 == vet2)
			throw std::invalid_argument("不存在顶点");
		// 删除边 vet1 - vet2
		remove(adjList[vet1], vet2);
		remove(adjList[vet2], vet1);
	}

	 // 打印邻接表
	void print()
	{
		std::cout << "邻接表 = ";
		for (auto& adj : adjList)
		{
			const auto& key = adj.first;
			const auto& vec = adj.second;
			std::cout << key<< ": ";
			printVector(vetsToVals(vec));
		}
	}

	std::vector<int> vetsToVals(std::vector<Vertex*> vec)
	{
		
	}

	void printVector(std::vector<int> vertices)
	{
		for (auto& num : vertices)
			std::cout << num << " ";
	}
private:
	std::unordered_map<Vertex*, std::vector<Vertex*>> adjList;

	
};