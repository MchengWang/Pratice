#include <iostream>

#define MAXV 3

struct MGraph
{
	int numVertice, numEdges; 
	char VerticesList[MAXV];
	int Edge[MAXV][MAXV];
};

int printVertices(MGraph G)
{
	int count = 0;
	for (int i = 0; i < G.numVertice; i++)
	{
		int indegree = 0, outdegree = 0;
		for (int j = 0; j < G.numVertice; j++)
			outdegree += G.Edge[i][j];
		for (int j = 0; j < G.numVertice; j++)
			indegree += G.Edge[j][i];
		if (outdegree > indegree)
		{
			std::cout << G.VerticesList[i];
			count++;
		}
	}

	return count;
}