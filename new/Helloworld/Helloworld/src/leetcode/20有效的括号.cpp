#include <iostream>
#include <string>
#include <unordered_map>
#include <stack>

class Solution {
public:
    bool isValid(std::string s) {
        // 如果字符串长度为奇数，可以直接返回
        if (s.length() % 2 != 0) return false;

        // 定义括号的对应关系
        std::unordered_map<char, char> maps = {
            {')' , '('} ,
            {']' , '['} ,
            {'}' , '{'}
        };

        // 创建栈对象
        std::stack<char> rooms;

        // 遍历字符串，获得每一位的字符
        for (char ch : s)
        {
            // 如果在对应关系中存在这个符号
            if (maps.count(ch))
            {
                // 栈不为空 或者栈顶元素部位括号对应关系中对应的元素
                if (rooms.empty() || rooms.top() != maps[ch])
                    return false;
                else rooms.pop();

            }
            else rooms.push(ch); // 将元素压入栈
        }

        return rooms.empty();
    }
};

//int main()
//{
//    Solution sol;
//    std::string s;
//    std::cin >> s;
//    std::cout << sol.isValid(s) << std::endl;
//}