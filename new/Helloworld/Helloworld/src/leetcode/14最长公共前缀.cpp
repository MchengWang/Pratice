#include <iostream>
#include <string>
#include <vector>

//输入：strs = ["flower", "flow", "flight"]
//输出："fl"
//
//输入：strs = ["dog", "racecar", "car"]
//输出：""

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if (strs.empty() || strs.size() == 0) return "";  // 如果vector容器中元素为空，直接返回空字符串

        std::string pre = strs[0];  // 将第一个字符串作为初始前缀

        for (int i = 1; i < strs.size(); i++) {
            // 逐个比较当前字符串与前缀的字符
            int j = 0;
            while (j < pre.length() && j < strs[i].length() && pre[j] == strs[i][j]) j++;
            pre = pre.substr(0, j);  // 更新前缀为共同的子串
            if (pre.empty()) break;  // 如果前缀为空，则不需要继续比较
        }
        return pre;
    }
};