#include <iostream>
#include <stack>
#include <string>

#define CHAR_TO_INT(x) (int)x - 48

//class Solution {
//public:
//	int calculate(std::string s) {
//		// 可以设计两个栈
//		// 一个栈用于存储符号
//		// 另一个栈用于存储操作数
//		std::stack<char> sta_char;
//		std::stack<int> sta_int;
//
//		// 定义取值
//		int a = 0, b = 0;
//		
//		// 将字符串的每一位进行遍历获得每一位的值
//		for (int i = 0; i < s.size(); i++)
//		{
//			if(s[i] == ' ') continue;
//			else
//			{
//				if (s[i] >= '0' && s[i] <= '9')
//					sta_int.push(CHAR_TO_INT(s[i]));
//				else
//				{
//					if (sta_char.empty()) sta_char.push(s[i]);
//					else
//					{
//						switch (s[i])
//						{
//						case '+':
//						case '-':
//						{
//							// 当前字符运算级别低于乘除 ，就要先行弹出符号栈中的符号进行操作数计算，后将操作数压回栈中
//							switch (sta_char.top())
//							{
//							case '*':
//							{
//								// 分别取出操作数栈中的两个数值，进行相应的计算后，压回栈中
//								a = sta_int.top();
//								sta_int.pop();
//								b = sta_int.top();
//								sta_int.pop();
//								sta_int.push(b * a);
//								break;
//							}
//							case '/':
//							{
//								a = sta_int.top();
//								sta_int.pop();
//								b = sta_int.top();
//								sta_int.pop();
//								sta_int.push(b / a);
//								break;
//							}
//							}
//							sta_char.push(s[i]);
//							break;
//						}
//						case '*':
//						case '/':
//							// 对于乘除符号，则直接将其压回符号栈中即可
//							sta_char.push(s[i]);
//							break;
//						}
//					}
//				}
//			}
//		}
//
//		// 循环遍历栈中的元素，直到栈为空
//		while (!sta_char.empty())
//		{
//			// 分别取出操作数栈中的两个栈顶元素
//			a = sta_int.top();
//			sta_int.pop();
//			b = sta_int.top();
//			sta_int.pop();
//			// 在取出一个符号栈中的栈顶元素，进行计算。后将得到结果压回操作数栈中
//			switch (sta_char.top())
//			{
//			case '+': sta_int.push(b + a);
//				break;
//			case '-': sta_int.push(b - a);
//				break;
//			case '*': sta_int.push(b * a);
//				break;
//			case '/': sta_int.push(b / a);
//				break;
//			}
//			// 因为使用了操作栈中栈顶元素操作符，就需要删除符号栈中的栈顶元素
//			sta_char.pop();
//		}
//		// 操作数栈中的栈顶元素即为最终结果
//		int ji = 1 , result = 0;
//		while (!sta_int.empty())
//		{
//			result += (sta_int.top() * ji);
//			ji *= 10;
//			sta_int.pop();
//		}
//
//		return result;
//	}
//};

class Solution {
public:
	bool isOp(char c) {
		return (c == '+' || c == '-' || c == '*' || c == '/');// 判断字符是否为操作符
	}
	// 执行算术运算
	int compute(int numa, int numb, char op) {
		switch (op) {
		case '+':
			return numa + numb;
		case '-':
			return numa - numb;
		case '*':
			return numa * numb;
		case '/':
			return numa / numb;
		default:
			return 0;
		}
	}
	// 获取操作符的优先级
	int getPrecedence(char op) {
		if (op == '+' || op == '-') {
			return 1;
		}
		else if (op == '*' || op == '/') {
			return 2;
		}
		return 0;  // 默认优先级为0
	}
	int calculate(std::string s) {
		// 计算表达式的值
		std::stack<int> sta_int;
		std::stack<char> sta_char;

		for (int i = 0; i < s.size(); i++) {
			char c = s[i];
			if (isdigit(c)) {
				// 处理多位数字
				int num = 0;
				while (isdigit(c)) {
					num = num * 10 + (c - '0');
					c = s[++i];
				}
				sta_int.push(num);
			}
			if (isOp(c)) {
				// 弹出优先级大于等于当前操作符的栈顶操作符，并进行运算
				while (!sta_char.empty() && getPrecedence(sta_char.top()) >= getPrecedence(c)) {
					int operand2 = sta_int.top();
					sta_int.pop();

					int operand1 = sta_int.top();
					sta_int.pop();

					char op = sta_char.top();
					sta_char.pop();

					int result = compute(operand1, operand2, op);
					sta_int.push(result);
				}
				sta_char.push(c);
			}

			if (c == '(') {
				sta_char.push(c);
			}

			if (c == ')') {
				// 弹出栈顶操作符直到遇到左括号，并进行运算
				while (!sta_char.empty() && sta_char.top() != '(') {
					int operand2 = sta_int.top();
					sta_int.pop();

					int operand1 = sta_int.top();
					sta_int.pop();

					char op = sta_char.top();
					sta_char.pop();

					int result = compute(operand1, operand2, op);
					sta_int.push(result);
				}
				if (!sta_char.empty() && sta_char.top() == '(') {
					sta_char.pop();  // 弹出左括号
				}
			}
		}

		// 执行剩余的运算
		while (!sta_char.empty()) {
			int operand2 = sta_int.top();
			sta_int.pop();

			int operand1 = sta_int.top();
			sta_int.pop();

			char op = sta_char.top();
			sta_char.pop();

			int result = compute(operand1, operand2, op);
			sta_int.push(result);
		}

		return sta_int.top();

	}
};

int main()
{
	//std::cout << (int)'0' << std::endl; // 48
	//std::cout << (int)'9' << std::endl; // 57
	//std::cout << (int)'+' << std::endl; // 43
	//std::cout << (int)'-' << std::endl; // 45
	//std::cout << (int)'*' << std::endl; // 42
	//std::cout << (int)'/' << std::endl; // 47
	Solution sol;
	std::cout << sol.calculate("3+2*2") << std::endl;
	std::cout << sol.calculate("3/2") << std::endl;
	std::cout << sol.calculate("3+5/2") << std::endl;
	std::cout << sol.calculate(" 3 + 5 / 2  ") << std::endl;
	std::cout << sol.calculate(" 42 ") << std::endl;
	return 0;
}