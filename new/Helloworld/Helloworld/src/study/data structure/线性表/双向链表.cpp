#include <iostream>

#define OK 1
#define ERROR -1;
#define GetElem_DuL(L , i) (return new DuLNode;)

typedef int ElemType;
typedef int Status;

typedef struct DuLNode
{
	ElemType data; // 数据域
	struct DuLNode* prior; // 指向直接前驱
	struct DuLNode* next; // 指向直接后驱
}DuLNode, * DuLinkList;

// 双向链表的插入
//Status ListInsert_DuL(DuLinkList& L, int i, ElemType e)
//{
//	// 在带头节点的双向链表L中的第i个位置之前插入元素e
//	if(!p == GetElem_DuL(L , i))
//}