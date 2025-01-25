#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
	void reverseString(std::vector<char>& s) {
		int left = 0, right = s.size() - 1; // 分别作为头和尾的指针
		while (left <= right) // 当头指针在尾指针的左侧，代表未到达中间位置
		{
			char temp = s[left];
			s[left] = s[right];
			s[right] = temp;
			left++;
			right--;
		}
	}
};

int main()
{
	//std::vector<char> vecs = { 'h','e','l','l','o' };
	std::vector<char> vecs = { 'H','a','n','n','a' , 'h'};
	Solution sol;
	sol.reverseString(vecs);
	std::for_each(vecs.begin(), vecs.end(), [](const char ch) { std::cout << ch << " "; });
	return 0;
}