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

int Search_Bin(SSTable ST, KeyType key)
{
	// 在有序表ST中折半查找其关键字等于key的数据元素。若找到，则函数值为该元素在表中的位置，否则为0
	int low = 1, high = ST.length; // 置查找区间初值
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (key == ST.R[mid].key) return mid; // 找到待查元素
		else if (key < ST.R[mid].key) high = mid - 1; // 继续在前一子表进行查找
		else low = mid + 1; // 继续在后一子表进行查找
	}

	return 0;
}