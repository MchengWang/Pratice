#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
	int longestValidParentheses(std::string s) {
		int num = s.size();
		int ans = 0;
		int start = -1;
		std::vector<int> stack;      //存放‘(’的下标
		for (int i = 0; i < num; i++) {
			if (s[i] == '(') {  //遇到'('
				stack.push_back(i);     //下标入栈
			}
			else {               //遇到')'
				if (stack.empty()) {
					//栈空，此时因为s[i]是‘)’，且前面没有剩余的‘(’与之匹配
					//于是前面的子串不再可能再与后面拼接成更大的子串
					//我们直接更新 start = i 截断前面的子串，后续的子串最长从start开始
					start = i;
				}
				else {
					//栈不空，即有‘(’与之匹配，先将其出栈
					stack.pop_back();
					//此时需要考虑该处已经匹配的括号前面是否还有‘(’未匹配
					if (stack.empty()) {
						//栈空，说明从start之后(不包括start)的括号均已配对
						//取当前子串长度 i - start 和已有ans比较，取最大值
						ans = std::max(i - start, ans);
					}
					else {
						//栈不空，说明从start之后还有‘(’等待配对
						//此时栈顶的‘(’即为最近的未匹配括号，下标记为j
						//则从 j + 1 开始取得当前最长子串长度 i - j，
						//并和已有ans比较，取最大值
						ans = std::max(i - stack.back(), ans);
					}
				}
			}
		}

		return ans;
	}
};