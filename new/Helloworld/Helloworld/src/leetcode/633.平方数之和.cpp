#include <iostream>
#include <cmath>

class Solution {
public:
    bool judgeSquareSum(int c) {
        // 通过定义 a 然后利用a^2 + b^2 = c 得到 b 的平方
        for (long a = 0; a * a <= c; a++)
        {
            // 利用开平方函数，计算 b 的算数平方根
            double b = std::sqrt(c - a * a);
            // 如果 b 为一个确定的整数，且不是小数，则匹配成功
            if (b == (int)b)
            {
                return true;
            }
        }
        return false;
    }
};