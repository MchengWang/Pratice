#include "structs.h"

#define w 200

typedef struct
{
	RedType rec; // 记录
	KeyType key; // 从记录中抽取的关键字
	int rnum; // 所属归并端的段号
}RcdNode , WorkArea[w]; // 内存工作区，容量为w

WorkArea wa;