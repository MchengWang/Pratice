#include <iostream>
#include <vector>

class Solution {
public:
    int singleNonDuplicate(std::vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            int mid = (high - low) / 2 + low;
            if (nums[mid] == nums[mid ^ 1]) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }
        return nums[low];
    }
};

int main()
{
    Solution sol;
    std::vector<int> test = { 1,1,2,3,3,4,4,8,8 };
    std::cout << (sol.singleNonDuplicate(test) == 2) << std::endl;
    return 0;
}