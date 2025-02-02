#include <iostream>
#include <string>

#define MAX_VERTEX_NUM 20

typedef int VertexType;
typedef std::string InfoType; 

typedef struct ArcBox
{
	int tailvex, headvex; // 该弧的尾和头顶点的位置
	struct ArcBox* hlink, * tlink; // 分别为弧头相同和弧尾相同的弧的链域
	InfoType* info; // 该弧的相关信息的指针
}ArcBox;

typedef struct VexNode
{
	VertexType data;
	ArcBox* firstin, * firstout; // 分别指向嗲顶点第一条入弧和出弧
}VexNode;

typedef struct
{
	VexNode alist[MAX_VERTEX_NUM]; //表头向量
	int vexnum, arcnum; // 有向图的当前定点数和弧数
}OLGraph;