#include <iostream>

#define MAXSIZE 100 // 顺序表可能达到的最大长度
#define OK 1
#define ERROR -1

typedef int ElemType;
typedef int Status;


typedef struct
{
	ElemType* elem; // 存储空间的基地址
	int length; // 当前长度
}SqList;

// 初始化
Status InitList(SqList& L)
{
	// 构造一个空的顺序表L
	L.elem = new ElemType[MAXSIZE]; // 为顺序表分配一个大小为MAXSIZE的数组空间
	if (!L.elem) exit(OVERFLOW); // 存储分配失败推出
	L.length = 0; // 空表长度为0
	return OK;
}

// 取值
Status GetElem(SqList L, int i, ElemType& e)
{
	if (i < 1 || i > L.length) return ERROR; // 判断i值是否合理，若不合理返回ERROR

	e = L.elem[i - 1]; // elem[i - 1]单元存储第i个数据元素
	
	return OK;
}

// 查找
int LocateElem(SqList L, ElemType e)
{
	// 在顺序表中查找值为e的数据元素，返回其序号
	for (int i = 0; i < L.length; i++)
		if (L.elem[i] == e) return i + 1; // 查找成功，返回序号 i+1
	return 0; // 查找失败，返回0
}

// 插入
Status ListInsert(SqList& L, int i, ElemType e)
{
	// 在顺序表L中第i个位置插入新的元素e,i值的合法范围是1<=i<=L.length+1
	if (i < 1 || i > L.length + 1) return ERROR; // i值不合法
	if (L.length == MAXSIZE) return ERROR; // 当前存储空间已满
	for (int j = L.length - 1; j >= i - 1; j--)
		L.elem[j + 1] = L.elem[j]; // 插入位置及之后的元素后移
	L.elem[i - 1] = e; // 将新元素e放入第i个位置
	++L.length; // 表长加一
	return OK;
}

// 删除
Status ListDelete(SqList& L, int i)
{
	// 在顺序表L中删除第i个元素，i值的合法范围是1<=i<=L.lenght
	if (i < 1 || i > L.length) return ERROR; // i值不合法
	for (int j = i; j <= L.length; j--)
		L.elem[j - 1] = L.elem[j]; // 被删除元素之后的元素前移
	--L.length; // 表长减一
	return OK;
}

// 顺序有序表的合并
void MergeList_Sq(SqList LA, SqList LB, SqList LC)
{
	// 已知顺序表LA和LB的元素按值非递减排列
	// 归并LA和LB得到新的顺序有序表LC，LC的元素也按值非递减排列
	LC.length = LA.length + LB.length; // 信标长度为待合并两表的长度之和
	LC.elem = new ElemType[LC.length]; // 为合并后的新表分配一个数组空间
	ElemType* pc = LC.elem; // 指针pc指向新表的第一个元素
	ElemType* pa = LA.elem;
	ElemType* pb = LB.elem; // 指针pa和pb的初值分别指向两个表的第一个元素
	ElemType* pa_last = LA.elem + LA.length - 1; // 指针pa_last指向LA的最后一个元素
	ElemType* pb_last = LB.elem + LB.length - 1; // 指针pb_last指向LB的最后一个元素
	while (pa <= pa_last && pb <= pb_last) // 未达到LA和LB的表尾
	{
		if (*pa <= *pb) *pc++ = *pa++; // 依次摘取量表中值较小的节点插入LC的最后
		else *pc++ = *pb++;
	}
	while (pa <= pa_last) *pc++ = *pa++; // 已到达LB表尾，依次将LA的剩余元素插入LC的最后
	while (pb <= pb_last) *pc++ = *pb++; // 已到达LA表尾，依次将LB的剩余元素插入LC的最后
}