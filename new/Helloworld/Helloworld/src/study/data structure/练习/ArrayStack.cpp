#include <iostream>
#include <assert.h>

#define maxSize 100

template <typename T>
class ArrayStack
{
public:
	// 初始化
	ArrayStack() :top(-1) {}

	// 判栈为空
	bool isEmpty()
	{
		return top == -1;
	}

	// 进栈
	bool push(T x)
	{
		if (top == maxSize - 1)
		{
			throw std::out_of_range("栈满");
			return false;
		}
		data[++top] = x;
		return true;
	}

	// 出栈
	bool pop(T& t)
	{
		if (top == -1)
		{
			throw std::out_of_range("栈为空");
			return false;
		}
		t = data[top--];
		return true;
	}

	// 获取栈顶元素
	bool getTop(T& t)
	{
		if (top == -1)
		{
			throw std::out_of_range("栈为空");
			return false;
		}
		t = data[top];
		return true;
	}
private:
	T data[maxSize];
	int top;
};


int main()
{
	ArrayStack<int>* astack = new ArrayStack<int>();
	astack->push(10);
	astack->push(12);
	int num = 0;
	astack->pop(num);
	astack->push(11);
	astack->pop(num);
	astack->getTop(num);
	assert(num == 10);
	std::cout << num << std::endl;
	return 0;
}