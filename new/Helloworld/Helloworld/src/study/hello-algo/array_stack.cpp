#include <iostream>
#include <vector>

class ArrayStack
{
public:
	/* 获取栈的长度 */
	int size()
	{
		return stack.size();
	}

	/* 判断栈是否为空 */
	bool isEmpty()
	{
		return stack.size() == 0;
	}

	/*入栈*/
	void push(int num)
	{
		stack.push_back(num);
	}

	/* 出栈 */
	int pop()
	{
		int num = top();
		stack.pop_back();
		return num;
	}

	/* 访问栈顶元素 */
	int top()
	{
		if (isEmpty()) std::cout << "栈为空" << std::end;
		return stack.back();
	}

	/* 返回 vector */
	std::vector<int> toVector()
	{
		return stack;
	}
private:
	std::vector<int> stack;
};