#include <iostream>
#include <string>

class Solution {
public:
    bool isPalindrome2(std::string s) {
        // 创建双指针，分别指向开始和最后
        int start = 0, end = s.size() - 1;
        while (start < end)
        {
            // 当当前字符不是数字或者字母，则跳过当前位置元素对比
            if (!isalnum(s[start]))
                start++;
            if (!isalnum(s[end]))
                end--;
            // 如果指针相遇时，判断元素字符是否相等
            if (start < end && tolower(s[start]) != tolower(s[end]))
                 return false;
        }
        return true;
    }

    bool isPalindrome(std::string s) {
        std::string sgood;
        for (char ch : s) {
            if (isalnum(ch)) {
                sgood += tolower(ch);
            }
        }
        int start = 0, end = sgood.size() - 1;
        while (start < end) {
            if (sgood[start] != sgood[end]) {
                return false;
            }
            ++ start;
            -- end;
        }
        return true;
    }
};

//int main()
//{
//    Solution sol;
//    std::cout << sol.isPalindrome("adda") << std::endl;
//    std::cin.get();
//}