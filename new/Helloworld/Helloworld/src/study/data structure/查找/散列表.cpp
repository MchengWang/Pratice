#include <iostream>
#include <string>

#define m 20 // 散列表的表长
#define NULLKEY 0 // 单位为空的标记

typedef int KeyType;
typedef std::string InfoType;

typedef struct
{
	KeyType key; // 关键字项
	InfoType otherinfo; //其他数据项
}HashTable[m];

int SearchHash(HashTable HT, KeyType key)
{
	// 在散列表HT中查找关键字为key的元素，若查找成功，返回散列表的单元标号，否则返回-1
	H0 = H(key); // 根据散列函数H(key)计算散列地址
	if (HT[H0].key == NULLKEY) return -1; // 若单元H0为空，则所查元素不存在
	else if (HT[H0].key == key) return H0; // 若单元H0中元素的关键字为key，则查找成功
	else
	{
		for (int i = 1; i < m; i++)
		{
			Hi = (H0 + 1) % m; // 按照线性表探测法计算下一个散列地址Hi
			if (HT[Hi].key == NULLKEY) return -1; // 若单元Hi为空，则所查元素不存在
			else if (HT[Hi].key == key) return Hi; // 若单元Hi中元素的关键字为key，则查找成功
		} // for
	} // else
}