#include <iostream>
#include <string>
#include <stack>

class Solution {
public:
	std::string reverseWords(std::string s) {
		std::string temp = "", strs = "", tt = "";
		std::stack<std::string> sta;
		for (int i = 0; i < s.size(); i++)
		{
			if (s.at(i) == ' ' || i == s.size() - 1)
			{
				if (s.at(i) != ' ') temp.push_back(s[i]);

				if (!temp.empty())
				{
					sta.push(temp);
					temp.erase();
				}

			}
			else if (s.at(i) != ' ') temp.push_back(s.at(i));
			else continue;
		}

		temp.erase();

		while (!sta.empty())
		{
			strs.append(sta.top().data());
			sta.pop();
			if (!sta.empty()) strs.append(" ");
		}

		return strs;
	}
};

int main()
{
	Solution sol;
	std::string str = sol.reverseWords("  hello world  ");
	std::string temp = "";
	for (int i = 0; i < str.size(); i++)
	{
		if (str.at(i) == ' ' || i == str.size() - 1)
		{
			if (str.at(i) != ' ') temp.push_back(str[i]);
			std::cout << temp << " ";
			temp.erase();
		}
		else temp.push_back(str[i]);
	}
	return 0;

}