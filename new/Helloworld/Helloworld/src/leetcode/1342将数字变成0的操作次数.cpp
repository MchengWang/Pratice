#include <iostream>

class Solution {
public:
    int numberOfSteps(int num) {
        int count = 0;
        while (num != 0)
        {
            if (num % 2 == 0) num >>= 1;
            else num -= 1;

            count++;
        }
        return count;
    }
};

//int main()
//{
//    Solution sol;
//    int num = 0;
//    std::cin >> num;
//    std::cout << sol.numberOfSteps(num) << std::endl;
//    std::cin.get();
//}