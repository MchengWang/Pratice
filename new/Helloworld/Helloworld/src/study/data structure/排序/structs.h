#pragma once
#include <string>
#define MAXSIZE 20 // 顺序表的最大长度

typedef int KeyType;// 定义关键字类型为整数
typedef std::string InfoType;

typedef struct
{
	KeyType key; // 关键字项
	InfoType otherinfo; // 其他数据项
}RedType; // 记录类型

typedef struct
{
	RedType r[MAXSIZE + 1]; // r[0]闲置或用作哨兵单元
	int length; // 顺序表长度
}SqList; // 顺序表类型