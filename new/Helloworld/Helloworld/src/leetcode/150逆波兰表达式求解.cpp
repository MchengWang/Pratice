#include <iostream>
#include <vector>
#include <string>
#include <stack>
//
//#define STRING_TO_INT(x) std::stoi(x , 0 ,10)
//
//class Solution {
//public:
//	int evalRPN(std::vector<std::string>& tokens) {
//		std::stack<int> sta;
//		int a = 0, b = 0;
//		for (int i = 0; i < tokens.size(); i++)
//		{
//			if (tokens[i].size() > 1)
//				sta.push(STRING_TO_INT(tokens[i]));
//			else
//			{
//				switch (tokens[i].at(0))
//				{
//				case '+':
//				{
//					a = sta.top();
//					sta.pop();
//					b = sta.top();
//					sta.pop();
//					sta.push(b + a);
//					break;
//				}
//				case '-':
//				{
//					a = sta.top();
//					sta.pop();
//					b = sta.top();
//					sta.pop();
//					sta.push(b - a);
//					break;
//				}
//				case '*':
//				{
//					a = sta.top();
//					sta.pop();
//					b = sta.top();
//					sta.pop();
//					sta.push(b * a);
//					break;
//				}
//				case '/':
//				{
//					a = sta.top();
//					sta.pop();
//					b = sta.top();
//					sta.pop();
//					sta.push(b / a);
//					break;
//				}
//				default:
//					sta.push(STRING_TO_INT(tokens[i]));
//					break;
//				}
//			}
//		}
//		return sta.top();
//	}
//};
//
//int main()
//{
//	Solution sol;
//	//std::vector<std::string> vecs = { "2","1","+","3","*" };
//	//std::vector<std::string> vecs = { "4","13","5","/","+" };
//	std::vector<std::string> vecs = { "10","6","9","3","+","-11","*","/","*","17","+","5","+" };
//	std::cout << sol.evalRPN(vecs) << std::endl;
//	return 0;
//}

#include <iostream>
#include <vector>
#include <string>
#include <stack>

#define STRING_TO_INT(x) std::stoi(x , 0 ,10)

class Solution {
public:
	int evalRPN(std::vector<std::string>& tokens) {
		std::stack<int> sta;
		int a = 0, b = 0;
		for (int i = 0; i < tokens.size(); i++)
		{
			if (tokens[i].size() > 1)
				sta.push(STRING_TO_INT(tokens[i]));
			else
			{
				switch (tokens[i].at(0))
				{
				case '+':
				{
					a = sta.top();
					sta.pop();
					b = sta.top();
					sta.pop();
					sta.push(b + a);
					break;
				}
				case '-':
				{
					a = sta.top();
					sta.pop();
					b = sta.top();
					sta.pop();
					sta.push(b - a);
					break;
				}
				case '*':
				{
					a = sta.top();
					sta.pop();
					b = sta.top();
					sta.pop();
					sta.push(b * a);
					break;
				}
				case '/':
				{
					a = sta.top();
					sta.pop();
					b = sta.top();
					sta.pop();
					sta.push(b / a);
					break;
				}
				default:
					sta.push(STRING_TO_INT(tokens[i]));
					break;
				}
			}
		}
		return sta.top();
	}
};

int main()
{
	Solution sol;
	//std::vector<std::string> vecs = { "2","1","+","3","*" };
	//std::vector<std::string> vecs = { "4","13","5","/","+" };
	std::vector<std::string> vecs = { "10","6","9","3","+","-11","*","/","*","17","+","5","+" };
	std::cout << sol.evalRPN(vecs) << std::endl;
	return 0;
}