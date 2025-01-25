#include <iostream>
#include <string>

class Solution {
public:
	int myAtoi(std::string strs) {
		int i = 0, flag = 1;
		long result = 0l;

		while (strs[i] == ' ') i++;

		if (strs[i] == '-' || strs[i] == '+') {
			flag = (strs[i] == '-') ? -1 : 1;
			i++;
		}

		while (i < strs.length() && strs[i] <= '9' && strs[i] >= '0') {
			result = result * 10 + (strs[i] - '0');
			i++;

			if (result * flag >= INT_MAX) return INT_MAX;
			if (result * flag <= INT_MIN) return INT_MIN;
		}

		return result * flag;
	}

};

int main()
{
	Solution sol;
	std::cout << sol.myAtoi("   -042") << std::endl;
	return 0;
}