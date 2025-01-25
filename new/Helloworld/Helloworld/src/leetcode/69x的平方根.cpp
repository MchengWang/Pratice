#include <iostream>

class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = x, result = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if ((long long)mid * mid <= x) {
                result = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    int nums = 1;
    while (nums != 0)
    {
        std::cin >> nums;
        std::cout << sol.mySqrt(nums) << std::endl;
    }
    std::cin.get();
}