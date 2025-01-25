#include <iostream>
#include <string>

class Solution {
public:
    int lengthOfLastWord(std::string s) {
        int index = s.size() - 1;

        while (s[index] == ' ') {
            index--;
        }
        int length = 0;
        while (index >= 0 && s[index] != ' ') {
            length++;
            index--;
        }

        return length;
    }
};

//int main()
//{
//    Solution sol;
//    std::cout << sol.lengthOfLastWord("ss df ssss") << std::endl;
//    std::cin.get();
//}