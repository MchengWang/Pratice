#include <iostream>

#define MAXSIZE 100 // 顺序栈存储空间的初始化分配量
#define OK 1
#define ERROR -1

typedef int SElemType;
typedef int Status;

typedef struct 
{
	SElemType* base; // 栈底指针
	SElemType* top; // 栈顶指针
	int stacksize; // 栈可用的最大容量
} SqStack;

 //初始化
Status InitStack(SqStack& S)
{
	 //构造一个空栈S
	S.base = new SElemType[MAXSIZE]; // 为顺序栈动态分配一个最大容量为MAXSIZE的数组空间
	if (!S.base) exit(OVERFLOW); // 存储分配失败
	S.top = S.base; // top初始为base，空栈
	S.stacksize = MAXSIZE; // stacksize 置为栈的最大容量MAXSIZE
	return OK;
}

 //入栈
Status Push(SqStack& S, SElemType e)
{
	 //插入元素e为新的栈顶元素
	if (S.top - S.base == S.stacksize) return ERROR; // 栈满
	*S.top++ = e; // 将元素e压入栈顶，栈顶指针加1
	return OK;
}

 //出栈
Status Pop(SqStack& S, SElemType& e)
{
	 //删除S的栈顶元素，用e返回其值
	if (S.top == S.base) return ERROR; // 栈空
	e = *--S.top; // 栈顶指针减1，将栈顶元素赋给e
	return OK;
}

// 取栈顶元素
SElemType GetTop(SqStack S)
{
	 //返回S的栈顶元素，不修改栈顶指针
	if (S.top != S.base) // 栈非空
		return *(S.top - 1); //返回栈顶元素的值，栈顶指针不变
}

// 数制转换
void conversion(int N)
{
	// 对于任何一个非负十进制数，打印输出与其等值的八进制数
	SqStack S;
	InitStack(S); // 初始化空栈S
	while (N)
	{
		Push(S, N % 8); // 把N与8求余得到的八进制数压入栈S
		N /= 8; // N更新为N与8的商
	}
	while (!StackEmpty(S)) // 当栈S非空时，循环
	{
		Pop(S, e); // 弹出栈顶元素e
		std::cout << e; // 输出e
	}

}

 //括号匹配
Status Matching()
{
	// 检验表达式中所含括号是否正确匹配，如果正确匹配，则返回true，否则返回false
	// 表达式以“#”结束
	SqStack S;
	InitStack(S); // 初始化空栈

	int flag = 1; // 标记匹配结果以控制循环及返回结果
	char ch;
	std::cin >> ch; // 读入第一个字符
	while (ch != '#' && flag) // 假设表达式以“#”结尾
	{
		switch (ch)
		{
		case '[': // 若是左括号，则将其压入栈
		case '(':
			Push(S, ch);
			break;
		case ')': // 若是‘）’,则根据当前栈顶元素的值分情况考虑
			if (!StackEmpty(S) && GetTop(S) == '(')
				Pop(S, x); // 若栈非空且栈顶元素是“（”，则正确匹配
			else flag = 0; // 若栈空或栈顶元素不是“（”，则错误匹配
			break;
		case ']': // 若是‘]’，则根据当前栈顶元素的值分情况考虑
			if (!StackEmpty(S) && GetTop(S) == '[')
				Pop(S, x); // 若栈非空且栈顶元素是“[”，则正确匹配
			else flag = 0; // 若栈空或栈顶元素不是“[”，则错误匹配
			break;
		} // switch
		std::cin >> ch; // 继续读下一个字符
	} // while
	if (StackEmpty(S) && flag) return true; // 匹配成功
	else return false; // 匹配失败
}

 //表达式求值
char EvaluateExpression()
{
	// 算术表达式的算符优先算法，设OPTR和OPND分别为运算符栈和操作数栈
	SqStack OPND, OPTR;
	InitStack(OPND); // 初始化OPND栈
	InitStack(OPTR); // 初始化OPTR栈
	Push(OPTR, '#'); //将表达式起始符‘#’压入OPTR栈
	char ch;
	std::cin >> ch;
	while (ch != '#' || GetTop(OPTR) != '#') // 表达式没有查找完毕或OPTR的栈顶元素部位‘#’
	{
		if (!In(ch)) // ch不是运算符则进OPND栈
		{
			Push(OPND, ch);
			std::cin >> ch;
		}
		else
		{
			switch (Precede(GetTop(OPTR) , ch)) // 比较OPTR的栈顶元素和ch的优先级
			{
			case '<' :
				Push(OPTR, ch); // 当前字符ch压入OPTR栈，读入下一个字符ch
				std::cin >> ch;
				break;
			case '>':
				Pop(OPTR, theta); // 弹出OPTR栈顶的运算符
				Pop(OPND, b); //弹出OPND栈顶的两个运算数
				Pop(OPND, a);
				Push(OPND, Operate(a, theta, b)); //将运算结果压入OPND栈
				break;
			case '=': // OPTR的栈顶元素是“(”且ch是“）”
				Pop(OPTR, x); // 弹出OPTR栈顶的“（”，读入下一个字符ch
				std::cin >> ch;
				break;
			} // switch
		}
	} // while
	return GetTop(OPND); // OPND栈顶元素即表达式求值结果
}