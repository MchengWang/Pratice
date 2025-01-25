#include <iostream>
#include <string>

typedef int KeyType;
typedef std::string InfoType;

typedef struct
{
	KeyType key; // 关键字域
	InfoType otherinfo; // 其他域 
}ElemType;

typedef struct
{
	ElemType* R; // 存储空间基地址
	int length; // 当前长度
}SSTable;

int Search_Seq(SSTable ST , KeyType key)
{
	// 在顺序表ST中顺序查找其关键字等于key的数据元素。若找到，则函数值为该元素在表中的位置，否则为0
	for (int i = ST.length; i >= 1; i--)
		if (ST.R[i].key == key) return i; // 从后往前查找
	return 0;
}

int Search_Seq(SSTable ST, KeyType key)
{
	// 在顺序表ST中顺序查找其关键字等于key的数据元素，若找到，则函数值为该元素在表中的位置，否则则为0
	ST.R[0].key = key; // “监视哨”
	for (int i = ST.length; ST.R[i].key != key; i--) // 从后往前找
		return i;
}