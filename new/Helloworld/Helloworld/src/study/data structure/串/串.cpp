#include <iostream>

#define MAXLEN 255 // 穿的最大长度

// 串的定长顺序存储结构
typedef struct
{
	char ch[MAXLEN]; // 存储串的一维数组
	int length; // 穿的当前长度
}SString;

// 串的堆式顺序存储结构
typedef struct
{
	char* ch; //若是非空串，则按串长分配存储区，否则ch为NULL
	int length; // 串的当前长度
}HString;

// 串的链式存储结构
#define CHUNKSIZE 80 // 可由用户定义的块大小
typedef struct Chunk
{
	char ch[CHUNKSIZE];
	struct Chunk* next;
}Chunk;

typedef struct
{
	Chunk* head, * tail; // 串的头和尾指针
	int length; // 串的当前长度
}LString;

// BF算法
int Index_BF(SString S, SString T, int pos)
{
	// 返回模式T在主串S中第pos个字符开始第一次出现的位置。若不存在，则返回0
	// 其中，T非空，1<= pos < S.length
	int i = pos, j = 1; // 初始化
	while (i <= S.length && j <= T.length) // 两个串均未比较到表尾
	{
		if (S.ch[i] == T.ch[j]) { //继续比较后继字符
			++i;
			++j;
		}
		else
		{
			i = i - j + 2; // 指针后退，重新开始匹配
			j = 1;
		}
	}
	if (j > T.length) return i - T.length; // 匹配成功
	else return 0; // 匹配失败
}