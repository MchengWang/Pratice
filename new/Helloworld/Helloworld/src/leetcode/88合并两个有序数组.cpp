#include <vector>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        int pointer1 = 0, pointer2 = 0;
        int count = m + n + 0;
        std::vector<int> arr;
        while (pointer1 < m || pointer2 < n)
        {
            if (pointer1 == m) arr.push_back(nums2[pointer2++]);
            else if (pointer2 == n) arr.push_back(nums1[pointer1++]);
            else if (nums1[pointer1] < nums2[pointer2]) arr.push_back(nums1[pointer1++]);
            else arr.push_back(nums2[pointer2++]);
        }

        nums1 = arr;
    }
};