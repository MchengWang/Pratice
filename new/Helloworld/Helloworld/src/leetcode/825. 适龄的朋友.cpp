#include <vector>
#include <algorithm>

class Solution {
public:
    int numFriendRequests(std::vector<int>& ages) {
        int n = ages.size();
        sort(ages.begin(), ages.end());
        int left = 0, right = 0, count = 0;
        for (int age : ages) {
            if (age < 15) {
                continue;
            }
            while (ages[left] <= 0.5 * age + 7) {
                ++left;
            }
            while (right + 1 < n && ages[right + 1] <= age) {
                ++right;
            }
            count += right - left;
        }
        return count;
    }
};