#include <iostream>
#include <string>
#include <map>
//
////×Ö·û          ÊýÖµ
////I             1
////V             5
////X             10
////L             50
////C             100
////D             500
////M             1000
//
class Solution {
private:
    std::map<char, int> nums = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };

public:
    int romanToInt(std::string s) {
        int result = 0;
        int length = s.length();
        for (int i = 0; i < length; i ++) {
            int value = nums[s[i]];
            if (i < length - 1 && value < nums[s[i + 1]]) {
                result -= value;
            }
            else {
                result += value;
            }
        }
        return result;
    }
};
//
//int main()
//{
//    Solution sol;
//    std::string s;
//    std::cin >> s;
//    while (s != "0")
//    {
//        int num = sol.romanToInt(s);
//        std::cout << num << std::endl;
//        std::cin >> s;
//    }
//    std::cin.get();
//}