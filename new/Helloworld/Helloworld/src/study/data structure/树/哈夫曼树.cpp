#include <iostream>

 //哈夫曼的存储表示
typedef struct
{
	int weight; // 节点的权值
	int parent, lchild, rchild; // 节点的双亲，左孩子，右孩子的下标
}HTNode , *HuffmanTree;

 //构造哈夫曼树
void CreateHuffmanTree(HuffmanTree& HT, int n)
{
	// 构造哈夫曼树HT
	if (n <= 1) return;
	int m = 2 * n - 1;
	HT = new HTNode[m + 1]; // 0号单元未用，所以需要动态分配m+1个单元，HT[m]表示根节点
	for (int i = 1; i <= m; ++i) // 将1~m号单元中的双亲，左孩子，右孩子的下表初始化为0
	{
		HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
	}
	for (int i = 1; i <= n; ++i) // 输入前n个单元中叶子节点的权值
		std::cin >> HT[i].weight;

	for (int i = n + 1; i <= m; ++i)
	{
		// 通过n-1次的选择、删除、合并来创建哈夫曼树
		Select(HT, i - 1, s1, s2);
		// 在HT[k](1<=l<=i -1)中选择两个其双亲域为0且权值最小的节点，并返回他们在HT中的序号s1和s2
		HT[s1].parent = i;
		HT[s2].parent = i;
		// 得到新节点i，从森林中删除s1,s2。将s1和s2的双亲域由0改为i
		HT[i].lchild = s1;
		HT[i].rchild = s2; // s1 ， s2 分别作为i的左右孩子
		HT[i].weight = HT[s1].weight + HT[s2].weight; // i的权值为左右孩子权值之和
	} // for
}

typedef char** HuffmanCode; // 动态分配数组存储哈夫曼编码表

// 根据哈夫曼树求哈夫曼编码
void CreateHuffmanCode(HuffmanTree HT, HuffmanCode& HC, int n)
{
	// 从叶子到根逆向求每个字符的哈夫曼编码，存储在编码表HC中
	HC = new char* [n + 1]; // 分配存储n个字符编码的编码表空间
	char* cd = new char[n]; // 分配临时存放每个字符编码的动态数组空间
	cd[n - 1] = '\0'; // 编码结束符
	for (int i = 1; i <= n; i++) // 逐个字符求哈夫曼编码
	{
		int start = n - 1; // start开始时指向最后，即编码结束符位置
		int c = i;
		HuffmanTree f = HT[i].parent; // f指向节点c的双亲节点
		while (f != 0)
		{
			--start; // 回溯一次start向前指一个位置
			if (HT[f].lchild == c)
				cd[start] = '0'; // 节点c是f的左孩子，则生成代码0
			else
				cd[start] = '1'; // 节点c是f的右孩子，则生成代码1
			c = f;
			f = HT[f].parent; // 继续向上回溯
		} // 求出第i个字符的编码
		HC[i] = new char[n - start]; // 为第i个字符编码分配空间
		strcpy(HC[i], &cd[start]); // 将求得的编码从临时空间cd赋值到HC的当前行中
	} // for
	delete cd; // 释放临时空间
}

 //利用二叉树求解表达式的值
 //表达式树的创建
void InitExpTree()
{
	// 表达式树的创建算法
	InitStack[EXPT]; // 初始化EXPT栈
	InitStack[OPTR]; // 初始化OPTR栈
	Push(OPTR, '#'); // 将表达式起始符‘#’压入OPTR栈
	std::cin >> ch; 
	while (ch != '#' || GetTop(OPTR) != '#') // 表达式没有查找完毕或OPTR的栈顶元素不为‘#’
	{
		if (!In(ch)) // ch不是运算符
		{
			CreateExpTree(T, NULL, NULL, ch); // 以ch为根创建一棵只有根节点的二叉树
			Push(EXPT, T); // 将二叉树根节点T金EXPT栈
			std::cin >> ch; // 读入下一个字符
		}
		else
			switch (Precede(GetTop(OPTR) , ch)) // 比较OPTR的栈顶元素和ch的优先级
			{
			case '<':
				Push(OPTR, ch);
				std::cin >> ch; // 当前字符ch压入OPTR栈，读入下一个字符
				break;
			case '>':
				Pop(OPTR, theta); //弹出OPTR栈顶的运算符
				Pop(EXPT, b); Pop(EXPT, a); // 弹出EXPT栈顶的两个操作数
				CreateExpTree(T, a, b, theta); // 以theta为根，a为左子树，b为右子树，创建一棵二叉树
				Push(EXPT, T); // 是二叉树根节点T进EXPT栈
				break;
			case '=': // OPTR的栈顶元素是“（”且ch是“）”
				Pop(OPTR, x); // 弹出OPTR栈顶的“（”，读入下一个字符ch
				std::cin >> ch;
				break;
			} // switch
	} // while
}

